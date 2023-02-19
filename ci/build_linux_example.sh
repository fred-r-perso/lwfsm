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
apt-get -y install git rsync gpg

# latest CMAKE
apt-get -y update && \
apt-get -y install -y software-properties-common lsb-release && \
apt-get -y clean all

wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null

apt-get -y-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"

apt-get -y update
apt-get -y install kitware-archive-keyring
rm /etc/apt/trusted.gpg.d/kitware.gpg

apt-get -y update
apt-get -y install cmake

# Ownership issue patch
git config --global --add safe.directory /__w/lwfsm/lwfsm

#################
# BUILD EXAMPLE #
#################

cmake ./examples/linux_x86_64/lwfsm_demo/
cmake --build ./examples/linux_x86_64/lwfsm_demo/
 

popd # return to main repo sandbox root

# exit cleanly
exit $?
