//
//  helperfuncs.cpp
//  MelodyMaker
//
//  Created by Chris Gregg on 3/20/15.
//  Copyright (c) 2015 Chris Gregg. All rights reserved.
//

#include "helperfuncs.h"

// prints out an introduction describing how to use the program
void intro() {
        std::cout << "Welcome to MelodyMain. Type the word in the ";
        std::cout << "left column to do the action on the right" << std::endl;
        std::cout << "load       : load a new input file" << std::endl;
        std::cout << "save       : output to a file" << std::endl;
        std::cout << "print      : prints the contents of the last loaded song" << std::endl;
        std::cout << "play       : play the last loaded song" << std::endl;
        std::cout << "reverse    : reverse the last loaded song" << std::endl;
        std::cout << "duration   : print out the length of the last loaded song in seconds" << std::endl;
        std::cout << "tempo      : change the speed by a percentage" << std::endl;
        std::cout << "append     : appends notes from a second melody to the loaded one" << std::endl;
        std::cout << "octaveup   : increases the octave by 1 step" << std::endl;
        std::cout << "octavedown : decreases the octave by 1 step" << std::endl;
        std::cout << "quit       : exit the program" << std::endl;
}

Note stringToNote(std::string s) {
        Note note;
        std::string delimiters = " ";
        size_t current;
        size_t next = -1;
        int noteCount = 0;
        do
        {
                current = next + 1;
                next = s.find_first_of( delimiters, current );
                std::string field=s.substr( current, next - current );
                
                // strip newlines
                field.erase(std::remove(field.begin(), field.end(), '\n'), field.end());
                field.erase(std::remove(field.begin(), field.end(), '\r'), field.end());
                
                if (field==" " or field=="\t" or field=="") continue;
                
                switch(noteCount) {
                        case 0: // duration in seconds
                                note.setDuration(atof(field.c_str()));
                                break;
                                
                        case 1: // note
                                if (field=="A") note.setPitch(Note::A);
                                else if (field=="B") note.setPitch(Note::B);
                                else if (field=="C") note.setPitch(Note::C);
                                else if (field=="D") note.setPitch(Note::D);
                                else if (field=="E") note.setPitch(Note::E);
                                else if (field=="F") note.setPitch(Note::F);
                                else if (field=="G") note.setPitch(Note::G);
                                break;
                                
                        case 2: // octave
                                note.setOctave(atoi(field.c_str()));
                                break;
                                
                        case 3: // accidental
                                if (field=="NATURAL") note.setAccidental(Note::NATURAL);
                                else if (field=="FLAT") note.setAccidental(Note::FLAT);
                                else if (field=="SHARP") note.setAccidental(Note::SHARP);
                                break;
                                
                        case 4: // repeat
                                if (field=="false") note.setRepeat(false);
                                else if (field=="true") note.setRepeat(true);
                                break;
                }
                //std::cout << current << ": '" << field << "'" << std::endl;
                noteCount++;
        }
        while (next != std::string::npos);
        return note;
}

void loadFile(Melody &melody) {
        std::cout << "File name? ";
        std::string filename;
        std::cin >> filename;
        std::string line;
        std::ifstream myfile (filename.c_str());
        if (myfile.is_open())
        {
                while (getline (myfile,line))
                {
                        melody.addNote(stringToNote(line));
                }
                myfile.close();
        }
        
        else std::cout << "Unable to open file!\n\n";
}

void saveFile(Melody &melody) {
        // saves the song to a file
        std::cout << "File name? ";
        std::string filename;
        std::cin >> filename;
        std::string line;
        std::ofstream myfile (filename.c_str());
        if (myfile.is_open())
        {
                myfile << melody.toString();
                myfile.close();
        }
        
        else std::cout << "Unable to open file!\n\n";
}

void testSound() {
        SDL_Init(SDL_INIT_AUDIO);
        
        Beeper b;
        
        Note::Pitch allPitches[7] = {Note::C,Note::D,Note::E,Note::F,Note::G,Note::A,Note::B};
        
        for (int octave=3;octave<=8;octave++) {
                for (int pitch=0;pitch<7;pitch++) {
                        Note n(500,allPitches[pitch],octave,Note::FLAT,false);
                        std::cout << b.freq_from_pitch(n) << "\n";
                        b.beep(b.freq_from_pitch(n), 250);
                        b.wait();
                        
                        n.setAccidental(Note::NATURAL);
                        std::cout << b.freq_from_pitch(n) << "\n";
                        b.beep(b.freq_from_pitch(n), 250);
                        b.wait();
                        
                        n.setAccidental(Note::SHARP);
                        std::cout << b.freq_from_pitch(n) << "\n";
                        b.beep(b.freq_from_pitch(n), 250);
                        b.wait();
                }
        }
}

