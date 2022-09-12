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
#include "outsource.h"	//<- Header 

// g++ (Debian 10.2.1-6) 10.2.1 20210110
// g++ main.cpp outsource.cpp -o tasker
// ./tasker

// WHEN YOU HAVE VARIABLES THAT NEED TO BE GLOBAL BETWEEN FILES THEY NEED TO BE DEFINED IN HEADER AND C++ FILE

// Global extern variables 
int dirSize = 0; 								// Holds the size of the directory 
std::string files[1024]; 						// Hold the wallpaper filename inside as string inside array 
std::string newWallPaper;						// Holds the current wallpaper as a string
std::size_t foundPNG; 							// Unsigned integral type to hold returned index of substring 
std::size_t foundJPG;							// Unsigned integral type to hold returned index of substring 
std::string picPath;							// Holds the path to the photos 
//std::string desktopDir;						// FOR MY SETUP -  Holds the path to the Desktop 
std::vector<std::string> *desktopFiles;			// FOR MY SETUP -  Holds the file names in Desktop path 

// Main
int main(int argc, char *argv[]) {
	
	int i = 0; 
	struct utsname sysInfo; 						// Holds utsname struct for detecting OS
	char username[16];								// Holds the Account username for path 
	int size = 0;									// Holds the conversion size of array
	struct dirent *entry = nullptr; 				// Holds the dirent struct for files
	DIR *directory = nullptr; 						// Holds the open directory stream
	char *charpicPath = nullptr; 					// Holds the path to the directorys as a char*
	std::string currentOS; 							// Current OS name
	std::string usernameSTR; 						// Holds the Account user as a string 

	// Call uname with pointer to the struct 
	if (uname(&sysInfo)) {
		//std::cout << uname(&sysInfo) << std::endl;
		std::cout << "Failed to test system at uname() call!\n";
		exit(-1);
	}

	// Get the current OS
	currentOS = (sysInfo.sysname);					
	
	// Verify that we are on linux :) 
	assert (currentOS.compare("Linux") == 0);

	// Get the local username 
	getlogin_r(username, 16); 


	// Calculate the size of the occupied array 
	for (i = 0; i < sizeof(username); i++) {
		if (username[i] != NULL) {
			size++; 
		} 
	}

	// Convert the char[] to a string 
	usernameSTR = convertToString(username, size);

	// Generate the path for the pictures folder 
	picPath = ("/home/" + usernameSTR + "/Pictures/");		
	
	// Switch string to char * 
	charpicPath = &picPath[0]; 

	// Opening the Pictures folder 
	directory = opendir(charpicPath);

	// Make sure that directory is valid
	if (directory != nullptr) {

		// While there is something else to read
		while (entry = readdir(directory)) {

			// Skip either file name 
			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
				continue;
			} 
			// Save the file name for later use 
			files[dirSize] = entry->d_name;

			// Count the number of files in the directory 
			dirSize++;
		}
	}

	// Close the file stream 
	closedir(directory);
	
	// Verify that there is at least one file in the directory 
	assert (dirSize > 0);


	// Set the path to open 
	//std::string desktopDir = ("/home/" + usernameSTR + "/Desktop/");

	// This function will return a list of files in directory 
	//std::vector<std::string> *returnedForNoReason = openDesktop(desktopDir);

	// Search the vector list for "client.ovpn" 
    //for (int i = 0; i < desktopFiles->size(); i++) {

        // Check the files for an openvpn client -> autologin client !!!!!
        //if (desktopFiles->at(i).compare("client.ovpn") == 0) {
        	// Generate a new thread 

        	// Display TCP IP events 
        //	break; 
        //}
    //}

	// Switch wallpaper 
	change(); 

	
	return 0; 
}


//TO DO:
/*
Add this program to the startup 
Add a key listener to manually change wall paper  
Add try catch blocks for errors 
Add functionality to auto execute any bash command (such as for openvpn client)
*/
