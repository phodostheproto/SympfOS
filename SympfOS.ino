//This File is using example code and will be fleshed out once ready

#include <LedControl.h>
#include "Sprites.h"
//PIN DECLARATIONS
const int DIN_PIN = 11;
const int CS_PIN = 7;
const int CLK_PIN = 13;

//SWITCHES FOR REMOTE
const int BOOP2 = A2; //WILL BE USED FOR A CAPACITIVE SENSOR
const int BOOP3 = A3; //WILL BE USED FOR A CAPACITIVE SENSOR
const int FACE_UP = 3;
const int FACE_DOWN=4;
const int RESET = 5;


const int PANELS = 6; //NUMBER OF PANELS IN CIRCUIT
int CASE_TRACK=0;


/*
//Character set !!!!NOTE THEY ARE UPSIDE DOWN!!!!
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const uint64_t IMAGES[] PROGMEM ={
  0x0000000000000000, //Space
  //used in deafaultFace Cycle
  0xfcfecfe7e7cefcf8, //Left Eye1
  0x7fff79391d0e0301, //Left Eye2
  0xfeff9e9cb870c080, //Right Eye2
  0x3f7ff3e7e7733f1f, //Right Eye1
  0x00f8fe3f1f0e0000, //L Blink1    
  0x003f7ff0c0000000, //L Blink2
  0x00fcfe0f03000000, //R Blink2
  0x001f7ffcf8700000, //R Blink2 
  //Dead Face
  0x8142241818244281, //Thinx
  0x1020408080402010, //Thinx1
  0x0804020101020408, //Thinx2
  0x1824428181422418, //Diamond

  0x6699996666999966, //Checker

  //Hypno stuffs
  0x3c66c38181c3663c, //Thick Circle
  0x3c7ec3c3c3c37e3c, //Thicker Circle1
  0x3c7ee7c3c3e77e3c, //Thinker Circle2
  0x3c7effe7e7ff7e3c, //Thicker Circle3
  0x3c7effffffff7e3c, //Solid Circle
  0x3c66dbbdbddb663c, //Double Circle Solid
  0x3c7ec3dbdbc37e3c, //Doted Circle
  0x3c66dba5a5db663c, //Double Circle
  0x3c66c39999c3663c, //Dotted Circle2
  0x0018244242241800, //Small Circle

  //Surprised?
  0x3c4281818181423c, //Empty Circle
  0xc0201010101020c0, //Empty Circle1
  0x0304080808080403, //Empty Circle2

  //Misc
  0x3c4281999981423c, //DottedCircle
  0xc0201090901020c0, //DottedCircle1
  0x0304080909080403, //Dotted Circle2
  0x3c4299999999423c, //Eye Circle
  0xc0209090909020c0, //Eye Circle
  0x0304090909090403, //Eye Circle
  0x3c4299bdbd99423c, //Dotted Eye
  0xc02090d0d09020c0, //Dotted Eye1
  0x0304090b0b090403, //Dotted Eye2

  //Circle Blinks
  0x000000ffff000000, //Dash
  0x000000f0f0000000, //Dash1
  0x0000000f0f000000, //Dash2
  0x000000fcfc000000, //Dash3
  0x0000003f3f000000, //Dash4

  //Text stuffs
  0xc3e77e3c3c7ee7c3, //X
  0xffffc0ffffc0ffff, //E
  0x7effc0cfcfc3ff7e, //G
  0xc3c3c3663c181818, //Y
  0x183c6666ffe7c381, //A
  0xffffc0ffff03ffff, //S
  0xc3e7ffffffdbdbc3, //M
  0xfeffc3ffffc3fffe, //B
  0xffff18181818ffff, //I

  //Confusion
  0xff81bda5a1bf80ff, //Swirl1
  0xff81bda5a5ada1bf, //Swirl2
  0xff01fd85a5bd81ff, //Swirl3
  0xfd85b5a5a5bd81ff, //Swirl4
  0x3cfefececcc0ff7e, //Swirl5
  0x7efec7c7dfdfce40, //Swirl6
  0x7eff0333737f7f3c, //Swirl7
  0x0273fbfbe3e37f7e,  //Swirl8
  //Squares
  0xff818181818181ff, //Large Square
  0x007e424242427e00, //Med Square
  0x00003c24243c0000,  //Small Square

  //DASHES
  0x8844221108040201,
  0x8040201008040201,
  0x8040201088442211,
  0x8844221188442211,
  0x0804020100000000,
  0x0000000080402010,
  0x0804020180402010,
  0x1020408000000000,
  0x1020408001020408,
  0x0000000001020408,
  0x0102040810204080,
  0x0102040811224488,
  0x1122448810204080,
  0xff818181818181ff
};
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//const int IMAGES_LEN = sizeof(IMAGES)/8;
//int RUNNING_FACE = 0;

LedControl display = LedControl(DIN_PIN, CLK_PIN, CS_PIN, PANELS);


void displayImage(uint64_t image, int addr) {
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

  delay(250);
  displayImage(IMAGES[49],0); //49 I, 48 B, 47 M 
  displayImage(IMAGES[49],3); //49 I, 48 B, 47 M 
  delay(250);
  displayImage(IMAGES[48],1); //49 I, 48 B, 47 M
  displayImage(IMAGES[48],4); //49 I, 48 B, 47 M  
  delay(250);
  displayImage(IMAGES[47],2); //49 I, 48 B, 47 M 
  displayImage(IMAGES[47],5); //49 I, 48 B, 47 M 
  delay(250);



  delay(2000);
  clearAll();
}


void setup() {
  clearAll();
  boot();

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



void loop() {
  defaultFaceCycle();

  /*displayImage(IMAGES[i]);
  if (++i >= IMAGES_LEN ) {
    i = 0;
  }*/
}