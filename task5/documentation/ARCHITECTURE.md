# System Architecture

## Overview
The firmware follows a layered embedded architecture where hardware access is isolated in driver modules and application logic is implemented in the main loop. A timer-driven event mechanism is used to control periodic GPIO sampling and UART transmission.



## High-Level Block Diagram

### Push Button (PD0)
###   ↓
### GPIO Driver
###   ↓
### Application Logic
###   ↓
### Sampling Control Flag
###   ↓
### Timer2 Interrupt → timer_flag
###   ↓
### GPIO Read (PD1)
###   ↓
### UART Driver
###   ↓
### PC Terminal



## Layered Architecture

### Driver Layer
- GPIO driver handles Port D pin configuration and input reads
- Timer driver configures Timer2 and generates periodic interrupts
- UART driver configures USART1 and transmits serial data
- All peripheral registers are accessed only within drivers

### Application Layer
- Initializes all drivers
- Implements start/stop sampling logic
- Responds to timer events
- Reads GPIO input values
- Transmits sampled values over UART

## Control Flow
- System initializes drivers
- Button press toggles sampling state
- Timer interrupt sets `timer_flag`
- Main loop processes sampling when enabled

## Data Flow
Each timer event results in a single GPIO sample being transmitted as a text value (`0` or `1`) on a new UART line.

## Design Rationale
- Clear separation of hardware and application logic
- Deterministic sampling using timer interrupts
- Simple and reusable driver interfaces



## Architectural Benefits

- Easy to understand and maintain
- Matches industry-standard embedded firmware practices
- Documentation accurately reflects implemented behavior
