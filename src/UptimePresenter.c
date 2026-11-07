#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "ssd1306_font.h"
#include "UptimePresenter.h"


static unsigned char ssd1306_display_data[DATA_BUFFER_SIZE] = {0xff};

static void zero_out_data(void){
  for (int buffer_index = 0; buffer_index < DATA_BUFFER_SIZE; buffer_index++){
    ssd1306_display_data[buffer_index] = 0;
  }
}

void UptimePresenter_Destroy(void){
  zero_out_data();
}

unsigned char* UptimePresenter_GetData(void){
  return ssd1306_display_data;
}


static int  get_font_index(char char_to_map){
  int font_index = 0;
  int font_base_offset = 0x40;
  int ascii_number_offset = 0x2F;
  int ascii_lower_case_offset = 0x60;

  if(char_to_map >= 'A' && char_to_map <= 'Z')
     font_index = char_to_map - font_base_offset;
  
  if(char_to_map >= '0' && char_to_map <= '9')
     font_index = (char_to_map - ascii_number_offset) + ('Z' - font_base_offset);

  if(char_to_map >= 'a' && char_to_map <= 'z')
     font_index = char_to_map - ascii_lower_case_offset;
 

  return font_index;
}

uint8_t* UptimePresenter_MapAsciiToFont(char char_to_map){
  return font[get_font_index(char_to_map)];
}


void UptimePresenter_FormatTimestamp(uint16_t uptime_seconds, char* buffer_to_fill){
  if (uptime_seconds == UPTIME_MAX)
    uptime_seconds = 0;

  if(uptime_seconds > UPTIME_MAX)
    uptime_seconds %= UPTIME_MAX;

  int minutes = uptime_seconds / 60;
  int seconds = uptime_seconds % 60;
  

  snprintf(buffer_to_fill, TIMESTAMP_LENGTH, "%02dm %02ds", minutes, seconds);
}


void static write_uptime_header(void){
  uint8_t uptime_header[] = "UPTIME";
  
  for(int uptime_header_index = 0; uptime_header_index < sizeof(uptime_header); uptime_header_index++){
    char* font_letter_pointer = UptimePresenter_MapAsciiToFont(uptime_header[uptime_header_index]);
    int next_font_item_index = uptime_header_index * FONT_CHAR_SIZE;

    memcpy(&ssd1306_display_data[next_font_item_index], font_letter_pointer, FONT_CHAR_SIZE);
  }
}

void UptimePresenter_Create(void){
  zero_out_data();
  write_uptime_header();
}

void UptimePresenter_UpdateUptime(uint16_t uptime_seconds){
  char timestamp_buffer[TIMESTAMP_LENGTH];
  UptimePresenter_FormatTimestamp(uptime_seconds, timestamp_buffer);
  
  int display_data_timestamp_offset = DISPLAY_LINE_BYTES;

  for(int i = 0; i < TIMESTAMP_LENGTH; i++){
    char* font_pointer = UptimePresenter_MapAsciiToFont(timestamp_buffer[i]);
    int display_data_index = display_data_timestamp_offset + (i * FONT_CHAR_SIZE);
    memcpy(&ssd1306_display_data[display_data_index], font_pointer, FONT_CHAR_SIZE); 
  }
}
