extern "C"
{
#include "UptimePresenter.h"
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


