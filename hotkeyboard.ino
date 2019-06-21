#include <Keyboard.h>

#define SHIFT_DATA   7 //Shift register 
#define SHIFT_LATCH  9
#define SHIFT_CLK    8

#define OUTPUT_1 5
#define OUTPUT_2 6

#define INPUT_FIRST 10
#define INPUT_LAST A3

void printKeyPressed(int input_registered, int current_output){
  //Serial.println("I"+String(input_registered)+":O"+String(current_output));

  /*
   * Keypad layout
   * 
   * A1 B1 -- -- -- -- --
   * A2 B2 C2 D2 E2 F2 G2
   * A3 B3 C3 -- E3 F3 G3
   * A4 -- -- -- E4 F4 G4
   * A5 B5 C5 D5 E5 F5 G5
   * A6 B6 C6 D6 E6 F6 G6
   * A7 B7 C7 D7 E7 F7 G7
   * A8 B8 C8 D8 E8 F8 --
   * 
   */
  switch(input_registered){
    case 0:
    switch(current_output){
      case 1:
      Serial.println("F7");
      break;
      case 2:
      Serial.println("F8");
      break;
      case 5:
      Serial.println("E8");
      break;
      case 6:
      Serial.println("E7");
      break;
      case 7:
      Serial.println("E6");
      break;
      case 8:
      Serial.println("E5");
      break;
      case 9:
      Serial.println("E3");
      break;
      case 10:
      Serial.println("E4");
      break;
    }
    break;
    case 4:
    switch(current_output){
      case 2:
      Serial.println("G2");
      break;
      case 5:
      Serial.println("G7");
      break;
      case 6:
      Serial.println("G6");
      break;
      case 7:
      Serial.println("G5");
      break;
      case 8:
      Serial.println("G4");
      break;
    }
    break;
    case 5:
    switch(current_output){
      case 1:
      Serial.println("A2");
      break;
      case 2:
      Serial.println("A3");
      break;
      case 5:
      Serial.println("C3");
      break;
      case 6:
      Serial.println("A8");
      break;
      case 7:
      Serial.println("A7");
      break;
      case 8:
      Serial.println("A6");
      break;
      case 9:
      Serial.println("A4");
      break;
      case 10:
      Serial.println("A5");
      break;
    }
    break;
    case 6:
    switch(current_output){
      case 5:
      Serial.println("F6");
      break;
      case 6:
      Serial.println("F5");
      break;
      case 7:
      Serial.println("F4");
      break;
      case 8:
      Serial.println("F3");
      break;
    }
    break;
    case 8:
    switch(current_output){
      case 2:
      Serial.println("C2");
      break;
      case 5:
      Serial.println("D8");
      Keyboard.print('.');
      break;
      case 6:
      Serial.println("D7");
      Keyboard.print('3');
      break;
      case 7:
      Serial.println("D6");
      Keyboard.print('6');
      break;
      case 8:
      Serial.println("D5");
      Keyboard.print('9');
      break;
      case 10:
      Serial.println("D2");
      break;
    }
    break;
    case 9:
    switch(current_output){
      case 2:
      Serial.println("B2");
      break;
      case 5:
      Serial.println("C8");
      Keyboard.print('00');
      break;
      case 6:
      Serial.println("C7");
      Keyboard.print('2');
      break;
      case 7:
      Serial.println("C6");
      Keyboard.print('5');
      break;
      case 8:
      Serial.println("C5");
      Keyboard.print('8');
      break;
      case 9:
      Serial.println("G3");
      break;
    }
    break;
    case 10:
    switch(current_output){
      case 1:
      Serial.println("F2");
      break;
      case 2: // Alpha
      Serial.println("E2");
      Keyboard.press(KEY_LEFT_ALT);
      delay(100);
      Keyboard.press('1');
      /*Keyboard.print("2");
      delay(100);
      Keyboard.print("2");
      delay(100);
      Keyboard.print("4");
      delay(100);*/
      
      delay(1000);
      Keyboard.release('1');
      
      break;
      case 5:
      Serial.println("B8");
      Keyboard.print('0');
      break;
      case 6:
      Serial.println("B7");
      Keyboard.print('1');
      break;
      case 7:
      Serial.println("B6");
      Keyboard.print('4');
      break;
      case 8:
      Serial.println("B5");
      Keyboard.print('7');
      break;
      case 10:
      Serial.println("B3");
      break;
    }
    break;
    case 11:
    switch(current_output){
      case 3: // Open new tab in internet browser
      Serial.println("B1");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('t');
      break;
      case 4: // Open Windows Explorer
      Serial.println("A1");
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('e');
      break;
    }
    break;
  }

  delay(100);
  Keyboard.releaseAll();
}
//const int keyPressed[][11] = {{},};

void setup() {
  // This code runs once
  Keyboard.begin(); // Set up keyboard
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  
  int pin;
  for (pin = INPUT_FIRST; pin <= INPUT_LAST; pin++){
    pinMode(pin, INPUT);
  }

  //set shift register to 0
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, 0);
}

void loop() {
  // This code runs repeatedly

  int output_pin;
  for (output_pin = 1; output_pin <= 10; output_pin++){
    // Only one output should be HIGH at a time.

    // Direct output pins.
    switch(output_pin){
      case 1:
      digitalWrite(OUTPUT_1, HIGH);
      break;
      case 2:
      digitalWrite(OUTPUT_2, HIGH);
      break;
      case 3: // Add a point of data to the shift register
      digitalWrite(SHIFT_DATA, HIGH);
      digitalWrite(SHIFT_CLK, HIGH);
      digitalWrite(SHIFT_CLK, LOW);
      digitalWrite(SHIFT_DATA, LOW);
      digitalWrite(SHIFT_LATCH, HIGH);
      digitalWrite(SHIFT_LATCH, LOW);
      break;    
      default: // Move the data one spot over in the shift register
      digitalWrite(SHIFT_CLK, HIGH);
      digitalWrite(SHIFT_CLK, LOW);
      digitalWrite(SHIFT_LATCH, HIGH);
      digitalWrite(SHIFT_LATCH, LOW);
      break;
    }
    delay(1);
    
    
    // Check input pins
    int input_pin;
    for (input_pin = INPUT_FIRST; input_pin <= INPUT_LAST; input_pin++){
      if (input_pin == 17) input_pin += 1;
      if (digitalRead(input_pin) == HIGH){
        delay(10);
        if (digitalRead(input_pin) == HIGH){
          //Serial.println(input_pin);
          //Serial.println(String(input_pin-INPUT_FIRST));
          //Serial.println("INPUT: I"+(input_pin+12-INPUT_FIRST >= 14 ? String(input_pin + 14-INPUT_FIRST) : String(input_pin + 12-INPUT_FIRST)));
          printKeyPressed(input_pin-INPUT_FIRST, output_pin);
        }
      }
    }
    
    delay(1);
    // Turn off any pins that may be left on
    switch(output_pin){
      case 1:
      digitalWrite(OUTPUT_1, LOW);
      break;
      case 2:
      digitalWrite(OUTPUT_2, LOW);
      break;
      case 10: // Reset shift register
      digitalWrite(SHIFT_CLK, HIGH);
      digitalWrite(SHIFT_CLK, LOW);
      digitalWrite(SHIFT_LATCH, HIGH);
      digitalWrite(SHIFT_LATCH, LOW);
      break;
    } // switch
  }  // for
} // loop
