#define SHIFT_DATA   11 //Shift register 
#define SHIFT_LATCH  12
#define SHIFT_CLK    13

#define OUTPUT_FIRST 5
#define OUTPUT_LAST 9

#define INPUT_FIRST 10
#define INPUT_LAST A3


/*
int get_bit_from_byte(int x, int index){
  // index is 0 at LSB
  return (x >> index) & 1; // Bitwise '&' to get rid of other digits to the left
}*/

void printKeyPressed(int input_registered, int current_output){
  current_output += 1; // Start at 1
  if (current_output == 10){
    current_output = 11; // We skipped #10 in the wiring since it is NC.
  }
  input_registered += 12;
  if (input_registered>=14){
    input_registered += 1;
  }
  switch(input_registered){
    case 12:
    switch(current_output){
      case 1:
      Serial.println("F7");
      break;
      case 2:
      Serial.println("F8");
      break;
      case 3:
      Serial.println("E4");
      break;
      case 4:
      Serial.println("E3");
      break;
      case 5:
      Serial.println("E5");
      break;
      case 6:
      Serial.println("E6");
      break;
      case 7:
      Serial.println("E7");
      break;
      case 8:
      Serial.println("E8");
      break;
      //default:
      //Serial.println("?");
    }
    break;
    case 13:
    switch(current_output){
      case 5:
      Serial.println("F5");
      break;
      case 6:
      Serial.println("F6");
      break;
      case 7:
      Serial.println("F7");
      break;
      case 8:
      Serial.println("F8");
      break;
      //default:
      //Serial.println("13?");
    }
    break;
    case 15:
    switch(current_output){
      case 2:
      Serial.println("G2");
      break;
      case 5:
      Serial.println("G4");
      break;
      case 6:
      Serial.println("G5");
      break;
      case 7:
      Serial.println("G6");
      break;
      case 8:
      Serial.println("G7");
      break;
      //default:
      //Serial.println("15?");
    }
    break;
    case 16:
    switch(current_output){
      case 1:
      Serial.println("A2");
      break;
      case 2:
      Serial.println("A3");
      break;
      case 3:
      Serial.println("A5");
      break;
      case 4:
      Serial.println("A4");
      break;
      case 5:
      Serial.println("A6");
      break;
      case 6:
      Serial.println("A7");
      break;
      case 7:
      Serial.println("A8");
      break;
      case 8:
      Serial.println("C3");
      break;
      //default:
      //Serial.println("16?");
    }
    break;
    case 17:
    switch(current_output){
      case 2:
      Serial.println("C2");
      break;
      case 3:
      Serial.println("D2");
      break;
      case 5:
      Serial.println("D5");
      break;
      case 6:
      Serial.println("D6");
      break;
      case 7:
      Serial.println("D7");
      break;
      case 8:
      Serial.println("D8");
      break;
      //default:
      //Serial.println("17?");
    }
    break;
    case 18:
    switch(current_output){
      case 4:
      Serial.println("G3");
      break;
      case 5:
      Serial.println("C5");
      break;
      case 6:
      Serial.println("C6");
      break;
      case 7:
      Serial.println("C7");
      break;
      case 8:
      Serial.println("C8");
      break;
      //default:
      //Serial.println("18?");
    }
    break;
    case 19:
    switch(current_output){
      case 1:
      Serial.println("F2");
      break;
      case 2:
      Serial.println("E2");
      break;
      case 3:
      Serial.println("B3");
      break;
      case 5:
      Serial.println("B5");
      break;
      case 6:
      Serial.println("B6");
      break;
      case 7:
      Serial.println("B7");
      break;
      case 8:
      Serial.println("B8");
      break;
      //default:
      //Serial.println("19?");
    }
    break;
    case 20:
    switch(current_output){
      case 11:
      Serial.println("B1");
      break;
      case 9:
      Serial.println("A1");
      break;
      //default:
      //Serial.println("20?");
    }
    break;
    //default:
    //Serial.println("??");
  }
}
//const int keyPressed[][11] = {{},};

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(SHIFT_DATA, OUTPUT);
  pinMode(SHIFT_LATCH, OUTPUT);
  pinMode(SHIFT_CLK, OUTPUT);

  int pin;
  for (pin = OUTPUT_FIRST; pin <= OUTPUT_LAST; pin++){
    pinMode(pin, OUTPUT);
  }
  for (pin = INPUT_FIRST; pin <= INPUT_LAST; pin++){
    pinMode(pin, INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(analogRead(2));
  //delay(1000);
  
  int output_pin = 0;
  for (output_pin = 0; output_pin < 10; output_pin++){
    // Only one output should be HIGH at a time.
    //Serial.print("new");
    // Direct output pins.
    digitalWrite(OUTPUT_FIRST, OUTPUT_FIRST == output_pin ? HIGH: LOW);
    digitalWrite(OUTPUT_FIRST + 1, OUTPUT_FIRST + 1 == output_pin ? HIGH: LOW);
    if (output_pin >=2){
    
      // Convert the rest to a 3-digit binary word.
      digitalWrite(OUTPUT_FIRST + 2, ( ( (output_pin-2) >> 0) & 1) ? HIGH: LOW);
      digitalWrite(OUTPUT_FIRST + 3, ( ( (output_pin-2) >> 1) & 1) ? HIGH: LOW);
      digitalWrite(OUTPUT_FIRST + 4, ( ( (output_pin-2) >> 2) & 1) ? HIGH: LOW);
    }else{
      digitalWrite(OUTPUT_FIRST + 2, LOW);
      digitalWrite(OUTPUT_FIRST + 3, LOW);
      digitalWrite(OUTPUT_FIRST + 4, LOW);
    }
    delay(10);
    Serial.println("O"+String(output_pin)+": "+(OUTPUT_FIRST == output_pin ? "1": "0"));
    Serial.println("O"+String(output_pin)+": "+(OUTPUT_FIRST+1 == output_pin ? "1": "0"));
    
    Serial.println("O"+String(output_pin)+": "+(String( ( (output_pin-2) >> 0) & 1)));
    Serial.println("O"+String(output_pin)+": "+(String( ( (output_pin-2) >> 1) & 1) ? "1": "0"));
    Serial.println("O"+String(output_pin)+": "+(String( ( (output_pin-2) >> 2) & 1) ? "1": "0"));
    
    

    // Check input pins
    int input_pin;
    for (input_pin = INPUT_FIRST; input_pin < INPUT_FIRST+8; input_pin++){
      if (digitalRead(input_pin) == HIGH){
        delay(1);
        if (digitalRead(input_pin) == HIGH){
          Serial.println(String(input_pin-INPUT_FIRST));
          Serial.println("INPUT: I"+(input_pin+12-INPUT_FIRST >= 14 ? String(input_pin + 14-INPUT_FIRST) : String(input_pin + 12-INPUT_FIRST)));
          printKeyPressed(input_pin-INPUT_FIRST, output_pin-OUTPUT_FIRST);
        }
      }
    }
    delay(5000);
  }
  
}
