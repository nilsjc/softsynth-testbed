cmake_minimum_required(VERSION 3.29.2)

project(softsynth)

add_subdirectory(external/portaudio)

include_directories(synthmodules)

add_executable(${PROJECT_NAME} main.cpp 
                        synthmodules/PlateReverb.h
                        synthmodules/PlateReverb.cpp)

target_link_libraries(${PROJECT_NAME} PortAudio)