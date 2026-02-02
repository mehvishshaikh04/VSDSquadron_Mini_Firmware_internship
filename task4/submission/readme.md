# Task-4: UART Software Oscilloscope

## Description
This project is done as part of Task-4.  
It reads a GPIO input pin at a fixed time interval and sends the values to a PC using UART.

A push button is used to start and stop the sampling. The output can be seen directly on a serial terminal.



## Drivers Used
- GPIO
- Timer
- UART



## Hardware Connections

| Function      | Pin |
|--------------|-----|
| Push Button  | PD0 |
| GPIO Input   | PD1 |
| UART TX      | PD5 |
| UART RX      | PD6 |
| Ground       | GND |



## How the Project Works
When the button is pressed, sampling starts.  
The timer triggers GPIO reads at regular intervals.  
Each sampled value (0 or 1) is printed on the UART terminal.

Pressing the button again stops the sampling.



## Build and Flash
1. Build the project using the VSDSquadron Mini toolchain
2. Flash the program to the board
3. Connect UART pins to a USB-to-Serial converter



## UART Settings
- Baud rate: 9600  
- Data bits: 8  
- Parity: None  
- Stop bits: 1  



## How to Demo
1. Open a serial terminal with the above settings
2. Press the button to start sampling
3. Observe the GPIO values on the terminal
4. Press the button again to stop sampling
5. Change PD1 connection between GND and 3.3V to see different values
