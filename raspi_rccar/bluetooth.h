/*
 * bluetooth.h
 *
 *  Created on: 2017. 3. 24.
 *      Author: ulysse
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_


void BTInitialize(void);// just input NULL
void BTTransmit(unsigned char data);
unsigned char BTReceive(void);

#endif /* BLUETOOTH_H_ */
