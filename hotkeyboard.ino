/*  hotkeyboard

    AUTHOR: Bryce Dombrowski
    Copyright 2019 - https://brycedombrowski.com
    
    This program takes an old keypad from a cash register and turns it into a hotkey keyboard for any computer that you plug it into.
    Since this uses an Arduino Pro Micro, we can use it to emulate multiple keys pressed per key.
    I have it set to use the Windows ALT keycodes to type out greek characters, which is very helpful when writing lab reports. 
    There's also a few quality of life shortcuts, like the Superscript shortcut for Word.
    You can read more about this project's build process on my website: brycedombrowski.com
*/

// Libraries includes
#include "HID-Project.h"
#include <rickroll.h>

// Define I/O pins
#define OUTPUT_1     4
#define OUTPUT_2     5
#define SHIFT_DATA   6
#define SHIFT_CLK    7
#define SHIFT_LATCH  8
#define PIN_TONE     9

#define INPUT_FIRST 10
#define INPUT_LAST  A3

void keyPressed(int input_registered, int current_output){
  /* This function takes the output pin that is currently set to HIGH and the input pin that is currently reading HIGH to determine which button has been pressed.
   * Then, a macro or action is taken based on the button pressed.
  */

  /* Keypad layout for reference
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
      case 1: // Greek letter Phi
      // Serial.println("F7");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_6);   
      break;
      case 2: // Greek letter Tau
      // Serial.println("F8");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_4);   
      break;
      case 5: // Greek letter Sigma
      // Serial.println("E8");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_3);   
      break;
      case 6: // Greek letter Theta
      // Serial.println("E7");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_5);
      BootKeyboard.write(KEYPAD_2);   
      break;
      case 7: // Greek letter Pi
      // Serial.println("E6");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_0);   
      break;
      case 8: // Greek letter Mu
      // Serial.println("E5");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_5);
      BootKeyboard.write(KEYPAD_6);   
      break;
      case 9: // Greek letter capital Delta
      // Serial.println("E3");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_1);
      BootKeyboard.write(KEYPAD_6);  
      break;
      case 10: // Greek letter Gamma
      // Serial.println("E4");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_4);
      BootKeyboard.write(KEYPAD_7);   
      break;
    }
    break;
    case 4:
    switch(current_output){
      case 2: // Change the selection to the Symbol font (in Word)
      // Serial.println("G2");   
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(KEY_LEFT_SHIFT);
      BootKeyboard.write('q');
      break;
      case 5: // Greek letter capital Sigma (sum)
      // Serial.println("G7");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_2);
      BootKeyboard.write(KEYPAD_2);
      BootKeyboard.write(KEYPAD_8); 
      break;
      case 6: // Greek letter Omega
      // Serial.println("G6");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_9); 
      break;
      case 7: // Greek letter Epsilon
      // Serial.println("G5"); 
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_2);
      BootKeyboard.write(KEYPAD_3);
      BootKeyboard.write(KEYPAD_8); 
      break;
      case 8: // Greek letter Del (partial differential)
      // Serial.println("G4");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_8);
      BootKeyboard.write(KEYPAD_7);
      BootKeyboard.write(KEYPAD_0); 
      BootKeyboard.write(KEYPAD_6); 
      break;
    }
    break;
    case 5:
    switch(current_output){
      case 1: // Apply subscript formatting (in Word)
      // Serial.println("A2");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.write('=');
      break;
      case 2: // Apply the Normal Style (in Word)
      // Serial.println("A3");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(KEY_LEFT_SHIFT);
      BootKeyboard.write('n');
      break;
      case 5: // Record the last 30 seconds with Windows game bar
      // Serial.println("C3");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('g');
      break;
      case 6: // Add border outline (in Excel)
      // Serial.println("A8");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(KEY_LEFT_SHIFT);
      BootKeyboard.press('7');
      break;
      case 7: // Apply currency format
      // Serial.println("A7");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(KEY_LEFT_SHIFT);
      BootKeyboard.press('4');
      break;
      case 8: // Apply scientific format
      // Serial.println("A6");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(KEY_LEFT_SHIFT);
      BootKeyboard.press('6');
      break;
      case 9: // Increase the font size (in Word)
      // Serial.println("A4");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press(']');
      break;
      case 10: // Decrease the font size (in Word)
      // Serial.println("A5");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press('[');
      break;
    }
    break;
    case 6:
    switch(current_output){
      case 5: // Greek letter Rho
      // Serial.println("F6");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_6);
      BootKeyboard.write(KEYPAD_1);   
      break;
      case 6: // Greek letter Nu
      // Serial.println("F5");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_5);
      BootKeyboard.write(KEYPAD_7);   
      break;
      case 7: // Greek letter Lambda
      // Serial.println("F4");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_5);
      BootKeyboard.write(KEYPAD_5);   
      break;
      case 8: // Greek letter Delta
      // Serial.println("F3");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_4);
      BootKeyboard.write(KEYPAD_8);   
      break;
    }
    break;
    case 8:
    switch(current_output){
      case 2:
      // Serial.println("C2");
      Consumer.write(MEDIA_VOL_DOWN);
      return; // Returns to avoid the delay at the end of the function. This was much easier than writing a whole set of code to handle the repeat delay for media keys.
      break;
      case 5:
      // Serial.println("D8");
      BootKeyboard.press(KEYPAD_DOT);
      break;
      case 6:
      // Serial.println("D7");
      BootKeyboard.press(KEYPAD_3);
      break;
      case 7:
      // Serial.println("D6");
      BootKeyboard.press(KEYPAD_6);
      break;
      case 8:
      // Serial.println("D5");
      BootKeyboard.press(KEYPAD_9);
      break;
      case 10:
      // Serial.println("D2");
      Consumer.write(MEDIA_VOL_UP);
      return; // Returns to avoid the delay at the end of the function. This was much easier than writing a whole set of code to handle the repeat delay for media keys.
      break;
    }
    break;
    case 9:
    switch(current_output){
      case 2: // Volume mute
      // Serial.println("B2");
      Consumer.write(MEDIA_VOLUME_MUTE);
      break;
      case 5:
      // Serial.println("C8");
      // There is no "00" key on Windows, so this is my approximation
      BootKeyboard.print("00");
      break;
      case 6:
      // Serial.println("C7");
      BootKeyboard.press(KEYPAD_2);
      break;
      case 7:
      // Serial.println("C6");
      BootKeyboard.press(KEYPAD_5);
      break;
      case 8:
      // Serial.println("C5");
      BootKeyboard.press(KEYPAD_8);
      break;
      case 9: // Degree symbol
      // Serial.println("G3");     
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_0);
      BootKeyboard.write(KEYPAD_1);
      BootKeyboard.write(KEYPAD_7);
      BootKeyboard.write(KEYPAD_6); 
      break;
    }
    break;
    case 10:
    switch(current_output){
      case 1: // Greek letter Beta
      // Serial.println("F2");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_4);
      BootKeyboard.write(KEYPAD_6);   
      break;
      case 2: // Greek letter Alpha
      // Serial.println("E2");
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.write(KEYPAD_9);
      BootKeyboard.write(KEYPAD_4);
      BootKeyboard.write(KEYPAD_5);     
      break;
      case 5:
      // Serial.println("B8");
      BootKeyboard.press(KEYPAD_0);
      break;
      case 6:
      // Serial.println("B7");
      BootKeyboard.press(KEYPAD_1);
      break;
      case 7:
      // Serial.println("B6");
      BootKeyboard.press(KEYPAD_4);
      break;
      case 8:
      // Serial.println("B5");
      BootKeyboard.press(KEYPAD_7);
      break;
      case 10: // Begin recording with Windows game bar
      // Serial.println("B3");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('r');
      break;
    }
    break;
    case 11:
    switch(current_output){
      case 3: // Play a song! 
      // Serial.println("B1");
      playRickRoll(PIN_TONE); // Why not?
      break;
      case 4: // Apply superscript formatting (in Word)
      // Serial.println("A1");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.write(KEY_LEFT_SHIFT);
      BootKeyboard.write('+');
      
      /* Open calendar tab
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('d');
      */
      break;
    }
    break;
  }

  delay(50); // Leave a small amount of time for keys to be pressed
  BootKeyboard.releaseAll();
  delay(100); // Debounce, allows some time between key presses. Future work could include adding a repeat delay.
}

