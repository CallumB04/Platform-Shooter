cmake_minimum_required(VERSION 3.5.0)
project(Platform-Shooter VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(deps)
add_executable(Platform-Shooter src/Game.cpp src/Main.cpp)
target_link_libraries(Platform-Shooter PRIVATE sfml-graphics sfml-window sfml-system)