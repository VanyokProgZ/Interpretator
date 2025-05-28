cmake_minimum_required(VERSION 3.15)
project(Interpretator)

find_package(Curses REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(interpret ${SOURCE_FILES} samples/interpret.cpp)

target_include_directories(interpret
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(Curses_FOUND)
    target_link_libraries(interpret PRIVATE ${Curses_LIBRARIES})
else()
    message(FATAL_ERROR "ncurses library not found!")
endif()