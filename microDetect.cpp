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
   _linit = _level;
   Serial.print("init sonore - l: ");
   Serial.print(_level);
   Serial.print(" diff:");
   Serial.println(_leveldiff);
  _lmini = _level - _leveldiff;
  _lmaxi = _level + _leveldiff;
}

void MicroDetect::detect(funcDetect func)
{
  delay(50);
  init();
  delay(50);
  _level = analogRead(_microPin);
  
  if(_level >= _lmaxi || _level <= _lmini) 
  {    
    Serial.print("detection sonore - l: ");
    Serial.print(_level);
    Serial.print(" min:");
    Serial.print(_lmini);
    Serial.print(" max:");
    Serial.print(_lmaxi);
    Serial.print(" init:");
    Serial.println(_linit);
    func();
  }
}
