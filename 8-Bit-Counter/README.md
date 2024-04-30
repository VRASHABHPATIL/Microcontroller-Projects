# 8-Bit-Counter
## PROBLEM STATEMENT
Design and implement a `8 bit` counter system using the `Atmega32` microcontroller. The objective is to create a system that displays a count value continuously on aseven-segment `display` or an `LCD`, accurately tracking and displaying the count value

## VIRTUAL IMPLEMENTATION
`Note : Here this virual implementation is done under Proteous  and that file is provided here in this project as  Backup Of timerproject.pdsbak `

<img src="https://github.com/VRASHABHPATIL/Microcontroller-Projects/assets/105427388/3f6ac6c2-6447-4254-aafc-794fa9e2b745" width=500 height=400/>

## CIRCUIT EXPLANATION

•**Atmega32**: The Atmega32 is a popular `8-bit microcontroller` from the `AVR` family developed by Atmel (now Microchip Technology). It features a `RISC architecture`, a wide range of peripherals, and is widely used in various applications due to its versatility, performance, and availability of development tools. It has `32KB of flash memor`y for program storage, `2KB of SRAM` for data storage, and various I/O ports for interfacing with external devices.

•A `7-segment` display is a simple electronic component used to represent numeric digits and some basic symbols. It consists of `seven individual LED (Light Emitting Diode)` segments arranged in a specific pattern to form the digit representation from `0 to 9` and a few `letters (A, B, C, D, E, F)` as well. These displays are widely used in various electronic devices, from digital clocks and calculators to microwave ovens and scoreboard display.

## FLOW OF THE CODE

1. LDI R19, 0 This instruction loads the value 0 into register R19.

2. CBI DDRB, 0 This instruction clears bit 0 of the DDRB (Data Direction Register B) register.

3. LDI R20, 0xFF This instruction loads the value 0xFF (all bits set) into register R20.OUT DDRC, R20 This instruction writes the value of R20 (0xFF) to the DDRC (Data Direction Register C) register, configuring all pins of Port C as outputs.

4. LDI R20, 0x06 This instruction loads the value 0x06 into register R20.

5. OUT TCCR0, R20 This instruction writes the value of R20 (0x06) to the TCCR0 (Timer/Counter Control Register 0), presumably configuring Timer/Counter 0 with the 
specified settings.

6. AGAIN: This is a label indicating the start of a loop.

7. IN R20, TCNT0 This instruction reads the value of the TCNT0 (Timer/Counter 0) register and stores it in R20.

8. OUT PORTC, R20 This instruction writes the value of R20 to the PORTC register, which controls the output values on Port C.

9. IN R16, TIFR This instruction reads the value of the TIFR (Timer/Counter Interrupt Flag Register) and stores it in R16.

10. SBRS R16, TOV0 This instruction skips the next instruction if bit TOV0 (Timer/Counter Overflow Flag 0) in R16 is set.

11. RJMP AGAIN This instruction performs a relative jump back to the "AGAIN" label, creating a loop.

12. LDI R16, 1 << TOV0 This instruction loads the value 1 left-shifted by the position of TOV0 (Timer/Counter Overflow Flag 0) into R16.

13. OUT TIFR, R16 This instruction writes the value of R16 to the TIFR register, presumably to clear the Timer/Counter Overflow Flag.

14. RJMP AGAIN This instruction performs a relative jump back to the "AGAIN" label, creating an infinite loop.The code sets up Timer/Counter 0 and continuously reads its value, writing it to PORTC. It then checks the Timer/Counter Overflow Flag (TOV0) and clears it before repeating the process indefinitely

`note : Code's are provided above `
