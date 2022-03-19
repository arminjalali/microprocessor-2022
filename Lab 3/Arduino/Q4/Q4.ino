#include <LiquidCrystal.h>

String userName = "ABCD";
String password = "1234";
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

void setup(){
  Serial.begin(9600);
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
    if(Serial.available()>0){
      char customKey = Serial.read();
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
    if(Serial.available()>0){
      char customKey = Serial.read();
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
