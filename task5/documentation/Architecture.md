# System Architecture

## Overview
This project follows a layered embedded firmware architecture where hardware-specific drivers are separated from application logic. A timer-driven event mechanism is used to ensure deterministic sampling of a GPIO input and transmission of data over UART.
The architecture is designed to be simple, modular, and reusable.

## High-Level Block Diagram
<img width="530" height="195" alt="image" src="https://github.com/user-attachments/assets/39af7202-dd34-407b-ac60-449c6f00b286" />


## Layered Architecture

### 1. Driver Layer
Located in the `lib/` directory.

The driver layer is responsible for all direct hardware interactions.

- **GPIO Driver**
  - Configures the GPIO pin connected to the push button
  - Reads the digital state of the button (pressed or released)

- **Timer Driver**
  - Configures a hardware timer
  - Generates periodic interrupts used to control sampling timing

- **UART Driver**
  - Initializes UART peripheral
  - Transmits text data to a PC serial terminal

Each driver exposes a clean API and hides hardware register details from the application.

### 2. Application Layer
Located in `app/main.c`.

The application layer:
- Controls program flow
- Coordinates driver usage
- Processes sampled data
- Formats output for UART transmission

The application does **not** directly access hardware registers and interacts only through driver APIs.


## Control Flow (Timing Behavior)

1. The timer is configured to generate periodic interrupts.
2. Each timer interrupt sets a software flag indicating that a new sample is required.
3. The main loop continuously checks this flag.
4. When the flag is detected:
   - The flag is cleared
   - The GPIO button state is read
   - The sampled value is prepared for transmission
   - The value is sent over UART
This design ensures predictable and deterministic sampling behavior.

## Data Flow
<img width="364" height="305" alt="image" src="https://github.com/user-attachments/assets/72689fc6-e6fa-47ff-8de3-d4c2dd1049d6" />

Each sampled GPIO value is transmitted as a human-readable text value on a new line.


## Design Rationale

- **Separation of Concerns**
  - Hardware access is isolated in drivers
  - Application logic remains clean and readable

- **Deterministic Sampling**
  - Timer-controlled sampling ensures consistent behavior

- **Simplicity**
  - Line-based UART output is easy to verify and debug
  - Suitable for learning and demonstration purposes

- **Reusability**
  - Drivers can be reused in future projects
  - Application logic can be extended without modifying drivers


## Architectural Benefits

- Easy to understand for new engineers
- Matches industry-standard embedded firmware structure
- Documentation accurately reflects implemented behavior
- Fully compliant with Task-5 documentation requirements


