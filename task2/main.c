#include "ch32v00x.h"
#include "gpio.h"
#include "uart.h"

void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 8000; i++)
    {
        __asm volatile ("nop");
    }
}

int main(void)
{
    gpio_init();
    uart_init();

    uart_print("VSDSquadron Task-2\r\n");
    uart_print("UART Validation\r\n");

    while (1)
    {
        gpio_set();
        uart_print("UART working, LED HIGH\r\n");
        delay_ms(500);

        gpio_clear();
        uart_print("UART working, LED LOW\r\n");
        delay_ms(500);
    }
}
