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

- run `scripts/set_vars.sh`
- install the required pack(s): 
```
cpackget add https://keil.com/pack/ARM.CMSIS.5.9.0.pack
cpackget add https://keil.com/pack/Keil.STM32U5xx_DFP.2.1.0.pack
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

## How to use ?

### With VSCode and the Keil Studio Pack extension
- Open the Keil Studio Pack extension

### With CMSIS-Toolbox command line interface

- Build the project
  - Use the `cbuild` command from CMSIS-Toolbox to generate and build one or all configurations of the solution
  - Find out which `configurations` are specified by the solution:
  ```
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ cbuild list configurations lwfsm_demo.csolution.yml 
  .debug+B-U585I-IOT02A
  .release+B-U585I-IOT02A
  ```
  - Build the debug configuration and install the missing CMSIS packs if any:
  ```
  fredr2010@penguin:~/gh/lwfsm/examples/stm32/cmsis_lwfsm_demo$ cbuild lwfsm_demo.csolution.yml --packs --configuration .debug+B-U585I-IOT02A
  ```

- connect the [b-u585i-iot02a](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) board to your laptop over USB
- Flash the executable in the [b-u585i-iot02a](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html)
- Start a terminal emulator like [teraterm](https://ttssh2.osdn.jp/index.html.en) on your PC
- Configure the serial link:
  - Speed: 115200
  - Data: 8-bit
  - Parity: none
  - Stop bits: 1 bit
  - Flow control : none
- Press the RESET-BUTTON (black button) on the board
- Observe the logs in the console and interact with the system with the USER-BUTTON (blue button)

## Facing issues ?

Please report issues in [github](https://github.com/fred-r-perso/lwfsm/issues).
