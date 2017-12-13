#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "motorFrame.h"
#include "bluetooth.h"



void main()
{

    unsigned char packet;
    unsigned char lVector,rVector;
    unsigned char lOutput,rOutput;

    printf("rc_car program is started\n");


    motorInit();
    if(signal(SIGINT,setBack) == SIG_ERR)
    	printf("Cannot handle SIGINT!\n");
    if(signal(SIGQUIT,setBack) == SIG_ERR)
    	printf("Cannot handle SIGQUIT!\n");
    if(signal(SIGTSTP,setBack) == SIG_ERR)
    	printf("Cannot handle SIGSTP!\n");

    BTInitialize();

    printf("setup succeeded\n");

    while(1)
    {
        packet = BTReceive();

        if(packet & 0x80)
            lVector = FRONT;
        else
            lVector = BACK;

        if(packet & 0x08)
            rVector = FRONT;
        else
            rVector = BACK;

        lOutput = ((packet & 0b01110000)>>4);
        rOutput = (packet & 0b00000111);

        /*
        BTTransmit(lOutput);
        BTTransmit(rOutput);
*/
        motorControl(lVector, lOutput*34, rVector, rOutput*34 );




    }




}
