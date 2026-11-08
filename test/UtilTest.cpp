extern "C"
{

  #include "Util.h"

} // end of extern "C"

#include "CppUTest/TestHarness_c.h"

TEST_GROUP(Util){};

TEST(Util, Create){
  CHECK_EQUAL_C_BOOL(true, AlwaysTrue());
}