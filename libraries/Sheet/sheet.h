#ifndef sheet_h
#define sheet_h

class Sheet {
  public:
    void
      init (), 
    	SetColor (int sh, uint16_t r, uint16_t g, uint16_t b, bool show),
    	sheetSetColor (uint8_t sh, uint32_t rgb, bool show),
      RainbowPulse (uint8_t wait),
    	fadeTo (int sh, uint16_t sr, uint16_t sg, uint16_t sb, uint16_t er, uint16_t eg, uint16_t eb),
      AllWhite(),
      WipeDownColor(int sh, uint16_t r, uint16_t g, uint16_t b),
      WipeUpColor (int sh, uint16_t r, uint16_t g, uint16_t b),
      Strobe(int sh, int duration, uint16_t r, uint16_t g, uint16_t b),
      StrobeTo (int sh, uint16_t sr, uint16_t sg, uint16_t sb, uint16_t er, uint16_t eg, uint16_t eb),
      BlackSpiral (uint8_t wait),
      Chakras();

  private:
    void update(bool show);
    uint32_t Wheel(byte WheelPos);
};

#endif