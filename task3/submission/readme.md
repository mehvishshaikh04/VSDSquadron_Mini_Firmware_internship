# VSDSquadron Mini Task-3
## Peripheral Driver Library Demo

### Objective:
This Task-3 project demonstrates how to build reusable firmware libraries for the VSDSquadron Mini RISC-V board. We implemented GPIO and UART libraries and created an application that uses them to blink the on-board LED and log its state over UART.


### Libraries Implemented:
**GPIO Library**  
Provides functions to control the LED:
- `gpio_init()` → sets up the LED pin  
- `gpio_set()` → turns the LED ON  
- `gpio_clear()` → turns the LED OFF  

**UART Library**  
Provides functions to send messages to the PC:
- `uart_init()` → initializes UART1  
- `uart_print()` → prints strings  
- `uart_print_num()` → prints numbers  

### Demo Application:
The application blinks the LED on PD6 in a simple pattern:
- 3 blinks with 0.5 s interval  
- 3 blinks with 1 s interval  
- 3 blinks with 2 s interval  

Each blink is logged over UART showing the phase number and LED state. The pattern repeats indefinitely, demonstrating how the libraries can be used in a real application.

### To run this demo on the VSDSquadron Mini:
1. Open the project in **VSCode with PlatformIO**.
2. Connect the board to your PC via USB.
3. Build the firmware by selecting `pio run`.
4. Upload the firmware to the board with `pio run -t upload`.
5. Open the Serial Monitor at 115200 baud to view the LED and UART logs.
