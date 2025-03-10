// Program to demonstrate the MD_Parola library
//
// Simplest program that does something useful - Hello World!
//
// NOTE: MD_MAX72xx library must be installed and configured for the LED
// matrix type being used. Refer documentation included in the MD_MAX72xx
// library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
//#define MAX_DEVICES 1
//#define CLK_PIN   12
//#define DATA_PIN  13
//#define CS_PIN    4

// Hardware SPI connection
//MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
// Arbitrary output pins

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 6
#define CLK_PIN   12  //BLUE
#define DATA_PIN  11  //GREEN
#define CS_PIN    10  //RED

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup(void)
{
  P.begin();
  P.displayText("O12345", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
}

void loop(void)
{
  P.displayAnimate();
}