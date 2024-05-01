#include <avr/io.h>
#include <util/delay.h>
// Define the common cathode 7-segment display segment patterns for numbers 
0 to 9
const uint8_t seg_7[10] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111 // 9
};
// Function to display a digit on the 7-segment display
void displayDigit(uint8_t digit) {
    PORTD = seg_7[digit];
    _delay_ms(2); // You may need to adjust the delay based on your display's 
    characteristics
}
// Function to display the time on the 4-digit 7-segment display
void displayTime(int minutes, int seconds) {
    int m2, m1, s2, s1;
    m2 = minutes / 10;
    m1 = minutes % 10;
    s2 = seconds / 10;
    s1 = seconds % 10;
    for (int i = 0; i < 200; i++) {
        // Display the time on each digit of the 7-segment display
        PORTC = 0b00000001; // Select digit 1
        displayDigit(m2);
        PORTC = 0b00000010; // Select digit 2
        displayDigit(m1);
        PORTC = 0b00000100; // Select digit 3
        displayDigit(s2);
        PORTC = 0b00001000; // Select digit 4
        displayDigit(s1);
    }
}
int main(void) {
    // Set the digit select pins (PC0 to PC3) as output
    DDRC = 0b00001111;
    // Set the segment pins (PD0 to PD7) as output
    DDRD = 0b11111111;
    // Initialize your RTC or time source here
     int hours = 0;
    int minutes = 0;
    int seconds = 0;
    while (1) {
        // Convert hours to minutes and add to the total minutes
        minutes += hours * 60; // Convert minutes and seconds to 
        seconds
        int totalSeconds = (minutes * 60) + seconds;
        // Display the time on the 4-digit 7-segment display
        displayTime(totalSeconds / 60, totalSeconds % 60);
        // Increment the seconds for continuous display
        seconds++;
        // Wait for 1 second before updating the display
        _delay_ms(1000);
    }
    return 0;
}

