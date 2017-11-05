cmake_minimum_required(VERSION 3.8)
project(CPP_RUSH_00_)

set(CMAKE_CXX_STANDARD 98 "-lncurses")

set(SOURCE_FILES main.cpp GameClass.cpp GameClass.h Player.cpp Player.h Obstacle.cpp Obstacle.h LightObstacle.cpp LightObstacle.h BulletClass.cpp BulletClass.h  N_vis.cpp N_vis.hpp HeavyObstacle.cpp HeavyObstacle.h Enemy.cpp Enemy.h)
add_executable(CPP_RUSH_00_ ${SOURCE_FILES})