#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Programmed by: ");
  lcd.setCursor(0,1);
  lcd.print(" Armin & Mehran ");
  Serial.println(" Programmed by: ");
  Serial.println(" Armin & Mehran ");
  delay(3000);
  lcd.clear();
  Serial.write(12);
 

}
  
void loop(){
  String str1 = "";
  String str2 = "";
  char operand;
  boolean flag = false;
  lcd.setCursor(0,0);
  while(1){
    char customKey = customKeypad.getKey();
    if (customKey){
      if (customKey == 'c'){
        lcd.clear();
        Serial.write(12);
        str1 = "";
        continue;
      }
      lcd.print(customKey);
      Serial.print(customKey);
      if(customKey < 48 || customKey > 57){
        operand = customKey;
        break;
      }
      str1 += customKey;
    }
  }
  while(1){
    char customKey = customKeypad.getKey();
    if (customKey){
      if (customKey == 'c'){
        lcd.clear();
        Serial.write(12);
        flag = true;
        break;
      }
      if(customKey == '='){
        break;
      }
//      else if(customKey < 48 || customKey > 57){
//        lcd.clear();
//        lcd.print("  Invalid input ");  
//      }
      lcd.print(customKey);
      Serial.print(customKey);
      str2 += customKey;
    }
  }
  if(!flag){
    lcd.setCursor(0,1);
    float num1 = str1.toInt();
    float num2 = str2.toInt();
    float answer;
    if(operand == '+'){
      answer = num1 + num2;
    }
    else if (operand == '-'){
      answer = num1 - num2;
    }
    else if(operand == '/'){
      answer = num1 / num2;
    }
    else if(operand == '*'){
      answer = num1 * num2;
    }
    lcd.print(answer);
    Serial.println();
    Serial.print(answer);
    delay(2000);
    lcd.clear();
    Serial.write(12);
   
  }
}
