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


// Array Class
class Array {
 public: 
  struct Point {
    Point() {
      
    }
    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }
    int x;
    int y;
  };
  struct Node {
    Node() {
      
    }
    Node* next_;
    Point data_;
  };

  Node* head_;
  int size_;

  Array() {
    head_ = NULL;
    size_ = 0;
  }

  ~Array() {
    while (pop_front().x != -1) {
      continue;
    }
  }

  Array(const Array& other) {
    Node* node = other.head_;
    while (node) {
      push_front(node->data_);
      node = node->next_;
    }
  }

  Array& operator=(const Array& other) {
    Node* node = other.head_;
    while (node) {
      push_front(node->data_);
      node = node->next_;
    }
  }

  void push_front(Point p) {
    if (head_) {
      Node* node = new Node;
      node->next_ = head_;
      node->data_ = p;
      head_ = node;
    } else {
      head_ = new Node;
      head_->next_ = NULL;
      head_->data_ = p;
    }
    size_++;
  }

  Point pop_front() {
    if (head_ == NULL) {
      return Point(-1, -1);
    }

    Point p = head_->data_;
    
    if (head_->next_) {
      Node* node = head_->next_;
      delete head_;
      head_ = node;
    } else {
      delete head_;
      head_ = NULL;
    }

    size_--;

    return p;
  }
  
};


// Display Class
class Display {
 public:
  void IntroScreen() {
    matrix.fillScreen(matrix.Color444(1, 0, 1));

    // draw some text!
    matrix.setCursor(11, 1);  // start at top left, with one pixel of spacing
    matrix.setTextSize(1);   // size 1 == 8 pixels high
    matrix.print("DK");
    //std::vector<std::string> text = {'D'}
  }

  // slowly changes color by spiralling into next color
  bool ColorChange(int del, bool is_reverse) {
    buttonState1 = digitalRead(buttonPin1);
    Serial.println(buttonState1);

    // slowely go through all the hues
    for (int i = 100; i < 1535; i+=100) {
      Spiral(i-100, 50, is_reverse);
      if ( digitalRead(buttonPin1) == HIGH) {return false;}
      is_reverse = !is_reverse;
    }

    return true;
  }
  
  // helper function to spiral through a matrix
  void Spiral(int hue, int del, bool reverse) {
    int r = 0, c = 0;
    int nr = 16, nc = 31;
    Array order;
    while (1) {
      uint16_t color = matrix.ColorHSV(hue, 255, 255, false);
      if (c > nc) {break;}
    
      // remove/print top row
      order.push_front(Array::Point(c,r)); // from point in line
      order.push_front(Array::Point(nc,r)); // to point in line
      if (!reverse) {
        ReverseHandle(order, hue, del);
      }
      r++;
      if (r > nr) {break;}
    
      // remove/print right column
      order.push_front(Array::Point(nc,r)); // from point in line
      order.push_front(Array::Point(nc,nr)); // to point in line
      if (!reverse) {
        ReverseHandle(order, hue, del);
      }
      nc--;
      if (c > nc) {break;}

      // remove/print bottom row
      order.push_front(Array::Point(nc,nr)); // from point in line
      order.push_front(Array::Point(c,nr)); // to point in line
      if (!reverse) {
        ReverseHandle(order, hue, del);
      }
      nr--;
      if (r > nr) {break;}

      // remove/print left column
      order.push_front(Array::Point(c,nr)); // from point in line
      order.push_front(Array::Point(c,r)); // to point in line
      if (!reverse) {
        ReverseHandle(order, hue, del);
      }
      delay(del);
      c++;

      // increment hue
      hue += 100/8;
    }

    // if reverse spiral other direction
    if (reverse) {
      ReverseHandle(order, hue, del);
    }
  }

  void ReverseHandle(Array& order, int hue, int del) {
    uint16_t color = matrix.ColorHSV(hue, 255, 255, false);
    int c = 1;
    while (order.size_ > 0) {
      if (c % 4 == 0) {
        hue -= 100/8;
      }
      color = matrix.ColorHSV(hue, 255, 255, false);
      Array::Point from = order.pop_front();
      Array::Point to = order.pop_front();
      matrix.drawLine(from.x, from.y, to.x, to.y ,color);
      delay(del);
      c++;
    }
  }

  // Uses DfS Traversal and other math functions to apply a cool animation
  bool dfsTraversal(int x_size, int y_size) {
    Array a_pos;
    Array a_color;
    int hue = random(1535);
    int sat = 255;
    matrix.fillScreen(matrix.ColorHSV(hue, sat, 255, false));
    Array::Point p2 = Array::Point(hue, sat);
    for (int i = 0; i < x_size; i++) {
      hue = random(1535);

      // puts all the pixels where we will be drawing into an array
      for (int j = 0; j < y_size; j++) {
        a_pos.push_front(Array::Point(i,j));
        a_pos.push_front(Array::Point(i/2, j*2));
        a_pos.push_front(Array::Point(32-i/2, 16-j*2));
        a_color.push_front(Array::Point(hue, sat));
      }

      // goes through array and display the pixel necessary
      for (int j = 0; j < y_size*3; j++) {
        if ( digitalRead(buttonPin) == HIGH) {return false;}
        Array::Point p1 = a_pos.pop_front();
        matrix.drawPixel(p1.x, p1.y, matrix.ColorHSV(p2.x, p2.y, 255, false)); 
      }
      
      p2 = a_color.pop_front(); 
    }

    return true;
  }

};


extern Display dis;
bool color_reverse = false;

// setup function
void setup() {
  Serial.begin(9600);
  
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

  // Show intro screen on display
  matrix.begin();
  dis.IntroScreen();
} 


void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    bool keepGo = dis.ColorChange(100, color_reverse);
    while (keepGo) {
      color_reverse = !color_reverse;
      keepGo = dis.ColorChange(100, color_reverse);
    }
    dis.IntroScreen();
  }

  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH) {
    bool keepGo = dis.dfsTraversal(32, 16);
    int counter = 0;
    while (keepGo) {
      keepGo = dis.dfsTraversal(32, 16);
    }
    dis.IntroScreen();
  }
  
}
