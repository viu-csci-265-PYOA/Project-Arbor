# **CSCI 265 Project Closeout**

### **Team name:** Pick Your Own Adventure (PYOA)

### **Project/product name:** Arbor

### **Contact person**

* #### duncan-mcleod-1996

## **Table of Contents**

1. #### Overview 

2. #### Final Updates 

3. #### Organizational review 

4. #### Technical review 

5. #### End State of the Product 

## **1\. Overview**

This document is meant to wrap up the team project in the context of the course. That is, it provides:

* Final updates on:  
  * the state of Arbor  
  * and the state of the document deliverables.  
* A review of  
  * the organizational decisions made by the team,  
  * which ones worked out and didn’t work,  
  * and what we would do differently if given a “do-over”.  
* A similar review conducted on the technical decisions made by the team.  
* Discussion on the end state of Arbor based on  
  * remaining future work and plans for the project  
  * and an overall summary and recommendations with regards to the project.

## **2\. Final Updates**

The section will briefly summarize the final state of Arbor and document deliverables. Specifically highlighting changes since the previous phase.

### **Game Code Updates**

This section includes features we either added, modified, or removed since phase 3\.

Features Added:

* **Narrative Navigation:** The narrative navigation is implemented with a vector of our rooms and indexing to path to the correct room based on the user's choice. The two options are stored as integers within our room struct, and they are used to update the currentRoom index once chosen.  
* **Room Loading:** Our Game Manager system uses file reading to pull information from our room directory text file and assign it to our rooms using our Room Managers ‘loadRooms()’ function. Our room class system was designed for easy navigation between rooms based on user input.   
* **Text Loading:** Our text loading is now restricted to a specified region within the game window, this fixed our previous collision issues with the graphical components on Arbor’s game screen. This revision comes with the addition of manual scrolling support (mouse & keyboard) for our descriptions that are too long for the game window.   
* **Game Saving:** Using our save system header, we can store the room index of the user’s current location in Arbor. This enables the user to not only exit to the Main Menu, but exit the game entirely and still resume from where they left off at a later time.


  
Features Removed:

* **Next Screen:** The next screen was our original solution to the problem we had of our narrative descriptions being too long to fit on our game window. This was solved by implementing a specified text region and scrolling support.  
* **Pause Menu:** The pause menu was replaced with routing back to the main menu, and still has ‘Continue The Quest’ and ‘Exit’ buttons, and now you can also restart the game at any point from there.   
* **Inventory:** Our implemented inventory system is functional in the hard-coded prototype, but we were not able to port it over to the GUI version before the end of this phase. We plan to re-implement in the future.

### **Documents Updates**

* **Charter**: Shuffled team roles to reflect the change in responsibilities since the previous phase.  
* **Standards**: a new addition to processes was added since the previous phase. Specifically in the Merging Guidelines section, step 5 (at the end of the document). It addresses the need to merge parent branches into all child branches after a child branch was merged to the parent. This meant to ensure everyone works with the latest updates. The Organizational Review section goes into detail the necessity of this addition. The standards document should now be accurate and up to date with the final PYOA’s organization and processes.  
* **Requirements**: Various updates to reflect removed and added features as well as respond to feedback given in Phase 3\.  
  * Section 4: Added individual Game Flow and Plot Line sections, entered the “Neutral” plot line summary, and summarized possible plot for the “Good” and “Evil” endings. Also added diagrams to explain the branching as it currently stands.  
  * Section 5: Elaborated on potential item classes and usage for future development.  
  * Section 6: Removed Pause Screen and moved Character Creation to future development.  
  * Section 7: Added a use case for gameplay to elaborate on different outcomes that the user may face.  
  * Section 11: Added Diagrams to Appendix.  
* **Design**: Completed this phase, accurately reflects current functionality to the best of our abilities.  
* **Test**: This document is new to this phase and outlines decisions made regarding testing the functionality of project arbor.  
* **Project Closeout**: this document is new to this phase. It should be complete and correct to the best of the team’s ability.

## **3\. Organizational Review**

In this section we review the major team/organizational decisions made, the impact of those decisions, and what we might do differently if we had the project to do over again.

* **SDLC**: Initially we thought that we’d implement a spiral approach. However, with regards to the team’s experience and the deliverable focuses in each phase, we found that a scrum-based approach was more suitable.   
* **Timing**: Workload near the end of the semester wasn’t properly accounted for. We were on track for charter, proposal, and standards. However, the timing we allocated for requirements, design and test plan was not sufficient.  
* **Planning:** Building on the previous point, a more clear idea of roles and what expectations were across the team could help us organize our work more efficiently.  
* **Code Standards**: Less adherence to since the team wasn’t reviewing for that and lack of time.  
* **Version Control Issue**: On November 21, 2025 there were issues merging the dev/gui branch to the development branch. The issue was the merging branch copied over the other thus creating a broken commit history. It’s unclear why this happened, but the impacts lead to an additional step in the version control standards in the Standards document. Outside this instance, version control standards were rocky at the beginning. Mainly team members wouldn’t inform the reviewer of the pull request resulting in the pull request being in limbo for a time. Ever since the Nov. 23 incident, everyone was more on top of proper procedure.

## **4\. Technical review**

In this section we review the major technical decisions made, the impact of those decisions, and what we might do differently if we had the project to do over again.

