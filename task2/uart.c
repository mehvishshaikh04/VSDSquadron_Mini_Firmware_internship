#include "ch32v00x.h"
#include "uart.h"

static void uart_send_char(char c)
{
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    USART_SendData(USART1, c);
}

void uart_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD |
                           RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef gpio;

    gpio.GPIO_Pin = GPIO_Pin_5;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    USART_InitTypeDef uart;
    uart.USART_BaudRate = 9600;
    uart.USART_WordLength = USART_WordLength_8b;
    uart.USART_StopBits = USART_StopBits_1;
    uart.USART_Parity = USART_Parity_No;
    uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    uart.USART_Mode = USART_Mode_Tx;

    USART_Init(USART1, &uart);
    USART_Cmd(USART1, ENABLE);
}

void uart_print(const char *msg)
{
    while (*msg)
    {
        uart_send_char(*msg++);
    }
}
