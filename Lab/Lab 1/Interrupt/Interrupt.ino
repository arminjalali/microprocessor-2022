#define NAME "armin"
const int button[] = {18, 19, 20};
const int LED[] = {0, 1, 2, 3, 4, 5, 6};

volatile byte button1 = 0;
volatile byte button2 = 0;
volatile byte button3 = 0;

void buttonPush1() {
  button1 = 1;
}

void buttonPush2() {
  button2 = 1;
}

void buttonPush3() {
  button3 = 1;
}

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

  attachInterrupt(digitalPinToInterrupt(button[0]), buttonPush1, FALLING);
  attachInterrupt(digitalPinToInterrupt(button[1]), buttonPush2, FALLING);
  attachInterrupt(digitalPinToInterrupt(button[2]), buttonPush3, FALLING);
}

void loop() {

  if (button1 == 1) {
    HIGH_LED_series();
    button1 = 0;
    
  }
  else if (button2 == 1) {
    for (int i = 0 ; i < strlen(NAME) ; i++) {
      HIGH_LED();
      delay(300);
      LOW_LED();
      delay(300);
    }
    HIGH_LED();
    button2 = 0;
  }
  else if (button3 == 1){
    LOW_LED();
    button3 = 0;
  }
}
