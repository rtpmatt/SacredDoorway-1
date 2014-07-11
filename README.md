SacredDoorway
=============

Check out the primary sketch or libraries/Sheet for more information about interacting with the Doorway.

LED Strip Diagram
=================

Shows the directional flow of data and segments.
```
              Left                            Right
    1   2   3   4   5   6   7       7   6   5   4   3   2   1  ---- Sheet Number
    0  59->60  119>120 179>180     239>240 299>300 359>360 419
F   |   |   |   |   |   |   |   B   |   |   |   |   |   |   |   F
R   |   |   |   |   |   |   |   A   |   |   |   |   |   |   |   R
O   v   ^   v   ^   v   ^   v   C   ^   v   ^   v   ^   v   ^   O
N   |   |   |   |   |   |   |   K   |   |   |   |   |   |   |   N
T   |   |   |   |   |   |   |       |   |   |   |   |   |   |   T
   29->30  89->90  149>150 209-->--210 269>270 329>330 389>390

```

Here's a basic breakdown of Sheet class
```cpp
Sheet sheet;

// Set the first sheet to white and update the display. Passing false as the last parameter will
// not update the display
sheet.SetColor(1, 255, 255, 255, true);

// Illuminate all sheets in a fading cascade of rainbows. This could be iterated over
// several times to extend the effect's duration.
sheet.RainbowPulse();

// Fade the first sheet from black (off) to white.
// The color math here will nicely transition between two colors and can be
// chained for added niceness.
sheet.fadeTo(1, 0, 0, 0, 255, 255, 255);

// A sweeping transition that turns all sheets to white
sheet.AllWhite();

// Fill sheet one with red starting at the top
sheet.WipeDownColor(1, 255, 0, 0); 

// Fill sheet one with red starting at the bottom
sheet.WipeUpColor(1, 255, 0, 0);

// Strobe the first sheet 20 times, green
sheet.Strobe(1, 20, 0, 255, 0); 

// Like fadeTo, this takes two sets of RGB values and will strobe 20 times as it 
// transitions to the last color
sheet.StrobeTo(1, 0, 0, 0, 255, 255, 255);

// Does a blinds sort of effect on all sheets from whatever color they're currently on
// to black, with 20ms in between each transition
sheet.BlackSpiral(20);

// Performs a bottom to top color animation on each chakra (1st sheet)
sheet.Chakras();
```
