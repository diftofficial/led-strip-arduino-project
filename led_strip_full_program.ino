#include <IRremote.h>

int x = 0;
int r, g, b;
int IRpin = 11;
int RED = 5;
int GREEN = 6;
int BLUE = 9;

IRrecv irrecv(IRpin);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop(){
  if(irrecv.decode(&results)){
    unsigned int value = results.value;
    Serial.println(value);
    Serial.println(x);
    if(value == 12495){
      x = 1;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 58359 || value == 6375){
      x = 2;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0); 
    }
    if(value == 31365 || value == 539){
      x = 3;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 25979 || value == 4335){
      x = 4;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 14535 || value == 15547){
      x = 5;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 23205 || value == 59295){
      x = 6;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 17085 || value == 65015){
      x = 7;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 19125 || value == 5499){
      x = 8;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    if(value == 21165 || value == 64539){
      x = 9;
      analogWrite(RED,0);
      analogWrite(GREEN,0);
      analogWrite(BLUE,0);
    }
    irrecv.resume();
  }
  if(x == 1){
    analogWrite(RED,20);
    analogWrite(GREEN,40);
    analogWrite(BLUE,255);
  }
  if(x == 2){
    for (r = 100; r < 200; r++) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
    for (b = 25; b < 256; b++) { 
      analogWrite(BLUE, b);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }  
    } 
    // fade from violet to red
    for (b = 255; b > 50; b--) { 
      analogWrite(BLUE, b);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
    for (r = 255; r > 120; r--) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
  }
  if(x == 3){
    analogWrite(RED,255);
    analogWrite(GREEN,255);
    analogWrite(BLUE,255);
  }
  if(x == 4){
    analogWrite(RED,220);
    analogWrite(GREEN,0);
    analogWrite(BLUE,240);
  }
  if(x == 5){
    analogWrite(RED,0);
    analogWrite(GREEN,255);
    analogWrite(BLUE,240);
  }
  if(x == 6){
      // fade from blue to violet
    for (r = 0; r < 256; r++) { 
      analogWrite(RED, r);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
    // fade from violet to red
    for (b = 255; b > 0; b--) { 
      analogWrite(BLUE, b);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
    // fade from red to yellow
    for (g = 0; g < 256; g++) { 
      analogWrite(GREEN, g);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
    // fade from yellow to green
    for (r = 255; r > 0; r--) { 
      analogWrite(RED, r);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
    // fade from green to teal
    for (b = 0; b < 256; b++) { 
      analogWrite(BLUE, b);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
    // fade from teal to blue
    for (g = 255; g > 0; g--) { 
      analogWrite(GREEN, g);
      delay(50);
      if(irrecv.decode(&results)){
        break;
      }
    } 
  }
  if(x == 7){
    analogWrite(GREEN,200);
    for (b = 0; b < 256; b++) { 
      analogWrite(BLUE, b);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }  
    } 
    // fade from violet to red
    for (b = 255; b > -1; b--) { 
      analogWrite(BLUE, b);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
  }
  if(x == 8){
    analogWrite(BLUE,200);
    for (r = 0; r < 256; r++) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }  
    } 
    // fade from violet to red
    for (r = 255; r > -1; r--) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
  }
  if(x == 9){
    analogWrite(GREEN,200);
    for (r = 0; r < 256; r++) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }  
    } 
    // fade from violet to red
    for (r = 255; r > -1; r--) { 
      analogWrite(RED, r);
      delay(30);
      if(irrecv.decode(&results)){
        break;
      }
    }
  }
}
