#include <Adafruit_NeoPixel.h>
#include <sheet.h>

#define PIN 6

/*
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

// Parameter 1 = number of pixels in strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(419, PIN, NEO_GRB + NEO_KHZ800);
*/

Sheet sheet;

void setup() {
	sheet.init();
	/*	
	strip.begin();
	strip.setBrightness(brightness); // Not really necessary, seems that the default of the library is max brightness
	strip.show(); // Initialize all pixels to 'off'
	*/
}

// ========== FUNCTIONS OH MY ============



/**
 * @param uint8 sh - Sheet number (1-7)
 * @param uint16 r - Red Value
 * @param uint16 g - Green Value
 * @param uint16 b - Blue Value
 * @param bool show - Whether or not to update the display
 */
/*	
void setSheetColor (int sh, uint16_t r, uint16_t g, uint16_t b, bool show = false) {
	for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
		strip.setPixelColor(i, r, g, b);
		strip.setPixelColor(419 - i, r, g, b);
	}

	update(show);
}

void fadeSheetTo (int sh, 
				  uint16_t sr, uint16_t sg, uint16_t sb,
				  uint16_t er, uint16_t eg, uint16_t eb,
				  int steps) {
	uint16_t r_diff = er - sr;
	uint16_t g_diff = eg - sg;
	uint16_t b_diff = eb - sb;
	
	for (int i = 0; i < steps; i++) {
		setSheetColor(
			sh, 
			sr + i * r_diff / steps,
			sg + i * g_diff / steps,
			sb + i * b_diff / steps
		);

		strip.show();
	}
}
*/



void loop() {
	for (int i = 0; i < 1; i++) {
		//sheet.RainbowPulse(1);
	}
	//sheet.BlackSpiral(40);

	//sequenceOne();
	//sequenceTwo();
	//sequenceThree();
	//sequenceFour();
	//sequenceFive();
	sequenceSix();

	delay(50);
}

void sequenceOne () {
	sheet.Strobe(1, 10, 255, 255, 255);
	sheet.Strobe(2, 10, 255, 255, 255);
	sheet.Strobe(3, 20, 255, 145, 0);
	sheet.WipeDownColor(1, 255, 145, 0);
	sheet.WipeDownColor(3, 0, 145, 255);
	sheet.WipeDownColor(5, 0, 255, 0);
	sheet.fadeTo(3, 0, 145, 255, 0, 0, 0);
	sheet.fadeTo(5, 0, 255, 0, 0, 0, 0);
	sheet.WipeDownColor(5, 255, 145, 0);
	sheet.WipeDownColor(5, 0, 145, 255);
	sheet.fadeTo(5, 0, 145, 255, 0, 0, 0);
	
	sheet.WipeDownColor(1, 0, 145, 255);
	sheet.WipeDownColor(1, 255, 255, 255);
	sheet.fadeTo(1, 255, 255, 255, 255, 0, 0);
	sheet.WipeDownColor(5, 0, 0, 0);

	sheet.fadeTo(4, 0, 0, 0, 145, 145, 0);
	sheet.Strobe(6, 20, 255, 255, 255);

	sheet.fadeTo(7, 255, 255, 0, 0, 0, 0);
	sheet.fadeTo(4, 145, 145, 0, 0, 0, 0);

	sheet.WipeDownColor(7, 0, 0, 0);
}

// Red & White
void sequenceTwo () {
	sheet.WipeUpColor(1, 255, 255, 255);
	sheet.Strobe(6, 20, 255, 255, 255);
	sheet.WipeDownColor(5, 255, 0, 0);
	sheet.WipeDownColor(1, 255, 0, 0);
	sheet.Strobe(2, 2, 255, 255, 255);
	sheet.Strobe(3, 2, 255, 255, 255);
	sheet.Strobe(4, 2, 255, 255, 255);
	sheet.Strobe(3, 2, 255, 255, 255);
	sheet.Strobe(2, 2, 255, 255, 255);
	sheet.WipeUpColor(5, 255, 255, 255);
	sheet.BlackSpiral(10);
}

void sequenceThree () {
	sheet.StrobeTo(1, 0, 0, 0, 255, 0, 0);
	sheet.StrobeTo(2, 0, 0, 0, 255, 255, 0);
	sheet.StrobeTo(3, 0, 0, 0, 255, 145, 0);
	sheet.StrobeTo(4, 0, 0, 0, 0, 255, 0);
	sheet.StrobeTo(5, 0, 0, 0, 0, 128, 255);
	sheet.StrobeTo(6, 0, 0, 0, 255, 0, 255);
	sheet.StrobeTo(7, 0, 0, 0, 255, 255, 255);
	sheet.BlackSpiral(100);
}

