/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         All_Light
* @author       Cindy
* @version      V1.0
* @date         2019.07.29
* @brief        Light up all RGB lights in blue
* @details
* @par History  
*
*/
#include <stdlib.h>
#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                        // Define the pins of the RGB light
#define MAX_LED 14                  //14 RGB light

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
uint8_t i = 0;                            
uint32_t color = strip.Color(0,0,255);   //Green、Red、Blue
int m = 0;
/**
* Function       setup
* @author        wusicaijuan
* @date          2019.07.29
* @brief         Initial configuration
* @param[in]     void
* @retval        void
* @par History   no
*/
void setup()
{
  // put your setup code here, it will run once:
  strip.begin();           
  strip.show();           
}

/**
* Function       RGB_Light
* @author        Cindy
* @date          2019.07.29
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_1(int i)
{
 int R = random (0, 150);  
 int G = random (0, 150);  
 int B = random (0, 150);  
 uint32_t color = strip.Color(G, R, B);  //set color
 strip.setPixelColor(i, color);  //Set the serial number of the lighted lamp
 strip.show();
}

/**
* Function       RGB_Light_Mode1()
* @author        Cindy
* @date          2019.07.29
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_Mode1()
{
  for(int i=MAX_LED ;i >= 0;i-- )
  {
       RGB_Light_1(i);
       delay(100);
    }
    RGB_OFF();
    delay(100);
}
/**
* Function       RGB_Light_2
* @author        Cindy
* @date          2019.07.29
* @brief         Light up RGB lights
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_2(int i, int R, int G, int B)
{
  uint32_t color = strip.Color(G, R, B);
  strip.setPixelColor(i, color);
  strip.show();
}


/**
* Function       RGB_OFF
* @author        Cindy
* @date          2019.07.29
* @brief         Close all RGB light
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_OFF()
{ 
  uint8_t i = 0;
  uint32_t color = strip.Color(0, 0, 0);
  for(i=0;i<MAX_LED;i++)   
  {
    strip.setPixelColor(i, color);  
  }
    strip.show();
}
/**
* Function       RGB_Light_Mode1
* @author        Cindy
* @date          2019.07.29
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_Mode2()
{
    for(int i= 0 ;i < MAX_LED ;i++ )
  {
       RGB_Light_2(i, 255, 165, 0);
       delay(100);
    }
   RGB_OFF();
   delay(100);
}
/**
* Function       RGB_Light
* @author        Cindy
* @date          2019.07.29
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_3(int R, int G, int B)
{
  uint8_t i = 0;
  R = map(R, 0, 255, 0, 100);  
  G = map(G, 0, 255, 0, 100);
  B = map(B, 0, 255, 0, 100);
  uint32_t color = strip.Color(G, R, B);  
  for(i=0;i<MAX_LED;i++)   
  {
    strip.setPixelColor(i, color); 
  }
  strip.show();
}

/**
* Function       RGB_Light_Mode3
* @author        Cindy
* @date          2019.07.29
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
void RGB_Light_Mode3()
{ 
   RGB_Light_3(150,0 ,0);  
   delay(400);
   RGB_Light_3(0,150 ,0);  
   delay(400);
   RGB_Light_3(0,0 ,150);   
   delay(400);
   RGB_Light_3(150,150 ,0);
   delay(400);
   RGB_Light_3(150,0 ,150);  
   delay(400);
   RGB_Light_3(0,150,150);
   delay(400);
   RGB_Light_3(150,150,150);
   delay(400);
   RGB_Light_3(0,0 ,0);  
   delay(400);

}

/**
* Function       Wheel
* @author        Cindy
* @date          2019.07.29
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
/**
* Function       rainbow
* @author        Cindy
* @date          2019.07.29
* @brief         
* @param[in]     void
* @retval        void
* @par History   no
*/
void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
/**
* Function       RGB_Light_Mode3
* @author        Cindy
* @date          2019.07.29
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  for( int x = 0; x < 3; x++)
  {
  RGB_Light_Mode2();
  }
  delay(200);
  for( int x = 0; x < 8; x++)
  {
  RGB_Light_Mode1();
  }
  RGB_OFF();
  delay(200);
  RGB_Light_Mode3();
  delay(200);
  rainbow(20);
  delay(200);
}