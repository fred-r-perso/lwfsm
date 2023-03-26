#!/bin/bash

export CMSIS_PACK_ROOT="/home/$USER/.arm/Packs"
echo $CMSIS_PACK_ROOT is available for the child process
export PATH=$PATH:/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-cmsis/tools.open.cmsis.pack.ctools/1.5.0/bin
export PATH=$PATH:/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-ce-default/tools.kitware.cmake/3.25.2/bin
export PATH=$PATH:/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-community/ninja/1.10.2
export PATH=$PATH:/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-ce-default/compilers.arm.none.eabi.gcc/10.3.1-2021.10/bin
export ASM="/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-ce-default/compilers.arm.none.eabi.gcc/10.3.1-2021.10/bin/arm-none-eabi-as"
export CC="/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-ce-default/compilers.arm.none.eabi.gcc/10.3.1-2021.10/bin/arm-none-eabi-gcc"
bash
