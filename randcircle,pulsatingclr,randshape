//code is made for annimations on DKINNOVATION LED PANEL SPEAKER
//Donovan Kitten made this code

#include <Adafruit_GFX.h>   // Core graphics library from ADAFRUIT
#include <RGBmatrixPanel.h> // Hardware-specific library
//#include <IRremote.h>


#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int  buttonPin1 = 3; 
const int  buttonPin2 = 4;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button
int buttonPushCounter2 = 0;
int buttonState2 = 0;
int lastButtonState2 = 0;


void setup() {
  //initialize randum number generator
  randomSeed(analogRead(15));
  // initialize the button pin as a input:

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);


  // initialize the LED as an output:
  buttonState = digitalRead(buttonPin);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
      matrix.begin();
  matrix.fillScreen(matrix.Color444(1, 0, 1));

  // draw some text!
  matrix.setCursor(11, 1);  // start at top left, with one pixel of spacing
  matrix.setTextSize(1);   // size 1 == 8 pixels high

  // print DK Inn.
 
  matrix.setTextColor(matrix.Color444(0,12,9));
  matrix.print('D');
  matrix.setTextColor(matrix.Color444(0,12,11));
  matrix.print('K');


  matrix.setCursor(6, 9);  // next line
  matrix.setTextColor(matrix.Color444(0,14,8));
  matrix.print('I');
  matrix.setTextColor(matrix.Color444(0,8,14));
  matrix.print('n');
  matrix.setTextColor(matrix.Color444(0,0,14));
  matrix.print('n');
  matrix.setTextColor(matrix.Color444(0,5,10));
  matrix.print('.');
  } 

  

  
  //random numbers for random everything
long randshape;
long randx; 
long randy;
long randsize;
  //random colors
long randr;
long randg;
long randb;
   //randum numbers for circle explode cord.
long randNumber4;
long randNumber5;
long randNumber6;
   //randum numbers for circle explode colors.
long randNumber7;
long randNumber8;
long randNumber9;



void loop() {


  // read the pushbutton input pin:

  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
   lastButtonState = buttonState;
  // save the current state as the last state, for next time through the loop


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  // pulsating colors animation
  if (buttonPushCounter == 1) {
    buttonPushCounter1 = 0;
    buttonPushCounter2 = 0;
    randsize = random(8);
    randr = random(15);
    randg = random(15);
    randb = random(15);
    int n = randsize;
    int i = randr;
    int o = randg;
    int p = randb;
    
if (n==8){
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(0, 0, 32, 16, matrix.Color444(i+3,o-4,p-4));
    matrix.drawRect(1, 1, 30, 14, matrix.Color444(i+3,o-3,p-3));
    matrix.drawRect(2, 2, 28, 12, matrix.Color444(i+2,o-3,p-3));
    matrix.drawRect(3, 3, 26, 10, matrix.Color444(i+2,o-2,p-2));
    matrix.drawRect(4, 4, 24, 8, matrix.Color444(i+1,o-2,p-2));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i+1,o-1,p-1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i,o-1,p-1));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i,o,p));
    delay(50);
}
if (n==7){
  matrix.fillScreen(matrix.Color444(0, 0, 1));

    matrix.drawRect(1, 1, 30, 14, matrix.Color444(i-3,o+3,p-3));
    matrix.drawRect(2, 2, 28, 12, matrix.Color444(i-3,o+2,p-3));
    matrix.drawRect(3, 3, 26, 10, matrix.Color444(i-2,o+2,p-2));
    matrix.drawRect(4, 4, 24, 8, matrix.Color444(i-2,o+1,p-2));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i-1,o+1,p-1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i-1,o,p-1));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i,o,p));
    delay(50);
    
  }

if (n==6)
{
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(2, 2, 28, 12, matrix.Color444(i-3,o-3,p+2));
    matrix.drawRect(3, 3, 26, 10, matrix.Color444(i-2,o-2,p+2));
    matrix.drawRect(4, 4, 24, 8, matrix.Color444(i-2,o-2,p+1));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i-1,o-1,p+1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i-1,o-1,p));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i,o,p));
    delay(50);
    
  }

if (n==5)
{
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(3, 3, 26, 10, matrix.Color444(i,o,p));
    matrix.drawRect(4, 4, 24, 8, matrix.Color444(i,o-1,p-1));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i+1,o-1,p-1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i+1,o-2,p-2));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i+2,o-2,p-2));
    delay(50);
    
  }

if (n==4){
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(4, 4, 24, 8, matrix.Color444(i,o,p));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i-1,o,p-1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i-1,o+1,p-1));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i-2,o+1,p-2));
    delay(50);
    
  }

