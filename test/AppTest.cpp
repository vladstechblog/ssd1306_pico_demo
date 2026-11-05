extern "C"
{
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "App.h"
#include "Timer.h"
#include "SSD1306.h"
#include "UptimePresenter.h"
#include <stdbool.h>

int fake_return_value = 0xaabb;
uint8_t* fake_data_ptr = (uint8_t*) 0xffeeddcc;

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

int SSD1306_defaultInitialization(void){
  return mock_c()->actualCall("SSD1306_defaultInitialization")
    ->intReturnValue();
}

int SSD1306_setAddressModeToHorizontal(void){
  return mock_c()->actualCall("SSD1306_setAddressModeToHorizontal")
    ->intReturnValue();
}

int SSD1306_clearDisplayMemory(void){
  return mock_c()->actualCall("SSD1306_clearDisplayMemory")
    ->intReturnValue();
}

int SSD1306_sendDataBuffer(data_t* data_to_send, unsigned int data_size){
  return mock_c()->actualCall("SSD1306_sendDataBuffer")
    ->withPointerParameters("data_to_send", data_to_send)
    ->withUnsignedIntParameters("data_size", data_size)
    ->intReturnValue();
}

void UptimePresenter_Create(void){
  mock_c()->actualCall("UptimePresenter_Create");
}

uint8_t* UptimePresenter_GetData(void){
  return (uint8_t*) mock_c()->actualCall("UptimePresenter_GetData")
  ->pointerReturnValue();
}

void UptimePresenter_UpdateUptime(uint16_t timestamp){
  mock_c()->actualCall("UptimePresenter_UpdateUptime")
    ->withUnsignedIntParameters("timestamp", timestamp);
}

void sleep_ms(uint32_t ms){
  mock_c()->actualCall("sleep_ms")
    ->withUnsignedIntParameters("ms", ms);
}

bool AlwaysTrue(void){
  return mock_c()->actualCall("AlwaysTrue")
    ->boolReturnValue();
}



} //end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


void recordDisplayInitializationExpectations(void){
  mock().expectOneCall("SSD1306_Create")
    .withPointerParameter("i2c_address", fake_i2c_address);
  
  mock().expectOneCall("SSD1306_defaultInitialization")
    .andReturnValue(fake_return_value);
  
  mock().expectOneCall("SSD1306_setAddressModeToHorizontal")
    .andReturnValue(fake_return_value);

  mock().expectOneCall("SSD1306_clearDisplayMemory")
    .andReturnValue(fake_return_value);
}

void recordI2CSetupExpectations(void){
  mock().expectOneCall("i2c_init")
    .withPointerParameter("i2c_address", fake_i2c_address)
    .withUnsignedIntParameter("baudrate", BAUDRATE)
    .andReturnValue(BAUDRATE);

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

void record_UptimePresenter_Create_expectation(void){
  mock().expectOneCall("UptimePresenter_Create");
}

void record_UptimePresenter_GetData_expectation(void){
  mock().expectOneCall("UptimePresenter_GetData")
    .andReturnValue(fake_data_ptr);
}

void record_UptimePresenter_UpdateUptime_expecatation(){
  mock().expectOneCall("UptimePresenter_UpdateUptime")
    .withUnsignedIntParameter("timestamp", 1);
}

void record_SSD1306_sendDataBuffer_expectation(data_t* data_to_send, unsigned int data_size){
  mock().expectOneCall("SSD1306_sendDataBuffer")
    .withPointerParameter("data_to_send", data_to_send)
    .withUnsignedIntParameter("data_size", data_size)
    .andReturnValue((int)(data_size * 2));
}

void record_sleep_one_second_expectations(void){
  mock().expectOneCall("sleep_ms")
    .withUnsignedIntParameter("ms", 1000);
}

void record_AlwaysTrue_returs_true(){
  mock().expectOneCall("AlwaysTrue")
    .andReturnValue(true);
}

void record_AlwaysTrue_returs_false(){
  mock().expectOneCall("AlwaysTrue")
    .andReturnValue(false);
}


TEST_GROUP(Display){
  
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
 
  void setup(){}
  
  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }
};

TEST(AppI2CSetup, initializei_default_I2C){
  recordI2CSetupExpectations();
  i2c_setup(fake_i2c_address, BAUDRATE, I2C_SCA_PIN, I2C_CLK_PIN);
}


TEST_GROUP(Integration){

  void setup(){
  }

  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }
};

TEST(Integration, app_main_test){
  recordI2CSetupExpectations();
  recordDisplayInitializationExpectations();
  record_UptimePresenter_Create_expectation();
  record_AlwaysTrue_returs_true();
  record_sleep_one_second_expectations();
  record_UptimePresenter_UpdateUptime_expecatation();
  record_UptimePresenter_GetData_expectation();
  record_SSD1306_sendDataBuffer_expectation(fake_data_ptr, DATA_BUFFER_SIZE);
  record_AlwaysTrue_returs_false();

  app_main();
  LONGS_EQUAL(1, *Timer_GetCounterPointer());
}
