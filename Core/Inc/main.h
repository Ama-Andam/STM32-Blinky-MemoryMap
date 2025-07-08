#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx.h"

// Define LED pin (PA5)
#define LED_PIN 5
#define LED_PORT GPIOA


// Functions
void delay(volatile uint32_t count);
void gpio_init(void);

#endif /* __MAIN_H */
