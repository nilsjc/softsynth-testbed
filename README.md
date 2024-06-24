# A software synth test bed
In this repository you will find experiments done with the PortAudio sound API.<br>
PortAudio is a free and cross-platform sound API made by Ross Bencina.<br>
[Read more about Portaudio here!](https://www.portaudio.com/)<br>
You will also find experiments with a GUI, made with WXWidgets<br>
To build the GUI you need to install wxwidgets on your system. I have done it on a Windows machine with mingw compiler. Read more about it in buildinstructions.txt Unfortunately, it's not as simple process.<br>
My plan in the future is to make a kind of modular synth. Meanwhile i will test different sound modules in the main.cpp loop.<br>
So this repo will be a bit chaotic. You will, however, find ready built programs(built for Windows) in the builtprogram folder.<br>
# History
2024-06-24<br>
Restructure of project. Now two folders, "sound" and "gui".<br>
2024-06-17<br>
Audio delay with interpolation. Based on Will Pirkles DSP book. This audio delay is very suitable for modulated delay, like chorus and flanger. It should also be possible to extend it for a old style pitch shifter module. The test program process any incoming sound from the PC microphone.<br>
2024-06-11<br> 
Reverb module. The test program will process any incoming sound from the PC microphone. The reverb is based on the well-known Dattorro reverb.
[Read more about the reverb here!](https://ccrma.stanford.edu/~dattorro/EffectDesignPart1.pdf)<br>
