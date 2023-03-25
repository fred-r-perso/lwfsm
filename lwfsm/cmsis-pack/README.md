# __LWFSM : *cmsis-pack*__

This folder contains LwFSM as a [CMSIS-Pack](https://www.open-cmsis-pack.org/) and the necessary files and scripts to generate a new version of the pack.

## Prerequisites

To build the pack need the following software:

  - bash compatible shell (under Windows, use for example git bash)
  - Python v3.6 or later
  - [7-ZIP](https://7-zip.org/) to create the pack file
  - CMSIS Pack installed in CMSIS_PACK_ROOT (for [PackChk](https://www.keil.com/pack/doc/CMSIS_Dev/Pack/html/packChk.html) utility)
  - [xmllint](https://gitlab.gnome.org/GNOME/libxml2) in path (XML schema validation; available only for Linux: *libxml2-utils*)

## What does it contain ?

The LwFSM cmsis pack is available in the `pack/` folder.

The scripts are available in the `scripts/` folder.

The XML schema is available in the `resources/` folder.


## How to use ?

Please note that this tool requires folders and cmsis-packs in your local environment.

### Environment variables
[OPTIONAL] For instance, on a Linux machine, it expects:
```
CMSIS_PACK_ROOT="/home/$USER/.arm/Packs"
```
[MANDATORY] You mst have the PackChk tool in your PATH.  
You can call on Linux:
```
./scripts/set_vars.sh
```

### First installation

- For VSCode, follow [this method](https://github.com/Open-CMSIS-Pack/vscode-get-started)
- VSCode extensions in use: Arm.cmsis-csolution, Arm.device-manager, Arm.embedded-debug, Arm.keil-studio-pack
- Generic install: see [cmsis-toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/installation.md)

This will install the required OpenCMSIS tool: `packchk`.

[OPTIONAL] You can create your CMSIS_PACK_ROOT folder like this:
```
./scripts/set_vars.sh
mkdir /home/$USER/.arm/
mkdir /home/$USER/.arm/Packs
cd /home/$USER/.arm/Packs
cpackget -v init --pack-root . https://www.keil.com/pack/index.pidx
```

### Generate the pack

Make sure you have updated the .pdsc file.

Work from the upper level folder: `lwfsm/lwfsm/`

Then:
```
./cmsis-pack/scripts/gen_pack.sh
```

### Install the pack

Work from the upper level folder: `lwfsm/lwfsm/`

Then:
```
cpackget add ./cmsis-pack/pack/fred-r-perso.lwfsm.0.1.0.pack
```
