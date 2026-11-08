extern "C"
{

#include "CppUTestExt/MockSupport_c.h"
#include "Timer.h"

void sleep_ms(uint32_t ms){
  mock_c()->actualCall("sleep_ms")
    ->withUnsignedIntParameters("ms", 1000);
}

} // end of extern "C"

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(Timer)
{
    int counter = 1234;
    void setup(){   
      Timer_Create(&counter);
    }

    void teardown(){
    }
};

TEST(Timer, CreateSetsCorrectPointerAddress){
  POINTERS_EQUAL(&counter, Timer_GetCounterPointer());
}

TEST(Timer, DestroySetsCounterPointerToNULL){
  Timer_Destroy();
  POINTERS_EQUAL(NULL, Timer_GetCounterPointer());
}

TEST(Timer, CreatSetsCounterToZero){
  int* actual = Timer_GetCounterPointer(); 
  LONGS_EQUAL(0, *actual);
}


TEST_GROUP(Tick){ 
  
  void recordSleepMsExpectations(){
    mock().expectOneCall("sleep_ms")
      .withUnsignedIntParameter("ms", 1000);
  }

  int counter;

  void setup(){
    Timer_Create(&counter);
    recordSleepMsExpectations();
  }

  void teardown(){
    mock().checkExpectations();
    mock().clear();
    Timer_Destroy();
  }
};

TEST(Tick, CallingTickIncrementsCounterByOne){
  Timer_Tick();
  LONGS_EQUAL(1, *(Timer_GetCounterPointer()));
}

TEST(Tick, AnotherTickIncrementTest){
  counter = 99;
  Timer_Tick();
  LONGS_EQUAL(100, *(Timer_GetCounterPointer()));
}

TEST(Tick, HandlesMaxSecondsCorrecly){
  counter = 5999;
  Timer_Tick();
  LONGS_EQUAL(0, *(Timer_GetCounterPointer()));
}