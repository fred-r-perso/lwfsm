#!/bin/bash
set -x
################################################################################
# File:    build_linux_example.sh
# Purpose: Script that builds the basic linux example
#          This script is executed by:
#            .github/workflows/build_example_workflow.yml
#
# Authors: Frédéric Ruellé
# Created: 2023-02-19
# Updated: 2023-02-19
# Version: 0.1.0
################################################################################

###################
# INSTALL DEPENDS #
###################

apt-get update
apt-get -y install git rsync gpg ca-certificates wget software-properties-common tar

# latest CMAKE
#apt-get -y update && \
#apt-get -y install -y software-properties-common lsb-release && \
#apt-get -y clean all

#wget --no-check-certificate -v 0 -O - https://apt.kitware.com/keys/kitware-archive-latest.asc > key.asc
#gpg --dearmor key.asc
#tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null < key.asc.gpg

#apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"
#apt-get -y update

#add-apt-repository 'deb [arch=amd64] https://apt.kitware.com/ubuntu bionic main'

#apt-get -y update
#apt-get -y install cmake

#rm /etc/apt/trusted.gpg.d/kitware.gpg

#Debian
wget --no-check-certificate -v 0 -O https://github.com/Kitware/CMake/releases/download/v3.24.2/cmake-3.24.2.tar.gz
tar -zxvf cmake-3.24.2.tar.gz
cd cmake-3.24.2
./bootstrap
make
make install
cmake --version
cd ..

# Ownership issue patch
git config --global --add safe.directory /__w/lwfsm/lwfsm

#################
# BUILD EXAMPLE #
#################

cmake ./examples/linux_x86_64/lwfsm_demo/
cmake --build ./examples/linux_x86_64/lwfsm_demo/
 
# exit cleanly
exit $?
