#include <Adafruit_NeoPixel.h>
#include <sheet.h>

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
Adafruit_NeoPixel* strip;

void Sheet::update (bool show) {
	if (show) {
		strip->show();
	}
}

Sheet::Sheet (Adafruit_NeoPixel s) {
	strip = &s;
}

/**
 * @param uint8 sh - Sheet number (1-7)
 * @param uint16 r - Red Value
 * @param uint16 g - Green Value
 * @param uint16 b - Blue Value
 * @param bool show - Whether or not to update the display
 */	
void Sheet::sheetSetColor(uint8_t sh, uint16_t r, uint16_t g, uint16_t b, bool show = false) {
	for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
		strip->setPixelColor(i, r, g, b);
		strip->setPixelColor(419 - i, r, g, b);
	}

	update(show);
}

void Sheet::sheetSetColor(uint8_t sh, uint32_t rgb, bool show = false) {
	for (int i = sheets[sh - 1]; i < sheets[sh]; i++) {
		strip->setPixelColor(i, rgb);
		strip->setPixelColor(419 - i, rgb);
	}

	update(show);
}

void Sheet::fadeSheetTo (uint8_t sh, 
				  uint16_t sr, uint16_t sg, uint16_t sb,
				  uint16_t er, uint16_t eg, uint16_t eb,
				  uint8_t steps = 256) {
	uint16_t r_diff = er - sr;
	uint16_t g_diff = eg - sg;
	uint16_t b_diff = eb - sb;
	
	for (uint8_t i = 0; i < steps; i++) {
		sheetSetColor(
			sh, 
			sr + i * r_diff / steps,
			sg + i * g_diff / steps,
			sb + i * b_diff / steps
		);
		
		strip->show();
	}
}