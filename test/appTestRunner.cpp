#include <CppUTest/CommandLineTestRunner.h>
#include "AppTest.cpp"
#include "UptimePresenterTest.cpp"
#include "UptimeFormatTest.cpp"
#include "TimerTest.cpp"
#include "UptimePresenter_SpyTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
