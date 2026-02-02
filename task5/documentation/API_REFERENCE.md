# API Reference

This document provides a complete reference for all drivers used in the UART Software Oscilloscope project.

---

## GPIO Driver
```c
`void GPIO_Init(void)`
-Purpose:Initialize PA0 as digital input with internal pull-up.  
-Parameters: None  
-Return Value:None  
- Example:
uint8_t GPIO_ReadButton(void)
Purpose: Read the current state of the push-button.
Parameters: None
Return Value:
1 if button is released
0 if button is pressed

Example:
uint8_t state = GPIO_ReadButton();
```

## UART Driver
```c
void UART_Init(uint32_t baud)
Purpose: Initialize UART peripheral with the specified baud rate.
Parameters: baud – UART baud rate (e.g., 9600)
Return Value: None
Example:
UART_Init(9600);

void UART_SendChar(char c)
Purpose: Transmit a single character over UART.
Parameters: c – Character to send
Return Value: None
Example:
UART_SendChar('A');

void UART_SendString(const char* str)

Purpose: Transmit a null-terminated string over UART.

Parameters: str – Pointer to the string

Return Value: None

Example:

UART_SendString("Hello, World!\n");

char UART_ReceiveChar(void)

Purpose: Receive a single character from UART (blocking).

Parameters: None

Return Value: Character received

Example:

char c = UART_ReceiveChar();
uint8_t UART_DataAvailable(void)

Purpose: Check if data is available to read from UART.

Parameters: None

Return Value: 1 if data available, 0 if no data

Example:

if (UART_DataAvailable()) {
    char c = UART_ReceiveChar();
```
## Timer Driver
```c
void Timer_Init(uint16_t ms)

Purpose: Configure a periodic timer interrupt every ms milliseconds.

Parameters: ms – Timer period in milliseconds

Return Value: None

Example:

Timer_Init(1);

void Timer_Start(void)

Purpose: Start the configured timer.

Parameters: None

Return Value: None

Example:

Timer_Start();

void Timer_Stop(void)

Purpose: Stop the timer and disable interrupts.

Parameters: None

Return Value: None

Example:

Timer_Stop();

void Timer_SetCallback(void (*callback)(void))

Purpose: Register a callback function to be called on each timer interrupt.

Parameters: callback – Pointer to function with void return and no parameters

Return Value: None

Example:

void SampleHandler(void) {
    // Read GPIO or update flag
}

Timer_SetCallback(SampleHandler);
```




