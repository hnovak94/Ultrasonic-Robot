#include <Adafruit_LEDBackpack.h>

#include <Wire.h>
#include <Adafruit_GFX.h>


//redownload adafruit led backback older eddition




Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
void setup()
{
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  matrix.begin(0x70); // pass in the address
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

void loop()
{
  matrix.clear();
  matrix.drawBitmap(0, 0, eyeopen, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(3000);
  matrix.clear();
  matrix.drawBitmap(0, 0, lookright, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.drawBitmap(0, 0, lookleft, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
  matrix.drawBitmap(0, 0, sadness, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(300);
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
