//
//  Beep.h
//  MelodyMaker
//
//  Created by Chris Gregg on 3/20/15.
//

#ifndef __MelodyMaker__Beep__
#define __MelodyMaker__Beep__

#include <stdio.h>
#include "Note.h"
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <queue>
#include <cmath>

const int AMPLITUDE = 28000;
const int FREQUENCY = 44100;

struct BeepObject
{
        double freq;
        int samplesLeft;
};

class Beeper
{
private:
        double v;
        std::queue<BeepObject> beeps;
public:
        Beeper();
        ~Beeper();
        void beep(Note note);
        void beep(double freq, int duration);
        void generateSamples(Sint16 *stream, int length);
        void wait();
        double freq_from_pitch(Note note);
};


#endif /* defined(__MelodyMaker__Beep__) */
