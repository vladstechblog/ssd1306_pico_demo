#include <stdint.h>
#include "ssd1306_font.h"
#include "UptimePresenter.h"


static unsigned char data_buffer[DATA_BUFFER_SIZE] = {0xff};

static void zero_out_data(void){
  for (int buffer_index = 0; buffer_index < DATA_BUFFER_SIZE; buffer_index++){
    data_buffer[buffer_index] = 0;
  }
}

void UptimePresenter_Create(void){
  zero_out_data();
}

void UptimePresenter_Destroy(void){
  zero_out_data();
}

unsigned char* UptimePresenter_GetData(void){
  return data_buffer;
}


static int  get_font_index(char char_to_map){
  int font_index = 0;
  int font_base_offset = 0x40;
  int ascii_number_offset = 0x2F;

  if(char_to_map >= 'A' && char_to_map <= 'Z')
     font_index = char_to_map - font_base_offset;
  
  if(char_to_map >= '0' && char_to_map <= '9')
     font_index = (char_to_map - ascii_number_offset) + ('Z' - font_base_offset);

  return font_index;
}

uint8_t* UptimePresenter_MapAsciiToFont(char char_to_map){
  return font[get_font_index(char_to_map)];
}
