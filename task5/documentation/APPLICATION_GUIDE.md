# Application Guide

## Overview
The application periodically samples a digital GPIO input and transmits the sampled values over UART. Sampling can be started or stopped using a push button.

## Initialization
At startup, the application:
- Initializes UART for serial output
- Configures GPIO pins on Port D
- Initializes Timer2 for periodic interrupts
- Prints startup messages over UART

## Operating Modes

### Idle Mode
- Sampling disabled
- No UART data output

### Sampling Mode
- Sampling enabled
- GPIO input sampled periodically
- Sampled values transmitted over UART

## Main Loop Behavior
- Button state is monitored to detect a press event
- Sampling state is toggled on a valid button press
- Timer interrupt sets `timer_flag`
- Main loop reads GPIO input when flag is set
- Sampled value is transmitted as `0` or `1`

## Timing Behavior
- Sampling interval is controlled by Timer2 (~500 ms)
- Timer interrupt only sets a flag
- All processing occurs in the main loop

## Output Format
- Line-based UART output
- One GPIO sample per line




