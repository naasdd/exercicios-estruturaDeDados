cmake_minimum_required(VERSION 3.10)
project(LogisticaEstelar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED CONFIG)

add_executable(app 
    app.cpp
    TAD_Sensor.cpp
    TAD_Carga.cpp
    TAD_Nave.cpp
    TAD_Camera.cpp
    TAD_Log.cpp
    TAD_Hangar.cpp
)

target_link_libraries(app PRIVATE raylib)
