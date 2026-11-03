extern "C"
{
#include "UptimePresenter_Spy.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(UptimePresenter_Spy_CreateDestroy)
{
    void setup(){
    }

    void teardown(){
    }
};

TEST(UptimePresenter_Spy_CreateDestroy, CreateZeroesOutTimestamp){
  UptimePresenter_Spy_Create();
  LONGS_EQUAL(0, UptimePresenter_Spy_GetTimeStamp());
}

TEST(UptimePresenter_Spy_CreateDestroy, DestroyZeroesOutTimestamp){
  UptimePresenter_Spy_Destroy();
  LONGS_EQUAL(0, UptimePresenter_Spy_GetTimeStamp());
}
