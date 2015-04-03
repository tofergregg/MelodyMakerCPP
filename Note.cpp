// Melody
//
// Instructor-provided code.
// A Note object represents a musical note in scientific music notation.
// For example, middle C is represented as C4.

#include "Note.h"
#include <sstream>

// default constructor for creating an A4, duration 1 second
Note::Note() {
        note=A;
        duration=1000;
        octave=4;
        accidental=NATURAL;
        repeat=false;
}

// pre : duration > 0 and 0 <= octave <= 10, otherwise throws an IllegalArgumentException
// constructs a note with the provided duration, pitch, octave, accidental
//       and repeat settings.
Note::Note(double duration, Pitch note, int octave, Accidental accidental, bool repeat) {
        if(duration <= 0 || octave < 0 || octave > 10) {
                std::cout << "Octave out of range!\n";
                exit(-1);
        }
        this->note = note;
        this->duration = duration;
        this->octave = octave;
        this->accidental = accidental;
        this->repeat = repeat;
}

// pre : duration > 0, otherwise throws an IllegalArgumentException
// constructs a note with the passed in duration, pitch and repeat settings.
Note::Note(double duration, Pitch note, bool repeat) {
        *this = Note(duration, note, 0, Note::NATURAL, repeat);
}

// returns the length of the note in seconds
double Note::getDuration() {
        return duration;
}

// returns the Accidental value of the note
Note::Accidental Note::getAccidental() {
        return accidental;
}

// returns the octave of the note
int Note::getOctave() {
        return octave;
}

// returns the pitch of the note (A - G or R of it is a rest)
Note::Pitch Note::getPitch() {
        return note;
}

// pre : d must be greater than 0, otherwise an IllegalArgumentException is thrown
// sets the duration of the note to be the given time
void Note::setDuration(double d) {
        if(d <= 0) {
                std::cout << "Duration is less than zero!\n";
                exit(-1);
        }
        duration = d;
}

// sets the accidental of the note to be the given accidental
void Note::setAccidental(Accidental a) {
        accidental = a;
}

// pre : octave must be greater than 0 and less than 10,
//       otherwise an IllegalArgumentException is thrown
// sets the octave of the note to be the passed in octave
void Note::setOctave(int octave) {
        if(octave < 0 || octave > 10) {
                std::cout << "Octave out of range!\n";
                exit(-1);
        }
        this->octave = octave;
}

// sets the pitch of the note to be the passed in pitch
void Note::setPitch(Pitch pitch) {
        note = pitch;
}

// sets the repeat of the note to be the passed in repeat
void Note::setRepeat(bool repeat) {
        this->repeat = repeat;
}

// returns true if the note is the beginning or ending note in a repeated section,
//       false otherwise
bool Note::isRepeat() {
        return repeat;
}

// returns a string in the format "<duration> <pitch> <repeat>" if the note is a rest,
//       otherwise returns a string in the format:
//       "<duration> <pitch> <octave> <accidental> <repeat>"
//       For example "2.3 A 4 SHARP true" and "1.5 R true".
std::string Note::toString() {
        std::stringstream ss;
        
        if(note == Note::R) {
                ss << duration << " " << note << repeat;
                
                return ss.str();
        } else {
                ss << duration << " "
                        << pitch_to_string()
                        << " " << octave
                        << " " << accidental_to_string()
                        << " " << (repeat ? "true" : "false");
                return ss.str();
        }
}

std::string Note::pitch_to_string() {
        std::string str;
        switch (note) {
                case Note::A : str="A";
                        break;
                case Note::B : str="B";
                        break;
                case Note::C : str="C";
                        break;
                case Note::D : str="D";
                        break;
                case Note::E : str="E";
                        break;
                case Note::F : str="F";
                        break;
                case Note::G : str="G";
                        break;
                case Note::R : str="R";
                default:
                        str="N"; // not a note
        }
        return str;
}

std::string Note::accidental_to_string() {
        std::string str;
        switch (accidental) {
                case Note::FLAT : str="Flat";
                        break;
                case Note::NATURAL : str="Natural";
                        break;
                case Note::SHARP : str="Sharp";
                        break;
                default:
                        str="X"; // not an accidental
        }
        return str;
}
