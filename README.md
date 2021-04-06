# GnomeWallpaperChanger

These days most desktop managers typically have this simple functionality of shuffling the background on intervals. I havent realized what a gift that was up until now. It was bothering me so much because I do not enjoy looking at the same background while on the computer for hours. So i figured that since I am practicing my at the moment, rather than use a simple bash script... I would write a program in C++ to do it. 

As it stands the default path that it looks for wallpapers is /Pictures path and this program will only run on Linux.

The is very simple to setup and once again, not even necessary for some. However, once I was finished I had the idea to to add more functionality by using threads to for other things such as exstablishing an OpenVPN connection.

*Setup
    Navigate to download folder 
     run "g++ -Wall -Wextra -o WallpaperChanger WallpaperChanger.cpp" (-Wall and -Wextra will tell you if anything suspicious is noticed by the compiler)  
    ./WallpaperChanger

This is the credit for the actual pipe algorithm - https://dev.to/aggsol/calling-shell-commands-from-c-8ej

