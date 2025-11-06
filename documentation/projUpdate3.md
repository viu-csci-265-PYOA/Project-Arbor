# CSCI 265 Project Update (Phase 3)

## Team name: Pick Your Own Adventure (PYOA)

## Project name: Arbor

## Contact person
- Duncan 

--- 

### Key revisions since phase 2

Our key revisions this phase were making changes to existing documents as per feedback received, as well as starting the remaining required documents. In addition to this Milu has continued working on the prototype, and we have begun narrowing down our goals for the front end.

### Changes to existing documents

Kristen edited our proposal to include a clearer baseline for our scalable features, and adjusted our projected risks. 

Kristen added a privacy policy to the team charter, and Kayley added more detail to our team strengths and weaknesses section.

Our standards and procedures document had an update to the version control section, which is when making a pull request make sure review is selected as the ‘version control team’.

### New documents started

Kristen and Maddie have begun working on the requirements document and the design document. 

The requirements document has the following sections:

* Known Issues/Omissions   
* Product Overview  
* Product features and behavior  
* User interface and navigation  
* Use cases/scenarios  
* Non-functional requirements  
* Feature prioritization  
* Glossary  
* Appendices 

The first draft of our requirements document is completed apart from some missing diagrams and elaboration on a few key concepts. The glossary will be a work in progress until completion, but has all the current necessary information. 

The design document is currently a skeleton of the required categories and information. We allocated a meeting specifically to figuring out the design, and then individually made our own DFD’s of what we thought the information from our brainstorm looked like. Timber then combined our individual versions into one diagram so we have one specific goal for how the product should be structured. This will help us in fleshing out the design document, which will be a priority in the next phase.

### Progress in the Prototype

The prototype currently features a basic version of the adventuring aspect of the game loop. This is achieved via a set of classes: Room, Action, Command, and GameState. Currently, it’s all written in pure C++, with a simple command line interface. The commands are the methods by which the character interacts with and moves through the world. A few potential commands are: open doors, unlock doors, collect items, search surroundings, change rooms. As it stands, only a command to move between rooms is implemented. A simple proof of concept tree of three rooms utilizes this move command.  
The prototype is now in a stage where development can be split up and tackled by different people, with a unifying framework to work together in.  

### Front End Research

Kayley started front end research, and we have opted to go for libraries rather than using a full on game engine. We are leaning towards the raylib library, as it seems to have the support we want for a minimal 2D display. Using a library is beneficial because the learning curve of a game engine at this point would be a reach for the amount of time we have remaining in the semester. 