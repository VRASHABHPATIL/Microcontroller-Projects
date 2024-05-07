## Digital Clock

### PROBLEM STATEMENT
Design a `digital clock` using a microcontroller that displays the current time on a `7-segment` display in minutes and seconds. The clock should be able to accurately keep track of time.


### VIRTUAL IMPLEMENTATION

<img src="https://github.com/VRASHABHPATIL/Microcontroller-Projects/assets/105427388/87d7fae4-f3de-41d9-b315-cf37be371dd3" height="500" width="800"/>

`note :The above proteous code is mentioned above as Backup Of digitalclock.pdsbak`

### CIRCUIT EXPLANATION
•**Atmega32**: The `Atmega32` is a popular `8-bit microcontroller` from the `AVR` family developed by Atmel (now Microchip Technology). It features a `RISC architecture`, a wide range of peripherals, and is widely used in various applications due to its versatility, performance, and availability of development tools. It has `32KB of flash memory` for program storage, `2KB of SRAM` for data storage, and various I/O ports for interfacing with external devices.

•**A 7-segment** display is a simple electronic component used to represent numeric digits and some basic symbols. It consists of seven individual `LED (Light Emitting Diode)` segments arranged in a specific pattern to form the digit representation from 0 to 9 and a few letters `(A, B, C, D, E, F)` as well. These displays are widely used in various electronic devices, from digital clocks and calculators to microwave ovens and scoreboard displays,such 4 segments were attached.

### FLOW OF THE CODE

Include Header Files: The code begins by including two header files, avr/io.h and util/delay.h, which are essential for handling I/O operations and introducing 
delays in AVR microcontroller programming.

Define Segment Patterns: The code defines an array seg_7 that holds the common cathode 7-segment display segment patterns for numbers 0 to 9. Each element in 
the array corresponds to a specific digit and contains the binary representation of the segments that need to be activated to display that digit.

displayDigit Function: This function is responsible for displaying a single digit on the 7-segment display. It takes an argument digit (0 to 9) and sets the 
corresponding segment pattern on the PORTD (connected to the 7-segment display) by assigning the value from the seg_7 array. The function then waits for a short delay of 2 milliseconds to display the digit.

displayTime Function: This function takes two arguments, minutes and seconds, representing the time to be displayed. Inside the function, the code calculates the 
individual digits for minutes and seconds (m2, m1, s2, and s1) by performing integer division and modulo operations.

Displaying Time on 7-Segment Display: The function then enters a loop that runs 200 times. In each iteration of the loop, it displays the time on each digit of the 
7-segment display one by one.

a. First, it selects digit 1 (the most significant digit for minutes) by setting PORTC to 0b00000001.

b. It then calls displayDigit to display the digit represented by m2 on the selected digit.

c. Next, it selects digit 2 (the least significant digit for minutes) by setting PORTC to 0b00000010.

d. It calls displayDigit to display the digit represented by m1 on the selected digit.

e. Then, it selects digit 3 (the most significant digit for seconds) by setting PORTC to 0b00000100.

f. It calls displayDigit to display the digit represented by s2 on the selected digit.

g. Finally, it selects digit 4 (the least significant digit for seconds) by setting PORTC to 0b00001000.

h. It calls displayDigit to display the digit represented by s1 on the selected digit.Main Function: In the main function, the code sets the necessary pins for the 7-segment display as output by configuring the data direction registers (DDRC and DDRD). It then initializes the variables hours, minutes, and seconds to zero.

Updating Time and Display: The code enters an infinite loop (while (1)) to continuously update and display the time on the 7-segment display.

a. It converts hours to minutes and adds them to the minutes variable.

b. It calculates the total number of seconds by converting minutes and seconds to seconds and stores it in totalSeconds.

c. It calls the displayTime function to display the time represented by totalSeconds in minutes and seconds on the 7-segment display.

d. It increments the seconds variable for continuous display.

e. It waits for 1 second before updating the display again using _delay_ms(1000).

End of Program: The program never reaches the return 0; statement since it runs in an infinite loop (while (1))
