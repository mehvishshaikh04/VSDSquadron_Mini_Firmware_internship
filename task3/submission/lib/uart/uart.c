#include "uart.h"
#include "ch32v00x.h"

void uart_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_5; // TX only
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    USART_InitTypeDef uart;
    uart.USART_BaudRate = 115200;
    uart.USART_WordLength = USART_WordLength_8b;
    uart.USART_StopBits = USART_StopBits_1;
    uart.USART_Parity = USART_Parity_No;
    uart.USART_Mode = USART_Mode_Tx;
    uart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

    USART_Init(USART1, &uart);
    USART_Cmd(USART1, ENABLE);
}

void uart_print(const char *s)
{
    while (*s)
    {
        USART_SendData(USART1, *s++);
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    }
}

void uart_print_num(unsigned long n)
{
    char buf[12];
    int i = 10;
    buf[11] = 0;

    if (n == 0) { uart_print("0"); return; }

    while (n && i >= 0)
    {
        buf[i--] = (n % 10) + '0';
        n /= 10;
    }
    uart_print(&buf[i+1]);
}
