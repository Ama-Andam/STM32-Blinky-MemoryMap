#include "main.h"


void delay(volatile uint32_t count) {
    while (count--) {
        __asm("nop"); // No Operation
    }
}

void gpio_init(void) {
    // Enable clock for GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Set PA0 as output
    LED_PORT->MODER &= ~(3UL << (2 * LED_PIN)); // Clear all the bits currently there
    LED_PORT->MODER |=  (1UL << (2 * LED_PIN)); // Set to 01 for Output

    // Optional: Set output type, speed, and pull-up/down
    GPIOA->OTYPER &= ~(1 << 0);        // Push-pull
    GPIOA->OSPEEDR |=  (3UL << (2 * 0)); // High speed
    GPIOA->PUPDR &= ~(3UL << (2 * 0));   // No pull-up, pull-down
}

int main(void) {
    gpio_init();

    while (1) {
        LED_PORT->ODR ^= (1 << LED_PIN);
        delay(1000000);
    }
}
