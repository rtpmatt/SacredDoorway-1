#ifndef sheet_h
#define sheet_h

class Sheet {
	public:
		Sheet (Adafruit_NeoPixel s);
  		void 
  			sheetSetColor (uint8_t sh, uint16_t r, uint16_t g, uint16_t b, bool show),
  			fadeSheetTo (uint8_t sh, uint16_t sr, uint16_t sg, uint16_t sb, uint16_t er, uint16_t eg, uint16_t eb, uint8_t steps);
};

#endif