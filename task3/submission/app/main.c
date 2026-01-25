#include "ch32v00x.h"
#include "gpio.h"
#include "uart.h"

void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 8000; i++)
        __asm volatile("nop");
}

int main(void)
{
    gpio_init();
    uart_init();

    uart_print("Task-3 LED Pattern Started\r\n");

    uint32_t blink_intervals[] = {500, 1000, 2000};

    while(1)
    {
        for(int phase = 0; phase < 3; phase++)
        {
            uart_print("Phase ");
            uart_print_num(phase + 1);
            uart_print(" - Interval: ");
            uart_print_num(blink_intervals[phase]);
            uart_print(" ms\r\n");

            for(int blink = 0; blink < 3; blink++)
            {
                gpio_set();               
                uart_print("LED_OFF\r\n");
                delay_ms(500);

                gpio_clear();             
                uart_print("LED_ON\r\n");

                delay_ms(blink_intervals[phase]);
            }
        }
    }
}
