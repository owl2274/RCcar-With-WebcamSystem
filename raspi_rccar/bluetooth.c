/*
 * bluetooth.c
 *
 *  Created on: 2017. 3. 24.
 *      Author: ulysse
 */

#include <stdio.h>

#include <unistd.h>

#include <sys/socket.h>

#include <bluetooth/bluetooth.h>

#include <bluetooth/rfcomm.h>

struct sockaddr_rc addr = { 0 } ;
int s , status;
char dest[18] = "20:16:09:05:38:18" ;


int BTInitialize(unsigned int baud)
{

	// allocate a socket
	s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM) ;
	// set the connection parameters (who to connect to)
	addr . rc_family = AF_BLUETOOTH;
	addr . rc_channel = 1;
	str2ba ( dest, &addr . rc_bdaddr ) ;
	// connect to server


	do{

		status = connect (s, (struct sockaddr *)&addr , sizeof(addr ) ) ;
		if(status <0) perror("uh oh");
		//printf("hello\n");
	}while(status != 0);

	/*
	if( 0 == status ) {
	    return 0;
	  }
	if( status < 0 ) perror( "uh oh" ) ;
	{
		close (s ) ;
		return -1;

	}*/
	delay(1500);


}
void BTTransmit(unsigned char data)
{
    send(s,&data,sizeof(char),0);

}


unsigned char BTReceive(void)
{
	int size = -1,lOutput,rOutput;
	unsigned char packet;
	size = recv(s,&packet,1,MSG_WAITALL );
	
    	return packet;
}


