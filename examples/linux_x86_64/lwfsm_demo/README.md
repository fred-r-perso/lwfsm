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

## Memcheck

You can leverage valgrind to mke sure this demo does not have memory issues.

- Build in debug mode
```
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ cmake -Bdbg -DCMAKE_BUILD_TYPE=Debug
-- The C compiler identification is GNU 7.5.0
-- The CXX compiler identification is GNU 7.5.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
Entering /home/fred/lwfsm/lwfsm/lwfsm/CMakeLists.txt
Exiting /home/fred/lwfsm/lwfsm/lwfsm/CMakeLists.txt
-- Configuring done
-- Generating done
-- Build files have been written to: /home/fred/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo/dbg
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ cmake --build dbg
[ 20%] Building C object CMakeFiles/lwfsm_demo.dir/app/lwfsm_app.c.o
[ 40%] Building C object CMakeFiles/lwfsm_demo.dir/app/lwfsm_app_model2.c.o
[ 60%] Building C object CMakeFiles/lwfsm_demo.dir/core/main.c.o
[ 80%] Building C object CMakeFiles/lwfsm_demo.dir/home/fred/lwfsm/lwfsm/lwfsm/src/lwfsm/lwfsm.c.o
[100%] Linking C executable lwfsm_demo
[100%] Built target lwfsm_demo
```

- Run the instrumented binary
```
fred@fred-N53Jl:~/lwfsm/lwfsm/examples/linux_x86_64/lwfsm_demo$ valgrind ./dbg/lwfsm_demo
==11794== Memcheck, a memory error detector
==11794== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11794== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==11794== Command: ./dbg/lwfsm_demo
==11794==
***** LwFSM demo project *****
Start with programming model 1
[INFO] LwFSM - init success.
[INFO] LwFSM - entering state: Initial State
Press b to continue
b
gButtonCnt=1
Press b to continue
b
gButtonCnt=2
...
gButtonCnt=10
Press a key to continue
Press b to continue
b
[INFO] LwFSM - FSM engine terminates with success.
***** LwFSM demo project completed.*****
==11794==
==11794== HEAP SUMMARY:
==11794==     in use at exit: 0 bytes in 0 blocks
==11794==   total heap usage: 2 allocs, 2 frees, 2,048 bytes allocated
==11794==
==11794== All heap blocks were freed -- no leaks are possible
==11794==
==11794== For counts of detected and suppressed errors, rerun with: -v
==11794== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Facing issues ?

Please report issues in [github](https://github.com/fred-r-perso/lwfsm/issues).
