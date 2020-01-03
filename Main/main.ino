/*
Developed by Patrick Gawel
All right reserverd 2020

*/
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
MCUFRIEND_kbv tft;     //Initlize screen      
#include <TouchScreen.h>
#define MINPRESSURE 200
#define MAXPRESSURE 1000
#include <FreeDefaultFonts.h>

#define BLACK   0x0000   //Define Basic Colors
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410


const int XP = 8, XM = A2, YP = A3, YM = 9; //ID=0x9341     //Calibration Values
const int TS_LEFT = 896, TS_RT = 132, TS_TOP = 80, TS_BOT = 894;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);  //Set Touchscreen Vals
int pixel_x, pixel_y; 

Adafruit_GFX_Button main_but; //Set Button 
void setup(void)
{
    Serial.begin(9600);  //Start Serial
    uint16_t ID = tft.readID();  //Get ID of scren
    if (ID == 0xD3) ID = 0x9481;  //Start Screen at ID location
    tft.begin(ID);
    tft.setRotation(0);  //Set photomode (Landscape/portrait)
    delay(50);
    tft.fillScreen(BLACK);  //Make screen Black
    startupSCREEN();  //Loading screen


}

void loop(void)
{
  int val=Touch_getXY;
  Serial.println(val);
  

 

}
void startupSCREEN(void){
    tft.setTextColor(WHITE);  //Write the Text
    tft.setTextSize(4);
    tft.setCursor(35 , 90);
    tft.print("Welcome");
    tft.setTextSize(2);
    tft.setCursor(40, 150);
    tft.print("Developed by:");
    tft.setTextSize(1);
    tft.setCursor(50, 200);

    for(int i=0; i<300; i=i+2){   //Loading Bar
      if(i==0){                   //Wait for clear screen to finish
        delay(1000);            
      }
      tft.fillRect(0,300, i, 10, WHITE); //Draw Rectange
      delay(50);
    }
    delay(1000);
    tft.fillScreen(BLACK);   //Clear Screen
}
bool Touch_getXY(void)      //Gets Touchscreen Values
{
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    if (pressed) {
        pixel_x = map(p.x, TS_LEFT, TS_RT, 0, tft.width()); //.kbv makes sense to me
        pixel_y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
    }
    return pressed;
}
