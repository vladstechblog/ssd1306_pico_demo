extern "C"
{
#include "UptimePresenter.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(UptimePresenter)
{
    void setup(){
      UptimePresenter_Create();
    }

    void teardown(){
       UptimePresenter_Destroy();
    }
};

TEST(UptimePresenter, Create){
  FAIL("Start here");
}

