# UART Software Oscilloscope

## Summary
This project implements a software-based oscilloscope using a push-button as the digital input. 
The MCU samples the button state at fixed intervals (1 ms) and streams the data over UART to a PC terminal in CSV format for waveform visualization.

## Target Hardware
- VSDSquadron Mini Board
- Push-button connected to GPIO PA0

## Supported Drivers
- GPIO (digital input)
- Timer (periodic interrupts for sampling)
- UART (serial data output)

## Folder Structure
<img width="422" height="444" alt="image" src="https://github.com/user-attachments/assets/908018c6-c22c-499f-a453-e545b748051c" />



## Quick Start
1. Open PlatformIO in VSCode
2. Build: `Ctrl+Alt+B`
3. Upload: `Ctrl+Alt+U`
4. Open Serial Monitor at 9600 baud
5. Connect PD1 wire to ground to get 0(low) as input and Leave PD1 jumper free to get 1(high) as input 
6. Press the button to observe monitor output
