cmake_minimum_required(VERSION 3.20.0)
project(
        EKF
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGSS -pthread)


add_subdirectory(ball_localization)
add_subdirectory(ball_detection)
add_subdirectory(ball_calibration)