if (n==3){
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(5, 5, 22, 6, matrix.Color444(i,o,p));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i-1,o-1,p+1));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i-2,o-2,p+2));
    delay(50);
    
  }

if (n==2){
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(6, 6, 20, 4, matrix.Color444(i,o,p));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i/2,o/2,p/2));
    delay(50);
    
  }

if (n==1){
  matrix.fillScreen(matrix.Color444(0, 0, 1));
    matrix.drawRect(7, 7, 18, 2, matrix.Color444(i,o,p));
    delay(50);
    
  }
  }
  //circle animations with circles popping up
    buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter1++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter1);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
   lastButtonState1 = buttonState1;
  if (buttonPushCounter1 == 1) {
    buttonPushCounter = 0;
    buttonPushCounter2 = 0;
    //random cord. 
    randNumber4 = random(32);
    randNumber5 = random(16);
    randNumber6 = random(0,9);
   int x=randNumber4;
   int y=randNumber5;
   int d=randNumber6;
// random color

  randNumber7 = random(5,15);
  randNumber8 = random(5,15);
  randNumber9 = random(5,15);
int r1 = randNumber7;
int g1 = randNumber8;
int b1 = randNumber9;

  matrix.fillCircle(x, y, d, matrix.Color444(r1, 0, b1));
    delay(100);
  matrix.fillCircle(x, y, d+1, matrix.Color444(r1, 0, b1));
    delay(100);
  matrix.fillCircle(x, y, d+2, matrix.Color444(r1, 0, b1));
    delay(100);
  matrix.fillCircle(x, y, d+3, matrix.Color444(r1, 0, b1));
    delay(100); 


  matrix.fillCircle(x/2, y+2, d, matrix.Color444(r1/2, g1, 0));
    delay(100);
  matrix.fillCircle(x/2, y+2, d+1, matrix.Color444(r1/2, g1, 0));
    delay(100);
  matrix.fillCircle(x/2, y+2, d+2, matrix.Color444(r1/2, g1, 0));
    delay(100);
  matrix.fillCircle(x/2, y+2, d+3, matrix.Color444(r1/2, g1, 0));
    delay(100); 

  matrix.fillCircle(x-4, y-2, d, matrix.Color444(r1, g1/2, 0));
    delay(100);
  matrix.fillCircle(x-4, y-2, d+1, matrix.Color444(r1, g1/2, 0));
    delay(100);
  matrix.fillCircle(x-4, y-2, d+2, matrix.Color444(r1, g1/2, 0));
    delay(100);
  matrix.fillCircle(x-4, y-2, d+3, matrix.Color444(r1, g1/2, 0));
    delay(100); 
    
  matrix.fillCircle(x+2, y/2, d, matrix.Color444(0, g1, b1));
    delay(100);
  matrix.fillCircle(x+2, y/2, d+1, matrix.Color444(0, g1, b1));
    delay(100);
  matrix.fillCircle(x+2, y/2, d+2, matrix.Color444(0, g1, b1));
    delay(100);
  matrix.fillCircle(x+2, y/2, d+3, matrix.Color444(0, g1, b1));
    delay(100); 

      
  }

  
    buttonState2 = digitalRead(buttonPin2);

  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter2++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter2);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
//random everything animation

   lastButtonState2 = buttonState2;
  if (buttonPushCounter2 == 1) {
    buttonPushCounter1 = 0;
    buttonPushCounter = 0;

//int sensorvalue = digitalRead(soundsensor);
    
//randum number

    randx = random(32);
    randy = random(16);
    randsize = random(10);
    randr = random(15);
    randg = random(15);
    randb = random(15);
    randshape = random(6); //drawLine,drawRect,fillRect,drawCircle,fillCirle
//fill screen with a random color

  matrix.fillScreen(matrix.Color444(randr/3, randg/3, randb/3));
  
//draw a random line
    if (randshape == 1){
      matrix.drawLine(randx, randy, randx*2, randy*2, matrix.Color444(randr, randg, randb));
      delay(50);
    }
//draw a random rectangle
    if (randshape == 2){
      matrix.drawRect(randx, randy, randx*2, randy*2, matrix.Color444(randr, randg, randb));
      delay(50);
    }    
//fill a random rectangle
    if (randshape == 3){
      matrix.fillRect(randx, randy, randx*2, randy*2, matrix.Color444(randr, randg, randb));
      delay(50);
    }
//draw a random circle
        if (randshape == 4){
        matrix.drawCircle(randx, randy, randsize, matrix.Color444(randr, randg, randb));
        delay(50);
    }
//fill random circle
        if (randshape == 5){
        matrix.fillCircle(randx, randy, randsize, matrix.Color444(randr, randg, randb));
        delay(50);
    }
    
}
}
