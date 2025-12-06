# CSCI 265 Test Plan

## Team name: Pick Your Own Adventure (PYOA)

## Project name: Project Arbor

## Primary contact: duncan-mcleod-1996

## Table of Contents

General overview
Key testing components 
Known issues
Test plan 
Key testing challenges 
Testing timeline 

## General overview

Project arbors testing will be handled manually and focus on three primary aspects of the game: navigation, saving and visuals. The scope of project arbor has been significantly impacted by the known issues and testing challenges. The testing documentation is accessible through the commit history in github.

## Key testing components

The primary components of project arbor that need testing are; navigating the decision tree, proper saving and resuming of our savefile, and ensuring visual appeal and synchronicity. 


## Known issues

Inability to run project arbor on specific computers. These issues range from compiling errors that cannot locate specific raylib library files to running the executable and nothing happening. 
A looping error message occurs when exiting the game from our main menu before reaching a Game Over screen. (possibly resolved)

Project arbor has only successfully run on 4 out of the 6 devices used by team PYOA. The source of these errors has not been discovered but time will be dedicated to investigating in our future testing timeline. The specific errors encountered are as follows:
Errors while compiling, claiming references to functions in missing libraries despite those libraries and paths being specifically included in the compile prompt. 
Problems with operating system variants. These caused problems with developing a makefile, requiring different compile commands based on operating systems. The raylib library itself seemed to function differently from operating system to operating system. 
Depending on the device, running the same executable would open the program and function perfectly while others did nothing. 

## Test Plan

Due to the small and relatively simple nature of our program we elected to do our testing manually. These tests were performed by the programmer in charge of a specific game function and then further tested by other team members before merging that game function with our main branch. These tests remain local and are focused on the function being modified. 

Separate tests were also performed on the program as a whole specifically going after edge cases. With the scale of our project these edge cases account for every possible path within our current program. The project edge cases fall under 2 main categories; narrative and savefile. The narrative edge cases include traversing our decision tree to reach every possible conclusion, ensuring a smooth transition between rooms. The savefile cases include accessing the main menu to automatically save your room then returning to that room. The process for savefile testing repeats for every possible room. 

The GUI is our last major component for testing but cannot necessarily be tested directly. Instead during the two types of testing previously mentioned, the GUI is being monitored for any misalignment or overlap in text. 

## Key testing challenges

Our Primary testing challenges revolved around an incompatible coding style of raylib and our coding team lead. This incompatibility led to a major overhaul of our program main causing it to become less modular than initially intended. This reduced modularity made it harder to isolate the source of specific errors. 

The secondary testing challenge presented itself in the form of file deletion while merging in github. Due to the small nature of our program we elected to do our testing manually. These tests were performed by the programmer in charge of a specific game function and then further tested by other team members before merging that game function with our main branch. The deletion of certain files after merging caused fundamental changes to the program after the testing had been completed. 

## Testing Timeline (hypothetical) 

Given more time elements we would include that require additional testing are: 
-Increased number of narrative options
-implimentation of items 
-implimentation of character traits 

Increasing the number of narrative options will simply increase the number of rooms for testing without needing to change any of the testing procedures. 
Implementing items and character traits will drastically increase the number of possibilities when considering every combination of room, item and trait. Implementing these two elements would likely require us to develop some form or automation to reasonably test. 
The last impact of these additional features would be their interaction with our savefile system. The traits being consistent from start to end would be manageable for testing the items would drastically increase complexity and also require some form of automation. 



