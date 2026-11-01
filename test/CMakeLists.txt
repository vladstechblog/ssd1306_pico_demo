include(include_local_cpputest_git_repo.cmake)

get_target_property(APP_SOURCES App SOURCES)
get_target_property(APP_SOURCE_DIR App SOURCE_DIR)
get_target_property(APP_INCLUDE_DIR App INCLUDE_DIRECTORIES)

foreach(SRC IN LISTS APP_SOURCES)
  list(APPEND APP_SOURCE_LIST "${APP_SOURCE_DIR}/${SRC}")
endforeach()

get_target_property(DISPLAY_SOURCES displayDriver SOURCES)
get_target_property(DISPLAY_SOURCE_DIR displayDriver SOURCE_DIR)
get_target_property(DISPLAY_INCLUDE_DIR displayDriver INCLUDE_DIRECTORIES)

message("\n\n${APP_SOURCE_LIST}\n\n")

add_executable(
  appTestRunner
  appTestRunner.cpp
  ${APP_SOURCE_LIST}
)

target_include_directories(
  appTestRunner
  PUBLIC
  include
  "${APP_INCLUDE_DIR}"
  "${DISPLAY_INCLUDE_DIR}"
)

target_link_libraries(
  appTestRunner
  PUBLIC
  CppUTest
  CppUTestExt
)
