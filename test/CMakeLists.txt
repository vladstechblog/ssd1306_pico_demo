include(include_local_cpputest_git_repo.cmake)

get_target_property(APP_SOURCES App SOURCES)
get_target_property(APP_SOURCE_DIR App SOURCE_DIR)
get_target_property(APP_INCLUDE_DIR App INCLUDE_DIRECTORIES)

add_executable(
  appTestRunner
  appTestRunner.cpp
  "${APP_SOURCE_DIR}/${APP_SOURCES}"
)

target_include_directories(appTestRunner PUBLIC include "${APP_INCLUDE_DIR}")

target_link_libraries(
  appTestRunner
  PUBLIC
  CppUTest
  CppUTestExt
)
