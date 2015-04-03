# MelodyMakerCPP
Melody Maker translation into C++ from Java
(see http://nifty.stanford.edu/2015/obourn-stepp-melody-maker/)

This program is a translation of the Java "Melody Maker" program written by
Allison Obourn and Marty Stepp and presented at SIGCSE 2015 during the "Nifty
Assignments" session.

Translator: Chris Gregg, Tufts University, cgregg@cs.tufts.edu

Requirements:
	C++ compiler (the current Makefile uses clang++)
	The Simple Directmedia Layer (SDL) Library: https://www.libsdl.org/download-2.0.php
	A sound output device (e.g., headphones or a speaker)

To Make:
	Use provided Makefile: make

Notes:

1. You may have to fiddle around with the SDL library location to get this to
make. For a Mac, Homebrew works well. This has been tested on Linux (Red Hat 6),
but not on Windows.

2. This project includes full Queue and Stack implementations, presumably made
by students. If desired, they can be replaced with STL queues and/or stacks,
with minor changes to the interface (e.g., "is_empty()" is used instead of 
"empty()" and "enqueue()" and "dequeue()" are used instead of "push_back()" and 
"pop()"

3. Melody.cpp is the full solution to the problem, and the project would
presumably be assigned to students without this file.


