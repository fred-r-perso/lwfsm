# __LWFSM : *cmsis_lwfsm_demo*__

This project runs on STM32U5 in the [Open-CMSIS-Pack ecosystem](https://github.com/Open-CMSIS-Pack) and illustrates how one can use the LwFSM code.

We recommend using it with [VSCode](https://code.visualstudio.com/) and the [KeilStudio Pack extension](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack).

## What is it doing ?

The `sw_project/Core/Src/main.c` file is the entry point of the program.
It configures the system and runs the applicative code.

The applicative code runs 2 state machines doing the same thing:
- each state machine is made of 3 states,
- each state collects a certain number of user-button key press,
- once all expected key-press are collected, then the state machine stops its execution

This logic is run two times:
- first with a programming model 1 FSM,
- then with a programming model 2 FSM.

## What does it contain ?

This example project contains:
- vcpkg-configuration.json to help you install the [CMSIS environment](https://github.com/Open-CMSIS-Pack/vscode-get-started#how-to-setup-your-cmsis-csolution-development-environment)
- The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md) and is written in the [`csolution`](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/YML-Format.md) format:

  - [`.cdefault.yml`](./.cdefault.yml) sets the default toolchain and specifies toolchain specific commandline options for supported toolchains.
  - [`lwfsm_demo.csolution.yml`](./lwfsm_demo.csolution.yml) lists and defines the hardware targets, build-types and projects.
  - [`sw_project/lwfsm_demo.cproject.yml`](./sw_project/lwfsm_demo.cproject.yml) defines the packs, components, source files and output files.

## Pre-requisites

__Option #1 (works for a Linux container in ChromeOS):__
- run `scripts/set_vars.sh`
- tune the GCC configuration for CMake.
  In `/home/$USER/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-cmsis/tools.open.cmsis.pack.ctools/1.5.0/etc/GCC.10.3.1.cmake`  
  Do the following change:
```
############### EDIT BELOW ###############
# Set base directory of toolchain
# set(TOOLCHAIN_ROOT "/home/runner/gcc-arm-none-eabi-10.3-2021.10/bin")
set(TOOLCHAIN_ROOT "/home/fredr2010/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-ce-default/compilers.arm.none.eabi.gcc/10.3.1-2021.10/bin"
# Prevent CMake from testing the toolchain
set(CMAKE_C_COMPILER_FORCED   1)
set(CMAKE_CXX_COMPILER_FORCED 1)
```
- install the required pack(s): 
```
cpackget add ARM.CMSIS
cpackget add Keil.STM32U5xx_DFP
cpackget add ../../../lwfsm/cmsis-pack/pack/fred-r-perso.lwfsm.0.1.0.pack
```
- install the VSCode extension if you want an IDE: 
  - Name: Keil Studio Pack
  - Id: Arm.keil-studio-pack
  - Description: Extension pack for Keil Studio development
  - Version: 1.3.2
  - Publisher: Arm
  - VS Marketplace Link: https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack
- or install the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox) if you want a CLI

__Or option #2:__
- install vcpkg as explained [here](https://www.followchain.org/install-vcpkg-on-ubuntu/)
- I also had to copy/paste the archive in ```~/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root$``` and extract it.
- install libnvurses5
```
sudo apt-get install libncurses5
```
- from lwfsm/examples/stm32/cmsis_lwfsm_demo:
```
$ sudo vcpkg activate
```
- it fails but you can install gcc for ARM by yourself

__Or option #3:__
Follow [these](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/installation.md) instructions:
- download CMSIS-Toolbox from ```https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases```
- install:
```
$ sudo mkdir /opt/cmsis-toolbox
$ sudo tar xf cmsis-toolbox-linux-arm64.tar.gz --strip-components=1 -C /opt/cmsis-toolbox/
```
- try:
```
$ /opt/cmsis-toolbox/bin/cpackget --version
bash: /opt/cmsis-toolbox/bin/cpackget : impossible d'exécuter le fichier binaire : Erreur de format pour exec()
```

__Or option #4 (works on Ubuntu 22.04):__
- you need CMAKE and GCC for ARM:
```
$ sudo apt-get update -y
$ sudo apt-get install -y cmake
$ sudo apt-get install -y gcc-arm-none-eabi
```
- download ```cmsis-toolbox.sh```
- install it:
```
$ sudo mkdir /opt/cmsis-toolbox-sh
$ sudo cp ~/Téléchargements/cmsis-toolbox.sh /opt/cmsis-toolbox-sh
$ sudo chmod +x /opt/cmsis-toolbox-sh/cmsis-toolbox.sh
$ cd /opt/cmsis-toolbox-sh/
$ sudo ./cmsis-toolbox.sh
```
- source the environment before using it:
```
$ source /opt/cmsis-toolbox-sh/./etc/setup
```
- install the required pack(s): 
```
cpackget add ARM.CMSIS
cpackget add Keil.STM32U5xx_DFP
cpackget add ../../../lwfsm/cmsis-pack/pack/fred-r-perso.lwfsm.0.1.0.pack
```

## How to use ?

### Build with VSCode and the Keil Studio Pack extension
- Open the Keil Studio Pack extension
- Select:
  - Active Solution: examples/stm32/cmsis_lwfsm_demo/lwfsm_demo
  - Target Type: B-U585I-IOT02A
  - Build Type: debug
  - Project: lwfs_demo
- See [how to configure a build task](https://github.com/ARM-software/vscode-cmsis-csolution#configure-a-build-task) or use the default one we provide
- Click on "Build"

### Build with CMSIS-Toolbox command line interface

- Build the project
  - Use the `cbuild` command from CMSIS-Toolbox to generate and build one or all configurations of the solution
  - Find out which `configurations` are specified by the solution:
  ```
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ cbuild list configurations lwfsm_demo.csolution.yml 
  .debug+B-U585I-IOT02A
  .release+B-U585I-IOT02A
  ```
  - You can do a clean-up:
  ```
  cbuild lwfsm_demo.csolution.yml --clean
  ```
  - Build the debug configuration and install the missing CMSIS packs if any:
  ```
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ cbuild lwfsm_demo.csolution.yml --packs --configuration .debug+B-U585I-IOT02A
  ```

  - In case you want to regenerate the RTE folder to replace the provided files:
  ```
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ csolution convert -s lwfsm_demo.csolution.yml 
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ cbuildgen cmake --update-rte ./sw_project/lwfsm_demo.debug+B-U585I-IOT02A.cprj
  ```

### Run the use-case out of VSCode

- connect the [b-u585i-iot02a](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) board to your laptop over USB
- Flash the executable in the [b-u585i-iot02a](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html)
  - use `examples/stm32/cmsis_lwfsm_demo/sw_project/out/lwfsm_demo/debug/B-U585I-IOT02A/lwfsm_demo.debug+B-U585I-IOT02A.bin`
  - copy it via mass storage in the board
  ```
  fredr2010@penguin:~/gh/lwfsm$ cp examples/stm32/cmsis_lwfsm_demo/sw_project/out/lwfsm_demo/debug/B-U585I-IOT02A/lwfsm_demo.debug+B-U585I-IOT02A.bin /mnt/chromeos/removable/DIS_U585AI/
  ```

- Start a terminal emulator like [teraterm](https://ttssh2.osdn.jp/index.html.en) on your PC
- Configure the serial link:
  - Speed: 115200
  - Data: 8-bit
  - Parity: none
  - Stop bits: 1 bit
  - Flow control : none
- Press the RESET-BUTTON (black button) on the board
- Observe the logs in the console and interact with the system with the USER-BUTTON (blue button)

### Run the use-case from VSCode

Update the location of the tools in `.vscode/lwfsm.code-workspace`:
```
		"cmsis-csolution.cbuildPath": "/home/fredr2010/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-cmsis/tools.open.cmsis.pack.ctools/1.5.0/bin/cbuild",
		"cmsis-csolution.csolutionPath": "/home/fredr2010/.config/Code/User/globalStorage/ms-vscode.vscode-embedded-tools/vcpkg/root/downloads/artifacts/vcpkg-artifacts-cmsis/tools.open.cmsis.pack.ctools/1.5.0/bin/csolution",
```

Then you need to generate the cprj files:
```
fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ ./scripts/set_vars.sh
/home/fredr2010/.arm/Packs is available for the child process
fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ csolution convert -s lwfsm_demo.csolution.yml
/home/fredr2010/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo/sw_project/lwfsm_demo.debug+B-U585I-IOT02A.cprj - info csolution: file generated successfully
/home/fredr2010/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo/sw_project/lwfsm_demo.release+B-U585I-IOT02A.cprj - info csolution: file generated successfully
/home/fredr2010/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo/sw_project/lwfsm_demo.debug+B-U585I-IOT02A.cbuild.yml - info csolution: file generated successfully
/home/fredr2010/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo/sw_project/lwfsm_demo.release+B-U585I-IOT02A.cbuild.yml - info csolution: file generated successfully
/home/fredr2010/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo/lwfsm_demo.cbuild-idx.yml - info csolution: file generated successfully
```

Then open the CMSIS panel:
- The Active Solution is: `lwfsm_demo`
- The Target Type is: `B-U585I-IOT02A`
- The Build Type is: `debug`
- The Project is: `lwfsm_demo`
and click on "Build".

## Facing issues ?

Please report issues in [github](https://github.com/fred-r-perso/lwfsm/issues).
