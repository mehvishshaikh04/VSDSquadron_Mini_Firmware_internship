# Application Guide

## Overview
The application implements a simple periodic sampling system. It reads the state of a push button connected to a GPIO pin and transmits the sampled values over UART as line-based serial output.

The application logic is implemented entirely in `main.c` and uses driver APIs for GPIO, Timer, and UART functionality.


## Application Behavior

The application operates in two primary modes:

- **Idle Mode**
- **Sampling Mode**

Sampling behavior is controlled through application logic and timer events.


## Application Flow

### 1. System Initialization
At startup, the application performs the following steps:

1. Initializes the GPIO driver for button input
2. Initializes the UART driver for serial communication
3. Initializes the timer driver for periodic interrupts
4. Enters the main execution loop


### 2. Sampling Operation

Once sampling is active, the following sequence occurs repeatedly:

1. Timer interrupt occurs at a fixed interval
2. Timer interrupt sets a software flag
3. Main loop detects the flag
4. GPIO button state is read
5. The sampled value (`0` or `1`) is prepared as text
6. The value is transmitted over UART
7. Application waits for the next timer event

This ensures controlled and periodic sampling.


## Timing Behavior

- Sampling is driven by a hardware timer
- Each sample is taken at a fixed interval
- Sampling timing is independent of UART transmission speed
- The timer ensures consistent sampling behavior


## Driver Coordination

The application coordinates multiple drivers as follows:

- **Timer Driver**
  - Controls when sampling occurs

- **GPIO Driver**
  - Provides the current button state

- **UART Driver**
  - Sends sampled data to the PC terminal

The application acts as the central controller that orchestrates these drivers.


## Output Format

- Output is transmitted as **line-based text**
- Each line represents one sampled GPIO value
- `1` indicates button released
- `0` indicates button pressed

Example output:

<img width="181" height="136" alt="image" src="https://github.com/user-attachments/assets/e83a33a9-bdfb-4f02-a3ec-256578e696ec" />

