#include <16F877A.h> 
#include <stdlib.h> 
#FUSES XT, NOWDT, NOPROTECT, NOBROWNOUT, NOLVP, NOPUT, NODEBUG, NOCPD 
#use delay(crystal=4000000) 
#include <lcd.c> 
#use rs232 (baud=9600,xmit=PIN_C6, rcv=PIN_C7, parity=N, stop=1) // configuretion for serial communication 

 

int counter = 0;                          // counter to be used 
char strInput[4];                         // string array for input characters 
unsigned long inputString;                // inputString value to be used 

 

void main() 
{ 
   lcd_init(); 
   delay_ms(10); 
    
   while(1) 
   { 
 if(kbhit()) // if data has been received 
      {                              
         char i = getc();                    // UART read 
         if (i == '*')            // special character for serial input. If the received character is *, then this condition is called 
         { 
 counter = 0; // counter to be zero again 
 printf("Incoming Data: %s",strInput); // print string array to the screen 
 inputString = atol(strInput); // change string array to long variable 
 inputString = inputString*2; // multiply inputString by 2 
 printf(" Number: %lu ",inputString); // print inputString value to the screen 
 printf(LCD_PUTC,"\fValue=%lu",inputString); // print inputString value to the LCD 
 memset(strInput, 0, 4); // clear the string array 
         } 
         else 
         { 
 strInput[counter] = i; // attend input character to the string array 
 counter++; // increase the counter by 1 
         } 
      } 
   } 
} 
