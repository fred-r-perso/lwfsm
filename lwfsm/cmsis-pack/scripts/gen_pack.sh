#!/bin/bash
# Version: 1.2
# Date: 2020-12-21
# This bash script generates a CMSIS Software Pack:
#
# Pre-requisites:
# - bash shell (for Windows: install git for Windows)
# - 7z in path (zip archiving utility)
#   e.g. Ubuntu: sudo apt-get install p7zip-full p7zip-rar)
# - PackChk is taken from latest install CMSIS Pack installed in $CMSIS_PACK_ROOT
# - xmllint in path (XML schema validation; available only for Linux)

############### EDIT BELOW ###############
# Extend Path environment variable locally
#

OS=$(uname -s)
case $OS in
  'Linux')
    if [ -z ${CMSIS_PACK_ROOT+x} ] ; then
      CMSIS_PACK_ROOT="/home/$USER/.arm/Packs"
    fi
    # CMSIS_TOOLSDIR="$(ls -drv ${CMSIS_PACK_ROOT}/ARM/CMSIS/* | head -1)/CMSIS/Utilities/Linux64"
    ;;
  'WindowsNT'|MINGW*|CYGWIN*)
    if [ -z ${CMSIS_PACK_ROOT+x} ] ; then
      CMSIS_PACK_ROOT="$LOCALAPPDATA/Arm/Packs"
    fi
    CMSIS_PACK_ROOT="/$(echo ${CMSIS_PACK_ROOT} | sed -e 's/\\/\//g' -e 's/://g' -e 's/\"//g')"
    # CMSIS_TOOLSDIR="$(ls -drv ${CMSIS_PACK_ROOT}/ARM/CMSIS/* | head -1)/CMSIS/Utilities/Win32"
    ;;
  'Darwin')
    echo "Error: CMSIS Tools not available for Mac at present."
    exit 1
    ;;
  *)
    echo "Error: unrecognized OS $OS"
    exit 1
    ;;
esac

# PATH_TO_ADD="$CMSIS_TOOLSDIR"

# [[ ":$PATH:" != *":$PATH_TO_ADD}:"* ]] && PATH="${PATH}:${PATH_TO_ADD}"
# echo $PATH_TO_ADD appended to PATH
# echo " "

# Pack warehouse directory - destination
PACK_WAREHOUSE=cmsis-pack/pack

# Temporary pack build directory
PACK_BUILD=cmsis-pack/.build

# Specify directory names to be added to pack base directory
PACK_DIRS="
  ./src
"

# Specify file names to be added to pack base directory
PACK_BASE_FILES="
  ../LICENSE
"

# Specify file names to be deleted from pack build directory
PACK_DELETE_FILES="
  *.gitignore
  Makefile
  CMakeLists.txt
"

############ DO NOT EDIT BELOW ###########
echo Starting CMSIS-Pack Generation: `date`
# Zip utility check
ZIP=7z
type -a "${ZIP}"
errorlevel=$?
if [ $errorlevel -gt 0 ]
  then
  echo "Error: No 7zip Utility found"
  echo "Action: Add 7zip to your path"
  echo " "
  exit
fi

# Pack checking utility check
PACKCHK=packchk
type -a ${PACKCHK}
errorlevel=$?
if [ $errorlevel != 0 ]
  then
  echo "Error: No PackChk Utility found"
  echo "Action: Add PackChk to your path"
  echo "Hint: Included in CMSIS Pack:"
  echo "$CMSIS_PACK_ROOT/ARM/CMSIS/<version>/CMSIS/Utilities/<os>/"
  echo " "
  exit
fi
echo " "

# Locate Package Description file
# check whether there is more than one pdsc file
NUM_PDSCS=`ls -1 ./*.pdsc | wc -l`
PACK_DESCRIPTION_FILE=`ls ./*.pdsc`
if [ ${NUM_PDSCS} -lt 1 ]
  then
  echo "Error: No *.pdsc file found in current directory"
  echo " "
  exit
