# Application Guide

## Overview
The application implements a simple software-based oscilloscope behavior using GPIO sampling and UART output.  
A push button is used to start and stop sampling, a hardware timer controls the sampling interval, and sampled GPIO values are transmitted over UART as line-based serial output.

All application logic is implemented in `main.c`, while hardware-specific operations are handled by driver APIs.


## Application Initialization

At system startup, the application performs the following steps:

1. Initializes UART for serial communication
2. Configures GPIO pins on Port D
   - Button input pin
   - Signal input pin
3. Initializes Timer2 for periodic interrupts
4. Prints startup messages on the UART terminal
5. Enters the main execution loop


## Application Modes

The application operates in two modes:

### 1. Idle Mode
- Sampling is disabled
- No signal values are transmitted
- Application waits for a button press to start sampling

### 2. Sampling Mode
- Sampling is enabled
- GPIO signal pin is sampled periodically
- Sampled values are transmitted over UART

The sampling mode is toggled using the push button.

---

## Main Application Flow

The main loop continuously performs the following tasks:

### Button Handling
1. The button state is read using the GPIO driver
2. A falling edge (button press) is detected
3. Sampling state is toggled
4. A status message is printed:
   - `"Sampling STARTED"` or
   - `"Sampling STOPPED"`

This mechanism prevents repeated toggling while the button is held down.



### Sampling Operation

When sampling is enabled:

1. Timer interrupt sets the `timer_flag`
2. Main loop detects `timer_flag`
3. The flag is cleared
4. GPIO signal pin is read
5. The sampled value is converted to text:
   - `'1'` for HIGH
   - `'0'` for LOW
6. The value is transmitted over UART
7. A new line is printed

Each timer event results in exactly one sample being transmitted.

---

## Timing Behavior

- Sampling is controlled by Timer2 interrupts
- Timer interval determines sampling rate
- Timer interrupt only sets a software flag
- All processing occurs in the main loop
- UART transmission does not block timer operation

This ensures predictable and stable sampling behavior.



## Output Format

- Output is **line-based serial text**
- Each line represents one sampled GPIO value

Example output:

<img width="278" height="225" alt="image" src="https://github.com/user-attachments/assets/e1eb667c-7aee-4c97-8bea-9d50d277e286" />


## Driver Interaction

The application coordinates multiple drivers:

- **GPIO Driver**
  - Reads button and signal inputs

- **Timer Driver**
  - Controls sampling interval
  - Signals sampling events using a flag

- **UART Driver**
  - Sends status messages
  - Transmits sampled values

The application interacts with hardware **only through driver APIs**, without direct register access.


## Edge Case Handling

- Button state is tracked to detect only valid press events
- Button bounce may cause rapid toggling, which is acceptable for this demonstration
- If sampling is disabled, timer events are ignored
- UART transmission delays do not affect sampling timing


## Design Considerations

- Simple control logic improves readability
- Timer-driven sampling ensures consistency
- Line-based output simplifies debugging and verification
- Structure supports easy future extension




