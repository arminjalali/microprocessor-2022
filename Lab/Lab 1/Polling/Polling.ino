#define NAME "armin"
const int button[] = {18, 19, 20};
const int LED[] = {0, 1, 2, 3, 4, 5, 6};


void LOW_LED() {
  for (int i = 0 ; i < 7 ; i++)
    digitalWrite(LED[i], LOW);
}

void HIGH_LED() {
  for (int i = 0 ; i < 7 ; i++) {
    digitalWrite(LED[i], HIGH);
  }  
}

void HIGH_LED_series() {
  for (int i = 0 ; i < 7 ; i++) {
    digitalWrite(LED[i], HIGH);
    delay(500);
  }  
}

void setup() {
  for (int i = 0 ; i < 3 ; i++){
    pinMode(button[i], INPUT);}

  for (int i = 0 ; i < 7 ; i++){
    pinMode(LED[i], OUTPUT);}
  LOW_LED();
}

void loop() {

  if (!digitalRead(button[0])) {
    HIGH_LED_series();
  }
  else if (!digitalRead(button[1])) {
    for (int i = 0 ; i < strlen(NAME) ; i++) {
      HIGH_LED();
      delay(300);
      LOW_LED();
      delay(300);
    }
    HIGH_LED();
  }
  else if (!digitalRead(button[2])){
    LOW_LED();
  }
}
