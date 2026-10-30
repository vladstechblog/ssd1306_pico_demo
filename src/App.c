#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "App.h"

void i2c_setup(i2c_inst_t* i2c_address, uint baudrate, uint data_pin, uint clock_pin){
  i2c_init(i2c_address, baudrate);
  gpio_set_function(data_pin, GPIO_FUNC_I2C);
  gpio_set_function(clock_pin, GPIO_FUNC_I2C);
  gpio_pull_up(data_pin);
  gpio_pull_up(clock_pin);
}

void app_main(void){
   
}
