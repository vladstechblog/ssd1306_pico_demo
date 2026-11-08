#ifndef FAKE_GPIO_H
#define FAKE_GPIO_H

//minimal test implementation needed from Pico SDK's hardware/structs/io_bank0.h
typedef enum gpio_function_t {
    GPIO_FUNC_I2C = 3, ///< Select I2C as GPIO pin function
} gpio_function_t;

void gpio_set_function(uint gpio, gpio_function_t fn);
void gpio_pull_up(uint gpio);

#endif /* FAKE_GPIO_H */