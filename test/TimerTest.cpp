extern "C"
{

#include "Timer.h"

}

#include "CppUTest/TestHarness.h"

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