void sequenceFour () {
	sheet.fadeTo(5, 0, 0, 0, 0, 255, 0);
	sheet.WipeDownColor(7, 178, 54, 170);

	sheet.fadeTo(3, 0, 0, 0, 255, 255, 0);
	sheet.WipeUpColor(7, 0, 0, 0);
	
	sheet.WipeDownColor(5, 255, 255, 0);
	sheet.WipeDownColor(7, 178, 54, 170);
	
	sheet.fadeTo(2, 0, 0, 0, 0, 255, 0);
	sheet.WipeUpColor(7, 0, 0, 0);

	sheet.WipeUpColor(3, 0, 255, 0);
	sheet.WipeDownColor(7, 178, 54, 170);
	
	sheet.WipeUpColor(1, 178, 54, 170);
	sheet.WipeUpColor(7, 0, 0, 0);
	
	sheet.WipeDownColor(1, 54, 178, 62);
	sheet.WipeDownColor(7, 178, 54, 170);
	
	sheet.fadeTo(5, 0, 255, 0, 0, 0, 0);
	sheet.WipeUpColor(7, 0, 0, 0);

	sheet.fadeTo(2, 0, 255, 0, 0, 0, 0);
	sheet.fadeTo(3, 255, 255, 0, 0, 0, 0);

	sheet.fadeTo(1, 54, 178, 62, 0, 0, 0);
	
}

