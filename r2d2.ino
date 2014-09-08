#include "R2D2_Sound.h"
#include "stepMotor.h"
//#include "StackArray.h"
//#include "delegate.h"
#include "microDetect.h"

int speakerPin = 8;
int ledPin = 5;

//int ledVert = 6;
int ledBleu = 6;
//int ledJaune = 4;
//int ledRouge = 3;
int pause = 0;

R2D2_Sound bouche(speakerPin);
StepMotor tete(9, 10, 11, 12);
MicroDetect oreille(A1, 7);

void allume(int led, int duree)
{
  digitalWrite(led, HIGH);
  if(duree > 0) {
    delay(duree);
    digitalWrite(led, LOW);
  }
}

void eteindre(int led)
{
  digitalWrite(led, LOW);
}

/*
FuturAction allume(int led, long duree)
{
  digitalWrite(led, HIGH);
  return  (FuturAction) {millis(), duree, eteindre};
}*/

void ledRandForce()
{
  int duree = random(50, 250);
  int led = random(5, 6);
  allume(led, duree);
}

void ledRand()
{
  int duree = random(50, 350);
  int led = random(4, 7);
  allume(led, duree);
}

void parle()
{
  bouche.ohhh();
  tete.clockwise(70);ledRandForce();
  tete.anticlockwise(100);ledRandForce();
  tete.clockwise(30);ledRandForce();
}


void setup() {
  randomSeed(analogRead(0));
  tete.init();
  oreille.init();
  bouche.sound3();
}

void loop() {
  tete.clockwise(40);ledRand();
  tete.anticlockwise(130);ledRand();
  
  tete.clockwise(60);ledRand();
  tete.anticlockwise(30);ledRand();
  
  tete.clockwise(100);ledRand();
  tete.anticlockwise(30);ledRand();

  oreille.detect(parle);  
  pause = random(150, 400);
  delay(pause);
  
  tete.clockwise(70);ledRand();
  tete.anticlockwise(50);ledRand();
  
  tete.clockwise(12);ledRand();
  tete.anticlockwise(90);ledRand();
  
  tete.clockwise(55);ledRand();
  tete.anticlockwise(15);ledRand();
 
  oreille.detect(parle);   
  pause = random(150, 400);
  delay(pause);
}
