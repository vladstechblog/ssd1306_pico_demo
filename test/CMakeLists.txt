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

add_executable(
  integrationTestRunner
  integrationTestRunner.cpp
  ${APP_SOURCE_LIST}
)

target_include_directories(
  integrationTestRunner 
  PUBLIC
  include
  "${APP_INCLUDE_DIR}"
  "${DISPLAY_INCLUDE_DIR}"
)

target_link_libraries(
  integrationTestRunner
  PUBLIC
  Timer
  CppUTest
  CppUTestExt
)

add_executable(
  componentTestRunner
  componentTestRunner.cpp
)

target_include_directories(
  componentTestRunner
  PUBLIC
  include
  "${APP_INCLUDE_DIR}"
  "${DISPLAY_INCLUDE_DIR}"
)

target_link_libraries(
  componentTestRunner
  PUBLIC
  Util
  UptimePresenter
  Timer
  CppUTest
  CppUTestExt
)
