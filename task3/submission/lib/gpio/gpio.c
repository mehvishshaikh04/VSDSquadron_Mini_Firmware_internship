#include "gpio.h"
#include "ch32v00x.h"

#define LED_PIN GPIO_Pin_6

void gpio_set(void)   { GPIO_ResetBits(GPIOD, LED_PIN); } // LED ON (active-low)
void gpio_clear(void) { GPIO_SetBits(GPIOD, LED_PIN); }   // LED OFF

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = LED_PIN;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    gpio_clear(); // ensure LED OFF at startup
}