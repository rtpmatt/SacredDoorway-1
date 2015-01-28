#include <Adafruit_NeoPixel.h>
#include <sheet.h>

#define PIN 7

int sheets[8] = {
	0,
	30,
	60,
	90,
	120,
	150,
	180,
	210			
};
int end = 419;
int brightness = 255;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(419, PIN, NEO_GRB + NEO_KHZ800);

void Sheet::update (bool show) {
	if (show) {
		strip.show();
	}
}

void Sheet::init () {
	strip.begin();
	strip.setBrightness(brightness); // Not really necessary, seems that the default of the library is max brightness
	strip.show(); // Initialize all pixels to 'off'
}

/**
 * @param uint8 sh - Sheet number (1-7)
 * @param uint16 r - Red Value
 * @param uint16 g - Green Value
 * @param uint16 b - Blue Value
 * @param bool show - Whether or not to update the display
 */	
void Sheet::SetColor(int sh, uint16_t r, uint16_t g, uint16_t b, bool show = false) {
	for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
		strip.setPixelColor(i, r, g, b);
		strip.setPixelColor(419 - i, r, g, b);
	}

	update(show);
}

void Sheet::fadeTo (int sh, 
					uint16_t sr, uint16_t sg, uint16_t sb,
					uint16_t er, uint16_t eg, uint16_t eb) {
	uint16_t r_diff = er - sr;
	uint16_t g_diff = eg - sg;
	uint16_t b_diff = eb - sb;
	int steps = 256;
	
	for (int i = 0; i < steps; i++) {
		SetColor(	
			sh, 
			sr + i * r_diff / steps,
			sg + i * g_diff / steps,
			sb + i * b_diff / steps,
			true
		);	
	}
}

void Sheet::fade2xTo (int sh1, uint16_t sr1, uint16_t sg1, uint16_t sb1, uint16_t er1, uint16_t eg1, uint16_t eb1,
					  int sh2, uint16_t sr2, uint16_t sg2, uint16_t sb2, uint16_t er2, uint16_t eg2, uint16_t eb2) {
	int steps = 256;
	
	for (int i = 0; i < steps; i++) {
		SetColor(	
			sh1, 
			sr1 + i * (er1 - sr1) / steps,
			sg1 + i * (eg1 - sg1) / steps,
			sb1 + i * (eb1 - sb1) / steps,
			false
		);

		SetColor(	
			sh2, 
			sr2 + i * (er2 - sr2) / steps,
			sg2 + i * (eg2 - sg2) / steps,
			sb2 + i * (eb2 - sb2) / steps,
			false
		);

		strip.show();
	}
}

void Sheet::fade3xTo (int sh1, uint16_t sr1, uint16_t sg1, uint16_t sb1, uint16_t er1, uint16_t eg1, uint16_t eb1,
					  int sh2, uint16_t sr2, uint16_t sg2, uint16_t sb2, uint16_t er2, uint16_t eg2, uint16_t eb2,
					  int sh3, uint16_t sr3, uint16_t sg3, uint16_t sb3, uint16_t er3, uint16_t eg3, uint16_t eb3) {
	int steps = 256;
	
	for (int i = 0; i < steps; i++) {
		SetColor(	
			sh1, 
			sr1 + i * (er1 - sr1) / steps,
			sg1 + i * (eg1 - sg1) / steps,
			sb1 + i * (eb1 - sb1) / steps,
			false
		);

		SetColor(	
			sh2, 
			sr2 + i * (er2 - sr2) / steps,
			sg2 + i * (eg2 - sg2) / steps,
			sb2 + i * (eb2 - sb2) / steps,
			false
		);

		SetColor(	
			sh3, 
			sr3 + i * (er3 - sr3) / steps,
			sg3 + i * (eg3 - sg3) / steps,
			sb3 + i * (eb3 - sb3) / steps,
			false
		);

		strip.show();
	}
}

void Sheet::allRainbowPulse (uint8_t wait) {
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
		
		strip.show();
		
		delay(wait);
	}
}

void Sheet::rainbowPulse (int sh, int wait) {	
	for(int j = 0 ; j < 255; j++) {
		for(int i = sheets[sh - 1]; i < sheets[sh]; i++) {
			strip.setPixelColor(i, Wheel(j));
			strip.setPixelColor(419 - i, Wheel(j));
		}
		
		strip.show();
		
		delay(wait);
	}
}

void Sheet::rainbowPulseStrobe (int sh) {
	for(int j = 0 ; j < 255; j++) {
		for(int i = sheets[sh - 1]; i < sheets[sh]; i++) {
			strip.setPixelColor(i, Wheel(j));
			strip.setPixelColor(419 - i, Wheel(j));
		}
		strip.show();
		
		SetColor(sh, 0, 0, 0, true);
		delay(20);
	}
}

