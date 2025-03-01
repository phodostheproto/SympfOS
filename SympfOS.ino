
//This File is using example code and will be fleshed out once ready
#include <LedControl.h>
#include "Sprites.h"
//PIN DECLARATIONS NANO
const int DIN_PIN = 11; //GREEN WIRE
const int CS_PIN = 7;   //RED WIRE
const int CLK_PIN = 13; //BLUE


//SWITCHES FOR REMOTE
const int BOOP2 = A2; //WILL BE USED FOR A CAPACITIVE SENSOR
const int BOOP3 = A3; //WILL BE USED FOR A CAPACITIVE SENSOR
const int FACE_UP = 3;
const int FACE_DOWN=4;
const int RESET = 5;


const int PANELS = 6; //NUMBER OF PANELS IN CIRCUIT
int CASE_TRACK=0;



//const int IMAGES_LEN = sizeof(IMAGES)/8;
//int RUNNING_FACE = 0;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN, PANELS);


void displayImage(uint64_t image, int addr) {
  /*
   * Used to Display sprites on any one of the 6 displays addressed by the addr
   * Feed a 64bit int into here from an array and use the addr argument to pick the display
   *
  */


  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(addr, i, j, bitRead(row, j));
    }
  }
}

void clearAll(){
  for(int addr=0;addr<7;addr++){
    display.clearDisplay(addr);
    display.shutdown(addr, false);
    display.setIntensity(addr, 1);
  }
}


void boot(){//displays the IBM Logo in a flash

  delay(50);
  displayImage(IMAGES[49],0); //49 I, 48 B, 47 M 
  displayImage(IMAGES[49],3); //49 I, 48 B, 47 M 
  delay(50);
  displayImage(IMAGES[48],1); //49 I, 48 B, 47 M
  displayImage(IMAGES[48],4); //49 I, 48 B, 47 M  
  delay(50);
  displayImage(IMAGES[47],2); //49 I, 48 B, 47 M 
  displayImage(IMAGES[47],5); //49 I, 48 B, 47 M 
  delay(50);



  delay(500);
  //clearAll();
}




/*
void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      display.setLed(0, i, j, bitRead(row, j));
    }
  }
}
*/

void defaultFaceCycle() {
 //Default Animation
  //Display Right Eye
  displayImage(IMAGES[1],1);
  displayImage(IMAGES[2],0);
  //Display Left Eye
  displayImage(IMAGES[3],5);
  displayImage(IMAGES[4],4);

  delay(random(2000,6000)); // Random Begin Blink Tick
  
  displayImage(IMAGES[5],1);
  displayImage(IMAGES[6],0);
  displayImage(IMAGES[7],5);
  displayImage(IMAGES[8],4);
  delay(random(500,1200)); //Random End Blink Tick

}

void emptyEyeCycle() {
 //Default Animation
  //Display Right Eye
  displayImage(RECTS[2],2);
  displayImage(RECTS[2],3);
  displayImage(CIRCLES[11],1);
  displayImage(CIRCLES[12],0);
  //Display Left Eye
  displayImage(CIRCLES[11],5);
  displayImage(CIRCLES[12],4);

  delay(random(2000,6000)); // Random Begin Blink Tick
  
  displayImage(RECTS[6],2);
  displayImage(RECTS[6],3);
  displayImage(RECTS[5],0);
  displayImage(RECTS[4],1);

  displayImage(RECTS[5],4);
  displayImage(RECTS[4],5);
  
  delay(random(500,1200)); //Random End Blink Tick
}
void confusedFace1(){
  //clearAll();

  for(int i=0;i<4;i++){
  //displayImage(CONFUSION[i],0);
  //displayImage(CONFUSION[i],5);
  displayImage(CONFUSION[i],1);
  displayImage(CONFUSION[i],4);
  delay(1);
  }
}
void sayGex(){
  //delay(50);
  displayImage(TEXT[6],0);  
  displayImage(TEXT[3],3);  
  //delay(50);
  displayImage(TEXT[5],1); 
  displayImage(TEXT[2],4); 
  //delay(50);
  displayImage(TEXT[4],2);  
  displayImage(TEXT[1],5); 
  //delay(50);
  delay(500);
  displayImage(TEXT[6],3);  
  displayImage(TEXT[3],0);  
  //delay(50);
  displayImage(TEXT[5],4); 
  displayImage(TEXT[2],1); 
  //delay(50);
  displayImage(TEXT[4],5);  
  displayImage(TEXT[1],2); 
  delay(500);
}

void slashes(){
  //clearAll();

  for(int i=0;i<7;i++){
  //displayImage(CONFUSION[i],0);
  //displayImage(CONFUSION[i],5);
  displayImage(SLASHES1[i],1);
  displayImage(SLASHES2[i],4);
  delay(2000);
  }
}

void randomFaces(){

  displayImage(IMAGES[random(0,80)],0);
  displayImage(IMAGES[random(0,80)],5);
  displayImage(IMAGES[random(0,80)],2);
  displayImage(IMAGES[random(0,80)],3);
  displayImage(IMAGES[random(0,80)],4);
  displayImage(IMAGES[random(0,80)],1);



}

void hypnoFace(){


}
void deadFace(){
 
  displayImage(DEAD_FACE[2],0);
  displayImage(DEAD_FACE[1],1);
  displayImage(DEAD_FACE[5],3);
  displayImage(DEAD_FACE[5],2);
  displayImage(DEAD_FACE[2],4);
  displayImage(DEAD_FACE[1],5);


}

void setup() {
  clearAll();
  boot();
  delay(1000);

  //Display default face first
  displayImage(RECTS[2],2);
  displayImage(RECTS[2],3);
  displayImage(CIRCLES[11],1);
  displayImage(CIRCLES[12],0);
  //Display Left Eye
  displayImage(CIRCLES[11],5);
  displayImage(CIRCLES[12],4);

}
void loop() {

  //emptyEyeCycle(); //THIS IS MY FAVORITE AND NOW DEFAULT FACE
  //randomFaces();

  deadFace();

  //defaultFaceCycle();
  //confusedFace1();
  //sayGex();
  //slashes();
  
  /*displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }*/
}