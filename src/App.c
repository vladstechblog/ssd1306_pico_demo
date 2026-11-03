#include <stdbool.h>
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "Util.h"
#include "UptimePresenter.h"
#include "Timer.h"
#include "App.h"
#include "SSD1306.h"


void i2c_setup(i2c_inst_t* i2c_address, uint baudrate, uint data_pin, uint clock_pin){
  i2c_init(i2c_address, baudrate);
  gpio_set_function(data_pin, GPIO_FUNC_I2C);
  gpio_set_function(clock_pin, GPIO_FUNC_I2C);
  gpio_pull_up(data_pin);
  gpio_pull_up(clock_pin);
}


void initialize_display(i2c_inst_t* i2c_address){
  SSD1306_Create(i2c_address);
  SSD1306_defaultInitialization();
  SSD1306_setAddressModeToHorizontal();
  SSD1306_clearDisplayMemory();
}

void app_main(void){
  int counter = 0;
  
  i2c_setup(i2c_default, BAUDRATE, I2C_SCA_PIN, I2C_CLK_PIN);
  initialize_display(i2c_default);
  UptimePresenter_Create();
  Timer_Create(&counter);
 
  while(AlwaysTrue()){
    Timer_Tick();
    UptimePresenter_UpdateUptime(counter);
  }
}
