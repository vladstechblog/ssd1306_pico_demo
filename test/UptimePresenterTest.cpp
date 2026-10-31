extern "C"
{

#include "UptimePresenter.h"
#include "ssd1306_font.h"

}

#include "CppUTest/TestHarness.h"

TEST_GROUP(UptimePresenter)
{
    void fill_buffer_with_aa(){
      unsigned char* data = UptimePresenter_GetData();
      for (int i = 0; i < DATA_BUFFER_SIZE ; i++){
        data[i] = 0xaa;
      }
    }

    void check_buffer_is_zeroed_out(){
      unsigned char* data = UptimePresenter_GetData();
      for (int i = 0; i < DATA_BUFFER_SIZE; i++){
        BYTES_EQUAL(0, data[i]);
      }
    }

    void setup(){
    }

    void teardown(){
    }
};

TEST(UptimePresenter, GetData){
  unsigned char expected = 0xab;
  unsigned char* data = UptimePresenter_GetData();
  data[0] = expected;
  BYTES_EQUAL(expected, data[0]);
}

TEST(UptimePresenter, DestroyZeroesOutData){
  fill_buffer_with_aa();

  UptimePresenter_Destroy();
  check_buffer_is_zeroed_out();
}

TEST(UptimePresenter, CreateZeroesOutData){
  fill_buffer_with_aa();

  UptimePresenter_Create();
  check_buffer_is_zeroed_out();
}



TEST_GROUP(FormatUptimeData){

  void check_mapped_ascii_value(uint8_t* expected, uint8_t* actual){
    for(int i = 0; i < FONT_CHAR_SIZE; i++){
      BYTES_EQUAL(expected[i], actual[i]);
    }
  }

  void setup(){
    UptimePresenter_Create();
  }

  void teardown(){
    UptimePresenter_Destroy();
  }
};

TEST(FormatUptimeData, TestMapAscciToFontUpperCaseA){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x78, 0x14, 0x12, 0x11, 0x12, 0x14, 0x78, 0x00 };
  char upper_case_a = 'A';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(upper_case_a);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontUpperCaseJ){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x21, 0x41, 0x41, 0x3f, 0x01, 0x01, 0x01, 0x00 };
  char letter_J = 'J';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(letter_J);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontUpperCaseZ){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x41, 0x61, 0x59, 0x45, 0x43, 0x41, 0x00, 0x00 };
  char upper_case_z = 'Z';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(upper_case_z);
}

TEST(FormatUptimeData, TestMapAscciToFontNumberZero){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x3e, 0x41, 0x41, 0x49, 0x41, 0x41, 0x3e, 0x00 };
  char number_zero = '0';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(number_zero);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontNumberSeven){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x01, 0x01, 0x01, 0x61, 0x31, 0x0d, 0x03, 0x00 };
  char number_seven = '7';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(number_seven);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontNumberNine){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x06, 0x09, 0x09, 0x09, 0x09, 0x09, 0x7f, 0x00 };
  char number_nine = '9';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(number_nine);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontLowerCaseA){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x78, 0x14, 0x12, 0x11, 0x12, 0x14, 0x78, 0x00 };
  char lower_case_a = 'a';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(lower_case_a);
}

TEST(FormatUptimeData, TestMapAscciToFontLowerCaseI){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00 };
  char lower_case_i = 'i';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(lower_case_i);
  check_mapped_ascii_value(expected, actual);
}

TEST(FormatUptimeData, TestMapAscciToFontLowerCaseZ){
  uint8_t expected[FONT_CHAR_SIZE] = { 0x41, 0x61, 0x59, 0x45, 0x43, 0x41, 0x00, 0x00 };
  char lower_case_z = 'z';
  uint8_t* actual = UptimePresenter_MapAsciiToFont(lower_case_z);
  check_mapped_ascii_value(expected, actual);
}

