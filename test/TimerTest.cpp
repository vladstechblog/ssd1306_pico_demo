extern "C"
{

#include "Timer.h"

}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Timer)
{
    int counter = 1234;
    void setup(){   
    }

    void teardown(){
    }
};

TEST(Timer, CreateSetsCorrectPointerAddress){
  Timer_Create(&counter);
  POINTERS_EQUAL(&counter, Timer_GetCounterPointer());
}

TEST(Timer, DestroySetsPointerToNull){

}

