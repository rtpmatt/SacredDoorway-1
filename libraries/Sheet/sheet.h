#ifndef sheet_h
#define sheet_h

class Sheet {
	public:
		void
			init (), 
			SetColor (int sh, uint16_t r, uint16_t g, uint16_t b, bool show),
			allRainbowPulse (uint8_t wait),
			rainbowPulse (int sh, int wait),
			rainbowPulseStrobe (int sh),
			fadeTo (int sh, uint16_t sr, uint16_t sg, uint16_t sb, uint16_t er, uint16_t eg, uint16_t eb),
			fade2xTo (int sh1, uint16_t sr1, uint16_t sg1, uint16_t sb1, uint16_t er1, uint16_t eg1, uint16_t eb1,
					  int sh2, uint16_t sr2, uint16_t sg2, uint16_t sb2, uint16_t er2, uint16_t eg2, uint16_t eb2),
			fade3xTo (int sh1, uint16_t sr1, uint16_t sg1, uint16_t sb1, uint16_t er1, uint16_t eg1, uint16_t eb1,
               		  int sh2, uint16_t sr2, uint16_t sg2, uint16_t sb2, uint16_t er2, uint16_t eg2, uint16_t eb2,
               		  int sh3, uint16_t sr3, uint16_t sg3, uint16_t sb3, uint16_t er3, uint16_t eg3, uint16_t eb3),
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