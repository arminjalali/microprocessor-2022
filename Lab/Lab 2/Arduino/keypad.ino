#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
const int LED[] = {38, 37, 36, 35, 34, 33, 32, 31, 30}; //nine LED
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {26, 27, 28, 29}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {22, 23, 24, 25}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
// turn off all LEDs
void LOW_LED() {
  for (int i = 0 ; i < 9 ; i++)
    digitalWrite(LED[i], LOW);
}

// turn on numbers of LEDs
void HIGH_LED_series(int num) {
  for (int i = 0 ; i < num ; i++) {
    digitalWrite(LED[i], HIGH);
    delay(500);
  }
}
  
void setup(){
  Serial.begin(9600);
  for (int i = 0 ; i < 9 ; i++){
    pinMode(LED[i], OUTPUT);}
  LOW_LED();
}
  
void loop(){
  
  char customKey = customKeypad.getKey();
  if (customKey){
      if(customKey < 48 || customKey > 57){
        Serial.print(customKey);
      }
      else{
        String str = String (customKey);
        Serial.print(str);
        HIGH_LED_series(str.toInt());
        LOW_LED();
    }
  }
  int serialKey;
  if(Serial.available() > 0){
      serialKey = Serial.parseInt();
      if(serialKey >=0 && serialKey < 10){
        HIGH_LED_series(serialKey);
        LOW_LED();
        Serial.write(12);
      }
      else{
        Serial.println();
        Serial.println("invalid number");
      }
   }
}
