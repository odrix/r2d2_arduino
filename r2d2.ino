#include "R2D2_Sound.h"
#include "stepMotor.h"
//#include "StackArray.h"
//#include "delegate.h"
#include "microDetect.h"

int speakerPin = 8;
int ledPin = 6;

//int ledVert = 6;
int ledBleu = 5;
//int ledJaune = 4;
//int ledRouge = 3;
int pause = 0;

boolean secondInit = false;

R2D2_Sound bouche(speakerPin);
StepMotor tete(9, 10, 11, 12);
MicroDetect oreille(A1, 7);

void clignote (int led, int duree, int quantite)
{
  for(int i=0;i<quantite;i++)
  {
    digitalWrite(led, HIGH);
    delay(duree);
    digitalWrite(led, LOW);
    delay(duree);
  }
}

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
  Serial.println("<parle>");
  bouche.ohhh();
  tete.clockwise(70);ledRandForce();
  tete.anticlockwise(100);ledRandForce();
  tete.clockwise(30);ledRandForce();
  Serial.println("</parle>");
}

void activeLog()
{
   Serial.begin(9600);
}


void setup() {
  randomSeed(analogRead(0));
  activeLog();
  
  tete.init();
  oreille.init();
  bouche.sound3();
}

int seq[2][12] = {{40, -130, 60, -30, 100, -30, 70, -50, 20, -90, 55, -15},
{-150, 100, -80, 30, -40, 80, -100, 30, -60, 160, -90, 120}};

void loop() {
  for(int j=0;j<2;j++) {
    Serial.print("sequence ");
    Serial.println(j);
    for(int i=0;i<12;i++) {
      if(seq[j][i] > 0){
        tete.clockwise(seq[j][i]);
      } else {
        tete.anticlockwise(-1 * seq[j][i]);
      }
      ledRand();
      oreille.detect(parle);
      
      /*if(!secondInit && i == 6) {
        oreille.init();
        secondInit = true;   
      }
      else if(secondInit)
      {
        oreille.detect(parle);
      } */
    }
      
    Serial.println("sequence fini");
    pause = random(100, 400);
    clignote(ledPin, pause, random(2, 6));
  }
}

