#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT
} gpio_mode_t;

void gpio_init_pd(uint8_t pin, gpio_mode_t mode);
uint8_t gpio_read_pd(uint8_t pin);
void gpio_write_pd(uint8_t pin, uint8_t value);

#endif
