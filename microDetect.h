/*
  microDetect.h - Library to detect diff sonor level.
  Created by Adrien Bey, 08/09/2014.
  Released into the public domain.
*/
#ifndef MicroDetect_h
#define MicroDetect_h

#include "Arduino.h"

typedef void (*funcDetect)();

class MicroDetect
{
  public:
    MicroDetect(int microPin, int diffLevel);
    void init();
    void detect(funcDetect func);
    void setDebug(boolean debug);
  private:
    boolean _debug;
    int _microPin;
    int _level, _lmini, _lmaxi;
    int _leveldiff;
};

#endif
