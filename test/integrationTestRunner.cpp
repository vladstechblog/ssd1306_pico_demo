#include <CppUTest/CommandLineTestRunner.h>
//#include "UptimePresenter_SpyTest.cpp"
#include "AppTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
