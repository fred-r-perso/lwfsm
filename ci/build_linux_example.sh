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
apt-get -y install git rsync cmake

# Ownership issue patch
git config --global --add safe.directory /__w/lwfsm/lwfsm

#####################
# DECLARE VARIABLES #
#####################

pwd
ls -lah
export SOURCE_DATE_EPOCH=$(git log -1 --pretty=%ct)

#################
# BUILD EXAMPLE #
#################

cmake ./examples/linux_x86_64/lwfsm_demo/
cmake --build ./examples/linux_x86_64/lwfsm_demo/
 

popd # return to main repo sandbox root

# exit cleanly
exit 0
