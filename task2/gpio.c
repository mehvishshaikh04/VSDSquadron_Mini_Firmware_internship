#include "ch32v00x.h"
#include "gpio.h"

void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_6;          
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOD, &gpio);
}

void gpio_set(void)
{
    GPIO_SetBits(GPIOD, GPIO_Pin_6);
}

void gpio_clear(void)
{
    GPIO_ResetBits(GPIOD, GPIO_Pin_6);
}