void forceNumLock(){
  /* Forces NumLock to stay on. The ALT keycodes used by the keypad buttons wouldn't work otherwise.
  */
  if (!(BootKeyboard.getLeds() & LED_NUM_LOCK))
    BootKeyboard.write(KEY_NUM_LOCK);  
}

void setup() {
  /* This function sets up digital I/O pins and starts the keyboard emulator.
   */
  // Set up digital I/O pins
  int pin;
  for (pin = INPUT_FIRST; pin <= INPUT_LAST; pin++){
    pinMode(pin, INPUT);
  }
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(PIN_TONE, OUTPUT);

  // Sets the shift register to LOW on all pins, this will later be used for outputting.
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, 0);

  // Set up keyboard emulators from HID-Project
  BootKeyboard.begin();
  Consumer.begin();
}

void loop() {
  /* This is the event loop of the board.
   * Each output line is toggled sequentially, and all input lines are checked each toggle.
   * We also force num lock to stay on.
   */
  forceNumLock();

  // Run through each output line, from 1 to 10. 1 and 2 are I/O pins, where 3-10 make use of the shift register.
  // Note: I could have chained two shift registers together if I needed an two extra I/O pins on the Arduino.
  int output_pin;
  for (output_pin = 1; output_pin <= 10; output_pin++){
    // Only one output should be HIGH at a time.
    
    // Direct the output pins.
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
    } // switch
    delay(1); // Probably unnecessary

    // NOTE: Certain output pins will never trigger a HIGH signal on an input pin. This was an oversight and was only realized after project completion.
    
    // Check input pins for a signal, which would indicate that a button has been pressed.
    int input_pin;
    for (input_pin = INPUT_FIRST; input_pin <= INPUT_LAST; input_pin++){
      if (input_pin == 17)
        input_pin += 1;
      if (digitalRead(input_pin) == HIGH)
        keyPressed(input_pin-INPUT_FIRST, output_pin);
    } // for
    
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
