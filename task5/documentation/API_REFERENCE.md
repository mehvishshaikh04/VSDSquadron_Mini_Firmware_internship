# API Reference


## GPIO Driver

### void gpio_init_pd(uint8_t pin, gpio_mode_t mode)
- Configures a GPIOD pin as input or output.

Parameters:
- pin – GPIOD pin number
- mode – GPIO_INPUT or GPIO_OUTPUT

Return Value:
- None

Example:
```c
gpio_init_pd(0, GPIO_INPUT);
uint8_t gpio_read_pd(uint8_t pin)

Reads the state of a GPIOD pin.

Return Value:
1 if HIGH
0 if LOW
```


## UART Driver

### void uart_init(uint32_t baud)
- Initializes USART1 with the specified baud rate.
 
### void uart_send_char(char c)
- Transmits a single character over UART.

### void uart_send_string(const char *str)
- Transmits a null-terminated string over UART.
  


## Timer Driver  

### void timer_init(uint16_t period_ms)
- Configures Timer2 to generate periodic interrupts.
  
### extern volatile uint8_t timer_flag
- Flag set by Timer2 interrupt to indicate a sampling event.



