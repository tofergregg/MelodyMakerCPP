// Melody
//
// Instructor-provided code.
// This program tests your Melody object on any file you want.
//
// When the program starts, type load and enter the name of the file you want to play
// You can then type play to hear it or any of the other commands to test you Melody's
// other functionality.

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Beep.h"
#include "helperfuncs.h"

//#define TEST_SOUND

int main(int argc, char* argv[])
{
        (void)argc;
        (void)argv;
        
#ifdef TEST_SOUND
        testSound();
#else
        Melody *melody = NULL;
        intro();
        
        std::string command = "";
        
        while (command != "quit") {
                std::cout << "What would you like to do? ";
                std::cin >> command;
                std::transform(command.begin(), command.end(), command.begin(), ::tolower);
                if (!(command == "quit" or command == "load") and melody==NULL) {
                        std::cout << "You must load a song before trying to manipulate it\n";
                }
                else if (command=="load") {
                        if (melody) delete melody; // delete if already created.
                        melody = new Melody();
                        loadFile(*melody);
                }
                else if (command=="print") {
                        std::cout << melody->toString() << "\n";
                }
                else if (command=="play") {
                        melody->play();
                }
                else if (command=="reverse") {
                        melody->reverse();
                }
                else if (command=="duration") {
                        std::cout << melody->getTotalDuration() << "\n";
                }
                else if (command=="tempo") {
                        double tempo;
                        std::cout << "Percentage? ";
                        std::cin >> tempo;
                        
                        melody->changeTempo(tempo);
                }
                else if (command=="octaveup") {
                        melody->octaveUp();
                }
                else if (command=="octavedown") {
                        melody->octaveDown();
                }
                else if (command=="append") {
                        Melody newMelody;
                        loadFile(newMelody);
                        melody->append(newMelody);
                }
                else if (command=="save") {
                        saveFile(*melody);
                }
        }
        delete melody;
#endif
        return 0;
}
