/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Random_Light_1
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
void RGB_Light()
{
 int R = random (0, 255);  
 int G = random (0, 255);  
 int B = random (0, 255);  
  uint32_t color = strip.Color(G, R, B);  //设置颜色
  //strip.setPixelColor(i, color);  //设置点亮灯的序号
    for(i=0;i<MAX_LED;i++)   //设置i的值控制点亮灯的序号
  {
    strip.setPixelColor(i, color);  //点亮第一个RGB灯为红色
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
   RGB_Light();
   delay(300);
   RGB_Light();
   delay(300);
   RGB_Light();
   delay(300);
   RGB_Light();
   delay(300);
   RGB_Light();
   delay(300);

}

