# SSD1306 Pico Demo

This is a demo project of doing test driven development (TDD)
on a Raspberry Pi Pico boards with Pico C/C++ SDK and CppUTest harness.

The UptimePresenter is responsible for formatting the display data,
including convertion of ASCII characteers into a display font
(not something a driver should be doing :P).


## I2C Pinout and BaudRate

see [App.h](src/include/App.h)



## Building the Project

```shell
git clone https://github.com/vladstechblog/ssd1306_pico_demo.git
cd ssd1306_pico_demo
cmake -B build_p2w -DPICO_PLATFORM=rp2350 -DPICO_BOARD=pico2_2
picotool erase && picotool load -x build_p2w/src/demo.uf2
```


## Building and Running Host Build Tests

- component tests

```shell
git clone https://github.com/vladstechblog/ssd1306_pico_demo.git
cd ssd1306_pico_demo
cmake -B build_host -DPICO_PLATFORM=host
cmake --build build_host -t componentTestRunner
./build_host/test/componentTestRunner
```

- integration test

```shell
git clone https://github.com/vladstechblog/ssd1306_pico_demo.git
cd ssd1306_pico_demo
cmake -B build_host -DPICO_PLATFORM=host
cmake --build build_host -t integrationTestRunner
./build_host/test/integrationTestRunner
```
