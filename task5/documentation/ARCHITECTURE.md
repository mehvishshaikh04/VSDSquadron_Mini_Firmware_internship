# System Architecture

## Overview
This project follows a layered embedded firmware architecture where hardware-specific drivers are separated from application logic. A timer-driven event mechanism is used to ensure deterministic sampling of a GPIO input and transmission of data over UART.
The architecture is designed to be simple, modular, and reusable.

## High-Level Block Diagram
<img width="530" height="195" alt="image" src="https://github.com/user-attachments/assets/39af7202-dd34-407b-ac60-449c6f00b286" />


## Layered Architecture

### 1. Driver Layer
Located in the `lib/` directory.

The driver layer is responsible for all direct hardware interaction.

- **GPIO Driver**
  - Configures Port D pins
  - Reads push button state
  - Reads sampled signal input

- **Timer Driver**
  - Configures Timer2
  - Generates periodic interrupts
  - Sets a software flag for sampling control

- **UART Driver**
  - Configures USART1
  - Transmits characters and strings over serial interface

All hardware registers are accessed only inside drivers.


### 2. Application Layer
Located in `app/main.c`.

The application layer:
- Initializes all drivers
- Implements start/stop sampling control using a push button
- Responds to timer events
- Reads GPIO input values
- Sends sampled values to UART

The application interacts with hardware **only through driver APIs** and does not directly manipulate peripheral registers.


## Control Flow

1. System initializes GPIO, UART, and Timer drivers.
2. The application waits in the main loop.
3. A button press toggles the sampling state.
4. When sampling is enabled:
   - Timer interrupt sets `timer_flag`
   - Main loop detects the flag
   - GPIO signal pin is sampled
   - Sampled value is transmitted over UART
5. When sampling is disabled, no data is transmitted.


## Data Flow
<img width="381" height="369" alt="image" src="https://github.com/user-attachments/assets/e92b5114-d1dc-4b22-a28e-274202fa4229" />


Each sampled GPIO value is transmitted as a human-readable text value on a new line.


## Timing Behavior

- Sampling is controlled by Timer2
- Timer generates periodic interrupts based on configured interval
- Sampling timing is independent of UART transmission speed
- The timer interrupt only sets a flag; all processing occurs in the main loop


## Design Rationale

- **Modularity**
  - Drivers isolate hardware-specific logic
  - Application logic remains clean and readable

- **Deterministic Sampling**
  - Timer-based triggering ensures consistent sampling intervals

- **Simplicity**
  - Line-based UART output simplifies debugging and verification

- **Reusability**
  - Drivers can be reused in future embedded applications


## Architectural Benefits

- Easy to understand and maintain
- Matches industry-standard embedded firmware practices
- Documentation accurately reflects implemented behavior
