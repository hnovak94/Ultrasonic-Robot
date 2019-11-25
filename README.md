# Ultrasonic Robot

Solidworks, Arduino, Fritzing, and images for our Ultrasonic Robot Project

[Ultrasonic Robot Proposal](https://docs.google.com/document/d/1IroE3nTtVIrWQ_96-GmFiHwg22frUfM-Q0io6C9J3zw/edit)

[Trello](https://trello.com/b/CAv20ek3/ultrasonic-robot-schedule)

## Proposal

### Goal
Our goal is to create an ultrasonic robot that is emotionally expressive depending on the distance from an object to itself. 

### Possible Solutions

* Chirps and beeps
* Eyebrows moved by Servo- Up for happiness and down for anger
* Servo wheels
* LCD screen printing face- Expression changing with distance
* LED matrices- Expression changing with distance
* Different colored LEDs

### Solution

Our ultrasonic will display emotion using different colored LEDs and LED matrices. The ultrasonic sensor will set off different LEDs depending on the distance from an, which will depict one of two different emotions (sadness and happiness). The LED matrices (eyes) will show one of two pictures, which will again depict one of two emotions. If an object or a person in the path of the ultrasonic sensor comes closer than a set distance, the LEDs and the LED matrices will change to show happiness. If an object or person gets farther away, the LEDs and LED matrices will change to show sadness. We will use both translucent and opaque acrylic to manipulate the LEDs. There will be a translucent heart shape on the robot’s chest that the lights will shine through. We will also have two LEDs on either side of the mouth of the robot. For those three locations (two cheeks and heart), we’ll use alternating red and blue LEDs to show happiness and sadness. The last part of the plan is that, depending on distance, a Piezo buzzer will play one of two songs. We chose the songs based on recognizability and emotivity. We picked this solution because we believe it is within our engineering capabilities, and because we think that the combined use of colored LEDs and LED matrices will help our ultrasonic robot accurately depict different emotions.

### Solidworks

* Box to contain wires and Arduino (Robot body)
* Holes
* LED matrices
* Ultrasonic sensor
* 4 Arduino standoffs

### Arduino

* Code LED matrices with ultrasonic sensor 
* Code mood LEDs with ultrasonic sensor
* Code different length beeps with ultrasonic sensor

### Wiring

* Six LEDs (6 digital pins, resistors, GND)
* Two LED Matrices (Wires unknown)
* Ultrasonic Sensor (2 digital pins, 5V, GND)
* Battery (5V, GND)
* Piezo Buzzer (digital pin, GND (resistor))

### Parts and Their Functions
 
* 2 LED Matrix controlled by the ultrasonic sensor- Two different expressions
Sadness: Exp. 1
Happy: Exp. 2
* Motion controlled by the ultrasonic sensor (see below)
* Songs played by buzzer; change with expression
* 6 LEDs-Two different colors; change with expressions (1)
* The top half of the box is translucent- LEDs show through; wires not visible 
* The bottom half of the box is opaque-Wires and Arduino not visible 

### Materials

* 2 LED Matrices ($3.95 each)
* 1 Ultrasonic sensor
* 1 Arduino
* 6 LEDs (3 Red, 3 Blue)
* Breadboard
* Acrylic (Opaque + Translucent)
* Standoffs
* Nuts + Bolts
* Backpack
* Piezo Buzzer
* Battery
* Battery Holder

### Schedule*  Projected Finish Time: 7 WEEKS
Ultrasonic Robot Trello Page

1st WEEK- Finish planning 

2nd WEEK- Split up and do individual work on Arduino Coding + Wiring
			~Jeanne: Sounds + LED Matrices
			~Harriet: Wiring + Coding sounds

3rd WEEK- Finish some of the code and begin Solidworks
			~Jeanne: Done coding LEDs+Sounds with US+(maybe)finish coding LED matrices
			~Harriet: Start making box in Solidworks + help Jeanne finish coding
		
4th WEEK- Finish basic box shape and work on coding
	~Jeanne: Get all the parts to work together
	~Harriet: Finish the box shape

5th WEEK- Make holes in the box and final code touches
	~Jeanne: Done Coding
	~Harriet: Holes in the box

6th WEEK- Begin putting parts together
	~Laser cut box walls
	~Trial + Error, make changes
	~Assemble box

7th WEEK- Final Assembly
	~Box Assembled
	~Everything in the box 

		
*Changes and redesign may be necessary at any of the steps

### Important Links



## Solidworks
Backwall

Frontwall

Topwall

Bottomwall

Rightwall

Leftwall

BoxAssembly

## Arduino Files

## Fritzing Files

Fritzing Diagram with piezo buzzer, 2 LED matrices*, 3 RGB LEDs, Ultrasonic Sensor
![wiring diagram](https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/fritzingdiagram.ultras.robot.JPG)

*Matrices shown in picture are not exactly what are being used; they are placeholders to show the wiring needed. 

### Wiring

5V: red

GND: black

Ultrasonic sensor: blue digital pins

RGB LEDs: orange digital pins

LED matrices: green digital pins

