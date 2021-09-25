cmake_minimum_required(VERSION 2.8)

project(dirent_h LANGUAGES C)

add_executable(example example.c dirent.h)

target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(example PRIVATE shlwapi)
