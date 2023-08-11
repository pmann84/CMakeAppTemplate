set(APP_PROJECT_NAME "${PROJECT_NAME}_App")
message(STATUS "Setting up project for app ${APP_PROJECT_NAME}")

add_executable(${APP_PROJECT_NAME} main.cpp)

target_link_libraries(${APP_PROJECT_NAME} PRIVATE gfxlib_opengl_window)