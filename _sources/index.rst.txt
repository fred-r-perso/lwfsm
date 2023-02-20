.. LwFSM documentation master file, created by
   sphinx-quickstart on Sun Feb 19 05:11:14 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to LwFSM's documentation!
=================================

What is LwFSM ?
###############

LwFSM is a Finite State Machine (FSM) engine and its objective is to:
* be lightweight,
* be suitable for embedded systems,
* offer an abstract syntax in the FSM declaration.

**NOTE:** This code follows the principles of the lw modules from https://github.com/MaJerle

**NOTE:**  This code is provided by the author in his own name.

How to use LwFSM ?
##################

LwFSM offers:
* a set of macros to define the FSM
* 2 functions to initialize and run the state machine

The end-user can:
* start from the templates available in the `lwfsm/src` folder
* implement one C function per FSM state and associate it to its state with the macros
* initialize and run the FSM engine from his applicative code

Folders structure
#################

The code is available in the `lwfsm/` folder.

Examples are available in the `examples/` folder.

A more complete documentation is available in the `doc/` folder.

Design principles
#################

LwFSM is written in ISO C (C11).

The LwFSM engine can run several state machines concurrently:
* it uses a context describing an FSM,
* it does not use any global or module variable.

LwFSM is configurable via a set of defines gathered in some option files.

LwFSM does not have any hardware-adherence.
It only needs a C library and a printf-like service (see `lwfsm_log.h`).

Two programming models are proposed:
#. a first model targeting simplicity and more compact code: see `lwfsm_app_model1_template.c`,
#. a latter model targeting an improved maintainability, but requiring some more complex definitions: see `lwfsm_app_model2_template.c`.

The two models can be used in the same project, they are not exclusive.

.. toctree::
   :maxdepth: 3
   :caption: Contents:

LwFSM User API
==============
.. doxygengroup:: LwFSM_API_M1
.. doxygengroup:: LwFSM_API_M2

FSM declaration
===============
 .. doxygengroup:: LwFSM_Macros

LwFSM types
===========
.. doxygengroup:: LwFSM_Types

LwFSM configuration
===================
.. doxygengroup:: LWFSM_OPT

LwFSM logging service
=====================
.. doxygengroup:: LWFSM_LOG
