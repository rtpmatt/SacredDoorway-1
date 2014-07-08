#ifndef fader_h
#define fader_h

/*
 * Pulled from the Arduino Cookbook
 * Eventually will be used to fade an LED
 * or section of LEDs from one color to the other
 */

// This class will most likely not be necessary since the
// NeoPixel library includes constructors for RGB color values
class rgb_color {
  public:
	rgb_color(int r, int g, int b);
};

class fader {
	public:
  		void fade();
};

#endif