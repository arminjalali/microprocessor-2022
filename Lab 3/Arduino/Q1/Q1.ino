#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
String date;
void setup(){
  time_t t = now();
  setTime(1,1,1,5,3,2022);
  String y = String(year(t));
  String m = String(month(t));
  String d = String(day(t));
  date = y + "/" + m + "/" + d;
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Programmed by: ");
  lcd.setCursor(0,1);
  lcd.print(" Armin & Mehran ");
  delay(3000);
  lcd.clear();
}

void loop()
{
  for(int j = 0 ; j < 2 ; j++){
    lcd.setCursor(0 , j);
    for(int i = 0 ; i < 17 - date.length() ; i++){
       lcd.setCursor(i , j);
       lcd.print(date);
       delay(500);
       lcd.clear();
    }
  }
}
