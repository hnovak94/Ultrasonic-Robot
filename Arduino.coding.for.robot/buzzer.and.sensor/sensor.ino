// I could not easily find a favorable library that included every
// note and tone, so I had to include all of this which took up a
// lot of space. I would reccomend finding a library.
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
// matrix setup:
#include <Wire.h>
#include <Adafruit_GFX.h> // I found these libraries on the Adafruit website.
#include "Adafruit_LEDBackpack.h" // Found this one as well
Adafruit_8x8matrix matrix = Adafruit_8x8matrix(); // this declares a matrix as an object, this becomes handy when you have more than  one
// ultrasonic sensor setup:
#include <NewPing.h> // I use this library to help clear up my code, this helps to control the ultrasonic sensor
#define TRIGGER_PIN 6 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 2 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
// buzzer setup:
#include <NewTone.h> // I needed to use this because otherwise Tone and NewPing were using the same timer
int buzzer = 9; 
int sadCounter = 0; // this sets both counters to 0, because otherwise it has no idea at what number/song it should start
int happyCounter = 0; // same here
// RGB leds setup:
const int RredPin = 10; // R = Right LED, just helps to distinguish between the two RGB LEDs
const int RbluePin = 11;
const int LredPin = 12; // L = Left LED
const int LbluePin = 8;
void setup()
{
	Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
	pinMode(buzzer, OUTPUT);
	pinMode(TRIGGER_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	pinMode(RredPin, OUTPUT);
	pinMode(LredPin, OUTPUT);
	pinMode(RbluePin, OUTPUT);
	pinMode(LbluePin, OUTPUT);
	matrix.begin(0x70); // This sets up the adress for the matrix. You can change the adress by using soder, and then the adresses can be 0x71, 0x72, etc
}

static const uint8_t PROGMEM
eyeopen[] = // each eye image needed its own bitmap, so this one is its neutral, open eye position
{
	B00111100,
	B01111110,
	B11100111,
	B11100111,
	B11111111,
	B11111111,
	B01111110,
	B00111100
},

blink_step1[] = // to make the eyes blink,I had to create images that when combined,
// would make the eyes appear as if they were closing and opening quickly (blinking)
{
	B00111100,
	B01111110,
	B11100111,
	B11100111,
	B11111111,
	B11111111,
	B01111110,
	B00111100
},

blink_step2[] =
{
	B00000000,
	B00111100,
	B11100111,
	B11100111,
	B11111111,
	B00111100,
	B00000000,
	B00000000
},

blink_step3[] =
{
	B00000000,
	B00000000,
	B00000000,
	B11100111,
	B01111110,
	B00011000,
	B00000000,
	B00000000
},

blink_step4[] =
{
	B00000000,
	B00000000,
	B00000000,
	B10000001,
	B01111110,
	B00000000,
	B00000000,
	B00000000
};

static const uint8_t PROGMEM
lookright[] = // eyes look right
{
	B00111100,
	B01111110,
	B11110011,
	B11110011,
	B11111111,
	B11111111,
	B01111110,
	B00111100
},

lookleft[] = // eyes look left
{
	B00111100,
	B01111110,
	B11001111,
	B11001111,
	B11111111,
	B11111111,
	B01111110,
	B00111100
};

static const uint8_t PROGMEM
sadness[] = // this image makes the robot seem sad
{
	B00000000,
	B00000000,
	B10000001,
	B10000001,
	B01000010,
	B00111100,
	B00000000,
	B00000000
};

static const uint8_t PROGMEM
ecstaticness[] =
{
	B00000000,
	B00000000,
	B00111100,
	B01111110,
	B10000001,
	B10000001,
	B00000000,
	B00000000
};

void loop()
{
	unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
	uS = sonar.convert_cm(uS);
	Serial.print("Ping: ");
	Serial.print(uS); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
	Serial.println("cm");
	if (uS > 0 && uS < 50)
	{
		if (uS <= 15)
		{
			happysong();
			happyeyes();
		}
		else
			if (uS >= 16)
			{
				sadsong();
				sadeyes();
			}
	}
}

int sadsong()
{
	happyCounter = 0;
	sadCounter++;
	if (sadCounter == 4)
		sadCounter = 0;
	if (sadCounter == 0)
	{
		blueison();
		NewTone(buzzer, NOTE_E5);
		delay(750);
		NewTone(buzzer, NOTE_B5);
		delay(750);
		NewTone(buzzer, NOTE_CS6);
		delay(750);
		NewTone(buzzer, NOTE_E5);
		delay(750);
		NewTone(buzzer, NOTE_FS5);
		delay(300);
		NewTone(buzzer, NOTE_E5);
		delay(750);
	}
	if (sadCounter == 1)
	{
		blueison();
		NewTone(buzzer, NOTE_CS5);
		delay(250);
		noNewTone(buzzer);
		delay(100);
		NewTone(buzzer, NOTE_CS5);
		delay(250);
		NewTone(buzzer, NOTE_D5);
		delay(400);
		NewTone(buzzer, NOTE_E5);
		delay(750);
		noNewTone(buzzer);
		delay(500);
	}
	if (sadCounter == 2)
	{
		blueison();
		NewTone(buzzer, NOTE_E5);
		delay(750);
		NewTone(buzzer, NOTE_B5);
		delay(650);
		NewTone(buzzer, NOTE_CS6);
		delay(500);
		NewTone(buzzer, NOTE_D6);
		delay(250);
		NewTone(buzzer, NOTE_CS6);
		delay(500);
		NewTone(buzzer, NOTE_D5);
		delay(1000);
	}
	if (sadCounter == 3)
	{
		noNewTone(buzzer);
		delay(2000);
	}
}

int happysong()
{
	sadCounter = 0;
	happyCounter++;
	if (happyCounter == 4)
		happyCounter = 0;
	if (happyCounter == 0)
	{
		redison();
		NewTone(buzzer, NOTE_GS3);
		delay(350);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_GS4);
		delay(125);
		NewTone(buzzer, NOTE_GS3);
		delay(100);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_GS4);
		delay(200);
		noNewTone(buzzer);
		delay(25);
		NewTone(buzzer, NOTE_GS3);
		delay(350);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_F4);
		delay(125);
		NewTone(buzzer, NOTE_GS3);
		delay(100);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_F4);
		delay(200);
		noNewTone(buzzer);
		delay(25);
	}
	if (happyCounter == 1)
	{
		redison();
		NewTone(buzzer, NOTE_GS3);
		delay(350);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_GS4);
		delay(125);
		NewTone(buzzer, NOTE_GS3);
		delay(100);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_GS4);
		delay(200);
		noNewTone(buzzer);
		delay(25);
		NewTone(buzzer, NOTE_GS3);
		delay(350);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_F4);
		delay(125);
		NewTone(buzzer, NOTE_GS3);
		delay(100);
		NewTone(buzzer, NOTE_DS4);
		delay(100);
		NewTone(buzzer, NOTE_F4);
		delay(250);
		noNewTone(buzzer);
		delay(200);
	}
	if (happyCounter == 2)
	{
		redison();
		NewTone(buzzer, NOTE_GS5);
		delay(200);
		NewTone(buzzer, NOTE_AS5);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(200);
		noNewTone(buzzer);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(200);
		NewTone(buzzer, NOTE_AS5);
		delay(200);
		NewTone(buzzer, NOTE_GS5);
		delay(350);
		// --------
		NewTone(buzzer, NOTE_AS5);
		delay(525);
		NewTone(buzzer, NOTE_GS5);
		delay(600);
		noNewTone(buzzer);
		delay(200);
		NewTone(buzzer, NOTE_GS5);
		delay(200);
		NewTone(buzzer, NOTE_AS5);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(200);
		noNewTone(buzzer);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(1000);
		noNewTone(buzzer);
		delay(300);
	}
	if (happyCounter == 3)
	{
		redison();
		NewTone(buzzer, NOTE_GS5);
		delay(200);
		NewTone(buzzer, NOTE_AS5);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(200);
		noNewTone(buzzer);
		delay(200);
		NewTone(buzzer, NOTE_C6);
		delay(200);
		NewTone(buzzer, NOTE_AS5);
		delay(200);
		NewTone(buzzer, NOTE_GS5);
		delay(350);
		// --------
		NewTone(buzzer, NOTE_AS5);
		delay(525);
		NewTone(buzzer, NOTE_GS5);
		delay(600);
		noNewTone(buzzer);
		delay(200);
		NewTone(buzzer, NOTE_GS5);
		delay(500);
		NewTone(buzzer, NOTE_AS5);
		delay(150);
		noNewTone(buzzer);
		delay(100);
		NewTone(buzzer, NOTE_AS5);
		delay(875);
		noNewTone(buzzer);
		delay(300);
	}
	if (happyCounter == 4)
	{
		noNewTone(buzzer);
		delay(2000);
	}
}

int blueison()
// turns on both blue leds
{
	digitalWrite(RredPin, HIGH);
	digitalWrite(RbluePin, LOW);
	digitalWrite(LredPin, HIGH);
	digitalWrite(LbluePin, LOW);
}

int redison()
// turns on both red leds
{
	digitalWrite(RredPin, LOW);
	digitalWrite(RbluePin, HIGH);
	digitalWrite(LredPin, LOW);
	digitalWrite(LbluePin, HIGH);
}

int sadeyes()
{
	matrix.clear();
	matrix.drawBitmap(0, 0, sadness, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(300);
}

int blink()
{
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step1, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step2, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step3, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step4, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step3, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step2, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
	matrix.clear();
	matrix.drawBitmap(0, 0, blink_step1, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(100);
}

int happyeyes()
{
	matrix.clear();
	matrix.drawBitmap(0, 0, ecstaticness, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(3000);
}
