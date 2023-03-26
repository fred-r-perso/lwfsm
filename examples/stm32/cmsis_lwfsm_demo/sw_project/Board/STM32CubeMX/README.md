# __LWFSM : *CubeMX bypass*__

The component `Device:STM32Cube Framework` is required by dependencies though we do not need it.

In this example, we reuse the code generated with `stm32/cube_lwfsm_demo/lwfsm_demo.ioc`.

So, the code that should be added by the `Device:STM32Cube Framework` component is already added via the group `STM32 Core` in `lwfsm_demo.cproject.yml`.

Therefore, we add this fake gpdsc file in the project to bypass the invokation of the CubeMX tool.
