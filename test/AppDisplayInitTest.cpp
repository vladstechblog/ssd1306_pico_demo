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



} //end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


TEST_GROUP(Display){
  void setup(){}
  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }
};


TEST(Display, DisplayInitialization){
  mock().expectOneCall("SSD1306_Create")
    .withPointerParameter("i2c_address", fake_i2c_address);

  mock().expectOneCall("SSD1306_defaultInitialization");

  initialize_display(fake_i2c_address);
}

