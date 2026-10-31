extern "C"
{

#include "UptimePresenter.h"

}

#include "CppUTest/TestHarness.h"


TEST_GROUP(UptimeFormat)
{
    char* actual = NULL;

    void setup(){
      actual = (char*) calloc(TIMESTAMP_LENGTH, sizeof(char));
      memset(actual, 0, TIMESTAMP_LENGTH);
      UptimePresenter_Create();
    }

    void teardown(){
      UptimePresenter_Destroy();
      free(actual);
    }
};

TEST(UptimeFormat, Fail){
  char expected[TIMESTAMP_LENGTH] = "00m 00s";
  UptimePresenter_FormatTimestamp(0, actual);

  for (int i = 0 ; i < TIMESTAMP_LENGTH; i++){
    BYTES_EQUAL(expected[i], actual[i]);
  }
}

