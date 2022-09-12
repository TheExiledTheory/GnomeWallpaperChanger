
#include <iostream>
#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <typeinfo>
#include <assert.h>
#include <regex> 
#include <unistd.h>
#include <bits/stdc++.h> 
#include <ftw.h> 
#include <dirent.h>
#include <time.h> 
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include "outsource.h"  //<- Header 


// Function definitions // 

// This function will create a pipe to terminal and execute the command
std::string execCommand(const std::string cmd, int/*&*/ out_exitStatus)
{
    out_exitStatus = 0;

    // Send the command to c_str() to get a char* and fork into pipe 
    auto pPipe = ::popen(cmd.c_str(), "r");

    // Make sure that we get a valid return 
    if(pPipe == nullptr)
    {
        throw std::runtime_error("Cannot open pipe");
    }

    // Create holder array and string 
    std::array<char, 256> buffer;
    std::string result;

    // While we have not reached the end of pipe stream 
    while(not std::feof(pPipe))
    {
        // Read the bytes from the steram 
        auto bytes = std::fread(buffer.data(), 1, buffer.size(), pPipe);
        result.append(buffer.data(), bytes);
    }

    // Close the pipe 
    auto rc = ::pclose(pPipe);

    // Check that the process exited successfully  
    if(WIFEXITED(rc))
    {
        out_exitStatus = WEXITSTATUS(rc);
    }

    // Return result in the event of an error 
    return result;
}


// Take a char[] and convert to string  
std::string convertToString(char* a, int size) 
{ 
    int i; 
    std::string s = ""; 

    // Convert char* to String 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 
 

// Thread will run this to change background
void change(){

 	// Constantly run in background 
	while (1) {

		// Seed srand 
		srand(time(NULL));
	
		// Select a random element from file array 
		int randomNum = rand() % dirSize + 1; 

		// Select the current wallpaper string from files array 
		newWallPaper = files[randomNum];
        
		// Search for substring to make sure that it ends in png/jpg
		//.find() returns std::string::npos if no matches found 
		foundPNG = newWallPaper.find(".png");		
		foundJPG = newWallPaper.find(".jpg");

		// Make sure that the file is of either type 
		if (foundPNG != std::string::npos || foundJPG != std::string::npos) {
			
			//std::cout << "We have either a PNG or a JPG" << "\n";

			// Set the current wallinvalid_argumentpaper 
		    int exitStatus = 0;

		    /////////// YOU MUST CHANGE THIS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ BASED ON YOU DESKTOP MANAGER ///////////
		    auto result = execCommand("gsettings set org.mate.background picture-filename " + picPath + files[randomNum] + "", exitStatus);
		    std::cout << "Wallpaper switched! I am waiting for 10 minutes ..." << std::endl;

		    /////////// YOU MUST CHANGE THIS ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼ BASED ON YOUR DESIRED INTERVAL ///////////
		    std::this_thread::sleep_for(std::chrono::milliseconds(600000));
		    std::cout << "Switching wallpaper\n";
		}
	} 
}

// This function will open a specified directory, search for a file 
std::vector<std::string> *openDesktop(std::string desktopDir) {
    

    DIR *dir;                                       // Directory variable 
    struct dirent *direc = nullptr;                 // Directory struct 
    desktopFiles = new std::vector<std::string>();  // Innitialization of file vector list 

    // Make sure the pointer to the directory is not NULL
    if ((dir = opendir(desktopDir.c_str())) == NULL) {  // c_str copies string into char* to be passed to c-style function 
        std::cout << "Error(" << errno << ") opening" << desktopDir << std::endl; 
        return nullptr; 
    }

    // Read the directory file names while there
    while ((direc = readdir(dir)) != NULL) {
        // Place the file name into the string vector
        desktopFiles->push_back((std::string)direc->d_name);       
    }
    // Close file stream
    closedir(dir);

    // Return vector list 
    return desktopFiles;  

}






