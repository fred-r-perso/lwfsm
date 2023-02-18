# __LWFSM : *lwfsm_demo*__

This project runs on a Linux machine and illustrates how one can use the LwFSM code.

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
- a CMakeLists.txt file to compile the project for Linux x86_64 target with GCC
- the applicative code illustrating how to use LwFSM is located in the `App` folder.

## How to use ?

- Compile the project using CMake
```
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ cmake .
Entering /home/fred/lwfsm/lwfsm/lwfsm/CMakeLists.txt
Exiting /home/fred/lwfsm/lwfsm/lwfsm/CMakeLists.txt
-- Configuring done
-- Generating done
-- Build files have been written to: /home/fred/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ cmake --build .
[ 20%] Building C object CMakeFiles/lwfsm_demo.dir/app/lwfsm_app.c.o
[ 40%] Building C object CMakeFiles/lwfsm_demo.dir/app/lwfsm_app_model2.c.o
[ 60%] Building C object CMakeFiles/lwfsm_demo.dir/core/main.c.o
[ 80%] Building C object CMakeFiles/lwfsm_demo.dir/home/fred/lwfsm/lwfsm/lwfsm/src/lwfsm/lwfsm.c.o
[100%] Linking C executable lwfsm_demo
[100%] Built target lwfsm_demo
```
- Run the executable
```
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ ./lwfsm_demo
***** LwFSM demo project *****
Start with programming model 1
[INFO] LwFSM - init success.
[INFO] LwFSM - entering state: Initial State
Press b to continue
```

## Facing issues ?

Please report issues in [github](https://github.com/fred-r-perso/lwfsm/issues).
