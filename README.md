SacredDoorway
=============

I've updated the repo to include Neopixel and custom libraries.

LED Strip Diagram
=================

Shows the directional flow of data and segments.
```
            Left                           Right

     1   2   3   4   5   6   7      7   6   5   4   3   2   1  ---- Sheet Number
         -->     -->     -->         -->     -->     -->
    0  59  60  119 120 179 180     239 240 299 300 359 360 419
F   |   |   |   |   |   |   |   B   |   |   |   |   |   |   |   F
R   |   |   |   |   |   |   |   A   |   |   |   |   |   |   |   R
O   v   ^   v   ^   v   ^   v   C   ^   v   ^   v   ^   v   ^   O
N   |   |   |   |   |   |   |   K   |   |   |   |   |   |   |   N
T   |   |   |   |   |   |   |       |   |   |   |   |   |   |   T
   29  30  89  90  149 150 209     210 269 270 329 330 389 390
     -->     -->     -->     -->>>--     -->     -->     -->

```

In the Arduino_Neopixel vernacular you could address the entire first sheet (top to bottom) by doing something like:

```cpp
// Top down -- Sheet 1
for (int i = 0; i < 30; i++) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right
}

// Bottom up -- Sheet 1
for (int i = 29; i >= 0; i--) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right
}

// More concise example for offsets...
int sheet3start = 60;
int sheet3stop  = 89;

for (sheet3start; i < sheet3stop; i++) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right
}

// Also the strip.show() function must be called for the Pixels to actually turn on.
// This can be accomplished like follows
for (int i = 0; i < 30; i++) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right
}
strip.show();

// or ---- for a gradual turn on of each LED top to bottom, delay() exists in Arduino.h 
for (int i = 0; i < 30; i++) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right

	delay(500); // ms 
	strip.show();
}
```