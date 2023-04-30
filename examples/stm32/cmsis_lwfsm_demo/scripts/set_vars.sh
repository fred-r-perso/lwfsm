#!/bin/bash

export CMSIS_PACK_ROOT="/home/$USER/.arm/Packs"
echo $CMSIS_PACK_ROOT is available for the child process
export PATH=$PATH:/opt/cmsis-toolbox15/bin
# cmake
export PATH=$PATH:/usr/bin/
# ninja
export PATH=$PATH:/usr/local/bin
# arm-none-eabi-gcc
export PATH=$PATH:/usr/bin
export ASM="/usr/bin/arm-none-eabi-as"
export CC="/usr/bin/arm-none-eabi-gcc"
bash
