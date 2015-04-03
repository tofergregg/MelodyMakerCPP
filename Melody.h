//
//  Melody.h
//  MelodyMaker
//
//  Created by Chris Gregg on 3/19/15.
//

#ifndef __MelodyMaker__Melody__
#define __MelodyMaker__Melody__

#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

class Melody {
public:
        void addNote(Note note);
        void play();
        std::string toString();
        void reverse();
        double getTotalDuration();
        void changeTempo(double tempo);
        void append(Melody other);
        
        void setTitle(std::string title);
        std::string getTitle();
        
        void setArtist(std::string artist);
        std::string getArtist();
        void octaveDown();
        void octaveUp();

private:
        std::string artist,title;
        Queue song;
};

#endif /* defined(__MelodyMaker__Melody__) */
