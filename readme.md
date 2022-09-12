# GnomeWallpaperChanger

These days most desktop managers typically have this simple functionality of shuffling the background on intervals. I havent realized what a gift that was up until now. It was bothering me so much as I do not enjoy looking at the same background while on the computer for hours. So I figured that since I am practicing my C++ at the moment, rather than use a simple bash script... I would write a program in C++. 


**As it stands the default path that it looks for wallpapers is /Pictures directory and this program will only run on Linux.**



The is very simple to setup, again ... not even necessary for most. However, once I was finished I had the idea to to add more functionality by using threads to allow for parallel execution of multiple pipes for things such as exstablishing an OpenVPN connection and any other repetative task.






https://user-images.githubusercontent.com/54689832/189564115-74b072f8-9d38-4857-839d-dc93edbcc2ee.mp4





# Execution

     "g++ -Wall -Wextra -o WallpaperChanger WallpaperChanger.cpp" (-Wall and -Wextra will tell you if anything suspicious is noticed by the compiler)  
     "./WallpaperChanger"

This is the credit for the actual pipe algorithm - https://dev.to/aggsol/calling-shell-commands-from-c-8ej
