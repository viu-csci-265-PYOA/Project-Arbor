# Project name: code name ARBOR

## Team: Pick Your Own Adventure (PYOA)

## 1. Team Members

- duncan-mcleod-1996: *main contact* <img src="images/Funky-Emu.jpg" alt="Duncan's Image" Style="width:10%; height:auto;">
  - Lead: Project Lead/Testing
  - Understudy(s): Programming understudy
- <img src="images/kayleypfp.jpg" alt="kayley's Image" style="width:10%; height:auto;"> kayley-m:
  - Lead: GUI 
  - Understudy(s): Creative/Narrative
- <img src="images/Kristen1.jpg" alt="KristenM22's Image" style="width:10%; height:auto;"> KristenM22:
  - Lead: Documentation
- <img src="images/maddiemei8-profile.jpg" alt="Maddiemei8's Image" style="width:10%; height:auto;"> Ma:
  - Lead: Narrative
  - Understudy(s): Project Lead/Presentations
- <img src="images/lev.png" alt="Milu's Image" style="width:10%; height:auto;"> milutopaz:
  - Lead: Programming
  - Understudy(s): Version Control
- <img src="images/faol-image-01.jpg" alt="Timber-faol's Image" style="width:10%; height:auto;"> Timber-faol:
  - Lead: Version Control
  - Understudy(s): Presentation

## Table of Contents
1. [ Team Members ](#1-team-members#section1)
2. [ Directory Structure ](#2-directory-structure)
3. [ Project Overview ](#3-project-overview)
4. [ Building Arbor from Source Code ](#4-building-arbor-from-source-code)
   1. [ Windows ](#41-windows)
   2. [ Linus ](#42-linux)
      1. [ None Debian Distro ](#421-for-none-debian-distros)
      2. [ Debian Distros ](#422-debian-distros)
5. [ Running Arbor ](#5-running-arbor)


## 2. Directory Structure

<pre>
<strong>Project-Arbor</strong>
├───<strong>bin</strong>: executable(s).
├───<strong>documentation</strong>: project documents and deliverables.
├───<strong>images</strong>: document related images.
├───<strong>include</strong>: code header files.
├───<strong>lib</strong>: raylib library and dependencies.
├───<strong>resource</strong>: resources for source code to push/pull from.
│   ├───<strong>narrative</strong>
│   │   ├───<strong>lvl1_dungeon</strong>
│   │   └───<strong>lvl2_tavern</strong>
│   └───<strong>save</strong>
├───<strong>src</strong>: .cpp files.
│   └───<strong>raylib</strong>: raylib specific .c/.cpp files
└───<strong>test</strong>: contains relevant copies of code for testing.
</pre>

## 3. Project Overview

Arbor is a single player, text-based game, where the user is faced with different choices that guide the overarching story. Each action the user selects has the possibility of leading them down a specific branch of the game's narrative tree, allowing them to reach good, neutral or evil endings as well as customize the path that leads them there. Arbor is aimed at users who enjoy the fantasy genre and narrative driven content.

Arbor is set in a realm beset by magical unrest, rivers run green, once fertile fields have become arid, and violent storms roll across the land. The user awakes in a dungeon with no memory of how they came to be there and only a mysterious amulet to guide their way. Will they be able to recover their memories and unravel the mystery, or will they too succumb to the dark magic seeping into the land?

The objective of the game is to reach one of the three main narrative conclusions. The likelihood of reaching one of these endings is based upon the quality of the user’s decisions throughout the game. For instance, when faced with gathering information from one of the game’s NPCs, does the player attempt to befriend them or coerce them? If the player is more likely to choose the former, they proceed further down the branch leading towards the “Good” ending, whereas if they choose the latter, then that would lead down the “Evil” ending branch.

## 4. Building Arbor from Source Code

### 4.1 Windows

Run the command:

```bash
g++ \-o bin/raylib\_main.exe src/raylib/raytest.cpp src/raylib/raygui.cpp \-I include \-L lib \-lraylib \-lgdi32 \-lwinmm
```

* Note, currently only 4 or 6 team members are able to compile on Windows. It’s unclear why this is so, but it is being investigated. We hope no else experiences this, but be aware of it.

### 4.2 Linux

#### 4.2.1 For none-Debian Distros

* install raylib using your respective package manager. See below link for details and see section Install on GNU Linux:

[https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) 

Run the command:

```bash
g++ \-o bin/linux\_arbor.exe src/main.cpp src/rayGameManager.cpp src/RoomManager.cpp \-I include \-lraylib \-lGL \-lm \-lpthread \-ldl \-lrt \-lX11
```

#### 4.2.2 Debian Distros

If you are running a Debian distro, good luck. We haven’t been able to get it to compile on Debian distros. A couple of developer tried instead the recommended package from link above, but without success. They would get the following error when running the none-Debian distro compile command:

```bash
/usr/bin/ld: warning: rglfw.o: missing .note.GNU-stack section implies executable stack
/usr/bin/ld: NOTE: This behaviour is deprecated and will be removed in a future version of the linker
...
mutiple line regarding undefined references between /user/bin/ld and lib/raylib.a
...
lib/libraylib.a(rcore.o):rcore.c:(.pdata+0x0): dangerous relocation: collect2: fatal error: ld terminated with signal 11 [Segmentation fault], core dumped
compilation terminated.
```
Current hypothesis is not using the correct dynamic compiler linkers for a dynamically installed raylib package (ie: installation being on the repo instead of usr).


## 5. Running Arbor

On Windows, run:

```bash
arbor.exe
```
* A couple of developer when trying to run get a warning about missing files. Those files are:
  * libgcc_s_seh-1.dll and
  * libstdc++-6.dll
It's unclear at this time why this is so when the remaining developers can run Arbor just fine.

On Linux, run:

```bash
linux\_arbor.exe
```
* when trying to run this on Debian distro, the following error occurs:

```bash
./bin/linux_arbor.exe: error while loading shared libraries: libraylib.so.550: cannot open shared object file: No such file or directory
```
  The reason for this is in active investigation, but current hypothesis is libraylib.so is missing in the lib directory. Other cause could be not using proper linker during compile for a dynamic raylib package.

For Wine on Linux, run:

```bash
wine arbor.exe
```

* Note, this method hasn’t been tested, so result may vary.