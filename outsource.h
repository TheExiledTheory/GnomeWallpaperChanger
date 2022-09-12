// Header guard //
#ifndef OUTSOURCE_H
#define OUTSOURCE_H


// Global variables //
extern size_t foundPNG;
extern size_t foundJPG;
extern int dirSize;
extern std::string newWallPaper;
extern std::string files[1024]; 						
extern std::string picPath;
//extern std::string desktopDir; // FOR MY SETUP 
extern std::vector<std::string> *desktopFiles; // FOR MY SETUP


// Function declarations:prototypes // 
// Opens pipe to terminal to run command 
std::string execCommand(const std::string cmd, int out_exitStatus);	
// Converts char [] to String 
std::string convertToString(char* a, int size);
// Loop to change wallpaper
void change(); 
// Open desktop and return a list of files found 
std::vector<std::string> *openDesktop(std::string desktopDir); 	// FOR MY SETUP 

#endif