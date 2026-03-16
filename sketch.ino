#define LEFT_BUTTON 2
#define RIGHT_BUTTON 3
#define LEFT_LED 8
#define RIGHT_LED 9

int state = 0;
bool blinkState = false;

unsigned long lastBlink = 0;
int leftPressTime = 0;
int rightPressTime = 0;

void setup() {

  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  pinMode(LEFT_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int left = digitalRead(LEFT_BUTTON);
  int right = digitalRead(RIGHT_BUTTON);

  if(left == LOW)
    leftPressTime++;
  else
    leftPressTime = 0;

  if(right == LOW)
    rightPressTime++;
  else
    rightPressTime = 0;

  // Hazard mode
  if(leftPressTime >= 10 && rightPressTime >= 10){
    state = 3;
    Serial.println("HAZARD MODE");
  }

  // Left indicator
  else if(leftPressTime >= 10){
    if(state == 1)
      state = 0;
    else
      state = 1;

    Serial.println("LEFT BUTTON PRESSED");
  }

  // Right indicator
  else if(rightPressTime >= 10){
    if(state == 2)
      state = 0;
    else
      state = 2;

    Serial.println("RIGHT BUTTON PRESSED");
  }

  if(millis() - lastBlink > 300){

    lastBlink = millis();
    blinkState = !blinkState;

    if(state == 1){
      digitalWrite(LEFT_LED, blinkState);
      digitalWrite(RIGHT_LED, LOW);
    }

    else if(state == 2){
      digitalWrite(RIGHT_LED, blinkState);
      digitalWrite(LEFT_LED, LOW);
    }

    else if(state == 3){
      digitalWrite(LEFT_LED, blinkState);
      digitalWrite(RIGHT_LED, blinkState);
    }

    else{
      digitalWrite(LEFT_LED, LOW);
      digitalWrite(RIGHT_LED, LOW);
    }
  }

  delay(100);
}