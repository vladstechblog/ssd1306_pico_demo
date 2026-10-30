#ifndef FAKE_GPIO_H
#define FAKE_GPIO_H


//minimal test implementation needed form Pico SDK's hardware/structs/io_balk0.h
typedef enum gpio_function_t {
    GPIO_FUNC_I2C = 3, ///< Select I2C as GPIO pin function
} gpio_function_t;


void gpio_set_function(uint gpio, gpio_function_t fn);




#endif
