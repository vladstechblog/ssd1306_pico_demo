extern "C"
{
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/i2c.h"
#include "App.h"


uint i2c_init(i2c_inst_t* i2c_address, uint baudrate){
  return mock_c()->actualCall("i2c_init")
    ->withPointerParameters("i2c_address", i2c_address)
    ->withUnsignedIntParameters("baudrate", baudrate)
    ->unsignedIntReturnValue();
}

} //end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(App){
 

  void setup(){
    //TODO
  }

  void teardown(){
    mock().checkExpectations();
    mock().clear();
  }
};


TEST(App, initializei_default_I2C){
  mock().expectOneCall("i2c_init")
    .withPointerParameter("i2c_address", fake_i2c_address)
    .withUnsignedIntParameter("baudrate", fake_baudrate)
    .andReturnValue(fake_baudrate);

  i2c_setup(fake_i2c_address, fake_baudrate, I2C_SCA_PIN, I2C_CLK_PIN);
}
