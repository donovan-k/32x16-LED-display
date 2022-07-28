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

  // print each letter with a rainbow color
 
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

  

  
  //random numbers for colors
long randc;

  //randum number for x,y cord.
long randx;
long randy;




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

  if (buttonPushCounter == 1) {
    buttonPushCounter1 = 0;
    buttonPushCounter2 = 0;
//red,blue,green
    randc = random(3);
    
    randx = random(32);
    
    randy = random(16);
    
    int c = randc;
    int x = randx;
    int y = randy;

    
if (c==0){
    matrix.drawPixel(x,y,matrix.Color444(0,0,15));
}
if (c==1){
    matrix.drawPixel(x,y,matrix.Color444(0,15,0));
}
if (c==2){
    matrix.drawPixel(x,y,matrix.Color444(15,0,0));
}

  }
  
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
  //rainbow effect animation
   lastButtonState1 = buttonState1;
  if (buttonPushCounter1 == 1) {
    buttonPushCounter = 0;
    buttonPushCounter2 = 0;
//purple,red,blue
    randc = random(3);
    
    randx = random(32);
    
    randy = random(16);
    
    int c = randc;
    int x = randx;
    int y = randy;

    
if (c==0){
    matrix.drawPixel(x,y,matrix.Color444(15,0,15));
}
if (c==1){
    matrix.drawPixel(x,y,matrix.Color444(0,0,15));
}
if (c==2){
    matrix.drawPixel(x,y,matrix.Color444(15,0,0));
}
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
//color changing

   lastButtonState2 = buttonState2;
  if (buttonPushCounter2 == 1) {
    buttonPushCounter1 = 0;
    buttonPushCounter = 0;
//color changing slowly
  for (int x=15; x>0; x--){
    matrix.fillScreen(matrix.Color444(15, x, x)); 
    delay(100);
   }
  for (int x=0; x<15; x++){ //white to red
    matrix.fillScreen(matrix.Color444(15, 0, x));
    delay(100); 
  }
  for (int x=15; x>0; x--){ //red to blue
    matrix.fillScreen(matrix.Color444(x, 0, 15)); 
    delay(100);
  }  
  int y = 15;
  for (int x=0; x<15; x++){ //to green
    matrix.fillScreen(matrix.Color444(0, x, y)); 
    y--;
    delay(100);
  }  
  for (int x=0; x<15; x++){ //back to white
    matrix.fillScreen(matrix.Color444(x, 15, x));
    delay(100);
  }
}    
}
