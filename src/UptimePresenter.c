#include "UptimePresenter.h"


static unsigned char data_buffer[DATA_BUFFER_SIZE] = {0xff};

static void zero_out_data(void){
  for (int buffer_index = 0; buffer_index < DATA_BUFFER_SIZE; buffer_index++){
    data_buffer[buffer_index] = 0;
  }
}

void UptimePresenter_Create(void){

}

void UptimePresenter_Destroy(void){
  zero_out_data();
}

unsigned char* UptimePresenter_GetData(void){
  return data_buffer;
}
