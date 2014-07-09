#include <Adafruit_NeoPixel.h>
#include "sheet.h"

#define PIN 6

// Parameter 1 = number of pixels in strip
Adafruit_NeoPixel s = Adafruit_NeoPixel(419, PIN, NEO_GRB + NEO_KHZ800);
Sheet sheet(s);

uint8_t brightness = 1;

void setup() {
	s.begin();
	s.setBrightness(brightness); // Not really necessary, seems that the default of the library is max brightness
	s.show(); // Initialize all pixels to 'off'
}

void loop() {
	// Using the Sheet class...
	//sheet.fadeSheetTo(1, 0, 0, 0, 255, 171, 0); // sheet 1 black to orange
	//sheet.fadeSheetTo(1, 255, 171, 0, 255, 255, 255); // sheet 1 orange to white
	//sheet.fadeSheetTo(5, 0, 0, 0, 0, 255, 0); // Sheet 1 still orange, sheet 5 black to green
}

/*
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
*/