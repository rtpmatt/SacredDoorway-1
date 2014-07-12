#include <Adafruit_NeoPixel.h>
#include <sheet.h>

Sheet sheet;

void setup() {
	sheet.init();
}

void loop() {
	for (int i = 0; i < 1; i++) {
		//sheet.RainbowPulse(1);
	}
	//sheet.BlackSpiral(40);

	/*
	sheet.fade2xTo(1, 0, 0, 0, 255, 0, 0,
				   2, 0, 0, 0, 0, 255, 0);
	
	sheet.fade3xTo(1, 0, 0, 0, 0, 0, 255,
				   3, 0, 0, 0, 0, 255, 0,
				   5, 0, 0, 0, 255, 0, 0);
	*/
	//sheet.rainbowPulse(1, 0);	
	//testWipeDown();
	//testWipeUp();

	//sequenceOne();
	//sequenceTwo();
	//sequenceThree();
	//sequenceFour();
	//sequenceFive();
	//sequenceSix();

	delay(50);
}

void testWipeDown () {
	sheet.WipeDownColor(1, 255, 0, 0);
	delay(50);
	sheet.SetColor(1, 0, 0, 0, true);

	sheet.WipeDownColor(2, 255, 0, 0);
	delay(50);
	sheet.SetColor(2, 0, 0, 0, true);

	sheet.WipeDownColor(3, 255, 0, 0);
	delay(50);
	sheet.SetColor(3, 0, 0, 0, true);

	sheet.WipeDownColor(4, 255, 0, 0);
	delay(50);
	sheet.SetColor(4, 0, 0, 0, true);

	sheet.WipeDownColor(5, 255, 0, 0);
	delay(50);
	sheet.SetColor(5, 0, 0, 0, true);

	sheet.WipeDownColor(6, 255, 0, 0);
	delay(50);
	sheet.SetColor(6, 0, 0, 0, true);

	sheet.WipeDownColor(7, 255, 0, 0);
	delay(50);
	sheet.SetColor(7, 0, 0, 0, true);
}

void testWipeUp () {
	sheet.WipeUpColor(1, 255, 0, 0);
	delay(50);
	sheet.SetColor(1, 0, 0, 0, true);

	sheet.WipeUpColor(2, 255, 0, 0);
	delay(50);
	sheet.SetColor(2, 0, 0, 0, true);

	sheet.WipeUpColor(3, 255, 0, 0);
	delay(50);
	sheet.SetColor(3, 0, 0, 0, true);

	sheet.WipeUpColor(4, 255, 0, 0);
	delay(50);
	sheet.SetColor(4, 0, 0, 0, true);

	sheet.WipeUpColor(5, 255, 0, 0);
	delay(50);
	sheet.SetColor(5, 0, 0, 0, true);

	sheet.WipeUpColor(6, 255, 0, 0);
	delay(50);
	sheet.SetColor(6, 0, 0, 0, true);

	sheet.WipeUpColor(7, 255, 0, 0);
	delay(50);
	sheet.SetColor(7, 0, 0, 0, true);
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