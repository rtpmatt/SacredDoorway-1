#include <Adafruit_NeoPixel.h>
#include <sheet.h>

Sheet sheet;

void setup() {
	sheet.init();
}

void loop() {
	for (int i = 0; i < 5; i++) {
		sheet.allRainbowPulse(1);
	}

	sheet.BlackSpiral(20);
	sheet.rainbowPulseStrobe(1);
	sheet.BlackSpiral(20);

	sequenceOne();
	sequenceTwo();
	sequenceThree();
	sequenceFour();
	sequenceFive();
	sequenceSix();
	sequenceSeven();
	sequenceEight();
	sequenceNine();
}

void sequenceOne () {
	sheet.Strobe(1, 20, 255, 255, 255);
	sheet.Strobe(3, 20, 255, 145, 0);

	sheet.wipeDown(1, 255, 145, 0);
	sheet.wipeDown(3, 0, 145, 255);
	sheet.wipeDown(5, 0, 255, 0);
	sheet.fadeTo(3, 0, 145, 255, 0, 0, 0);
	sheet.fadeTo(5, 0, 255, 0, 0, 0, 0);
	sheet.wipeDown(5, 255, 145, 0);
	sheet.wipeDown(5, 0, 145, 255);
	sheet.fadeTo(5, 0, 145, 255, 0, 0, 0);
	
	sheet.wipeDown(1, 0, 145, 255);
	sheet.wipeDown(1, 255, 255, 255);
	sheet.fadeTo(1, 255, 255, 255, 255, 0, 0);
	sheet.wipeDown(5, 0, 0, 0);

	sheet.fadeTo(4, 0, 0, 0, 145, 145, 0);
	sheet.Strobe(6, 20, 255, 255, 255);

	sheet.fadeTo(7, 255, 255, 0, 0, 0, 0);
	sheet.fadeTo(4, 145, 145, 0, 0, 0, 0);

	sheet.wipeDown(7, 0, 0, 0);
}

// Red & White
void sequenceTwo () {
	sheet.wipeUp(1, 255, 255, 255);
	sheet.Strobe(6, 20, 255, 255, 255);
	sheet.wipeDown(5, 255, 0, 0);
	sheet.wipeDown(1, 255, 0, 0);
	sheet.Strobe(2, 2, 255, 255, 255);
	sheet.Strobe(3, 2, 255, 255, 255);
	sheet.Strobe(4, 2, 255, 255, 255);
	sheet.Strobe(3, 2, 255, 255, 255);
	sheet.Strobe(2, 2, 255, 255, 255);
	sheet.wipeUp(5, 255, 255, 255);
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
	sheet.wipeDown(7, 178, 54, 170);

	sheet.fadeTo(3, 0, 0, 0, 255, 255, 0);
	sheet.wipeUp(7, 0, 0, 0);
	
	sheet.wipeDown(5, 255, 255, 0);
	sheet.wipeDown(7, 178, 54, 170);
	
	sheet.fadeTo(2, 0, 0, 0, 0, 255, 0);
	sheet.wipeUp(7, 0, 0, 0);

	sheet.wipeUp(3, 0, 255, 0);
	sheet.wipeDown(7, 178, 54, 170);
	
	sheet.wipeUp(1, 178, 54, 170);
	sheet.wipeUp(7, 0, 0, 0);
	
	sheet.wipeDown(1, 54, 178, 62);
	sheet.wipeDown(7, 178, 54, 170);
	
	sheet.fadeTo(5, 0, 255, 0, 0, 0, 0);
	sheet.wipeUp(7, 0, 0, 0);

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
	sheet.wipeUp(2, 0, 0, 0);
	sheet.SetColor(6, 0, 134, 207, true);
	//sheet.SetColor(7, 0, 134, 207, true);
	sheet.wipeDown(3, 207, 73, 0);

	sheet.wipeDown(1, 176, 0, 207);
	sheet.wipeUp(1, 0, 0, 0);

	sheet.wipeDown(3, 0, 0, 0);
	sheet.wipeDown(2, 207, 73, 0);
	
	sheet.Chakras();
}

void sequenceSeven () {
	sheet.wipeDown(1, 255, 255, 255);
	sheet.wipeDown(1, 0, 0, 0);
	sheet.fade2xTo(3, 0, 0, 0, 255, 132, 0,
				   5, 0, 0, 0, 0, 132, 255);
	sheet.wipeUpRainbow(5);
	sheet.wipeDown(5, 255, 255, 255);
	sheet.fade3xTo(3, 255, 132, 0, 0, 0, 0,
				   2, 0, 0, 0, 255, 132, 0,
				   5, 255, 255, 255, 0, 0, 0);
	sheet.StrobeTo(2, 255, 132, 0, 0, 0, 0);
	sheet.wipeUp(4, 255, 255, 255);
	sheet.StrobeTo(6, 0, 0, 0, 255, 0, 0);
	sheet.StrobeTo(4, 255, 255, 255, 0, 132, 255);
	sheet.fadeTo(4, 0, 132, 255, 0, 0, 0);
}

