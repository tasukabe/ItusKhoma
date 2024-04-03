cmake_minimum_required(VERSION 3.0.0)

project(ItusKhoma)

set(CXX_STANDARD_REQUIRED 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(ItusKhoma Main.cpp Render.cpp)

target_link_libraries(ItusKhoma PRIVATE sfml-graphics sfml-window sfml-system)
