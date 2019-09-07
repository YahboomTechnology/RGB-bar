/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Random_Light_2
* @author       Cindy
* @version      V1.0
* @date         2019.07.29
* @brief        点亮所有的RGB灯为蓝色
* @details
* @par History  
*
*/
#include <stdlib.h>
#include "./Adafruit_NeoPixel.h"     //Library file
#define PIN 6                        // Define the pins of the RGB light
#define MAX_LED 5                   //5 RGB light

Adafruit_NeoPixel strip = Adafruit_NeoPixel( MAX_LED, PIN, NEO_RGB + NEO_KHZ800 );
uint8_t i = 0;                            
uint32_t color = strip.Color(0,0,255);   //绿、红、蓝

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
void RGB_Light(int i)
{
 int R = random (0, 255);  
 int G = random (0, 255);  
 int B = random (0, 255);  
 uint32_t color = strip.Color(G, R, B);  //设置颜色
 strip.setPixelColor(i, color);  //设置点亮灯的序号
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
   RGB_Light(0);
   delay(100);
   RGB_Light(1);
   delay(100);
   RGB_Light(2);
   delay(100);
   RGB_Light(3);
   delay(100);
   RGB_Light(4);
   delay(100);

}