void sequenceEight () {
	sheet.fade3xTo(3, 0, 0, 0, 255, 255, 0,
				   4, 0, 0, 0, 0, 255, 255,
				   6, 0, 0, 0, 255, 0, 255);
	sheet.fade3xTo(5, 0, 0, 0, 255, 255, 0,
				   3, 255, 255, 0, 255, 0, 255,
				   6, 255, 0, 255, 0, 0, 0);
	sheet.StrobeTo(5, 255, 255, 0, 0, 255, 255);
	sheet.StrobeTo(4, 0, 255, 255, 255, 255, 0);
	sheet.StrobeTo(4, 255, 255, 0, 0, 0, 0);
	sheet.StrobeTo(3, 255, 0, 255, 0, 0, 0);
	sheet.StrobeTo(2, 0, 0, 0, 255, 0, 255);
	sheet.SetColor(2, 255, 0, 255, true);
	sheet.wipeDown(2, 0, 0, 0);
	sheet.wipeUp(1, 255, 255, 0);
	sheet.wipeDown(6, 255, 255, 0);
	sheet.wipeUp(1, 255, 0, 255);
	sheet.wipeDown(6, 255, 0, 255);
	sheet.wipeUp(1, 0, 255, 255);
	sheet.wipeDown(6, 0, 255, 255);
	sheet.wipeUp(1, 0, 0, 0);
	sheet.wipeDown(6, 0, 0, 0);
	sheet.wipeDown(2, 0, 0, 0);

	sheet.fade3xTo(3, 0, 0, 0, 255, 98, 0,
				   4, 0, 0, 0, 0, 255, 98,
				   6, 0, 0, 0, 98, 0, 255);
	sheet.fade3xTo(5, 0, 0, 0, 255, 98, 0,
				   3, 255, 98, 0, 98, 0, 255,
				   6, 98, 0, 255, 0, 0, 0);
	sheet.StrobeTo(5, 255, 98, 0, 0, 255, 98);
	sheet.StrobeTo(4, 0, 255, 98, 255, 98, 0);
	sheet.StrobeTo(4, 255, 98, 0, 0, 0, 0);
	sheet.StrobeTo(3, 98, 0, 255, 0, 0, 0);
	sheet.StrobeTo(2, 0, 0, 0, 98, 0, 255);
	sheet.SetColor(2, 98, 0, 255, true);
	sheet.wipeDown(2, 0, 0, 0);
	sheet.wipeUp(1, 255, 98, 0);
	sheet.wipeDown(6, 255, 98, 0);
	sheet.wipeUp(1, 98, 0, 255);
	sheet.wipeDown(6, 98, 0, 255);
	sheet.wipeUp(1, 0, 255, 98);
	sheet.wipeDown(6, 0, 255, 98);
	sheet.wipeUp(1, 0, 0, 0);
	sheet.wipeDown(6, 0, 0, 0);
	sheet.wipeDown(2, 0, 0, 0);


	sheet.fade3xTo(3, 0, 0, 0, 89, 255, 0,
				   4, 0, 0, 0, 0, 89, 255,
				   6, 0, 0, 0, 255, 0, 89);
	sheet.fade3xTo(5, 0, 0, 0, 89, 255, 0,
				   3, 89, 255, 0, 255, 0, 89,
				   6, 255, 0, 89, 0, 0, 0);
	sheet.StrobeTo(5, 89, 255, 0, 0, 89, 255);
	sheet.StrobeTo(4, 0, 89, 255, 89, 255, 0);
	sheet.StrobeTo(4, 89, 255, 0, 0, 0, 0);
	sheet.StrobeTo(3, 255, 0, 89, 0, 0, 0);
	sheet.StrobeTo(2, 0, 0, 0, 255, 0, 89);
	sheet.SetColor(2, 255, 0, 89, true);
	sheet.wipeDown(2, 0, 0, 0);
	sheet.wipeUp(1, 89, 255, 0);
	sheet.wipeDown(6, 89, 255, 0);
	sheet.wipeUp(1, 255, 0, 89);
	sheet.wipeDown(6, 255, 0, 89);
	sheet.wipeUp(1, 0, 255, 89);
	sheet.wipeDown(6, 0, 255, 89);
	sheet.wipeUp(1, 0, 0, 0);
	sheet.wipeDown(6, 0, 0, 0);
	sheet.wipeDown(2, 0, 0, 0);
}

