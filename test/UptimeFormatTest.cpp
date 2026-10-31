extern "C"
{

#include "UptimePresenter.h"

}

#include "CppUTest/TestHarness.h"


TEST_GROUP(UptimeFormat)
{
    char* actual = NULL;

    void validate_timestamp(char* expected_values, char* actual_values){
      for (int i = 0 ; i < TIMESTAMP_LENGTH; i++){
        BYTES_EQUAL(expected_values[i], actual_values[i]);
      }
    }

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

TEST(UptimeFormat, Basic){
  char expected[TIMESTAMP_LENGTH] = "00m 00s";
  UptimePresenter_FormatTimestamp(0, actual);
  validate_timestamp(expected, actual);
}

TEST(UptimeFormat, LargetstUptimeSupportedOnDisplay){
  char expected[TIMESTAMP_LENGTH] = "99m 59s";
  UptimePresenter_FormatTimestamp(UPTIME_MAX - 1, actual);
  validate_timestamp(expected, actual);
}
