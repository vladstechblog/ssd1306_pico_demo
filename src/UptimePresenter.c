#include "UptimePresenter.h"


static unsigned char data_buffer[DATA_BUFFER_SIZE] = {0xff};


void UptimePresenter_Create(void){

}

void UptimePresenter_Destroy(void){

}

unsigned char* UptimePresenter_GetData(void){
  return data_buffer;
}
