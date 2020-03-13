# Ultrasonic Robot ☆

### Solidworks, Arduino, Fritzing, and images for our Ultrasonic Robot Project

- [Ultrasonic Robot Proposal](https://docs.google.com/document/d/1IroE3nTtVIrWQ_96-GmFiHwg22frUfM-Q0io6C9J3zw/edit)

- [Trello](https://trello.com/b/CAv20ek3/ultrasonic-robot-schedule)

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

Our ultrasonic will display emotion using different colored LEDs and LED matrices. The ultrasonic sensor will set off different LEDs depending on the distance from an, which will depict one of two different emotions (sadness and happiness). The LED matrices (eyes) will show one of two pictures, which will again depict one of two emotions. If an object or a person in the path of the ultrasonic sensor comes closer than a set distance, the LEDs and the LED matrices will change to show happiness. If an object or person gets farther away, the LEDs and LED matrices will change to show sadness. We will also have an RGB LED on either side of the mouth of the robot. For those two locations (two cheeks and heart), we’ll use alternating red and blue light to show happiness and sadness. The last part of the plan is that, depending on distance, a Piezo buzzer will play one of two songs. We chose the songs based on recognizability and emotivity. We picked this solution because we believe it is within our engineering capabilities, and because we think that the combined use of colored LEDs and LED matrices will help our ultrasonic robot accurately depict different emotions.

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

* 3 RGBx LEDs (6 digital pins, resistors, GND)
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

### Materials

* 2 LED Matrices ($3.95 each)
* 1 Ultrasonic sensor
* 1 Arduino
* 3 RGB LEDs
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

## Important Links

## Solidworks

### Backwall

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/backwall.robot.JPG?raw=true" width="175">

### Frontwall

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/frontwall.PNG?raw=true" width="175">

### Topwall

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/topwall.PNG?raw=true" width="175">

### Bottomwall

The bottom wall has four holes to hold the Arduino Uno.

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/bottomwall.robot.2.JPG?raw=true" width="225">

### Rightwall

This wall has eight small holes to hold the LED matrices in place, and two large holes to hold the ultrasonic sensor. This part is the front of the robot.

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/rightwall.PNG?raw=true" width="175">

### Leftwall

This wall has a hole at the top left for the SPDT switch and three smaller adjacent holes to hold the battery holder. There are also four holes for the breadboard bracket, and in the bottom left a hole for the USB port. 

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/leftwall.robot.2.JPG?raw=true" width="225">

### BoxAssembly

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/box.robot.2.JPG?raw=true" width="225">

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/insideofbox.JPG?raw=true" width="225">

The first picture shows the outside and "face" of the robot. It shows the ultrasonic sensor and LED matrices. The second picture shows the contents of the inside of the box. Inside is the breadboard, attached with a bracket, the arduino, attached to the floor, the battery holder, an SPDT switch, and the ultrasonic sensor holder. 

### LED Matrix

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/ledmatrix.JPG?raw=true" width="175">

This part I created in Solidworks in order to have something to mate into the assembly. There was no LED matrix part in the shared folder, and I needed to check my measurements. 

### LED Matrix Mount

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/ledmatrixmount.JPG?raw=true" width="175">

This part was created so that the LED matrices would be flush with the wall. The mount is a piece of acrylic that creates space between the matrix and the wall. This enables the matrix to be mounted cleanly. 

### Ultrasonic Sensor Mount

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/us.mount.JPG?raw=true" width="175">

I got this part off of grab CAD. I didn't make it, but I did add two holes to mount it in the wall. This part holds the ultrasonic sensor in place. 

Credit: [GrabCAD](https://grabcad.com/library/ultrasonic-holder-1)

### Breadboard Bracket

<img src="https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/bbbracket.JPG?raw=true" width="175">

This part I created from scratch, based on a model made by another student. It is used to hold the breadboard bracket against the wall, so that it can be secure without the assisstance of adhesive. 

## Arduino Files

### Buzzer songs

Code for the Charlie Brown Theme and All By Myself buzzer songs

### Coding for Sensor

This is our final code with the RGB LEDs, LED matrices, buzzer, working with the ultrasonic sensor. 

### Coding for LEDs

This folder has the file for the RGB LED code and the LED matrices code. 

## Fritzing Files

Fritzing Diagram with piezo buzzer, 2 LED matrices*, 3 RGB LEDs, Ultrasonic Sensor

![fritzing](https://github.com/hnovak94/Ultrasonic-Robot/blob/master/media/fritzingupdated.JPG?raw=true)

*Matrices shown in picture are not exactly what are being used; they are placeholders to show the wiring needed. 

## Wiring

5V (vcc): red, (RGB LEDs - black, GND: black)

Ultrasonic sensor: Echo-blue, Trig-green

RGB LEDs: Color of wire corresponds to color of LED (red with red, blue with blue, etc)

LED matrices: SCL-yellow, SDA-orange

Piezo buzzer: Pin ~9 - white
