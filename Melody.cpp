//
//  Melody.cpp
//  MelodyMaker
//
//  Created by Chris Gregg on 3/19/15.
//

#include "Melody.h"
#include "Beep.h"

#include <sstream>

void Melody::addNote(Note note) {
        song.enqueue(note);
}

void Melody::play() {
        Queue tempQueue;
        Queue repeatQueue;
        bool inRepeat = false;
        bool repeatNow = false;
        Beeper b;
        
        while (!song.isEmpty()) {
                Note tempNote = song.peek();
                if (tempNote.isRepeat() || inRepeat) {
                        if (inRepeat && tempNote.isRepeat()) {
                                // stop repeating
                                inRepeat = false;
                                repeatNow=true;
                        }
                        else {
                                inRepeat=true;
                        }
                        repeatQueue.enqueue(tempNote);
                }
                std::cout << tempNote.toString() << std::endl;
                b.beep(tempNote);
                
                
                tempQueue.enqueue(song.dequeue());
                
                if (repeatNow) {
                        while (!repeatQueue.isEmpty()) {
                                tempNote = repeatQueue.dequeue();
                                std::cout << tempNote.toString() << std::endl;
                                b.beep(tempNote);
                                repeatNow=false;
                        }
                }
        }
        while (!tempQueue.isEmpty()) {
                song.enqueue(tempQueue.dequeue());
        }
}

std::string Melody::toString() {
        std::stringstream ss;
        Queue tempQueue;
        
        while (!song.isEmpty()) {
                Note tempNote = song.dequeue();
                ss << tempNote.toString() << "\n";
                tempQueue.enqueue(tempNote);
        }
        while (!tempQueue.isEmpty()) {
                song.enqueue(tempQueue.dequeue());
        }
        return ss.str();
}

void Melody::reverse() {
        // create a stack for the reverse
        Stack noteStack;
        while(!song.isEmpty()) {
                noteStack.push(song.dequeue());
        }
        while(!noteStack.isEmpty()){
                song.enqueue(noteStack.pop());
        }
}

double Melody::getTotalDuration() {
        Queue tempQueue;
        bool inRepeat = false;
        double totalDuration=0.0;
        
        while (!song.isEmpty()) {
                Note tempNote = song.peek();
                if (tempNote.isRepeat() || inRepeat) {
                        if (inRepeat && tempNote.isRepeat()) {
                                // stop repeating
                                inRepeat = false;
                        }
                        else {
                                inRepeat=true;
                        }
                        totalDuration+=tempNote.getDuration();
                }
                totalDuration+=tempNote.getDuration();
                tempQueue.enqueue(song.dequeue());
                
        }
        while (!tempQueue.isEmpty()) {
                song.enqueue(tempQueue.dequeue());
        }
        return totalDuration;
}

void Melody::changeTempo(double tempo) {
       	// changes tempo by percentage
        // e.g., 50 would make the song 50% faster
        // and 200 would make the song twice as slow
        Queue tempQueue;
        while(!song.isEmpty()) {
                Note tempNote=song.dequeue();
                tempNote.setDuration(tempNote.getDuration()*tempo/100);
                tempQueue.enqueue(tempNote);
        }
        while (!tempQueue.isEmpty()){
                song.enqueue(tempQueue.dequeue());
        }
}

void Melody::append(Melody other) {
        while (!(other.song.isEmpty())) {
                song.enqueue(other.song.dequeue());
        }
}

void Melody::setTitle(std::string title) {
        this->title = title;
}

std::string Melody::getTitle() {
        return title;
}

void Melody::setArtist(std::string artist) {
        this->artist = artist;
}

std::string Melody::getArtist() {
        return artist;
}

void Melody::octaveDown() {
        Queue tempQueue;
        while(!song.isEmpty()) {
                Note tempNote=song.dequeue();
                tempNote.setOctave(tempNote.getOctave()-1);
                tempQueue.enqueue(tempNote);
        }
        while (!tempQueue.isEmpty()){
                song.enqueue(tempQueue.dequeue());
        }
}

void Melody::octaveUp() {
        Queue tempQueue;
        while(!song.isEmpty()) {
                Note tempNote=song.dequeue();
                tempNote.setOctave(tempNote.getOctave()+1);
                tempQueue.enqueue(tempNote);
        }
        while (!tempQueue.isEmpty()){
                song.enqueue(tempQueue.dequeue());
        }
}


