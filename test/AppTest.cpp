extern "C"
{
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "App.h"


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



} //end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(AppI2CSetup){
 
  void recordI2CInitExpectations(void){
    mock().expectOneCall("i2c_init")
      .withPointerParameter("i2c_address", fake_i2c_address)
      .withUnsignedIntParameter("baudrate", fake_baudrate)
      .andReturnValue(fake_baudrate);
  }

  void recordGPIOSetFunctionExpectationsForDataPin(void){
    mock().expectOneCall("gpio_set_function")
      .withUnsignedIntParameter("pin_number", I2C_SCA_PIN)
      .withIntParameter("pin_function", GPIO_FUNC_I2C);
  }

  void recordGPIOSetFunctionExpectationsForClockPin(void){
    mock().expectOneCall("gpio_set_function")
      .withUnsignedIntParameter("pin_number", I2C_CLK_PIN)
      .withIntParameter("pin_function", GPIO_FUNC_I2C);
  }

  void recordGPIOPullUpExpectationsForDataPin(void){
    mock().expectOneCall("gpio_pull_up")
      .withUnsignedIntParameter("pin_number", I2C_SCA_PIN);
  }

  void recordGPIOPullUpExpectationsForClockPin(void){
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
  recordI2CInitExpectations();
  recordGPIOSetFunctionExpectationsForDataPin();
  recordGPIOSetFunctionExpectationsForClockPin();
  recordGPIOPullUpExpectationsForDataPin();
  recordGPIOPullUpExpectationsForClockPin();
  i2c_setup(fake_i2c_address, fake_baudrate, I2C_SCA_PIN, I2C_CLK_PIN);
}


