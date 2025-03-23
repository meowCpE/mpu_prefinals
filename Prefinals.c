#include <xc.h>

#pragma config FOSC = XT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config CP = OFF

#define _XTAL_FREQ 4000000 // 4 MHz

void main() {
    TRISA = 0xFF; 
    TRISB = 0x00;// Port B as output (optional for more LEDs)
    PORTB = 0x00; 
 unsigned char counter = 0;
  unsigned char ones = 0;
    unsigned char tens = 0;
     
    while (1) {
       
        
       if (RA0 == 1) {
            __delay_ms(50); // Debounce delay
            if (RA0 == 1) { // Confirm button press
                counter+=3;
                if (counter > 99) {
                    counter = 0; // Reset to 00 if >99
                }

                // Extract ones and tens
                ones = counter % 10;
                tens = counter / 10;
                

                // Output to BCD decoders
                PORTB = (tens << 4) | ones;

                while (RA0 == 1); // Wait until button is released
            }
    }
       
       if (RA1 == 1) {
            __delay_ms(50); // Debounce delay
            if (RA1 == 1) { // Confirm button press
                counter+=2;
                if (counter > 99) {
                    counter = 0; // Reset to 00 if >99
                }

                // Extract ones and tens
                ones = counter % 10;
                tens = counter / 10;
                

                // Output to BCD decoders
                PORTB = (tens << 4) | ones;

                while (RA1 == 1); // Wait until button is released
            }
    }
       
       if (RA2 == 1) {
            __delay_ms(50); // Debounce delay
            if (RA2 == 1) { // Confirm button press
                counter++;
                if (counter > 99) {
                    counter = 0; // Reset to 00 if >99
                }

                // Extract ones and tens
                ones = counter % 10;
                tens = counter / 10;
                

                // Output to BCD decoders
                PORTB = (tens << 4) | ones;

                while (RA2 == 1); // Wait until button is released
            }
    }
       
       if (RA3 == 1) {
            __delay_ms(50); // Debounce delay
            if (RA3 == 1) { // Confirm button press
                counter--;
                if (counter > 99) {
                    counter = 0; // Reset to 00 if >99
                }

                // Extract ones and tens
                ones = counter % 10;
                tens = counter / 10;
                

                // Output to BCD decoders
                PORTB = (tens << 4) | ones;

                while (RA3 == 1); // Wait until button is released
            }
    }
       
       if (RA4 == 1) {
            __delay_ms(50); // Debounce delay
            if (RA4 == 1) { // Confirm button press
                counter=0;
                if (counter > 99) {
                    counter = 0; // Reset to 00 if >99
                }

                // Extract ones and tens
                ones = counter % 10;
                tens = counter / 10;
                

                // Output to BCD decoders
                PORTB = (tens << 4) | ones;

                while (RA4 == 1); // Wait until button is released
            }
    }
       
       
} 

}