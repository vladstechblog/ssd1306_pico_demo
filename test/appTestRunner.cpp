#include <CppUTest/CommandLineTestRunner.h>
#include "AppTest.cpp"
#include "AppDisplayInitTest.cpp"
#include "UptimePresenterTest.cpp"
#include "UptimeFormatTest.cpp"

int main(int argc, char* argv[]){
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
