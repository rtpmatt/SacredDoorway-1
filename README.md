SacredDoorway
=============

I've updated the repo to include Neopixel and custom libraries.

LED Strip Diagram
=================

Shows the directional flow of data and segments.
```
            Left                           Right

  1   2   3   4   5   6   7      7   6   5   4   3   2   1  ---- Sheet Number

       -->     -->     -->        -->     -->     -->
  0  59  60  119 120 179 180    239 240 299 300 359 360 419
  |   |   |   |   |   |   |      |   |   |   |   |   |   |
  |   |   |   |   |   |   |      |   |   |   |   |   |   |
  v   ^   v   ^   v   ^   v      ^   v   ^   v   ^   v   ^
  |   |   |   |   |   |   |      |   |   |   |   |   |   |
  |   |   |   |   |   |   |      |   |   |   |   |   |   |
 29  30  89  90  149 150 209    210 269 270 329 330 389 390
   -->     -->     -->     -->>--     -->     -->     -->

```

In the Arduino_Neopixel vernacular you could address the entire first sheet (top to bottom) by doing something like:

```cpp
// Top down
for (int i = 0; i < 30; i++) {
	strip.setPixelColor(i, 255, 255, 255); // All white - left
	strip.setPixelColor(419 - i, 255, 255, 255); // All White - right
}

// Bottom up
for (int i = 20; i >= 0; i--) {
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
```