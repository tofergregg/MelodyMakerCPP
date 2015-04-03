//
//  helperfuncs.h
//  MelodyMaker
//
//  Created by Chris Gregg on 3/20/15.
//  Copyright (c) 2015 Chris Gregg. All rights reserved.
//

#ifndef __MelodyMaker__helperfuncs__
#define __MelodyMaker__helperfuncs__

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Note.h"
#include "Melody.h"
#include "Beep.h"

void intro();
void loadFile(Melody &melody);
void saveFile(Melody &melody);
Note stringToNote(std::string s);
void testSound();

#endif /* defined(__MelodyMaker__helperfuncs__) */