elif [ ${NUM_PDSCS} -gt 1 ]
  then
  echo "Error: Only one PDSC file allowed in directory structure:"
  echo "Found:"
  echo "$PACK_DESCRIPTION_FILE"
  echo "Action: Delete unused pdsc files"
  echo " "
  exit
fi

SAVEIFS=$IFS
IFS=.
set ${PACK_DESCRIPTION_FILE}
# Pack Vendor
PACK_VENDOR="fred-r-perso"
# Pack Name
PACK_NAME="lwfsm"
echo "Generating Pack Version: for $PACK_VENDOR.$PACK_NAME"
echo " "
IFS=$SAVEIFS

#if $PACK_BUILD directory does not exist, create it.
if [ ! -d "$PACK_BUILD" ]; then
  mkdir -p "$PACK_BUILD"
fi

# Copy files into build base directory: $PACK_BUILD
# pdsc file is mandatory in base directory:
cp -f "./${PACK_VENDOR}.${PACK_NAME}.pdsc" "${PACK_BUILD}"

# Add directories
echo Adding directories to pack:
echo "${PACK_DIRS}"
echo " "
for d in ${PACK_DIRS}
do
  cp -r "$d" "${PACK_BUILD}"
done

# Add files
echo Adding files to pack:
echo "${PACK_BASE_FILES}"
echo " "
if [ ! -x ${PACK_BASE_FILES+x} ]; then
  for f in ${PACK_BASE_FILES}
    do
      cp -f "$f" $PACK_BUILD/
  done
fi

# Delete files
echo Deleting files from pack:
echo "${PACK_DELETE_FILES}"
echo " "
if [ ! -x ${PACK_DELETE_FILES+x} ]; then
  for f in ${PACK_DELETE_FILES}
    do
      find $PACK_BUILD/$(dirname "$f") -name $(basename "$f") -delete
  done
fi

# Run Schema Check (for Linux only):
# sudo apt-get install libxml2-utils

if [ $(uname -s) = "Linux" ]
  then
  echo "Running schema check for ${PACK_VENDOR}.${PACK_NAME}.pdsc"
  xmllint --noout --schema "./cmsis-pack/resources/PACK.xsd" "${PACK_BUILD}/${PACK_VENDOR}.${PACK_NAME}.pdsc"
  errorlevel=$?
  if [ $errorlevel -ne 0 ]; then
    echo "build aborted: Schema check of $PACK_VENDOR.$PACK_NAME.pdsc against PACK.xsd failed"
    echo " "
    exit
  fi
else
  echo "Use MDK PackInstaller to run schema validation for $PACK_VENDOR.$PACK_NAME.pdsc"
fi

# Run Pack Check and generate PackName file with version
"${PACKCHK}" "${PACK_BUILD}/${PACK_VENDOR}.${PACK_NAME}.pdsc" \
  -n PackName.txt
errorlevel=$?
if [ $errorlevel -ne 0 ]; then
  echo "build aborted: pack check failed"
  echo " "
  exit
fi

PACKNAME=$(cat PackName.txt)
rm -rf PackName.txt

# Archiving
# $ZIP a $PACKNAME
echo "creating pack file $PACKNAME"
#if $PACK_WAREHOUSE directory does not exist create it
if [ ! -d "$PACK_WAREHOUSE" ]; then
  mkdir -p "$PACK_WAREHOUSE"
fi
pushd "$PACK_WAREHOUSE" > /dev/null
PACK_WAREHOUSE=$(pwd)
popd  > /dev/null
pushd "$PACK_BUILD" > /dev/null
PACK_BUILD=$(pwd)
"$ZIP" a "$PACK_WAREHOUSE/$PACKNAME" -tzip
popd  > /dev/null
errorlevel=$?
if [ $errorlevel -ne 0 ]; then
  echo "build aborted: archiving failed"
  exit
fi

echo "build of pack succeeded"
# Clean up
echo "cleaning up ..."

rm -rf "$PACK_BUILD"
echo " "

echo Completed CMSIS-Pack Generation: $(date)