void sequenceNine () {
	//sheet.rainbowPulseStrobe(1);
	sheet.Strobe(1, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 127, 0, 255);
	sheet.Strobe(3, 1, 255, 0, 0);
	sheet.Strobe(4, 1, 127, 255, 0);
	sheet.Strobe(5, 1, 127, 0, 255);
	sheet.Strobe(6, 1, 255, 0, 0);
	sheet.Strobe(7, 1, 127, 255, 0);

	sheet.Strobe(1, 1, 127, 255, 0);
	sheet.Strobe(2, 1, 0, 255, 255);
	sheet.Strobe(3, 1, 127, 0, 255);
	sheet.Strobe(4, 1, 255, 0, 0);
	sheet.Strobe(5, 1, 127, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 127, 0, 255);

	sheet.Strobe(1, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 127, 0, 255);
	sheet.Strobe(3, 1, 255, 0, 0);
	sheet.Strobe(4, 1, 127, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 255);
	sheet.Strobe(6, 1, 127, 0, 255);
	sheet.Strobe(7, 1, 127, 255, 0);

	sheet.Strobe(1, 1, 127, 0, 255);
	sheet.Strobe(2, 1, 255, 0, 0);
	sheet.Strobe(3, 1, 127, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 255);
	sheet.Strobe(5, 1, 127, 0, 255);
	sheet.Strobe(6, 1, 127, 255, 0);
	sheet.Strobe(7, 1, 0, 255, 255);

	sheet.Strobe(1, 1, 255, 0, 0);
	sheet.Strobe(2, 1, 127, 255, 0);
	sheet.Strobe(3, 1, 0, 255, 255);
	sheet.Strobe(4, 1, 127, 0, 255);
	sheet.Strobe(5, 1, 127, 255, 0);
	sheet.Strobe(6, 1, 0, 255, 255);
	sheet.Strobe(7, 1, 127, 0, 255);

	sheet.Strobe(1, 1, 127, 255, 0);
	sheet.Strobe(2, 1, 0, 255, 255);
	sheet.Strobe(3, 1, 127, 0, 255);
	sheet.Strobe(4, 1, 127, 255, 0);
	sheet.Strobe(5, 1, 0, 255, 255);
	sheet.Strobe(6, 1, 127, 0, 255);
	sheet.Strobe(7, 1, 255, 0, 0);

	sheet.Strobe(1, 1, 0, 255, 255);
	sheet.Strobe(2, 1, 127, 0, 255);
	sheet.Strobe(3, 1, 127, 255, 0);
	sheet.Strobe(4, 1, 0, 255, 255);
	sheet.Strobe(5, 1, 127, 0, 255);
	sheet.Strobe(6, 1, 255, 0, 0);
	sheet.Strobe(7, 1, 127, 255, 0);


	sheet.Strobe(1, 2, 0, 255, 255);
	sheet.Strobe(2, 2, 127, 0, 255);
	sheet.Strobe(3, 2, 255, 0, 0);
	sheet.Strobe(4, 2, 127, 255, 0);
	sheet.Strobe(5, 2, 127, 0, 255);
	sheet.Strobe(6, 2, 255, 0, 0);
	sheet.Strobe(7, 2, 127, 255, 0);

	sheet.Strobe(1, 2, 127, 255, 0);
	sheet.Strobe(2, 2, 0, 255, 255);
	sheet.Strobe(3, 2, 127, 0, 255);
	sheet.Strobe(4, 2, 255, 0, 0);
	sheet.Strobe(5, 2, 127, 255, 0);
	sheet.Strobe(6, 2, 0, 255, 255);
	sheet.Strobe(7, 2, 127, 0, 255);

	sheet.Strobe(1, 2, 0, 255, 255);
	sheet.Strobe(2, 2, 127, 0, 255);
	sheet.Strobe(3, 2, 255, 0, 0);
	sheet.Strobe(4, 2, 127, 255, 0);
	sheet.Strobe(5, 2, 0, 255, 255);
	sheet.Strobe(6, 2, 127, 0, 255);
	sheet.Strobe(7, 2, 127, 255, 0);

	sheet.Strobe(1, 2, 127, 0, 255);
	sheet.Strobe(2, 2, 255, 0, 0);
	sheet.Strobe(3, 2, 127, 255, 0);
	sheet.Strobe(4, 2, 0, 255, 255);
	sheet.Strobe(5, 2, 127, 0, 255);
	sheet.Strobe(6, 2, 127, 255, 0);
	sheet.Strobe(7, 2, 0, 255, 255);

	sheet.Strobe(1, 2, 255, 0, 0);
	sheet.Strobe(2, 2, 127, 255, 0);
	sheet.Strobe(3, 2, 0, 255, 255);
	sheet.Strobe(4, 2, 127, 0, 255);
	sheet.Strobe(5, 2, 127, 255, 0);
	sheet.Strobe(6, 2, 0, 255, 255);
	sheet.Strobe(7, 2, 127, 0, 255);

	sheet.Strobe(1, 2, 127, 255, 0);
	sheet.Strobe(2, 2, 0, 255, 255);
	sheet.Strobe(3, 2, 127, 0, 255);
	sheet.Strobe(4, 2, 127, 255, 0);
	sheet.Strobe(5, 2, 0, 255, 255);
	sheet.Strobe(6, 2, 127, 0, 255);
	sheet.Strobe(7, 2, 255, 0, 0);

	sheet.Strobe(1, 2, 0, 255, 255);
	sheet.Strobe(2, 2, 127, 0, 255);
	sheet.Strobe(3, 2, 127, 255, 0);
	sheet.Strobe(4, 2, 0, 255, 255);
	sheet.Strobe(5, 2, 127, 0, 255);
	sheet.Strobe(6, 2, 255, 0, 0);
	sheet.Strobe(7, 2, 127, 255, 0);


	sheet.Strobe(1, 3, 0, 255, 255);
	sheet.Strobe(2, 3, 127, 0, 255);
	sheet.Strobe(3, 3, 255, 0, 0);
	sheet.Strobe(4, 3, 127, 255, 0);
	sheet.Strobe(5, 3, 127, 0, 255);
	sheet.Strobe(6, 3, 255, 0, 0);
	sheet.Strobe(7, 3, 127, 255, 0);

	sheet.Strobe(1, 3, 127, 255, 0);
	sheet.Strobe(2, 3, 0, 255, 255);
	sheet.Strobe(3, 3, 127, 0, 255);
	sheet.Strobe(4, 3, 255, 0, 0);
	sheet.Strobe(5, 3, 127, 255, 0);
	sheet.Strobe(6, 3, 0, 255, 255);
	sheet.Strobe(7, 3, 127, 0, 255);

	sheet.Strobe(1, 3, 0, 255, 255);
	sheet.Strobe(2, 3, 127, 0, 255);
	sheet.Strobe(3, 3, 255, 0, 0);
	sheet.Strobe(4, 3, 127, 255, 0);
	sheet.Strobe(5, 3, 0, 255, 255);
	sheet.Strobe(6, 3, 127, 0, 255);
	sheet.Strobe(7, 3, 127, 255, 0);

	sheet.Strobe(1, 3, 127, 0, 255);
	sheet.Strobe(2, 3, 255, 0, 0);
	sheet.Strobe(3, 3, 127, 255, 0);
	sheet.Strobe(4, 3, 0, 255, 255);
	sheet.Strobe(5, 3, 127, 0, 255);
	sheet.Strobe(6, 3, 127, 255, 0);
	sheet.Strobe(7, 3, 0, 255, 255);

	sheet.Strobe(1, 3, 255, 0, 0);
	sheet.Strobe(2, 3, 127, 255, 0);
	sheet.Strobe(3, 3, 0, 255, 255);
	sheet.Strobe(4, 3, 127, 0, 255);
	sheet.Strobe(5, 3, 127, 255, 0);
	sheet.Strobe(6, 3, 0, 255, 255);
	sheet.Strobe(7, 3, 127, 0, 255);

	sheet.Strobe(1, 3, 127, 255, 0);
	sheet.Strobe(2, 3, 0, 255, 255);
	sheet.Strobe(3, 3, 127, 0, 255);
	sheet.Strobe(4, 3, 127, 255, 0);
	sheet.Strobe(5, 3, 0, 255, 255);
	sheet.Strobe(6, 3, 127, 0, 255);
	sheet.Strobe(7, 3, 255, 0, 0);

	sheet.Strobe(1, 3, 0, 255, 255);
	sheet.Strobe(2, 3, 127, 0, 255);
	sheet.Strobe(3, 3, 127, 255, 0);
	sheet.Strobe(4, 3, 0, 255, 255);
	sheet.Strobe(5, 3, 127, 0, 255);
	sheet.Strobe(6, 3, 255, 0, 0);
	sheet.Strobe(7, 3, 127, 255, 0);

	sheet.fade3xTo(1, 0, 255, 255, 0, 0, 0,
				   2, 127, 0, 255, 0, 0, 0,
				   3, 127, 255, 0, 0, 0, 0);
	sheet.fade3xTo(4, 0, 255, 255, 0, 0, 0,
				   5, 127, 0, 255, 0, 0, 0,
				   6, 255, 0, 0, 0, 0, 0);
	sheet.fadeTo(7, 127, 255, 0, 0, 0, 0);
}

void sequenceTen () {
	
}