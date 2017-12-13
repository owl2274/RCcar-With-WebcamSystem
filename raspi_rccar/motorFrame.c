/*
 * motorFrame.c
 *
 *  Created on: 2017. 3. 21.
 *      Author: ulysse
 */

#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include "motorFrame.h"


void motorInit()
{
	wiringPiSetup();

	pinMode(LPIN_CTL1,OUTPUT);
	pinMode(LPIN_CTL2,OUTPUT);
	pinMode(RPIN_CTL1,OUTPUT);
	pinMode(RPIN_CTL2,OUTPUT);

	softPwmCreate(LPWM_CTL,0,255);
	softPwmCreate(RPWM_CTL,0,255);



}

void motorControl(unsigned char left,unsigned char lPWM,unsigned char right,unsigned char rPWM)
{

	switch(left)
	{
	case FRONT:
		digitalWrite(LPIN_CTL1,LOW);
		digitalWrite(LPIN_CTL2,HIGH);
		break;
	case BACK:
		digitalWrite(LPIN_CTL1,HIGH);
		digitalWrite(LPIN_CTL2,LOW);
		break;
	case STOP:
		digitalWrite(LPIN_CTL1,LOW);
		digitalWrite(LPIN_CTL2,LOW);
		break;
	}
	softPwmWrite(LPWM_CTL,lPWM);

	switch(right)
	{
	case FRONT:
		digitalWrite(RPIN_CTL1,LOW);
		digitalWrite(RPIN_CTL2,HIGH);
		break;
	case BACK:
		digitalWrite(RPIN_CTL1,HIGH);
		digitalWrite(RPIN_CTL2,LOW);
		break;
	case STOP:
		digitalWrite(RPIN_CTL1,LOW);
		digitalWrite(RPIN_CTL2,LOW);
		break;
	}
	softPwmWrite(RPWM_CTL,rPWM);
	/*
    switch(right)
    {
        case FRONT:
            PORTC &= ~0x01;
            PORTC |= 0x02;
            break;
        case BACK:
            PORTC |= 0x01;
            PORTC &= ~0x02;
            break;

        case STOP:
            PORTC &= ~0x03;
            break;
    }
    OCR1A = rPWM;

    switch(left)
    {
        case FRONT:
            PORTC &= ~0x04;
            PORTC |= 0x08;
            break;

        case BACK:
            PORTC |= 0x04;
            PORTC &= ~0x08;
            break;
        case STOP:
            PORTC &= ~0x0c;
            break;
    }
    OCR1B = lPWM;

    */
}

void setBack(int signo)
{
	digitalWrite(LPIN_CTL1,LOW);
	digitalWrite(LPIN_CTL2,LOW);
	digitalWrite(RPIN_CTL1,LOW);
	digitalWrite(RPIN_CTL2,LOW);
	softPwmWrite(LPWM_CTL,0);
	softPwmWrite(RPWM_CTL,0);
	exit(0);
}

void PWM(int pwm);
