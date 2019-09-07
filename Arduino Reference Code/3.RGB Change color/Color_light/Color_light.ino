/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Color_Light
* @author       Cindy
* @version      V1.0
* @date         2019.07.29
* @brief        Change color of RGB
* @details
* @par History  
*
*/
#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                        // Define the pins of the RGB light
#define MAX_LED 5                   //5 RGB light

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );


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
void RGB_Light(int R, int G, int B)
{
  uint8_t i = 0;
  R = map(R, 0, 255, 0, 100);    //Here you can change the brightness by mapping.
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
* Function       loop
* @author        Cindy
* @date          2019.07.29
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{ 
   RGB_Light(255,0 ,0);   //red
   delay(1000);
   RGB_Light(0,255 ,0);    //green
   delay(1000);
   RGB_Light(0,0 ,255);    //blue
   delay(1000);
   RGB_Light(255,255 ,0);   //yellow
   delay(1000);
   RGB_Light(255,0 ,255);   //purple
   delay(1000);
   RGB_Light(0,255,255);   //cyan
   delay(1000);
   RGB_Light(255,255,255);  //white
   delay(1000);
   RGB_Light(0,0 ,0);     //off
   delay(1000);

}

