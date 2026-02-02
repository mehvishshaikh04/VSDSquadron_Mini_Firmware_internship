#include <stdint.h>
#include "gpio.h"
#include "uart.h"
#include "timer.h"

#define BUTTON_PIN   0  
#define SIGNAL_PIN   1  

uint8_t sampling_enabled = 0;
uint8_t last_button_state = 1;

int main(void)
{
    uart_init(9600);

    gpio_init_pd(BUTTON_PIN, GPIO_INPUT);
    gpio_init_pd(SIGNAL_PIN, GPIO_INPUT);

    timer_init(500);  

    uart_send_string("\r\nSmart Oscilloscope Ready\r\n");
    uart_send_string("Press button to START / STOP\r\n");

    while (1)
    {
      
        uint8_t button_state = gpio_read_pd(BUTTON_PIN);
        if (button_state == 0 && last_button_state == 1) {
            sampling_enabled ^= 1;

            if (sampling_enabled)
                uart_send_string("Sampling STARTED\r\n");
            else
                uart_send_string("Sampling STOPPED\r\n");
        }
        last_button_state = button_state;

        
        if (timer_flag) {
            timer_flag = 0;

            if (sampling_enabled) {
                static uint8_t led_state = 0;
                led_state ^= 1;
 

                uint8_t val = gpio_read_pd(SIGNAL_PIN);
                uart_send_char(val ? '1' : '0');
                uart_send_string("\r\n");
            }
        }
    }
}
