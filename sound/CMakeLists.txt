cmake_minimum_required(VERSION 3.29.2)

project(softsynth)

add_subdirectory(external)

include_directories(synthmodules)

add_executable(${PROJECT_NAME} main.cpp
                        SynthManager.h
                        SynthManager.cpp
                        AudioStream.h
                        AudioStream.cpp
                        synthmodules/PlateReverb.h
                        synthmodules/PlateReverb.cpp
                        synthmodules/Adelay.h
                        synthmodules/Adelay.cpp)

target_link_libraries(${PROJECT_NAME} PortAudio)