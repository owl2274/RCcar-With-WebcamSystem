#include "controlStick.h"
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);   //bluetooth module Tx:Digital 2 Rx:Digital 3
controlStick c(A0,A1,0);

void setup() {
  // put your setup code here, to run once:
  
  String data;
  char buff[10];
  int cnt;
  
  Serial.begin(9600);
  
  BTSerial.begin(9600);
  /*
  Serial.println("ATcommand");
  
  BTSerial.print("AT\r\n");
  
  
  while(!BTSerial.available()){};
  while(BTSerial.available()) { 
    char c = BTSerial.read(); 
    buff[cnt] = c; 
    cnt ++; 
  } 
  buff[cnt] = '\0'; 
  cnt = 0;
  data = buff;
  Serial.print(data);
  
  if(data == "OK\r\n")
  { 
    Serial.println("yes"); 
  }
  else
  { 
    Serial.println("This message is never displayed"); 
    
    //while(1); 
  }
  
  BTSerial.print("AT+INIT\r\n");
  
  while(!BTSerial.available()){};
  while(BTSerial.available()) { 
    char c = BTSerial.read(); 
    buff[cnt] = c; 
    cnt ++; 
  } 
  buff[cnt] = '\0'; 
  cnt = 0;
  data = buff;
  Serial.print(data);
  
  if(data == "OK\r\n")
  { 
    Serial.println("yes"); 
  }else //if( data == "ERROR:(17)\r\n" )
  { 
    Serial.println("SPP lib has been repeated initialization."); 
    
    //while(1); 
  }

  BTSerial.print("AT+BIND=2016,08,150811\r\n");
  while(!BTSerial.available()){};
  while(BTSerial.available()) { 
    char c = BTSerial.read(); 
    buff[cnt] = c; 
    cnt ++; 
  } 
  buff[cnt] = '\0'; 
  cnt = 0;
  data = buff;
  Serial.print(data);
  
  if(data == "OK\r\n")
  { 
    Serial.println("yes"); 
  }else
  { 
    Serial.println("AT+BIND command is failed"); 
    
    //while(1); 
  }
  BTSerial.print("AT+PAIR=2016,08,150811,30\r\n");
  while(!BTSerial.available()){};
  while(BTSerial.available()) { 
    char c = BTSerial.read(); 
    buff[cnt] = c; 
    cnt ++; 
  } 
  buff[cnt] = '\0'; 
  cnt = 0;
  data = buff;
  Serial.print(data);
  
  if(data == "OK\r\n")
  { 
    Serial.println("yes"); 
  }else
  { 
    Serial.println("AT+PAIR command is failed"); 
    
    //while(1); 
  }
  BTSerial.print("AT+LINK=2016,08,150811\r\n");
  while(!BTSerial.available()){};
  while(BTSerial.available()) { 
    char c = BTSerial.read(); 
    buff[cnt] = c; 
    cnt ++; 
  } 
  buff[cnt] = '\0'; 
  cnt = 0;
  data = buff;
  Serial.print(data);
  
  if(data == "OK\r\n")
  { 
    Serial.println("yes"); 
  }else
  { 
    Serial.println("AT+LINK command is failed"); 
    
    //while(1); 
  }
  */

}

void loop() {
  // put your main code here, to run repeatedly:

  
 
  int x,y;
  unsigned char packet,back;
  int lOutput,rOutput;
  
  packet = c.conversion();
  
  BTSerial.write(packet);
  //BTSerial.write(packet);
  
  /*
  lOutput = ((packet & 0x01110000)>>4)*34;
  rOutput = (packet & 0x00000111)*34;*/
  lOutput = packet & 0x01110000;
  lOutput = lOutput >> 4;
  rOutput = packet & 0x00000111;
/*
  Serial.print("lOutput is ");
  Serial.print((int)((packet&0b01110000)>>4));

  if(packet & 0x80)
    Serial.print(" FRONT");
  else
    Serial.print(" BACK");
  
  Serial.print("    ,rOutput is ");
  Serial.print((int)(packet&0b00000111));
  if(packet & 0x08)
    Serial.println(" FRONT");
  else
    Serial.println(" BACK");
  delay(100);*/
  Serial.print(analogRead(A0));
  Serial.print(", ");
  Serial.println(analogRead(A1));
  
  /*
  Serial.print((int)((packet&0b01110000)>>4)*34);
    Serial.print(" ");
    Serial.print((int)(packet&0b00000111)*34);
  Serial.print(" ");
  */
  
  
 /*
  while(BTSerial.available())
  {
    back = BTSerial.read();
    Serial.print((int)back);
    Serial.print(" ");

    back = BTSerial.read();
    Serial.print((int)back);
    Serial.print('\n');
    
    
  }*/

  
  /*
  if (Serial.available())
    BTSerial.write(Serial.read());
 
/*
  x = analogRead(A0);
  y = analogRead(A1);
  
  Serial.print(x);
  Serial.print(' ');
  Serial.print(y);
  Serial.print(' ');

  
  Serial.print(x/4);
  Serial.print(' ');
  Serial.println(y/4);
  */
}
