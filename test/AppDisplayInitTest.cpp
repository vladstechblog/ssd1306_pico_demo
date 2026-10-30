extern "C"
{
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "App.h"
#include <stdbool.h>

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

