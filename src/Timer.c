#include "Timer.h"

static int* counter_ptr = NULL;

void Timer_Create(int* counter){
  counter_ptr = counter;
}

void Timer_Destroy(void){
}


int* Timer_GetCounterPointer(void){
  return counter_ptr;
}
