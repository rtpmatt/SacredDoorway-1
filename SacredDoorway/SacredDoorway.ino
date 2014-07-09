#include <Adafruit_NeoPixel.h>
#include <sheet.h>

/*
 * The 'strip' is composed of 419 (it should have been 420, but it's the last led so who cares)
 * LEDs with daisy chained segments. Which can make addressing a specific sheet a little intense.
 *
 * Basically the first 30 LEDs are the front left side of the first sheet and the last 29 are the front right side.
 * Meaning that to address the first led of the front right side you would need to address its offset 
 * from the last LED of the front left side (which should be 419, i.e, 419 would be the first LED for the front
 * sheet on the right side.)
 
 * Diagram to show the directional flow of data. 
 *
 *        Left                      Right
 *       -->     -->     -->        -->     -->     -->
 *  0  59  60  119 120 179 210    240 270 300 330 360 390 419
 *  |   |   |   |   |   |   |      |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |      |   |   |   |   |   |   |
 *  v   ^   v   ^   v   ^   v      ^   v   ^   v   ^   v   ^
 *  |   |   |   |   |   |   |      |   |   |   |   |   |   |
 *  |   |   |   |   |   |   |      |   |   |   |   |   |   |
 * 29  30  89  90  149 150 181    211 241 271 301 331 361 391
 *   -->     -->     -->     -->>--     -->     -->     -->
 *
 * Make sense? Good. I'll get some constructors defined for each sheet
 * so you'll just be able to say sheet1.set(4) or sheet5.set(10) to handle the offsets.
 *
 * The remainder of the code was ganked out of the strandtest library and just 
 * does a cascading rainbow over the entire strip.
 *
 * These LEDs are full color (so yeah, you can do pink).
 */

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
Adafruit_NeoPixel strip = Adafruit_NeoPixel(419, PIN, NEO_GRB + NEO_KHZ800);
uint8_t brightness = 1;

int sheets[] = {
		0,
		30,
		60,
		90,
		120,
		150,
		180,
		210					
};

void setup() {
	strip.begin();
	strip.setBrightness(brightness); // Not really necessary, seems that the default of the library is max brightness
	strip.show(); // Initialize all pixels to 'off'
}

void loop() {
	fadeIn();
	
	//nSheetSetColor(5, 255, 0, 0);
	
	fadeSheetTo(3, 0, 0, 0, 0, 0, 255);
	fadeSheetTo(6, 0, 0, 0, 0, 0, 255);
	fadeSheetTo(6, 0, 0, 255, 0, 127, 255);
	fadeSheetTo(6, 0, 127, 255, 0, 255, 255);
	fadeSheetTo(5, 0, 0, 0, 255, 0, 0);
	AllColorSpiral(strip.Color(255, 0, 50));
	fadeSheetTo(5, 255, 0, 50, 255, 171, 0);
	fadeSheetTo(2, 255, 0, 50, 0, 0, 255);
	fadeSheetTo(1, 255, 0, 50, 50, 255, 0);
	//rainbow(1);
	
	//AllBlackSpiral();
	
	AllWhite();
	
	AllBlackSpiral(20);
	
	//fadeOut();
	
	for (int i = 0; i < 5; i++) {
		AllSheetRainbowPulse(10);
	}
	AllBlackSpiral(1);
	//AllWhite();
	//fadeOut();
	
	
	
}

void AllSheetRainbowPulse (uint8_t wait) {
	uint8_t i, j;
	
	for(j = 0 ; j < 255; j++) {
		for(i = 0; i < 30; i++) {
			strip.setPixelColor(i, Wheel(j));
			strip.setPixelColor(419 - i, Wheel(j));
		}
		
		for(i = 30; i < 60; i++) {
			strip.setPixelColor(i, Wheel((j+10)));
			strip.setPixelColor(419 - i, Wheel((j+10)));
		}
		
		for(i = 60; i < 90; i++) {
			strip.setPixelColor(i, Wheel((j+20)));
			strip.setPixelColor(419 - i, Wheel((j+20)));
		}
		
		for(i = 90; i < 120; i++) {
			strip.setPixelColor(i, Wheel((j+30)));
			strip.setPixelColor(419 - i, Wheel((j+30)));
		}
		
		for(i = 120; i < 150; i++) {
			strip.setPixelColor(i, Wheel((j+40)));
			strip.setPixelColor(419 - i, Wheel((j+40)));
		}
		
		for(i = 150; i < 180; i++) {
			strip.setPixelColor(i, Wheel((j+50)));
			strip.setPixelColor(419 - i, Wheel((j+50)));
		}
		
		for(i = 180; i < 210; i++) {
			strip.setPixelColor(i, Wheel((j+60)));
			strip.setPixelColor(419 - i, Wheel((j+60)));
		}
		
		fadeIn();
		strip.show();
		
		delay(wait);
	}
}

void AllWhite() {
	uint16_t pixel;
	for (pixel = 0; pixel < 210; pixel++) {
		strip.setPixelColor(pixel, 255, 255, 255);
		strip.setPixelColor(419 - pixel, 255, 255, 255);
		
		strip.show();
		delay(1);
	}
}

void AllBlack() {
	uint16_t pixel, brightness;
	for (pixel = 0; pixel < 210; pixel++) {
		strip.setPixelColor(pixel, 0, 0, 0);
		strip.setPixelColor(419 - pixel, 0, 0, 0);
		
		strip.show();
	}
}

