const int RredPin = 11;
const int RbluePin = 13;

const int LredPin = 10;
const int LbluePin = 12;



void setup() {

pinMode(RredPin, OUTPUT);
pinMode(LredPin, OUTPUT);
pinMode(RbluePin, OUTPUT);
pinMode(LbluePin, OUTPUT);

}

void loop() {
/*
//L Red R Red
digitalWrite(RredPin, LOW);
digitalWrite(RbluePin, HIGH);
digitalWrite(LredPin, LOW);
digitalWrite(LbluePin, HIGH);
delay(1000);

//L Blue R Blue
digitalWrite(RredPin, HIGH);
digitalWrite(RbluePin, LOW);
digitalWrite(LredPin, HIGH);
digitalWrite(LbluePin, LOW);
delay(1000);
*/
//L Purple R Off
digitalWrite(RredPin, HIGH);
digitalWrite(RbluePin, HIGH);

digitalWrite(LredPin, LOW);
digitalWrite(LbluePin, LOW);
delay(1000);

}