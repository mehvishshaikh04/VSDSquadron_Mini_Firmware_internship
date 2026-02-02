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
task4/
└── submission/
├── lib/
│ ├── gpio.c / gpio.h
│ ├── uart.c / uart.h
│ └── timer.c / timer.h
├── app/
│ └── main.c
├── README.md
├── evidence/
│ ├── evidence.md
│ ├── task4_evidence_video.mp4
│ └── task4_monitor_output.png


## Quick Start
1. Open PlatformIO in VSCode
2. Build: `Ctrl+Alt+B`
3. Upload: `Ctrl+Alt+U`
4. Open Serial Monitor at 9600 baud
5. Press/release the button to observe monitor output
