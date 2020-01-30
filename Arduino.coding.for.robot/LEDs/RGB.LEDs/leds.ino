 

const int RredPin = 10;
const int RbluePin = 11;
const int LredPin = 12;
const int LbluePin = 8;
// The main code (in void loop) is 
// the opposite of what it depicts because
// the LEDs we used are common anodes which
// means that we use 5V instead of GND (for the long leg)
void setup()
{
	// R = right LED
	// L = left LED
	pinMode(RredPin, OUTPUT);
	pinMode(LredPin, OUTPUT);
	pinMode(RbluePin, OUTPUT);
	pinMode(LbluePin, OUTPUT);
}

void loop()
{
	// These commands make both LEDS turn Red
	// Red represents the happy emotion
	digitalWrite(RredPin, LOW);
	digitalWrite(RbluePin, HIGH);
	digitalWrite(LredPin, LOW);
	digitalWrite(LbluePin, HIGH);
	delay(1000);
	
	// These commands make both LEDs turn Blue
	// Blue represents the sad emotion
	digitalWrite(RredPin, HIGH);
	digitalWrite(RbluePin, LOW);
	digitalWrite(LredPin, HIGH);
	digitalWrite(LbluePin, LOW);
	delay(1000);
	
}
