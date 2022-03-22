# Lab 1
Introduction to input/output pins (PIO) and input interrupt
## Purpose
1. Introduction to PIO unit
2. Introduction to Polling and Interrupt-Driven 
3. Comparing the two ways mentioned above and answering the questions
## Components
1. Arduino Mega 2560 board
2. Light-emitting diode (LED)
3. Button
4. 220 ohm resistor
5. 10k ohm resistor
## Discussion
In this circuit, we use 3 buttons and a number of LEDs to design a circuit to understand the difference between the polling and interrupt-driven way.
In this experiment, when the bottom button is pressed, the LEDs light up from bottom to top, respectively. also When you press the middle button, the LEDs start blinking as many characters as my name (Armin) and stay on at the end. finallly, when you press the top button, all the LEDs turns off at once.
This circuit is designed in two ways, interrupt-driven and polling, and its Arduino files are available in folders called Interrupt and Polling.
\
![proteus](https://user-images.githubusercontent.com/58389402/159357143-767abfd1-c14b-40c2-9bf8-5e02ce502939.PNG)\
## Questions
1. What happens if we hold the button down for a long time? What is the solution to this problem?\
When we press a button and hold it down for a long time, the function that the button has to perform is done indefinitely (in polling way), and this is a kind of fault.
one of the advantages of using the interrupt-driven way is in this case. in the interrupt-driven implementation, even if we press and hold the button down indefinitely, that button operates only once and the circuit reaches the rest of its operations, but in the polling way, the circuit falls into a infinite loop and the operation repeated many times.

2. Suppose that in addition to current performance, we want to add another mechanism to the circuit that changes the status of an LED on or off every 5 seconds. explain the difference between interrupt-driven and polling way.
In the polling way, as explained in the first question, when we press and hold a button down for a long time, the circuit falls into a infinite loop and performs no function other than the function of the button and naturally until the circuit is stuck in this loop, it can not change the LED status every 5 seconds.
but in the interrupt way, the function of each button is executed only once and the program performs the rest of its tasks.

3. Suppose that if a specific pin becomes 1, a certain operation should be done, and 1 can occur at any moment and should never be lost. is it possible to design such a mechanism for this circuit by the polling way?
According to the above explanation and because of the possibility of falling into infinite loop, no
