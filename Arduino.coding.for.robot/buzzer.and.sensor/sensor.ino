#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
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
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
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
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
// ultrasonic sensor setup:
const int trigPin = 6;
const int echoPin = 2;
int timeSinceObject;
int duration, cm;
// buzzer setup:
int buzzer = 9;
int sadCounter = 0;
int happyCounter = 0;
// RGB leds setup:
const int RredPin = 10;
const int RbluePin = 11;
const int LredPin = 12;
const int LbluePin = 8;
boolean emotion = false;
void setup()
{
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(RredPin, OUTPUT);
	pinMode(LredPin, OUTPUT);
	pinMode(RbluePin, OUTPUT);
	pinMode(LbluePin, OUTPUT);
	matrix.begin(0x70);
	// false = sad
	// true = happy
	// 
	// 
	// 
	// 
	// 
}

static const uint8_t PROGMEM
eyeopen[] =
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

blink_step1[] =
{
	B00000000,
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
lookright[] =
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

lookleft[] =
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
happiness[] =
{
	B00011000,
	B00100100,
	B01000010,
	B01011010,
	B01100110,
	B01000010,
	B00000000,
	B00000000
};

static const uint8_t PROGMEM
sadness[] =
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

// 
// 
// 
// 
// 
void loop()
{
	cm = getDistance();
	cm = microsecondsToCentimeters(timeSinceObject);
	if (cm <= 10)
	{
		emotion = true;
	}
	if (cm >= 11)
	{
		emotion = false;
	}
	if (cm > 0 && cm < 100)
	{
		if (emotion == true)
		{
			happysong();
			redison();
			happyeyes();
			blink();
		}
		if (emotion == false)
		{
			sadsong();
			blueison();
			sadeyes();
			blink();
		}
	}
	Serial.println(cm);
	delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
	return microseconds / 29 / 2;
}

int getDistance()
{
	pinMode(trigPin, OUTPUT);
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	pinMode(echoPin, INPUT);
	timeSinceObject = pulseIn(echoPin, HIGH);
	return cm;
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
		tone(buzzer, NOTE_E5);
		delay(750);
		tone(buzzer, NOTE_B5);
		delay(750);
		tone(buzzer, NOTE_CS6);
		delay(750);
		tone(buzzer, NOTE_E5);
		delay(750);
		tone(buzzer, NOTE_FS5);
		delay(300);
		tone(buzzer, NOTE_E5);
		delay(750);
	}
	if (sadCounter == 1)
	{
		blueison();
		tone(buzzer, NOTE_CS5);
		delay(250);
		noTone(buzzer);
		delay(100);
		tone(buzzer, NOTE_CS5);
		delay(250);
		tone(buzzer, NOTE_D5);
		delay(400);
		tone(buzzer, NOTE_E5);
		delay(750);
		noTone(buzzer);
		delay(500);
	}
	if (sadCounter == 2)
	{
		blueison();
		tone(buzzer, NOTE_E5);
		delay(750);
		tone(buzzer, NOTE_B5);
		delay(650);
		tone(buzzer, NOTE_CS6);
		delay(500);
		tone(buzzer, NOTE_D6);
		delay(250);
		tone(buzzer, NOTE_CS6);
		delay(500);
		tone(buzzer, NOTE_D5);
		delay(1000);
	}
	if (sadCounter == 3)
	{
		noTone(buzzer);
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
		tone(buzzer, NOTE_GS3);
		delay(450);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_GS4);
		delay(225);
		tone(buzzer, NOTE_GS3);
		delay(200);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_GS4);
		delay(300);
		noTone(buzzer);
		delay(50);
		tone(buzzer, NOTE_GS3);
		delay(450);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_F4);
		delay(225);
		tone(buzzer, NOTE_GS3);
		delay(200);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_F4);
		delay(300);
		noTone(buzzer);
		delay(50);
	}
	if (happyCounter == 1)
	{
		redison();
		tone(buzzer, NOTE_GS3);
		delay(450);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_GS4);
		delay(225);
		tone(buzzer, NOTE_GS3);
		delay(200);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_GS4);
		delay(300);
		noTone(buzzer);
		delay(50);
		tone(buzzer, NOTE_GS3);
		delay(450);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_F4);
		delay(225);
		tone(buzzer, NOTE_GS3);
		delay(200);
		tone(buzzer, NOTE_DS4);
		delay(200);
		tone(buzzer, NOTE_F4);
		delay(350);
		noTone(buzzer);
		delay(300);
	}
	if (happyCounter == 2)
	{
		redison();
		tone(buzzer, NOTE_GS5);
		delay(200);
		tone(buzzer, NOTE_AS5);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(200);
		noTone(buzzer);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(200);
		tone(buzzer, NOTE_AS5);
		delay(200);
		tone(buzzer, NOTE_GS5);
		delay(350);
		// --------
		tone(buzzer, NOTE_AS5);
		delay(525);
		tone(buzzer, NOTE_GS5);
		delay(600);
		noTone(buzzer);
		delay(200);
		tone(buzzer, NOTE_GS5);
		delay(200);
		tone(buzzer, NOTE_AS5);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(200);
		noTone(buzzer);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(1000);
		noTone(buzzer);
		delay(300);
	}
	if (happyCounter == 3)
	{
		redison();
		tone(buzzer, NOTE_GS5);
		delay(200);
		tone(buzzer, NOTE_AS5);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(200);
		noTone(buzzer);
		delay(200);
		tone(buzzer, NOTE_C6);
		delay(200);
		tone(buzzer, NOTE_AS5);
		delay(200);
		tone(buzzer, NOTE_GS5);
		delay(350);
		// --------
		tone(buzzer, NOTE_AS5);
		delay(525);
		tone(buzzer, NOTE_GS5);
		delay(600);
		noTone(buzzer);
		delay(200);
		tone(buzzer, NOTE_GS5);
		delay(500);
		tone(buzzer, NOTE_AS5);
		delay(150);
		noTone(buzzer);
		delay(100);
		tone(buzzer, NOTE_AS5);
		delay(875);
		noTone(buzzer);
		delay(300);
	}
	if (happyCounter == 4)
	{
		noTone(buzzer);
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
	matrix.drawBitmap(0, 0, eyeopen, 8, 8, LED_ON);
	matrix.writeDisplay();
	delay(3000);
}
