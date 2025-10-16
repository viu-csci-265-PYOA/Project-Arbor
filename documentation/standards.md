# CSCI 265 Team Standards and Processes (Phase 2\)

## Team name: Pick Your Own Adventure (PYOA)

## Key contact person and email:

* Duncan McLeod, [duncanmcleod1996@gmail.com](mailto:duncanmcleod1996@gmail.com) 

## Document Structure:

In this document we will outline the core three areas of standards and processes:

* Documentation standards and processes  
* Coding standards and processes  
* Version control standards and processes

Each section details how we will enforce these standards and processes.

## Documentation standards and processes

A ‘Documentation’ directory will be maintained in the team repository. We will maintain all files listed below within that directory. Submission of these files will be done via ‘pull request’, which is mentioned later on in the version control standards.

* [charter.md](http://charter.md)  
* [proposal.md](http://proposal.md)  
* [standards.md](http://standards.md)  
* [projUpdate.md](http://projupdate.md) 

An ‘Images’ subdirectory will be maintained within our documents directory, it will be the location for any images referenced through our .md files. Image names must be descriptive and include the name of the relevant document and sufficient description as to what the image is.

For all documents required, we will be following the layout of the given sample document as close as possible, with minor adjustments made if needed. Any adjustments will follow the same heading and layout choices to maintain consistency.

For each document with components that will be written separately, we have constructed a peer review process to take place after first drafts.

* Each section is drafted individually  
* Assignment of specific team member(s) to review each section for:  
  * Clarity/readability  
  * Spelling & grammar  
  * Adherence to our style & format guidelines  
  * Accuracy of technical content  
* Feedback recorded in comments (docs or through git pull requests)  
* Original author revises their section based on the feedback given

For team members to confirm each review:

* Correct terminology  
* Proper grammar/spelling  
* Adherence to style template  
* Code snippets all compile/make sense  
* Diagrams/images are labeled and accurate


Documents composed by the team will be checked for correct spelling and grammar using basic proofreading tools such as spellcheck and Grammarly. Full sentence explanations will always be used, and confusing short hand and abbreviations will be avoided. All documents created by the team will also use consistent terminology.

The team will decide on a structure template for each document, which will include the content of the sections and the headings, as well as a consistent format for numbering and bullet points. Documents will be divided into sections and assigned to different team members to be completed before an internal deadline decided by the team. The sections will then be merged into a single master file, and a final consistency review will be performed before submission.

Files and documents in the google drive will be kept organized and stored in the correct folders. Meeting notes will be named using a standard YYYY-MM-DD format, and will include a short descriptor of the main item discussed in each meeting. This will allow team members to easily reference meeting notes and quickly find relevant information needed to complete their tasks. 

Meeting notes will follow a standard template agreed on by the team. The template will break up the information discussed during the meeting and make it easier to reference later. Relevant context will be given for all discussions, which will keep the notes understandable for any members not present at the meeting.

An update document will be kept in the Google Docs folder for each phase of the project. As each team member completes a task for the project, they will record it in the update document. Near the end of the phase, the document will be converted to a markdown file and formatted correctly for submission.

During the week of the formal presentation for each phase, the team members will complete a set of bullet points for their slides and submit them to the presentation lead by Wednesday at 4:00PM. Presentation scripts will be completed prior to the Thursday meeting to give the team time to do a final run through.

## Coding standards and processes

**Formatting**

The format of our code will be focused on comprehension to accommodate for the large number of members working on the project and the minimal experience with coding collaboration.   
The key features we will be implementing to achieve this will be:

* block statements: indent with a 4 space tab  
* operators: spaces between variables and operators  
* line character limit: 80  
* Variable declaration: as close to use as possible (avoid declaring all variables at the start)  
* Variable initializing: initialize in declaration  
* Repetition: if code repeats, convert it to a function  
* Curly braces: Place curly braces on the same line as the function, class, etc.  
* Global variables: Avoid global variables, aim to use namespaces.

**Naming Conventions**

In order to easily distinguish between classes, variables and structs, we will be assigning them different naming conventions.

* Variables: snake\_case  
* Classes and structs: PascalCase  
* Variable naming: Choose descriptive names and limit abbreviations   
  * For instance, a for loop should use 'i' for its index, or an 'add()' function can use 'x' and 'y'.

**Object-oriented programing (OOP)**

* Prefer composition over inheritance.  
* Any inheritance must be public.

**Overlap avoidance (Includes)**

Any symbol used in a file should be included with an ‘\#include’ statement in that file, even if another file included happens to include that symbol. In other words, do not use transitive inclusions.

* Header files should use \#define guards.  
* Define guard format: \<PATH\>\\\_\<FILE\>\\\_H  
  * For instance, SRC\\\_ACTION\\\_H.

## Version control standards and processes

Team PYOA’s GitHub repository is called Project-Arbor under the organization viu-csci-265-PYOA. As version control lead and understudy, Timber and Milu, will be responsible for maintaining the repository. These positions may change throughout the course of the project. Each member responsible for maintaining the repository will be a member of the VERSION CONTROL team.

Each team member will contribute to development, using their locally cloned repository. Team members are encouraged to keep a daily workflow consistent with checking the Pull-Request discord channel and pulling new content to bring their repository up to dev’s current state before beginning work. Team members should commit often and submit pull requests when they believe their work is ready to be merged to development.

The project will have three core branches: main, development, and sandbox. The general purpose of the branches is as follows:

* **main**: the most stable branch, which has been tested and will be used to mark the latest production version of the project. This branch is meant for the end user, marketing, and instructor marking.

  * **main/release**: sub-branches of main that mark the version/releases of the project. This sub-branch is not meant for active development, but end user and debugging. \[May not be implemented due to semester time constraints\].

* **development** (a.k.a **dev**): branches off the latest version of main, this is the active development branch. Code here is being worked on, but has not yet been tested in sandbox.

* **sandbox**: the branch for testing or debugging. Depending on the need, sandbox will be branched off the latest version of development, main, or a main/release branch. After the branch has completed testing and is merged to main, the branch is deleted.

**Branch Guidelines**

With respect to **branch naming**: 

* A branch name must include its parent’s branch name (main, dev, sandbox) followed by a descriptive sub-branch name that provides clear context and purpose. For example:  
  * “dev/feature/user-authentication” explains that the user-authentication feature is actively being worked on.

  * “sandbox/dev/user-authentication” explains that the user-authentication feature is being tested or debugged.

* To maintain naming consistency, branch names must adhere to the following conventions:  
  * Use lowercase throughout, no uppercase characters. Numbers are allowed, but should never start a branch name.

  * A forward slash “/” is used to separate branch and sub-branch names

  * No whitespace is allowed. The special character, dash “-” to be used for whitespace(s). No other special characters are permissible.

With respect to **branch logic**: 

* New branches will primarily be created for developing, testing, and marking releases.  
  * For active development, a new branch is created for a specific feature to be worked on. Once a feature is complete and found stable, the branch is merged to development and then deleted.

  * For testing and debugging, a sandbox branch is created. Once the branch passes testing it is then merged to main or development, then deleted.

  * For releases, a sub-branch of main is created at the deliverable deadline, prior to submission. Naming convention for releases are as follows:

    * A leading zero or character indicates a pre-production release, while a non-negative indicates a production release.

    * After the leading digit, a date convention is used: yy.mm.dd where any value less than 10 shall be preceded by a “0”.

    * For example, a pre-production release on October 1st, 2025 would appear as: main/release/0.25.10.01

**Commit Guidelines**

Team members are encouraged to commit regularly. Each commit represents one clear task or fix. No monolithic commits; keep them small and frequent. Frequent commits make testing easier and lower merge conflicts. In addition, rollback is more straightforward if a bug is detected.

Commit messages should adhere to the following conventions:

* Provide a description: explains why and what is being committed, i.e. reference to the feature.  
* Keep it brief: commit messages should be clear, understandable and concise, without the need for outside context.   
* Phrase as an Order: team members should use present tense and imperative language in their commit messages.  
* For example, a commit message for a commit that added a login flow feature would appear like: “Add login flow”

“Writing commit messages in this way forces software teams to understand the value an add or fix makes to the existing code line. If teams find it impossible to find the value and describe it, then it might be worth reassessing the motivations behind the commit.”

	– GitLab: [https://about.gitlab.com/topics/version-control/version-control-best-practices/](https://about.gitlab.com/topics/version-control/version-control-best-practices/)

**Merging Guidelines**

With regards to merging new content into a branch, merges should happen ideally once a week or upon completion of a sub-branch. Pull requests are required for main and development branches. All pull requests should be done for the team member’s cloned branch to development. In sub-branches that do not require pull requests, team members must make coordinated pushes through the team’s Discord channel as noted below:

1. For **pushing** to non-main/development branches: check the “push-pull-request” discord channel to see if anyone has pushed since your last pull of “branch-name”.

   1. If yes:

      1. Pull and resolve conflicts.

      2. Test to ensure code is still functional.

      3. Repeat loop at (1).

   2. If no:

      1. Post “I’m pushing to \[branch-name\].”

      2. Push and fix any conflicts.

      3. Post “I’m done pushing to \[branch-name\].”

      4. Others can now pull the new content and/or push their new content.

2. For **merging** to main/development branches: similarly to pushes in non-main/development branches, check the “push-pull-request” Discord channel to see if anyone has merged since your last pull of “branch-name.”  
   1. If yes:

      1. Pull and resolve conflicts.

      2. Test to ensure code is still functional.

      3. And repeat loop at (2).

   2. If no:

      1. Post “I’m ready to merge branch-name with main/development. @version-members I’m making a pull request.”

      2. Make a pull request on GitHub.

      3. Version control members will review code, then request changes if needed.

      4. The team member will then resolve conflicts and test their code again, repeating the loop at (2).

      5. If no changes are needed, the version control team will merge with the desired branch and post “branch-name successfully merged with main/development. @everyone should pull if they are working off of main/development.”

3. With regards to **code reviews**: 

   1. Code reviews are mandatory before merges can be made to main/development branches. These reviews are done by version control lead or understudy. If neither are able to review, then anyone who can will be placed temporarily under the version control team to complete the review.

   2. Code reviews are not mandatory, but highly encouraged for non-main/development branches. In these cases, the reviewer should be a team member who is familiar with the code in order to quicken the review process.

4. **Merging Strategy**: the team will use the **merge commit** strategy as it’s a simple default choice. Having a full commit history and clear merge boundaries should be an asset for troubleshooting bugs. However, if the commit history becomes too cluttered, the team may change to the squash and merge strategy to reduce clutter and have a linear commit history.

