/*
  R2D2_Sound.h - Library for R2D2 sound.
  Created by Adrien Bey, 28/07/2014.
  Released into the public domain.
*/
#ifndef R2D2_Sound_h
#define R2D2_Sound_h

#include "Arduino.h"
#include "pitches.h"

class R2D2_Sound
{
  public:
    R2D2_Sound(int pin);
    void ohhh();
    void uhoh();
    void r2D2();
    void sound0();
    void sound1();
    void sound2();
    void sound3();
    void sound4();
    void sound5();
    void sound6();
    void sound7();
    void sound8();
    void sound9();
    void sound10();
    void sound11();
    void sound12();
    void sound13();
    void sound14();
    void sound15();
    void sound16();
    void sound17();
    void sound18();
  private:
    int _spkPin;
    void beep(int pin, unsigned int note, unsigned long duration);
};

#endif
