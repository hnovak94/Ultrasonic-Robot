#include <MD_MAX72xx.h> // We use this to control the 8x8 LED matrix Displays - You'll need to install this library from the library manager if you donb't already have it.
#include <NewPing.h> // We use NewPing to control the Ultrasonic Sensors - You'll need to install this library from the library manager if you donb't already have it.

// define pins attached to LED matrix display 1
//#define  CLK_PIN   13  // We are using hardware SPI - make sure you have connected the CLK pin to the hardware CLK pin on your device
//#define DATA_PIN  11  // We are using hardware SPI - make sure you have connected the MOSI pin to the hardware MOSI pin on your device
#define CS_PIN    10  // Chip Select pin
#define  MAX_DEVICES 2 // number of displays - we need 2, one for each eye

#define LIGHT A5 // We use Analogue pin 5 to read the light value from the LDR

// We are using hardware SPI which automatically 
MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES); // Initialise the 2 Matrix displays

#define  t1  2  // Trigger pin on Ultrasonic Sensor 1
#define  e1  3  // Echo pin on Ultrasonic Sensor 1
#define  t2  4  // Trigger pin on Ultrasonic Sensor 2
#define  e2  5  // Echo pin on Ultrasonic Sensor 2
#define maxDist 400 // the max distance for the ultrasonic pulse

NewPing eyeR(t2, e2, maxDist ); // Initialise Ultrasonic sensor 2
NewPing eyeL(t1, e1, maxDist ); // Initialise Ultrasonic sensor 1

// We track the current state of the system with this integer variable, this way after a blink, we can out the eyes back to looking at the last direction they were in
// Possible states are:
// 0: Looking forward
// 1: Looking Right
// 2: Looking Left
int currentState = -1; 

// We store the time and distance for the pings for each Ultrasonic sensor in these variables
long duration1, duration2;
int distance1, distance2;

// We want the blink to be randomly inserted into the cycle
float nextBlink = millis() + 1000;

// We store the current light intensity in this variable
float lightAmount = 0;

uint8_t eye_forward[COL_SIZE] =
{
  0b00111100,
  0b01000010,
  0b01011010,
  0b10101101,
  0b10111101,
  0b10011001,
  0b01000010,
  0b00111100
};

uint8_t eye_right[COL_SIZE] =
{
  0b00111100,
  0b01000010,
  0b01110010,
  0b11011001,
  0b11111001,
  0b10110001,
  0b01000010,
  0b00111100
};

uint8_t eye_left[COL_SIZE] =
{
  0b00111100,
  0b01000010,
  0b01001110,
  0b10010111,
  0b10011111,
  0b10001101,
  0b01000010,
  0b00111100
};

uint8_t eye_blink[COL_SIZE] =
{
  0b00000000,
  0b00111100,
  0b01111110,
  0b11111111,
  0b10111101,
  0b11000011,
  0b01111110,
  0b00111100
};

void setup()
{
  // Initialise the Matrix Display library
  mx.begin();

  // Set the pin modes for Ultrasonic sensor 1
  pinMode( t1, OUTPUT );
  pinMode( e1, INPUT );

  // Set the pin modes for Ultrasonic sensor 2
  pinMode( t2, OUTPUT );
  pinMode( e2, INPUT );

  // Set each trigger pin on the Ultrasonic sensors to start at LOW 
  digitalWrite( t1, LOW );
  digitalWrite( t2, LOW );

// Set the pin mode for the LDR to be an INPUT
  pinMode( LIGHT, INPUT );

  // Start with the eyes looking forward
  ShowEye_Forward();
  currentState = 0;
}

