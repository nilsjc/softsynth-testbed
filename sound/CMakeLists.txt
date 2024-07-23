cmake_minimum_required(VERSION 3.29.2)

project(softsynth)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "../.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()


#if(NOT EXISTS ${CMAKE_PROJECT_NAME}/sound/external/CMakeLists.txt)
#    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
#endif()


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