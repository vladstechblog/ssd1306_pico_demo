#include <CppUTest/CommandLineTestRunner.h>
#include "UptimePresenterTest.cpp"
#include "UptimeFormatTest.cpp"
#include "TimerTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
