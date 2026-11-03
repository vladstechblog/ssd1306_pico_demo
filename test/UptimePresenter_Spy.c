#include <stdint.h>
#include "UptimePresenter_Spy.h"



static uint16_t timestmap = 0xffff;

void UptimePresenter_Spy_Create(void){
  timestmap = 0;
}

void UptimePresenter_Spy_Destroy(void){
  timestmap = 0;
}




uint16_t UptimePresenter_Spy_GetTimeStamp(void){
  return timestmap;
}
