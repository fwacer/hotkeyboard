//#include <Keyboard.h>
#include "HID-Project.h"
#include <rickroll.h>
//#include <U8glib.h> // lcd display

// Define Pins
#define SHIFT_DATA   6 //Shift register 
#define SHIFT_CLK    7
#define SHIFT_LATCH  8

#define OUTPUT_1 4
#define OUTPUT_2 5

#define INPUT_FIRST 10
#define INPUT_LAST A3

#define PIN_TONE 9
//#define PIN_NUMLOCK_LED 1

void keyPressed(int input_registered, int current_output){
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
      case 2: // Play a song!
      // Serial.println("G2");
      BootKeyboard.write(KEY_NUM_LOCK);
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
      /*
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.println("winword.exe");
      */
      /*
      // Open Steam
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.println("steam://open/games");
      */
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
      case 1: // Find
      // Serial.println("A2");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press('f');
      break;
      case 2: // Open Explorer
      // Serial.println("A3");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press('e');
      break;
      case 5:
      // Serial.println("C3");
      break;
      case 6:
      // Serial.println("A8");
      break;
      case 7: // Begin recording with Windows game bar
      // Serial.println("A7");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('r');
      break;
      case 8: // Record the last 30 seconds with Windows game bar
      // Serial.println("A6");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('g');
      break;
      case 9: // Open settings
      // Serial.println("A4");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press('i');
      break;
      case 10:
      // Serial.println("A5");
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
      return; // Returns to avoid the delay()
      /*
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(50);
      Keyboard.releaseAll();
      Keyboard.println("notepad++.exe");   */   
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
      return; // Returns to avoid the delay()
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
      case 9: // Play a song!
      // Serial.println("G3");     
      playRickRoll(PIN_TONE);
      
      /*
      // Open my website
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.println("https://www.brycedombrowski.com/");
      */
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
      case 10:
      // Serial.println("B3");
      break;
    }
    break;
    case 11:
    switch(current_output){
      case 3: // Open new tab in internet browser
      // Serial.println("B1");
      BootKeyboard.press(KEY_LEFT_CTRL);
      BootKeyboard.press('t');
      break;
      case 4:
      // Serial.println("A1");
      BootKeyboard.press(KEY_LEFT_GUI);
      BootKeyboard.press(KEY_LEFT_ALT);
      BootKeyboard.press('d');
      break;
    }
    break;
  }

  delay(50);
  BootKeyboard.releaseAll();
  delay(150);
}
//const int keyPressed[][11] = {{},};

/*void playTune (){
  int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };
  
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4
  };

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN_TONE, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_TONE);
  
  }
}*/

void forceNumLock(){
  // Forces NumLock to stay on. The ALT keycodes used by the keypad buttons wouldn't work otherwise.
  if (!(BootKeyboard.getLeds() & LED_NUM_LOCK))
    BootKeyboard.write(KEY_NUM_LOCK);  
}

/*
void displayLCD(){
  U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE); // for 0.91" model
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0,10);
  u8g.print("Hello World!";
}*/

void setup() {
  // This code runs once
  
  BootKeyboard.begin();
  Consumer.begin();
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);
  pinMode(OUTPUT_1, OUTPUT);
  pinMode(OUTPUT_2, OUTPUT);
  pinMode(PIN_TONE, OUTPUT);
  
  int pin;
  for (pin = INPUT_FIRST; pin <= INPUT_LAST; pin++){
    pinMode(pin, INPUT);
  }

  //set shift register to 0
  shiftOut(SHIFT_DATA, SHIFT_CLK, MSBFIRST, 0);

  //displayLCD(); 
}

void loop() {
  // This code runs repeatedly
  forceNumLock();
  
  
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
          keyPressed(input_pin-INPUT_FIRST, output_pin);
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
