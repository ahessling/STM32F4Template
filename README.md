CMake-based STM32F4 Template
============================

This repository contains a CMake-based template project as a starting point for STM32 F4 projects. ST's official *Standard Peripheral Library* is already included in this repository and will automatically be linked against the target application.

Both **C and C++** sources are supported. CMake will also try to find OpenOCD and will generate a *flash* target for easy programming of the microcontroller.

This template includes a sample application which turns on the blue LED on the STM32F4Discovery board for demonstration purposes.

# Prerequisites
Get CMake for your platform. You should use at least **CMake 2.8.12**.

For compiling the project, a GNU C/C++ compiler is required. I highly suggest the [GNU ARM Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm).
Make sure that the toolchain executables are in your **PATH** environment.

# Quick start
TODO
