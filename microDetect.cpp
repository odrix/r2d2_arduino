#include "microDetect.h"
#include "Arduino.h"

MicroDetect::MicroDetect(int microPin, int diffLevel)
{
  int _level;
  _microPin = microPin;
  _leveldiff = diffLevel;
}

void MicroDetect::init()
{
   _level = analogRead(_microPin);
  _lmini = _level - _leveldiff;
  _lmaxi = _level + _leveldiff;
}

void MicroDetect::detect(funcDetect func)
{
  _level = analogRead(_microPin);
  
  if(_level >= _lmaxi || _level <= _lmini) 
  {
    if(_debug)
    {
      Serial.print("bruit détecté: ");
      Serial.println(_level); 
    }
    func();
  }
}

void MicroDetect::setDebug(boolean debug)
{
  _debug = debug;
}
