# Platform-Shooter

An in-progress 2D platform shooter game, built using C++ and the SFML library.

## Prerequisites

- [CMake](https://cmake.org/download/) needs to be installed.
- A C++ compiler for generating binary folder.

## Running the Game

```bash
## Clone the Repository
git clone https://github.com/CallumB04/Platform-Shooter.git

## Update working directory
cd ./Platform-Shooter

## Create and enter build folder
mkdir build && cd build

## Generate binary folder, using generator of choice
cmake -G "Visual Studio 16 2019" ..

## Build project
cmake --build ./

## Copy assets into executable directory
cp ../assets ./Debug/assets -r

## Run game
cd Debug && ./Platform-Shooter
```
