#include "uart.h"
#include "ch32v00x.h"

void uart_init(uint32_t baud)
{
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1;

    GPIOD->CFGLR &= ~((0xF << (5 * 4)) | (0xF << (6 * 4)));
    GPIOD->CFGLR |=  (0xB << (5 * 4));   // PD5 TX
    GPIOD->CFGLR |=  (0x4 << (6 * 4));   // PD6 RX

    USART1->BRR = SystemCoreClock / baud;
    USART1->CTLR1 |= USART_CTLR1_TE | USART_CTLR1_UE;
}

void uart_send_char(char c)
{
    while (!(USART1->STATR & USART_STATR_TXE));
    USART1->DATAR = c;
}

void uart_send_string(const char *str)
{
    while (*str) uart_send_char(*str++);
}
