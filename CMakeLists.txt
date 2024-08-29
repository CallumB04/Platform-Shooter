cmake_minimum_required(VERSION 3.5.0)
project(Platform-Shooter VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(deps)
add_executable(Platform-Shooter src/Game.cpp src/Main.cpp src/State.cpp src/states/GameState.cpp src/states/MainMenuState.cpp src/entities/Player.cpp src/level/Platform.cpp src/entities/Bullet.cpp)
target_link_libraries(Platform-Shooter PRIVATE sfml-graphics sfml-window sfml-system)