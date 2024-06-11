cmake_minimum_required(VERSION 3.29.2)

project(softsynth)

add_subdirectory(external/portaudio)
add_subdirectory(external/wxwidgets)

add_executable(softsynth main.cpp 
                            MoogVCF.h 
                            MoogVCF.cpp 
                            envelope.h 
                            envelope.cpp
                            AudioDelay.h
                            AudioDelay.cpp
							PlateReverb.h
                            PlateReverb.cpp)

target_link_libraries(softsynth PortAudio wx::net wx::core wx::base)
