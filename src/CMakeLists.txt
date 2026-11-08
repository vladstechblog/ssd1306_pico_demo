add_library(UptimePresenter OBJECT UptimePresenter.c)
target_include_directories(UptimePresenter PUBLIC include)
target_link_libraries(UptimePresenter PUBLIC pico_stdlib_headers)

add_library(Timer OBJECT Timer.c)
target_include_directories(Timer PUBLIC include)
target_link_libraries(Timer PUBLIC pico_time_headers)

add_library(Util OBJECT Util.c)
target_include_directories(Util PUBLIC include)

add_library(App STATIC App.c)
target_include_directories(App PUBLIC include)
target_link_libraries(App PUBLIC Util hardware_i2c hardware_gpio displayDriver)

add_executable(demo main.c)
target_include_directories(demo PUBLIC include)
target_link_libraries(demo PUBLIC App UptimePresenter Timer pico_stdlib)

pico_add_extra_outputs(demo)