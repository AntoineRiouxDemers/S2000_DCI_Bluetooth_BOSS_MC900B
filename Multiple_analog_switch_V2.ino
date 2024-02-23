/* Multiple buttons on one Analog pin Example
   Use 4 buttons to one bus to control 4 LEDs
   Dev: Vasilakis Michalis // Date: 1/7/2015 // www.ardumotive.com */

//Constants
const int Up = 2;
const int Down = 13;
const int Next = 5;
const int Back = 12;
const int PlayPause = 4;
const int BT = 14;

int sum = 0;
int avg = 0;

//Variables
int State = 0;  //Stores analog value when button is pressed

int Delay = 300;


void setup() {
  Serial.begin(115200);

  pinMode(Up, OUTPUT);
  pinMode(Down, OUTPUT);
  pinMode(Next, OUTPUT);
  pinMode(Back, OUTPUT);
  pinMode(PlayPause, OUTPUT);
  pinMode(BT, OUTPUT);

  digitalWrite(Up, LOW);
  digitalWrite(Down, LOW);
  digitalWrite(Next, LOW);
  digitalWrite(Back, LOW);
  digitalWrite(PlayPause, LOW);
  digitalWrite(BT, LOW);
}

void loop() {
  avg = 0;
  sum = 0;
  
if(analogRead(A0) < 230){
  int i = 0;
  delay(10);
  for(i; i<500; i++){
    sum += analogRead(A0);
    }
  avg = sum / i;
  }

  //****Mode****
  if (avg >= 216 && avg <= 230) {//Mode Pressed
    Serial.println("POWER");
    digitalWrite(BT, HIGH);
    delay(300);
    digitalWrite(BT, LOW);

    if (analogRead(A0) >= 216 && analogRead(A0) <= 230) {//Mode Pressed
      delay(750);
      if (analogRead(A0) >= 216 && analogRead(A0) <= 230) {//Mode Pressed
      digitalWrite(BT, HIGH);
      delay(3000);
      Serial.println("BT");
      }
      delay(1000);
      }
    }
//****CH****
  else if (avg >= 95 && avg <= 105) {//CH Pressed
    Serial.println("Mute");
    digitalWrite(PlayPause, HIGH);
    delay(300);
    }

//****UP****
  else if (avg >= 33 && avg <= 45) {//Up Pressed
    int i = 0;
    int avgUp = 0;
    int sumUp = 0;
    delay(200);
    for(i; i<1000; i++){
      sumUp += analogRead(A0);
      }
    avgUp = sumUp / i;

    if (avgUp >= 33 && avgUp <= 45) {//Up Pressed
      delay(150);
      i = 0;
      avgUp = 0;
      sumUp = 0;
      delay(200);

      for(i; i<1000; i++){
        sumUp += analogRead(A0);
        }
      avgUp = sumUp / i;

      if (avgUp >= 33 && avgUp <= 45) {//Up Pressed
        int output = 0;

        while (avgUp >= 33 && avgUp <= 45) {
          output++;
          if (output == 2000){
            output = 0;
            Serial.println("Up");
            digitalWrite(Up, HIGH);
            delay(250);
            digitalWrite(Up, LOW);
          }
          i++;
          sumUp += analogRead(A0);
          avgUp = sumUp / i;
        }
      }
      else{
        Serial.println("Next");
        digitalWrite(Next, HIGH);
      }
    }
    else {
      Serial.println("Up");
      digitalWrite(Up, HIGH);
    }
    delay(200);

    i = 0;
    avgUp = 0;
    sumUp = 0;
    }

//****DOWN****
  else if (avg >= 1 && avg <= 26) {//Down Pressed
    int i = 0;
    int avgBk = 0;
    int sumBk = 0;
    delay(200);
    for(i; i<1000; i++){
      sumBk += analogRead(A0);
      }
    avgBk = sumBk / i;

    if (avgBk >= 1 && avgBk <= 26) {//Down Pressed
      delay(150);
      i = 0;
      avgBk = 0;
      sumBk = 0;
      delay(200);

      for(i; i<1000; i++){
        sumBk += analogRead(A0);
        }
      avgBk = sumBk / i;

      if (avgBk >= 1 && avgBk <= 26) {//Down Pressed
        int output = 0;

        while (avgBk >= 1 && avgBk <= 26) {
          output++;
          if (output == 2000){
            output = 0;
            Serial.println("Down");
            digitalWrite(Down, HIGH);
            delay(250);
            digitalWrite(Down, LOW);
          }
          i++;
          sumBk += analogRead(A0);
          avgBk = sumBk / i;
        }
      }
      else{
        Serial.println("Back");
        digitalWrite(Back, HIGH);
      }
    }
    else {
      Serial.println("Down");
      digitalWrite(Down, HIGH);
    }
    delay(200);

    i = 0;
    avgBk = 0;
    sumBk = 0;
    }

  digitalWrite(Up, LOW);
  digitalWrite(Down, LOW);
  digitalWrite(Next, LOW);
  digitalWrite(Back, LOW);
  digitalWrite(PlayPause, LOW);
  digitalWrite(BT, LOW);
}