void loop()
{
  // read in the current light level
  lightAmount = analogRead( LIGHT );
  // make sure the light value is within the range of the Max Intensity of the displays
  lightAmount = ( lightAmount / 255 ) * MAX_INTENSITY;
  // set the intensity
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Ping the Left eye with a recursion of 5
  distance1 = eyeL.ping_median( 5 );
  // Delay 500ms before we ping the right eye, so we don't get conflicting results
  delay(500);
  // Ping the Right eye with recursion of 5 
  distance2 = eyeR.ping_median( 5 );

  // Check to see if it's time to try to insert a blink
  if ( nextBlink < millis() )
  {
    // Set the next blink time to be a random time between now + 2 seconds and 10 seconds
    nextBlink = millis() + random(2000, 10000);

    // Now we need to decide if this blink is a single blink, or a double blink
    // Pick a random number between 1 and 13 and if it is less than or equal to 6, it's going to be a double blink
    if ( random(1,13) <= 6 )
      ShowEye_Blink_Dbl();
    else
      ShowEye_Blink();

    // Pause for 250ms to ensure the blink can happen before we go back to looking around
    delay(250);

    // Exit this itterartion of loop90 early.
    return;
  }
  
  // We need to work out if the difference between the distances of each ultrasonic sensors detected item is less than 15
  // or if both distances are 0, meaning nothing was detected
  // If this condition is met, then make the eyes look forward 
  float difference = ( distance2 - distance1 );
  if ( abs( difference ) < 250 || (distance1 == 0 && distance2 == 0 ) )
  {
    ShowEye_Forward();
    currentState = 0;
  }
  // Now if distance1 is greater than distance2 and distance1 is also greater than 0, then we want to look right  
  else if ( distance2 < distance1 && distance1 > 0)
  {
    ShowEye_Right();
    currentState = 1;
  }
  // Now if distance2 is greater than distance1 and distance2 is also greater than 0, then we want to look left  
  else if ( distance1 < distance2 && distance2 > 0 )
  {
    ShowEye_Left();
    currentState = 2;
  }

  // delay the loop for 250ms to ensure the eyes have time to display correctly
  delay(250);
}



/***************************************/
/************ MAX7219 Stuff ************/
/***************************************/

void ShowEye_Right()
{
  // Clear the displays
  mx.clear();
  // Set the current display brightness
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Loop through each row of the displays
  for (uint8_t row=0; row<ROW_SIZE; row++)
  {
    // Set the colums of the display 1
    mx.setColumn(row, eye_right[row]);
    // Set the colums of the display 2
    mx.setColumn(row+8, eye_right[row]);
  }
}

void ShowEye_Left()
{
// Clear the displays
  mx.clear();
  // Set the current display brightness
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Loop through each row of the displays
  for (uint8_t row=0; row<ROW_SIZE; row++)
  {
     // Set the colums of the display 1
    mx.setColumn(row, eye_left[row]);
     // Set the colums of the display 2
    mx.setColumn(row+8, eye_left[row]);
  }
}


void ShowEye_Forward()
{
// Clear the displays
  mx.clear();
  // Set the current display brightness
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Loop through each row of the displays
  for (uint8_t row=0; row<ROW_SIZE; row++)
  {
     // Set the colums of the display 1
    mx.setColumn(row, eye_forward[row]);
     // Set the colums of the display 2
    mx.setColumn(row+8, eye_forward[row]);
  }
}

void ShowEye_Blink()
{
// Clear the displays
  mx.clear();
  // Set the current display brightness
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Loop through each row of the displays
  for (uint8_t row=0; row<ROW_SIZE; row++)
  {
     // Set the colums of the display 1
    mx.setColumn(row, eye_blink[row]);
     // Set the colums of the display 2
    mx.setColumn(row+8, eye_blink[row]);
  }

  // Hold the blink for 150ms
  delay(150);

  // Put the state of the eyes back to what they were
  if ( currentState == 0 )
    ShowEye_Forward();
  else if ( currentState == 1 )
    ShowEye_Right();
  else if ( currentState == 2 )
    ShowEye_Left();

}

void ShowEye_Blink_Dbl()
{
// Clear the displays
  mx.clear();
  // Set the current display brightness
  mx.control(MD_MAX72XX::INTENSITY, lightAmount );

  // Loop through each row of the displays
  for (uint8_t row=0; row<ROW_SIZE; row++)
  {
     // Set the colums of the display 1
    mx.setColumn(row, eye_blink[row]);
     // Set the colums of the display 2
    mx.setColumn(row+8, eye_blink[row]);
  }

  // Wait 75ms
  delay(75);

  // Put the state of the eyes back to what they were - briefly
  if ( currentState == 0 )
    ShowEye_Forward();
  else if ( currentState == 1 )
    ShowEye_Right();
  else if ( currentState == 2 )
    ShowEye_Left();

  // Wait 75ms
  delay(75);

  // Blink the eyes
  ShowEye_Blink();
}