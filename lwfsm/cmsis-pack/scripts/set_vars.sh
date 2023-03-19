#!/bin/bash

export CMSIS_PACK_ROOT="/home/$USER/.arm/Packs"
echo $CMSIS_PACK_ROOT is available for the child process
export export PATH=$PATH:/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-cmsis/tools.open.cmsis.pack.ctools/1.5.0/bin/packchk
bash
