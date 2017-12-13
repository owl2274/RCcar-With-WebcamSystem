#ifndef __CONVERSION_H__
#define __CONVERSION_H__

#define xCenter ((float)505)
#define yCenter ((float)531)



class controlStick
{
    public:
        controlStick(int xPin,int yPin, int bt);
        unsigned char conversion();    
    private:
        int _xPin;  
        int _yPin;
        int _bt;   
        int xValue,yValue;
        int leftOutput,rightOutput ;
        
        
};

#endif
