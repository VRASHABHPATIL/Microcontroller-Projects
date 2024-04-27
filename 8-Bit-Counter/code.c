#include <avr/io.h>
#include <util/delay.h>
#define LED_PORT PORTC 
#define LED_DDR DDRC 
void displayBinary(uint8_t value) {
    LED_PORT = value; 
    _delay_ms(1000);
}
int main(void) {
    LED_DDR = 0xFF; 
    while (1) {
         for (uint8_t i = 0; i <= 255; i++) {
             displayBinary(i);
        }
    }
     return 0;
}
