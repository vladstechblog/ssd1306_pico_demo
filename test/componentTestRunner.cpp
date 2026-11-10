#include <CppUTest/CommandLineTestRunner.h>
#include "UptimePresenterTest.cpp"
#include "UptimeFormatTest.cpp"
#include "TimerTest.cpp"
#include "UtilTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}