//
//  Note.h
//  MelodyMaker
//
//  Created by Chris Gregg on 3/19/15.
//

#ifndef __MelodyMaker__Note__
#define __MelodyMaker__Note__

#include <iostream>
#include <stdlib.h>

class Note {
public:
        enum Accidental {
                SHARP, NATURAL, FLAT
        };
        
        enum Pitch { // values are half steps above A
                A=0, B=2, C=-9, D=-7, E=-5, F=-4, G=-2, R=10
        };
        
        // Default constructor
        Note();
        
        // pre : duration > 0 and 0 <= octave <= 10, otherwise throws an IllegalArgumentException
        // constructs a note with the provided duration, pitch, octave, accidental
        //       and repeat settings.
        
        Note(double duration, Pitch note, int octave, Accidental accidental, bool repeat);
        
        // pre : duration > 0, otherwise throws an IllegalArgumentException
        // constructs a note with the passed in duration, pitch and repeat settings.
        Note(double duration, Pitch note, bool repeat);
        
        // returns the length of the note in seconds
        double getDuration();
        
        // returns the Accidental value of the note
        Accidental getAccidental();
        
        // returns the octave of the note
        int getOctave();
        
        // returns the pitch of the note (A - G or R of it is a rest)
        Pitch getPitch();
        
        // pre : d must be greater than 0, otherwise an IllegalArgumentException is thrown
        // sets the duration of the note to be the given time
        void setDuration(double d);
        
        // sets the accidental of the note to be the given accidental
        void setAccidental(Accidental a);
        
        // pre : octave must be greater than 0 and less than 10,
        //       otherwise an IllegalArgumentException is thrown
        // sets the octave of the note to be the passed in octave
        void setOctave(int octave);
        
        // sets the pitch of the note to be the passed in pitch
        void setPitch(Pitch pitch);
        
        // sets the repeat of the note to be the passed in repeat
        void setRepeat(bool repeat);
        
        // returns true if the note is the beginning or ending note in a repeated section,
        //       false otherwise
        bool isRepeat();
        
        // returns a string in the format "<duration> <pitch> <repeat>" if the note is a rest,
        //       otherwise returns a string in the format:
        //       "<duration> <pitch> <octave> <accidental> <repeat>"
        //       For example "2.3 A 4 SHARP true" and "1.5 R true".
        std::string toString();
        
        std::string pitch_to_string();
        std::string accidental_to_string();

private:
        Pitch note;
        double duration;
        int octave;
        Accidental accidental;
        bool repeat;
};

#endif /* defined(__MelodyMaker__Note__) */
