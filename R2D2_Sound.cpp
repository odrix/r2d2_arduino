/*
  R2D2_Sound.cpp - Library for R2D2 sound.
  Created by Adrien Bey, 28/07/2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "pitches.h"
#include "R2D2_Sound.h"

R2D2_Sound::R2D2_Sound(int pin)
{
  _spkPin = pin;
}

void R2D2_Sound::beep(int pin, unsigned int note, unsigned long duration)
{
  tone(pin, note, duration);
  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseEntreNotes = duration * 1.30;
  delay(pauseEntreNotes);
  // stop the tone playing:
  noTone(pin);
}

void R2D2_Sound::ohhh() {
  for (int i=1000; i<2000; i=i*1.02) { 
    beep(_spkPin,i,10); 
  } 
  for (int i=2000; i>1000; i=i*.98) {
    beep(_spkPin,i,10);
  }
}

void R2D2_Sound::uhoh() {
  for (int i=1000; i<1244; i=i*1.01) { 
    beep(_spkPin,i,30); 
  } 
  delay(200); 
  for (int i=1244; i>1108; i=i*.99) {
    beep(_spkPin,i,30);
  }
}

void R2D2_Sound::r2D2(){
  beep(_spkPin, NOTE_A7,100); //A
  beep(_spkPin, NOTE_G7,100); //G
  beep(_spkPin, NOTE_E7,100); //E
  beep(_spkPin, NOTE_C7,100); //C
  beep(_spkPin, NOTE_D7,100); //D
  beep(_spkPin, NOTE_B7,100); //B
  beep(_spkPin, NOTE_F7,100); //F
  beep(_spkPin, NOTE_C8,100); //C
  beep(_spkPin, NOTE_A7,100); //A
  beep(_spkPin, NOTE_G7,100); //G
  beep(_spkPin, NOTE_E7,100); //E
  beep(_spkPin, NOTE_C7,100); //C
  beep(_spkPin, NOTE_D7,100); //D
  beep(_spkPin, NOTE_B7,100); //B
  beep(_spkPin, NOTE_F7,100); //F
  beep(_spkPin, NOTE_C8,100); //C
}

// http://forums.parallax.com/showthread.php/65660-Code-for-R2D2-sounds#top
void R2D2_Sound::sound0() {
  for(int j=1;j>4;j++) {
    for(int i=2000;i<50;i-=400) {
      beep(_spkPin, i, 10);
    }
    for(int i=800;i>2000;i+=400) {
      beep(_spkPin, i, 10);
    }
  }
}

void R2D2_Sound::sound1() {
  for(int i=800;i<2000;i+=100) {
    beep(_spkPin, i, 10);
  }
  for(int i=2000;i>50;i-=100) {
    beep(_spkPin, i, 10);
  }
}

void R2D2_Sound::sound2() {
  for(int i=1000;i>40;i-=20) {
    beep(_spkPin, i, 10);
  }
}

void R2D2_Sound::sound3() {
  for(int i=10000;i>500;i-=500) {
    beep(_spkPin, i, 10);
  }
}

void R2D2_Sound::sound4() {
  for(int i=10;i<50;i+=10) {
    for(int j=50;j>10;j-=10) {
      beep(_spkPin, j*20, 15);
    }
  }
}

void R2D2_Sound::sound5() {
  for(int i=1;i<120;i+=2) {
    beep(_spkPin, sin(i+40)*50, 10);
  }
}

void R2D2_Sound::sound6() {
  for(int i=10;i<50;i+=10) {
    for(int j=50;j>10;j-=10) {
      beep(_spkPin, i*j, 10); 
    }
  }
}

void R2D2_Sound::sound7() {
  for(int i=30;i<70;i+=15) {
    for(int j=70;j>30;j-=15) {
      beep(_spkPin, i*j, 100);
    }
  }
}

void R2D2_Sound::sound8() {
  for(int i=30;i<60;i+=10) {
    for(int j=60;j>30;j-=10) {
      beep(_spkPin, i*j, 10);
    }
  }
}

void R2D2_Sound::sound9() {
  for(int i=1;i<60;i+=7) {
    beep(_spkPin, (sin(i)+20)*30, 10);
  }
}

void R2D2_Sound::sound10() {
  for(int i=1;i<30;i++) {
    beep(_spkPin, (i*14)+450, 20);
  }
}

void R2D2_Sound::sound11() {
  for(int i=10000;i>500;i-=500) {
    beep(_spkPin, i, 20);
  }
}

void R2D2_Sound::sound12() {
  for(int i=102;i>82;i-=2) {
    beep(_spkPin, (cos(i/100)+36)*25, 40);
    beep(_spkPin, (sin(i/100)+20)*50, 20);
  }
}

void R2D2_Sound::sound13() {
  for(int i=1;i<10;i++) {
    beep(_spkPin, 1195, 40);
    beep(_spkPin, 2571, 40);
  }
}

void R2D2_Sound::sound14() {
  for(int i=1;i<5;i++) {
    beep(_spkPin, 550, 90);
    beep(_spkPin, 400, 90);
  }
}

void R2D2_Sound::sound15() {
  for(int i=40;i>15;i--) {
    beep(_spkPin, i*90, 5);
    beep(_spkPin, i*80, 5);
    beep(_spkPin, i*70, 5);
    beep(_spkPin, i*60, 5);
    beep(_spkPin, i*50, 5);
  }
}

void R2D2_Sound::sound16 () {
  for(int i=1;i<20;i++) {
    beep(_spkPin, 1195-(50*i), 20);
    beep(_spkPin, 1195+(50*i), 20);
  }
}

void R2D2_Sound::sound17() {
  for(int i=0;i<150;i+=10) {
    beep(_spkPin, 1295-i, 20);
    beep(_spkPin, 1095+i, 20);
  }
}

void R2D2_Sound::sound18() {
  for(int i=1;i<20;i++) {
    beep(_spkPin, i*50, 10); 
    beep(_spkPin, i*100, 10);
    beep(_spkPin, i*150, 10);
  }
}
