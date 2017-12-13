#include <arduino.h>
#include "controlStick.h"



controlStick::controlStick(int xPin,int yPin, int bt)
{
    pinMode(bt,INPUT);
    _bt = bt;
    _xPin = xPin;
    _yPin = yPin;

}
unsigned char controlStick::conversion()
{
    unsigned char packet,xPiece=0,yPiece=0;
    
    xValue = analogRead(_xPin);
    yValue = analogRead(_yPin);

    if(yValue < yCenter)
    {
      if(xValue <= xCenter)
      {
        leftOutput = ( xValue/xCenter*191+64 )*( (yCenter-yValue)/yCenter );
        rightOutput = ( (yCenter-yValue)/yCenter*255 ) + ( (xCenter-xValue)/(1023-xCenter)*255 );
      }
      else
      {
        leftOutput = ( (yCenter-yValue)/yCenter*255 ) + ( (xValue-xCenter)/(1023-xCenter)*255 );
        rightOutput = ( (1023-xValue)/(1023-xCenter)*191+64 )*( (yCenter-yValue)/yCenter );
      }
      packet = packet|0b10001000;
    }
    else
    {
      if(xValue < xCenter)
      {
        leftOutput = ( xValue/xCenter*191+64 )*( (yValue-yCenter)/(1023-yCenter) );  
        rightOutput = ( (yValue-yCenter)/(1023-yCenter)*255 ) + ( (xCenter-xValue)/(1023-xCenter)*255 );
      }
      else
      {
        leftOutput = ( (yValue-yCenter)/(1023-yCenter)*255 ) + ( (xValue-xCenter)/(1023-xCenter)*255 );
        rightOutput = ( (1023-xValue)/(1023-xCenter)*191+64 )*( (yValue-yCenter)/(1023-yCenter) );
      }

      
      packet = packet&0b01110111;
    }
    if(leftOutput>300)
        leftOutput = 255;

    if(rightOutput>300)
        rightOutput = 255;

    if(leftOutput > 247)
      packet = packet|0b01110000;
      
    else if(leftOutput > 10)
      packet = packet | ((leftOutput-9)/34+1)<<4;
      
   
    
    if(rightOutput > 247)
      packet = packet|0b00000111;
      
    else if(rightOutput > 10)
      packet = packet | ((rightOutput-9)/34+1);
      
    return packet;
    

}
