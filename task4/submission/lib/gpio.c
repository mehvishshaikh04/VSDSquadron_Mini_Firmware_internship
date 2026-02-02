#include "gpio.h"
#include "ch32v00x.h"

void gpio_init_pd(uint8_t pin, gpio_mode_t mode)
{
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;

    if (mode == GPIO_INPUT) {
        GPIOD->CFGLR &= ~(0xF << (pin * 4));
        GPIOD->CFGLR |=  (0x8 << (pin * 4));  
        GPIOD->OUTDR |= (1 << pin);            
    } else {
        GPIOD->CFGLR &= ~(0xF << (pin * 4));
        GPIOD->CFGLR |=  (0x3 << (pin * 4));   
    }
}

uint8_t gpio_read_pd(uint8_t pin)
{
    return (GPIOD->INDR >> pin) & 0x1;
}

void gpio_write_pd(uint8_t pin, uint8_t value)
{
    if (value)
        GPIOD->OUTDR |= (1 << pin);
    else
        GPIOD->OUTDR &= ~(1 << pin);
}
