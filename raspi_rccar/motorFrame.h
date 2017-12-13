/*
 * motorFrame.h
 *
 *  Created on: 2017. 3. 21.
 *      Author: ulysse
 */

#ifndef MOTORFRAME_H_
#define MOTORFRAME_H_

#define LPWM_CTL	22	//physical pin: 31
#define	LPIN_CTL1	24	//physical pin: 35
#define	LPIN_CTL2	25	//physical pin: 37

#define RPWM_CTL	26	//physical pin: 32
#define RPIN_CTL1	27	//physical pin: 36
#define RPIN_CTL2	28	//physical pin: 38



#define FRONT   (1)	//IN1(IN3):HIGH,		IN2(IN4):LOW
#define BACK    (2)	//IN1(IN3):LOW,			IN2(IN4):HIGH
#define STOP    (0)	//IN1(IN3):HIGH(LOW), 	IN2(IN4):HIGH(LOW)
void motorInit();
void motorControl(unsigned char left,unsigned char lPWM,unsigned char right,unsigned char rPWM);
void setBack(int signo);

void PWM(int pwm);


#endif /* MOTORFRAME_H_ */