void AllColorSpiral (uint32_t color) {
	uint16_t i;
	for (i = 0; i < 30; i++) {
		strip.setPixelColor(i, color);
		strip.setPixelColor(391 + i, color);
		
		strip.setPixelColor(210 - i, color);
		strip.setPixelColor(211 + i, color);
		
		strip.setPixelColor(59 - i, color);
		strip.setPixelColor(361 + i, color);
		
		strip.setPixelColor(89 - i, color);
		strip.setPixelColor(331 + i, color);
		
		strip.setPixelColor(119 - i, color);
		strip.setPixelColor(301 + i, color);
		
		strip.setPixelColor(149 - i, color);
		strip.setPixelColor(271 + i, color);
		
		strip.setPixelColor(179 - i, color);
		strip.setPixelColor(241 + i, color);
		
		strip.show();
		delay(10);
	}
}

void SheetColorSpiral (uint32_t color) {
	/*
	for (uint8_t i = sheets[n - 1]; i < sheets[n]; i++) {
		strip.setPixelColor(i, color);
		strip.setPixelColor(419 - i, color);
	}
	*/
	
	for (int i = 0; i < 30; i++) {
		strip.setPixelColor(i, color);
		strip.setPixelColor(391 + i, color);
		
		strip.setPixelColor(210 - i, color);
		strip.setPixelColor(211 + i, color);
		
		strip.setPixelColor(59 - i, color);
		strip.setPixelColor(361 + i, color);
		
		strip.setPixelColor(89 - i, color);
		strip.setPixelColor(331 + i, color);
		
		strip.setPixelColor(119 - i, color);
		strip.setPixelColor(301 + i, color);
		
		strip.setPixelColor(149 - i, color);
		strip.setPixelColor(271 + i, color);
		
		strip.setPixelColor(179 - i, color);
		strip.setPixelColor(241 + i, color);
		
		strip.show();
		delay(10);
	}
}

void AllBlackSpiral (uint8_t wait) {
	uint16_t i;
	for (i = 0; i < 30; i++) {
		strip.setPixelColor(i, 0);
		strip.setPixelColor(391 + i, 0);
		
		strip.setPixelColor(210 - i, 0);
		strip.setPixelColor(211 + i, 0);
		
		strip.setPixelColor(59 - i, 0);
		strip.setPixelColor(361 + i, 0);
		
		strip.setPixelColor(89 - i, 0);
		strip.setPixelColor(331 + i, 0);
		
		strip.setPixelColor(119 - i, 0);
		strip.setPixelColor(301 + i, 0);
		
		strip.setPixelColor(149 - i, 0);
		strip.setPixelColor(271 + i, 0);
		
		strip.setPixelColor(179 - i, 0);
		strip.setPixelColor(241 + i, 0);
		
		strip.show();
		delay(wait);
	}
}

void fadeIn () {
	if (brightness == 1) {
		for (int i = 1; i < 256; i++) {
			strip.setBrightness(i);
			strip.show();
		}
	}
	
	brightness = 255;
}

void fadeOut () {
	if (brightness == 255) {
		for (int i = 255; i > 0; i--) {
			strip.setBrightness(i);
			strip.show();
		}
	}
	
	brightness = 1;
}

/**
 * Rainbow fade on each sheet
 */
void rainbow(uint8_t wait) {
	uint16_t i, j;

	for(j=0; j<256; j++) {
		for(i=0; i<strip.numPixels(); i++) {
			strip.setPixelColor(i, Wheel((i+j) & 255));
		}
		
		//fadeIn();

		//strip.show();
		delay(wait);
	}
}

/**
 * Function to light the first sheet and proceed through each 'chakra'
 * illuminating each one by its color as specific intervals
 */
void chakraColors() {
	uint32_t chakras[] = {
		strip.Color(255, 255, 255), // white
		strip.Color(230, 0, 255),   // purple
		strip.Color(34, 0, 255),    // blue
		strip.Color(0, 255, 34),    // green
		strip.Color(255, 247, 0),   // yellow
		strip.Color(255, 111, 0),   // orange
		strip.Color(255, 0, 0)      // red
	};
	
	uint16_t cur = 6;
	int i;
	
	for(i = 29; i >= 0; i--) {
		if (i == 26 || i == 22 || i == 18 || i == 14 || i == 10 || i == 6) {
			cur--;
		}
		
		strip.setPixelColor(i, chakras[cur]);
		strip.setPixelColor(420 - i, chakras[cur]);
		
		strip.show();
		
		delay(50);
		
		strip.setPixelColor(i, 0);
		strip.setPixelColor(420 - i, 0);
	}
}

// Input a value 0 to 255 to get a color value.
uint32_t Wheel(byte WheelPos) {
	if(WheelPos < 85) {
	 return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
	} else if(WheelPos < 170) {
	 WheelPos -= 85;
	 return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
	} else {
	 WheelPos -= 170;
	 return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
	}
}

void fadeSheetTo (int sheet, int sr, int sg, int sb,
						 int er, int	 eg, int eb) {
	int r_diff = er - sr;
	int g_diff = eg - sg;
	int b_diff = eb - sb;
	int steps = 256;
	
	for (int i = 0; i < steps; i++) {
		/*
		nSheetSetColor(
			sheet, 
			sr + i * r_diff / steps,
			sg + i * g_diff / steps,
			sb + i * b_diff / steps
		);
		*/
		
		strip.show();
	}
}
