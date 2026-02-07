# Demo Guide

## Objective
This document describes how to run, test, and verify the UART-based GPIO sampling application on the VSDSquadron Mini board.

The demo demonstrates button-controlled start/stop sampling of a digital GPIO input, with sampled values transmitted over UART as line-based serial output.


## Hardware Setup

### Required Components
- VSDSquadron Mini board
- Push button
- Jumper wires
- USB cable for UART connection

### Pin Connections
- **PD0** → Push button (START / STOP control)
- **PD1** → Digital signal input
- Push button other terminal → GND
- UART → PC via USB

Internal pull-up resistors for GPIO inputs are enabled in software.


## Flashing the Firmware

1. Open the project in VS Code using PlatformIO
2. Build the project  
   `Ctrl + Alt + B`
3. Upload the firmware to the board  
   `Ctrl + Alt + U`
4. Confirm that flashing completes successfully without errors



## UART Configuration

Open a serial terminal with the following settings:

- **Baud Rate:** 9600
- **Data Bits:** 8
- **Parity:** None
- **Stop Bits:** 1
- **Flow Control:** None



## Running the Demo

1. Power on or reset the board
2. Open the UART serial monitor
3. Observe the startup messages:
```
Smart Oscilloscope Ready
Press button to START / STOP
```

4. Press the push button connected to **PD0**
5. Observe the message:
```
Sampling STARTED
```

6. GPIO input values from **PD1** will now be printed periodically as `0` or `1`
7. Press the push button again to stop sampling
8. Observe the message



## Expected Output

Example UART output during operation:
```
Sampling STARTED
1
1
0
1
Sampling STOPPED
```



## Output Interpretation

- `1` → GPIO input (PD1) is HIGH
- `0` → GPIO input (PD1) is LOW
- Each line represents one sampled GPIO value
- Output is generated only while sampling is enabled



## Verification Checklist

- UART startup messages appear correctly
- Button press toggles sampling state
- Data is printed only when sampling is active
- Sampling stops immediately when disabled
- Output values correctly reflect the signal applied to PD1



## Troubleshooting

- **No UART output:**  
  Verify the baud rate and correct COM port selection

- **Sampling does not start:**  
  Check push button wiring and PD0 connection

- **Incorrect GPIO values:**  
  Verify signal wiring on PD1



## Demo Completion Criteria

The demo is considered successful when:

- Sampling can be started and stopped using the push button
- GPIO values are streamed correctly over UART
- Output behavior matches the expected functionality




   







  

   

   


