/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         One_Light
* @author       Cindy
* @version      V1.0
* @date         2019.07.29
* @brief        Light up a RGB
* @details
* @par History  
*
*/
#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                        // Define the pins of the RGB light
#define MAX_LED 1                   //5 RGB light

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
uint8_t i = 0;                            
uint32_t color = strip.Color(0,50,0);   //Green, red, blue

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
  strip.setPixelColor(i,color);  //No.1 RGB red
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

}

