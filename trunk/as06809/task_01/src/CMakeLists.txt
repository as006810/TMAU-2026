cmake_minimum_required(VERSION 3.10)
project(ControlModels)

set(CMAKE_CXX_STANDARD 11)

add_executable(ControlModels 
    main.cpp 
    InputSignal.cpp
    Model1_6.cpp
    Model2_10.cpp
    Model3_4.cpp
)