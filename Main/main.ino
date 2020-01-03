#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;

#include <FreeDefaultFonts.h>

#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410

void setup(void)
{
    Serial.begin(9600);
    uint16_t ID = tft.readID();
    if (ID == 0xD3) ID = 0x9481;
    tft.begin(ID);
    tft.setRotation(0);
    delay(50);
    tft.fillScreen(BLACK);
    startupTEXT();

    for(int i=0; i<300; i=i+2){
      if(i==0){
        delay(1000);
      }
      if(i==200){
        delay(1500);
      }
      tft.fillRect(0,300, i, 10, WHITE);
      delay(50);
    }
}

void loop(void)
{

  

 

}
void startupTEXT(void){
    tft.setTextColor(WHITE);
    tft.setTextSize(4);
    tft.setCursor(35 , 90);
    tft.print("Welcome");
    tft.setTextSize(2);
    tft.setCursor(40, 150);
    tft.print("Developed by:");
    tft.setTextSize(1);
    tft.setCursor(50, 200);
    tft.print(" The Superior Major");  
}
