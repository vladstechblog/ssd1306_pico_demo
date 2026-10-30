#include "hardware/i2c.h"
#include "App.h"


void i2c_setup(i2c_inst_t* i2c_address, uint baudrate, uint clock_pin, uint data_pin){
  i2c_init(i2c_address, baudrate);
}

void app_main(void){
   
}
