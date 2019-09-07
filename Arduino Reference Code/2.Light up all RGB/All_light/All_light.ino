/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         All_Light
* @author       Cindy
* @version      V1.0
* @date         2019.07.29
* @brief        Light up all RGB light Blue
* @details
* @par History  
*
*/
#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                        //Define the pins of the RGB light
#define MAX_LED 5                    //5 RGB light

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
uint8_t i = 0;                            
uint32_t color = strip.Color(0,0,255);   //Green,red,blue

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
* Function       setup
* @author        Cindy
* @date          2019.07.29
* @brief         main fuction
* @param[in]     void
* @retval        void
* @par History   no
*/
void loop()
{
  for(i=0;i<MAX_LED;i++)   //Set the value of i to control the serial number of the light
  {
    strip.setPixelColor(i, color);  //5 RGB light become blue
  }
    strip.show();
}

