# STM32 Blinky - Memory Mapping Approach

This project demonstrates a simple LED blinky application for the STM32F446RE Nucleo board using direct memory mapping and register manipulation without HAL functions.

## Overview

This is part of a series where I implement the same functionality using two different approaches:
1. **HAL Functions** (separate repository) - Using STM32's high-level abstraction layer
2. **Memory Mapping** (this repository) - Direct register manipulation for deeper hardware understanding

## Hardware

- **Board**: STM32F446RE Nucleo
- **LED**: Built-in user LED (typically connected to PA5)

## Approach

This implementation uses direct register manipulation which provides:
- Low-level hardware control
- Better understanding of microcontroller internals
- Smaller code footprint
- More precise timing control
- Direct access to peripheral registers

### Key Concepts Used
- GPIO register manipulation (MODER, ODR, etc.)
- RCC clock enable registers
- Memory-mapped peripheral access
- Bit manipulation techniques

## Project Structure

```
├── Core/
│   ├── Inc/           # Header files
│   │   └── main.h
│   ├── Src/           # Source files
│   │   ├── main.c     # Main application with register manipulation
│   │   └── system_stm32f4xx.c
│   └── Startup/       # Startup files
├── Drivers/           # Minimal CMSIS drivers
└── *.ioc             # STM32CubeMX configuration (minimal)
```

## Register-Level Implementation

This project directly manipulates:
- **RCC_AHB1ENR**: To enable GPIOA clock
- **GPIOA_MODER**: To configure PA5 as output
- **GPIOA_ODR**: To control LED state
- Custom delay implementation using CPU cycles


## Learning Objectives

- Understanding STM32 register structure
- Direct peripheral manipulation
- Memory mapping concepts
- Bit-level operations
- Hardware abstraction understanding

## Demo

Youtube video: https://youtu.be/269zvtMcr_E

## Comparison

For a comparison using high-level HAL functions, check out the companion repository: [STM32-Blinky-HAL](https://github.com/Ama-Andam/STM32-Blinky-HAL)

This approach helps understand what happens "under the hood" when using HAL functions.

