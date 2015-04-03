//
//  Beep.cpp
//  MelodyMaker
//
//  Code borrowed and modified from: http://stackoverflow.com/a/10111570/561677

#include "Beep.h"

void audio_callback(void*, Uint8*, int);

Beeper::Beeper()
{
        SDL_AudioSpec desiredSpec;
        
        desiredSpec.freq = FREQUENCY;
        desiredSpec.format = AUDIO_S16SYS;
        desiredSpec.channels = 1;
        desiredSpec.samples = 2048;
        desiredSpec.callback = audio_callback;
        desiredSpec.userdata = this;
        
        SDL_AudioSpec obtainedSpec;
        
        // you might want to look for errors here
        SDL_OpenAudio(&desiredSpec, &obtainedSpec);
        
        // start play audio
        SDL_PauseAudio(0);
}

Beeper::~Beeper()
{
        SDL_CloseAudio();
}

void Beeper::generateSamples(Sint16 *stream, int length)
{
        int i = 0;
        while (i < length) {
                
                if (beeps.empty()) {
                        while (i < length) {
                                stream[i] = 0;
                                i++;
                        }
                        return;
                }
                BeepObject& bo = beeps.front();
                
                int samplesToDo = std::min(i + bo.samplesLeft, length);
                bo.samplesLeft -= samplesToDo - i;
                
                while (i < samplesToDo) {
                        stream[i] = AMPLITUDE * std::sin(v * 2 * M_PI / FREQUENCY);
                        i++;
                        v += bo.freq;
                }
                
                if (bo.samplesLeft == 0) {
                        beeps.pop();
                }
        }
}

void Beeper::beep(Note note) {
        beep(freq_from_pitch(note),note.getDuration()*1000);
        wait();
}

void Beeper::beep(double freq, int duration)
{
        BeepObject bo;
        bo.freq = freq;
        bo.samplesLeft = duration * FREQUENCY / 1000;
        
        SDL_LockAudio();
        beeps.push(bo);
        SDL_UnlockAudio();
}

void Beeper::wait()
{
        int size;
        do {
                SDL_Delay(20);
                SDL_LockAudio();
                size = (int)beeps.size();
                SDL_UnlockAudio();
        } while (size > 0);
        
}

void audio_callback(void *_beeper, Uint8 *_stream, int _length)
{
        Sint16 *stream = (Sint16*) _stream;
        int length = _length / 2;
        Beeper* beeper = (Beeper*) _beeper;
        
        beeper->generateSamples(stream, length);
}

double Beeper::freq_from_pitch(Note note) {
        // fn = f0 * a^n
        // f0 is the initial frequency. We will use 440Hz
        // a is the twelfth root of 2, or 1.05946309435930
        // n is the number of half steps away from f0 (positive or negative)
        
        double a = 1.05946309435930; // the twelfth root of 2
        double f0 = 440.0; // a440
        
        // Notes: (#=sharp, b=flat), half steps above A
        // C        -9 - beginning of octave
        // C#=Db  -8
        // D        -7
        // D#=Eb  -6
        // E=Fb     -5
        // E#=F     -4
        // F#=Gb  -3
        // G        -2
        // G#=Ab  -1
        // A         0
        // A#=Bb  +1
        // B=Cb     +2
        // B#     +3 - end of octave
        
        // convert pitch, accidental, and octave to steps above A3
        
        //std::cout << note.pitch_to_string() << ", "
        //        << note.accidental_to_string()
        //        << ", " << note.getOctave() << "\n";
        
        // convert pitch to integer number of steps
        int n = note.getPitch();
        if (note.getAccidental() == Note::FLAT) n--;
        if (note.getAccidental() == Note::SHARP) n++;
        
        // figure in octave
        n += 12 * (note.getOctave() - 4);
        
        return f0 * pow(a,n);
        
}
