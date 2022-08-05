# Basic Calculator

As my first full-fledged electronics project, I look at this calculator
with fondness. Inspiration struck when I first purchased my TI-84.
Wanting to make my own calculator, I collected the parts I had
tinkered with in the past and got to work on combining them into
a functional device.
In its current form, my calculator takes two numeric inputs along
with a basic operation (+,-,/,*), and displays a float answer on the
screen.
The heart of my calculator is the LCD (label 1), which makes use
of a specialized I2C library. The I2C breakout board (label 5)
differentiates it from a traditional 16x2 LCD Display as it
economizes the number of pins needed to operate.
If the LCD is the heart, then the Arduino Uno clone on the back
(label 4) is its brain.
In terms of real estate on the 3D printed enclosure (label 3), no
component is quite as eye-catching as the membrane keypad
(label 2), which acts as the primary user interface.

A video demonstration is located here: https://youtu.be/3QXVJ0pLwRI
