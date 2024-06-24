# A software synth test bed
In this repository you will find experiments done with the PortAudio sound API.<br>
PortAudio is a free and cross-platform sound API made by Ross Bencina.<br>
[Read more about Portaudio here!](https://www.portaudio.com/)<br>
You will also find experiments with a GUI, made with WXWidgets<br>
To build the GUI you need to install wxwidgets on your system. I have done it on a Windows machine with mingw compiler. Read more about it down here. Unfortunately, it's not as simple process.<br>
My plan in the future is to make a kind of modular synth. Meanwhile i will test different sound modules in the main.cpp loop.<br>
So this repo will be a bit chaotic. You will, however, find ready built programs(built for Windows) in the builtprogram folder.<br>
## Some build instructions
### How to build this project with mingw32 and cmake on Windows. It will build both projects "sound" and "gui"<br>

step 1: create build folder<br>
step 2: cd build<br>
step 3: cmake -S .. -B . -G "MinGW Makefiles"<br>
step 4: mingw32-make.exe<br>
<br>

### How to install wxWidgets on Windows with MinGW compiler:<br>
step 1: download wxwidgets as an install.exe file<br>
step 2: run the exe. wxwidgets will create a folder on c: root, like: **C:/wxWidgets-3.2.5**<br>
step 3: build wxwidgets, [follow these instructions](https://wiki.wxwidgets.org/Compiling_wxWidgets_with_MinGW)<br>
Note that these instructions is for MinGW. If you use other compilers the build process is different.<br>
This will take about 20 mins on my machine to build.<br>
step 4: add this path to windows enviroment variables: **C:\wxWidgets-3.2.5\lib\gcc_dll** <br>
<br>
Now it should work. BTW, here is a minimum CMAKE project using wxWidgets:
<br>
cmake_minimum_required(VERSION 3.29.2)
project(wxtest)
SET(wxWidgets_USE_LIBS)
#for using RichTextCtrl
FIND_PACKAGE(wxWidgets REQUIRED richtext aui adv html core xml net base) 
add_executable(${PROJECT_NAME} WIN32 main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
<br>
info about wxwidgets is based on this stackoverflow thread:
https://stackoverflow.com/questions/63977690/how-wxwidgets-cmake-find-in-window

--------------------------------------------------------------------------------------------------------------
# History
**2024-06-24**<br>
Restructure of project. Now two folders, "sound" and "gui".<br>
**2024-06-17**<br>
Audio delay with interpolation. Based on Will Pirkles DSP book. This audio delay is very suitable for modulated delay, like chorus and flanger. It should also be possible to extend it for a old style pitch shifter module. The test program process any incoming sound from the PC microphone.<br>
**2024-06-11**<br> 
Reverb module. The test program will process any incoming sound from the PC microphone. The reverb is based on the well-known Dattorro reverb.
[Read more about the reverb here!](https://ccrma.stanford.edu/~dattorro/EffectDesignPart1.pdf)<br>
