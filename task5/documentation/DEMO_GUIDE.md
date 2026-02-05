# Demo Guide

## Objective
This guide explains how to run, test, and verify the UART Software Oscilloscope application on the VSDSquadron Mini board.

The demo demonstrates start/stop controlled GPIO sampling with line-based UART output.


## Hardware Setup

### Required Components
- VSDSquadron Mini board
- Push button
- Jumper wires

### Connections
- **PD0** → Push button (START / STOP control)
- **PD1** → Signal input (can be connected to a button or logic source)
- Push button other terminal → GND
- UART connected to PC via USB

Internal pull-up resistors are enabled in software.


## Flashing the Firmware

1. Open the project in **VS Code with PlatformIO**
2. Build the project:  Ctrl + Alt + B
3. Upload the firmware:  Ctrl + Alt + U
4. Ensure flashing completes successfully


## UART Configuration

Open a serial monitor with the following settings:

- **Baud Rate:** 9600
- **Data Bits:** 8
- **Parity:** None
- **Stop Bits:** 1
- **Flow Control:** None


## Running the Demo

1. Reset or power the board
2. Open the UART serial monitor
3. Observe the startup messages:
   
   <img width="360" height="80" alt="image" src="https://github.com/user-attachments/assets/23160736-130b-4f3f-a81d-0d2e575df4d2" />

4. Press the push button connected to PD0
5. Observe the message:

   <img width="338" height="47" alt="image" src="https://github.com/user-attachments/assets/31636fc4-e80f-4542-90f0-dbcb972e1171" />

6. GPIO signal values (`0` or `1`) will now be printed periodically
7. Press the button again to stop sampling
8. Observe:

  <img width="238" height="39" alt="image" src="https://github.com/user-attachments/assets/82fdfdc1-71d8-4e36-8870-99524c2aa035" />

## Expected Output

Example UART output:

<img width="345" height="293" alt="image" src="https://github.com/user-attachments/assets/853174ac-71cb-4951-943d-ca0691402d07" />

### Output Meaning
- `1` → GPIO input is HIGH
- `0` → GPIO input is LOW
- Each line corresponds to one sampled value


## Verification Checklist

- UART messages appear correctly
- Button press toggles sampling state
- Data is printed only when sampling is active
- Sampling stops immediately when disabled
- Output values match the signal input state


## Troubleshooting

- **No UART output:** Check baud rate and COM port
- **Sampling not starting:** Verify PD0 wiring and button connection
- **Incorrect values:** Verify signal input wiring on PD1


## Demo Completion Criteria

The demo is considered successful when:
- Sampling can be started and stopped using the button
- GPIO values are streamed correctly over UART
- Output matches expected behavior


  

   

   


