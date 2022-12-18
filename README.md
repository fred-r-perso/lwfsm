# __LWFSM : *Lightweight FSM management system for embedded systems*__

## What is LwFSM ?

LwFSM is a Finite State Machine (FSM) engine and its objective is to:
- be lightweight,
- be suitable for embedded systems,
- offer an abstract syntax in the FSM declaration.

> **_NOTE:_**  This code has no link with the author's employer, it is provided by the author in his own name and as an individual.

## How to use LwFSM ?

LwFSM offers:
- a set of macros to define the FSM
- 2 functions to initialize and run the state machine

The end-user can:
- start from the templates available in the `lwfsm/src` folder
- implement one C function per FSM state and associate it to its state with the macros
- initialize and run the FSM engine from his applicative code

## Folders structure

The code is available in the `lwfsm/` folder.

Examples are available in the `examples/` folder.

A more complete documentation is available in the `doc/` folder.

## Design principles

LwFSM is written in ISO C (C11).

The LwFSM engine can run several state machines concurrently:
- it uses a context describing an FSM,
- it does not use any global or module variable.

LwFSM is configurable via a set of defines gathered in some option files.

LwFSM does not have any hardware-adherence.
It only needs a C library and a printf-like service (see `lwfsm_log.h`).

Two programming models are proposed:
- a first model targeting simplicity and more compact code: see `lwfsm_app_model1_template.c`,
- a latter model targeting an improved maintainability, but requiring some more complex definitions: see `lwfsm_app_model2_template.c`.

The two models can be used in the same project, they are not exclusive.
