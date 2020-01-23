
int buzzer = 9;
int buzzAmmount = 5;
int buzz = 0;

void setup(){
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT);
}

void loop(){
	buzz = tone;
buzz = buzz + buzzAmmount;
if (buzz > 20,000 || buzz < 0){
	buzzAmmount = -buzzAmmount;
}

}


