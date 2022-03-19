#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
String userName = "ABCD";
String password = "1234";
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','A'},
  {'4','5','6','B'},
  {'1','2','3','C'},
  {'*','0','=','D'}
};
byte rowPins[ROWS] = {22, 23, 24, 25}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {26, 27, 28, 29}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Programmed by: ");
  lcd.setCursor(0,1);
  lcd.print(" Armin & Mehran ");
  delay(3000);
  lcd.clear();
}
  
void loop(){
  String str1 = "";
  String str2 = "";
  lcd.setCursor(0,0);
  while(1){
    char customKey = customKeypad.getKey();
    if (customKey){
      if(customKey == '*'){
        break;
      }
      lcd.print(customKey);
      str1 += customKey;
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  while(1){
    char customKey = customKeypad.getKey();
    if (customKey){
      if(customKey == '*'){
        break;
      }
      lcd.print(customKey);
      str2 += customKey;
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  if(str1 == userName && str2 == password){
    lcd.print("Enter successful");
  }
  else if(str1 != userName){
    lcd.print("Username invalid");
  }
  else{
    lcd.print("  Wrong password ");
  }
  delay(2000);
  lcd.clear();
  
  

}