* **GUI Version:** We had major difficulties with transitioning our C++ prototype to integrate with Raylib’s library functions. Nearly all of the prototype code (e.g. input handling, file loading etc.) was written in a way that was incompatible with our GUI requirements. Proper planning would’ve had the GUI implementation being the base of our game, and building from there up so we could’ve designed the components with the GUIs requirements in mind.  
* **Design:** Timing and implementing before we had a clear design led to setbacks along the way. We needed to allocate more time to design planning. As we began our prototype before having a cohesive view of system modules and what we would need for graphical integration.  
* **Repository Management:** A big quality of life aspect that we could’ve used is a cleaner repo structure from the beginning, to divide headers and implementation files for better readability. This is something that can be outlined in standards, so that the team has a clearer picture of what files belong in each directory and what to do when we introduce new versions of existing files.  
* **Compiling**: duncan-mcleod-1996 and Timber-faol are unable to compile raylib code in Windows while everyone else is. It’s unclear why, but it’s likely to use the dynamic raylib version instead of the static version and not understand completely what the compiler linkers and/or flags are doing. If we were do this again, picking a single OS to run at first and understanding/testing what linkers/flags are doing/needed before advancing too far into the code. And also figuring out package are needed for the OS too  
* **Run Arbor**: again duncan-mcleod-1996 and Timber-faol unable to run Arbor executables on Windows and Linux Debian distro. Debian part seems more of a lack of support from Raylib themself. They have pack manager support for all other major Linux Distros but Debian. Mmilutopaz is able run/compile just fine on their Arch distro. Only seeable work around for this understanding the install requirements for Debian. Specifically, the dynamic raylib version which seems more complicated the static, so maybe picking that at first then moving to dynamic later once we understand how everything work would have been the better approach. As for Windows, it’s unclear outside getting warning of a couple files being missing. But again, not sure why they are missing for the two team member, but not the others.

## **5\. End State of the Product**

This section details the features and functionality that *was* successfully incorporated into the final product.

* **New Game Creation:** Using the Linux or Windows executable, users are able to launch Arbor and create a new game to explore the realm and save Arbor from magical chaos.  
* **Narrative Navigation:** Implemented decision-making, currently with a maximum of two choices which lead to various levels and dead ends. Arbor currently features a draft of the “Neutral” storyline and up to 3 playable levels: Dungeon, Tavern and Forest.  
* **Saving and Loading:** Save system stores the room index of the user’s current location in Arbor. This enables the user to not only exit to the Main Menu, but exit the game entirely and still resume from where they left off at a later time.  
* **A GUI:** A working implementation of a GUI for Arbor was created. This GUI renders all game screens, (e.g. Main menu, gameplay screen, etc.), it also has additional graphical components such as UI buttons, a restricted text box for our narrative descriptions, and a manual scrolling feature for if the description exceeds the size of the window. Arbors GUI handles user input through raylibs user interaction functions like ‘IsMouseButtonPressed()’, and a majority of our input is done through these mouse centric functions. Currently the only support for keyboard input is with the scrolling feature for our descriptions.  

\- It should also detail any core features and functionality that *wasn't* successfully incorporated into the final product, estimate how much work remains before these features could be completed, and make recommendations on what order they should be completed in (if the team had the time to complete them). 

* **Full Narrative:** The first priority would be to complete a narrative to give the user a fully fleshed out story. Arbor’s “Neutral” has 4 out of 7 levels playable. However, more time will be needed to fully write out two additional narrative branches.  
* **Ending State:** Currently Arbor has one end state for all narrative pathways, which is our ‘The End’ screen. We wanted to get winning and losing states set up as well as the proper pathing to them and display screens.  
* **Character Creation:** To make character creation functional we would need to restructure the narrative and build on the complexity of our room managing system. For instance, a room would not only need to accept a player’s input but also check a trait or item to see if the outcome should succeed or fail.

### **5.1 Future work**

In this section we discuss appropriate future work for the project, and the team members' plans regarding the project.

* Edit and complete the narrative branches. To have one playable ending and to feature expanded choices for the user.  
* Reimplement items and inventory. As well as consider the development of character traits and names  
* Expand on the number of gameplay screens available, i.e. a next screen. We would like to be able to implement the ability to load the specific player options at the end of each scene on our UI buttons. Also make minor visual adjustments to Arbor’s textures.  
* Understand the install requirements for Windows and Debian in order to properly compile and run for all teams, thus future gamers.

### **5.2 Summary and recommendations**

In this section we provide our final wrap-up of the project: giving our final overall thoughts on the project, the team, and our processes and techniques.

Developing Arbor from a concept to a functional demo has been an experience filled with successes and learning opportunities. While Arbor still has many iterations to go before we can consider it truly completed, the progress that we made in development over the latter half of the semester is significant.

Arbor gave everyone on team PYOA the opportunity to expand their skillset whether through backend development, learning about graphical user interfaces, managing version control processes, or simply helping contribute to the documentation needed in a development project of this scale. If we were to take anything away from the process, it would be to use everything we’ve learned in this course from the beginning. Having a clearer picture of design, what requirements we’d need for testing and maintenance from the conception of the product, would not only help us come up with a more coherent design, but also allow us to plan a more balanced workflow.

That being said, considering the experience level of the team, having a functional version of our project is an incredible milestone, and none of it would have been possible without the collaboration between all the team members of Pick Your Own Adventure. Although we began the semester in very specific roles, and at some times could have used more clarity around them, team members showed that they could be adaptable in stretching the boundaries of those responsibilities to help where needed.   
