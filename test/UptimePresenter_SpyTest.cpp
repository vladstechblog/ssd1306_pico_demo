extern "C"
{
#include "UptimePresenter_Spy.h"
} // end of extern "C"

#include "CppUTest/TestHarness.h"

TEST_GROUP(CreateDestroy){};

TEST(CreateDestroy, CreateZeroesOutTimestamp){
  UptimePresenter_Spy_Create();
  LONGS_EQUAL(0, UptimePresenter_Spy_GetTimeStamp());
}

TEST(CreateDestroy, DestroyZeroesOutTimestamp){
  UptimePresenter_Spy_Destroy();
  LONGS_EQUAL(0, UptimePresenter_Spy_GetTimeStamp());
}


TEST_GROUP(Spy){

  void setup(){
    UptimePresenter_Spy_Create();
  }

  void teardown(){
    UptimePresenter_Spy_Destroy();
  }
};

TEST(Spy, UpdateUptimeUpdatesTimestamp){
  uint16_t expected = 1234;
  UptimePresenter_UpdateUptime(expected);
  LONGS_EQUAL(expected, UptimePresenter_Spy_GetTimeStamp());
}