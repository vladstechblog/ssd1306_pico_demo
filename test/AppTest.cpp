extern "C"
{
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "App.h"
#include <stdbool.h>

uint i2c_init(i2c_inst_t* i2c_address, uint baudrate){
  return mock_c()->actualCall("i2c_init")
    ->withPointerParameters("i2c_address", i2c_address)
    ->withUnsignedIntParameters("baudrate", baudrate)
    ->unsignedIntReturnValue();
}

void gpio_set_function(uint pin_number, gpio_function_t function){
  mock_c()->actualCall("gpio_set_function")
    ->withUnsignedIntParameters("pin_number", pin_number)
    ->withIntParameters("pin_function", function);
}

void gpio_pull_up(uint pin_number){
  mock_c()->actualCall("gpio_pull_up")
    ->withUnsignedIntParameters("pin_number", pin_number);
}

void SSD1306_Create(i2c_inst_t* i2c_address){
  mock_c()->actualCall("SSD1306_Create")
    ->withPointerParameters("i2c_address", i2c_address);
}


void SSD1306_defaultInitialization(void){
  mock_c()->actualCall("SSD1306_defaultInitialization");
}


void SSD1306_setAddressModeToHorizontal(void){
  mock_c()->actualCall("SSD1306_setAddressModeToHorizontal");
}

void SSD1306_clearDisplayMemory(void){
  mock_c()->actualCall("SSD1306_clearDisplayMemory");
}



} //end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(Display){
  
  void recordDisplayInitializationExpectations(void){
    mock().expectOneCall("SSD1306_Create")
      .withPointerParameter("i2c_address", fake_i2c_address);
    mock().expectOneCall("SSD1306_defaultInitialization");
    mock().expectOneCall("SSD1306_setAddressModeToHorizontal");
    mock().expectOneCall("SSD1306_clearDisplayMemory");
  }


  void setup(){}
  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }
};


TEST(Display, DisplayInitialization){
  recordDisplayInitializationExpectations();
  initialize_display(fake_i2c_address);
}

TEST_GROUP(AppI2CSetup){
 
  void recordI2CSetupExpectations(void){
    mock().expectOneCall("i2c_init")
      .withPointerParameter("i2c_address", fake_i2c_address)
      .withUnsignedIntParameter("baudrate", fake_baudrate)
      .andReturnValue(fake_baudrate);

    mock().expectOneCall("gpio_set_function")
      .withUnsignedIntParameter("pin_number", I2C_SCA_PIN)
      .withIntParameter("pin_function", GPIO_FUNC_I2C);

    mock().expectOneCall("gpio_set_function")
      .withUnsignedIntParameter("pin_number", I2C_CLK_PIN)
      .withIntParameter("pin_function", GPIO_FUNC_I2C);

    mock().expectOneCall("gpio_pull_up")
      .withUnsignedIntParameter("pin_number", I2C_SCA_PIN);

    mock().expectOneCall("gpio_pull_up")
      .withUnsignedIntParameter("pin_number", I2C_CLK_PIN);
  }

  void setup(){
    //TODO
  }

  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }

};


TEST(AppI2CSetup, initializei_default_I2C){
  recordI2CSetupExpectations();
  i2c_setup(fake_i2c_address, fake_baudrate, I2C_SCA_PIN, I2C_CLK_PIN);
}
