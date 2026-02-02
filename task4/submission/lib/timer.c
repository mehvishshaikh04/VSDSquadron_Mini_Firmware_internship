#include "timer.h"
#include "ch32v00x.h"

volatile uint8_t timer_flag = 0;

void timer_init(uint16_t period_ms)
{
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;

    TIM2->PSC   = 24000 - 1;      
    TIM2->ATRLR = period_ms - 1;  
    TIM2->DMAINTENR |= TIM_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CTLR1 |= TIM_CEN;
}

void TIM2_IRQHandler(void) __attribute__((interrupt));
void TIM2_IRQHandler(void)
{
    if (TIM2->INTFR & TIM_UIF) {
        TIM2->INTFR &= ~TIM_UIF;
        timer_flag = 1;
    }
}

