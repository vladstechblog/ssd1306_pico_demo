#include "Timer.h"
#include "pico/time.h"

static int* counter_ptr = NULL;

void Timer_Create(int* counter){
  counter_ptr = counter;
  *counter_ptr = 0;
}

void Timer_Destroy(void){
  counter_ptr = NULL;
}


int* Timer_GetCounterPointer(void){
  return counter_ptr;
}

void Timer_Tick(void){
  (*counter_ptr)++; 
  sleep_ms(1000);
}