void Sheet::allRainbowPulseStrobe () {
	int i;

	for(int j = 0 ; j < 255; j++) {
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
		strip.show();
		
		SetColor(1, 0, 0, 0, false);
		SetColor(2, 0, 0, 0, false);
		SetColor(3, 0, 0, 0, false);
		SetColor(4, 0, 0, 0, false);
		SetColor(5, 0, 0, 0, false);
		SetColor(6, 0, 0, 0, false);
		SetColor(7, 0, 0, 0, true);

		delay(20);
	}
}

void Sheet::AllWhite() {
	uint16_t pixel;
	for (pixel = 0; pixel < 210; pixel++) {
		strip.setPixelColor(pixel, 255, 255, 255);
		strip.setPixelColor(419 - pixel, 255, 255, 255);
		
		strip.show();
		delay(1);
	}
}

void Sheet::wipeDown (int sh, uint16_t r, uint16_t g, uint16_t b) {
	if (sh == 2 || sh == 4 || sh == 6) {
		for (int i = sheets[sh]; i > sheets[sh - 1]; i--) {
			strip.setPixelColor(i, r, g, b);
			strip.setPixelColor(419 - i, r, g, b);
			
			strip.show();
			delay(30);
		}
	}
	else {
		for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
			strip.setPixelColor(i, r, g, b);
			strip.setPixelColor(419 - i, r, g, b);
			
			strip.show();
			delay(30);
		}
	}
}

void Sheet::wipeUp (int sh, uint16_t r, uint16_t g, uint16_t b) {
	if (sh == 2 || sh == 4 || sh == 6) {
		for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
			strip.setPixelColor(i, r, g, b);
			strip.setPixelColor(419 - i, r, g, b);
			
			strip.show();
			delay(30);
		}
	}
	else {
		for (int i = sheets[sh]; i > sheets[sh - 1]; i--) {
			strip.setPixelColor(i, r, g, b);
			strip.setPixelColor(419 - i, r, g, b);
			
			strip.show();
			delay(30);
		}
	}
}

void Sheet::wipeUp (int sh, uint32_t rgb) {
	if (sh == 2 || sh == 4 || sh == 6) {
		for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
			strip.setPixelColor(i, rgb);
			strip.setPixelColor(419 - i, rgb);
			
			strip.show();
			delay(50);
		}
	}
	else {
		for (int i = sheets[sh]; i > sheets[sh - 1]; i--) {
			strip.setPixelColor(i, rgb);
			strip.setPixelColor(419 - i, rgb);
			
			strip.show();
			delay(50);
		}
	}
}

void Sheet::wipeUpRainbow (int sh) {
	int color = 0;
	while (color < 256) {
		wipeUp(sh, Wheel(color));
		color = color + 32;
	}
}

void Sheet::Strobe (int sh, int duration, uint16_t r, uint16_t g, uint16_t b) {
	for (int i = 0; i < duration; i++) {
		SetColor(sh, r, g, b, true);
		delay(20);
		SetColor(sh, 0, 0, 0, true);
		delay(20);
	}
}

void Sheet::StrobeTo (int sh, 
					  uint16_t sr, uint16_t sg, uint16_t sb,
					  uint16_t er, uint16_t eg, uint16_t eb) {
	uint16_t r_diff = er - sr;
	uint16_t g_diff = eg - sg;
	uint16_t b_diff = eb - sb;
	int steps = 32;
	
	for (int i = 0; i < steps; i++) {
		SetColor(	
			sh, 
			sr + i * r_diff / steps,
			sg + i * g_diff / steps,
			sb + i * b_diff / steps,
			true
		);

		SetColor(	
			sh, 
			0,
			0,
			0,
			true
		);
		delay(20);
	}
}

void Sheet::BlackSpiral (uint8_t wait) {
	uint16_t i;
	for (i = 0; i < 30; i++) {
		strip.setPixelColor(i, 0);
		strip.setPixelColor(390 + i, 0);
		
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
		
		strip.setPixelColor(180 - i, 0);
		strip.setPixelColor(241 + i, 0);
		
		strip.show();
		delay(wait);
	}
}

void Sheet::spiralTo(int sh, uint16_t r, uint16_t g, uint16_t b) {
	for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
		strip.setPixelColor(i, r, g, b);
		int offset = 419 - 30;
		strip.setPixelColor(offset + i, r, g, b);
		strip.show();
		delay(20);
	}
}

void Sheet::Chakras() {
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
		
		delay(20);
		
		strip.setPixelColor(i, 0);
		strip.setPixelColor(420 - i, 0);
	}
}

uint32_t Sheet::Wheel(byte WheelPos) {
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