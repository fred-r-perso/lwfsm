# __LWFSM : *lwfsm_demo*__

This project runs on STM32U5 and illustrates how one can use the LwFSM code.

## What is it doing ?

The `Core/Src/main.c` file is the entry point of the program.
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
- a STM32CubeMX project to configure the system (`lwfsm_demo.ioc`),
- a STM32CubeIDE project to build the program (`.project`),
- the applicative code illustrating how to use LwFSM is located in the `App` folder.

## How to use ?

- Open the `.project` with STM32CubeIDE (Version: 1.10.1 or greater)
- Build the project
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

Please report issues in [github](https://github.com/fred-r/lwfsm/issues).