void sequenceFive () {
	sheet.Strobe(7, 5, 255, 255, 255);
	sheet.Strobe(6, 5, 255, 255, 255);
	sheet.Strobe(5, 5, 255, 255, 255);
	sheet.Strobe(4, 5, 255, 255, 255);
	sheet.Strobe(3, 5, 255, 255, 255);
	sheet.Strobe(2, 5, 255, 255, 255);
	sheet.Strobe(1, 5, 255, 255, 255);

	sheet.Strobe(7, 4, 255, 255, 255);
	sheet.Strobe(6, 4, 255, 255, 255);
	sheet.Strobe(5, 4, 255, 255, 255);
	sheet.Strobe(4, 4, 255, 255, 255);
	sheet.Strobe(3, 4, 255, 255, 255);
	sheet.Strobe(2, 4, 255, 255, 255);
	sheet.Strobe(1, 4, 255, 255, 255);

	sheet.Strobe(7, 3, 255, 255, 255);
	sheet.Strobe(6, 3, 255, 255, 255);
	sheet.Strobe(5, 3, 255, 255, 255);
	sheet.Strobe(4, 3, 255, 255, 255);
	sheet.Strobe(3, 3, 255, 255, 255);
	sheet.Strobe(2, 3, 255, 255, 255);
	sheet.Strobe(1, 3, 255, 255, 255);

	sheet.Strobe(7, 2, 255, 255, 255);
	sheet.Strobe(6, 2, 255, 255, 255);
	sheet.Strobe(5, 2, 255, 255, 255);
	sheet.Strobe(4, 2, 255, 255, 255);
	sheet.Strobe(3, 2, 255, 255, 255);
	sheet.Strobe(2, 2, 255, 255, 255);
	sheet.Strobe(1, 2, 255, 255, 255);

	sheet.Strobe(7, 1, 255, 255, 255);
	sheet.Strobe(6, 1, 255, 255, 255);
	sheet.Strobe(5, 1, 255, 255, 255);
	sheet.Strobe(4, 1, 255, 255, 255);
	sheet.Strobe(3, 1, 255, 255, 255);
	sheet.Strobe(2, 1, 255, 255, 255);
	sheet.Strobe(1, 1, 255, 255, 255);

	sheet.Strobe(7, 1, 255, 255, 255);
	sheet.Strobe(6, 1, 255, 255, 255);
	sheet.Strobe(5, 1, 255, 255, 255);
	sheet.Strobe(4, 1, 255, 255, 255);
	sheet.Strobe(3, 1, 255, 255, 255);
	sheet.Strobe(2, 1, 255, 255, 255);
	sheet.Strobe(1, 1, 255, 255, 255);

	sheet.Strobe(7, 1, 255, 255, 255);
	sheet.Strobe(6, 1, 255, 255, 255);
	sheet.Strobe(5, 1, 255, 255, 255);
	sheet.Strobe(4, 1, 255, 255, 255);
	sheet.Strobe(3, 1, 255, 255, 255);
	sheet.Strobe(2, 1, 255, 255, 255);
	sheet.Strobe(1, 1, 255, 255, 255);

	sheet.SetColor(1, 255, 255, 255, true);

	sheet.Strobe(7, 1, 255, 0, 0);
	sheet.Strobe(6, 1, 255, 130, 0);
	sheet.Strobe(5, 1, 255, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 125, 0, 255);

	sheet.Strobe(7, 1, 255, 0, 0);
	sheet.Strobe(6, 1, 255, 130, 0);
	sheet.Strobe(5, 1, 255, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 125, 0, 255);

	sheet.Strobe(7, 1, 255, 0, 0);
	sheet.Strobe(6, 1, 255, 130, 0);
	sheet.Strobe(5, 1, 255, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 125, 0, 255);

	sheet.Strobe(7, 1, 255, 0, 0);
	sheet.Strobe(6, 1, 255, 130, 0);
	sheet.Strobe(5, 1, 255, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 125, 0, 255);

	sheet.Strobe(7, 1, 255, 0, 0);
	sheet.Strobe(6, 1, 255, 130, 0);
	sheet.Strobe(5, 1, 255, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 125, 0, 255);

	sheet.Strobe(3, 1, 255, 130, 0);
	sheet.Strobe(4, 1, 255, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 125, 0, 255);

	sheet.Strobe(2, 1, 125, 0, 255);
	sheet.Strobe(3, 1, 255, 130, 0);
	sheet.Strobe(4, 1, 255, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 125, 0, 255);

	sheet.Strobe(2, 1, 125, 0, 255);
	sheet.Strobe(3, 1, 255, 130, 0);
	sheet.Strobe(4, 1, 255, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 125, 0, 255);

	sheet.Strobe(2, 1, 125, 0, 255);
	sheet.Strobe(3, 1, 255, 130, 0);
	sheet.Strobe(4, 1, 255, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 125, 0, 255);

	sheet.Strobe(2, 1, 125, 0, 255);
	sheet.Strobe(3, 1, 255, 130, 0);
	sheet.Strobe(4, 1, 255, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 125, 0, 255);

	sheet.Strobe(2, 2, 125, 0, 255);
	sheet.Strobe(3, 2, 255, 130, 0);
	sheet.Strobe(4, 2, 255, 255, 0);
	sheet.Strobe(5, 2, 0, 255, 0);
	sheet.Strobe(6, 2, 0, 255, 255);
	sheet.Strobe(7, 2, 125, 0, 255);

	sheet.Strobe(2, 3, 125, 0, 255);
	sheet.Strobe(3, 3, 255, 130, 0);
	sheet.Strobe(4, 3, 255, 255, 0);
	sheet.Strobe(5, 3, 0, 255, 0);
	sheet.Strobe(6, 3, 0, 255, 255);
	sheet.Strobe(7, 3, 125, 0, 255);

	sheet.Strobe(2, 4, 125, 0, 255);
	sheet.Strobe(3, 4, 255, 130, 0);
	sheet.Strobe(4, 4, 255, 255, 0);
	sheet.Strobe(5, 4, 0, 255, 0);
	sheet.Strobe(6, 4, 0, 255, 255);
	sheet.Strobe(7, 4, 125, 0, 255);

	sheet.Strobe(2, 5, 125, 0, 255);
	sheet.Strobe(3, 5, 255, 130, 0);
	sheet.Strobe(4, 5, 255, 255, 0);
	sheet.Strobe(5, 5, 0, 255, 0);
	sheet.Strobe(6, 5, 0, 255, 255);
	sheet.Strobe(7, 5, 125, 0, 255);

	sheet.Strobe(1, 1, 125, 0, 255);
	sheet.Strobe(1, 1, 255, 130, 0);
	sheet.Strobe(1, 1, 255, 255, 0);
	sheet.Strobe(1, 1, 0, 255, 0);
	sheet.Strobe(1, 1, 0, 255, 255);
	sheet.Strobe(1, 1, 125, 0, 255);

	sheet.Strobe(1, 1, 125, 0, 255);
	sheet.Strobe(1, 1, 255, 130, 0);
	sheet.Strobe(1, 1, 255, 255, 0);
	sheet.Strobe(1, 1, 0, 255, 0);
	sheet.Strobe(1, 1, 0, 255, 255);
	sheet.Strobe(1, 1, 125, 0, 255);
}

// Can we get some orange
void sequenceSix () {
	sheet.WipeUpColor(2, 0, 0, 0);
	sheet.SetColor(6, 0, 134, 207, true);
	//sheet.SetColor(7, 0, 134, 207, true);
	sheet.WipeDownColor(3, 207, 73, 0);

	sheet.WipeDownColor(1, 176, 0, 207);
	sheet.WipeUpColor(1, 0, 0, 0);

	sheet.WipeDownColor(3, 0, 0, 0);
	sheet.WipeDownColor(2, 207, 73, 0);
	
	sheet.Chakras();
}

/*
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

*/