#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void timer_init(uint16_t period_ms);
extern volatile uint8_t timer_flag;

#endif
