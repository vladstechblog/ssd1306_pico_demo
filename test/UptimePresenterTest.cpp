extern "C"
{
#include "UptimePresenter.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(UptimePresenter)
{
    void setup(){
    }

    void teardown(){
    }
};

TEST(UptimePresenter, GetData){
  unsigned char* data = UptimePresenter_GetData();
  BYTES_EQUAL(0xff, data[0]);
}


