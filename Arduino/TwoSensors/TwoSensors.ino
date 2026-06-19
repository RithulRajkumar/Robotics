/*
Use both IR and ultrasonic sensor together. 
LED turns ON only when BOTH sensors detect something at the same time — 
IR detects an object AND ultrasonic reads less than 25cm. 
If only one sensor triggers, LED blinks slowly. 
Print which sensor(s) triggered on Serial Monitor.
*/

const int IR_PIN = 8;   // Digital OUT pin of IR sensor module
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN = 11;

void setup() {
  Serial.begin(9600);

  pinMode(IR_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  return duration * 0.0343 / 2.0;
}

void loop() {
  int detectedIR = digitalRead(IR_PIN);
  float theDist = getDistance();

  if (detectedIR == LOW && theDist < 25.0) {
    Serial.println("Object detected! Both sensors triggered");
    digitalWrite(LED_PIN, HIGH);
  }
  else if (theDist >= 25.0 && detectedIR == LOW) {
    Serial.println("Only IR sensor was triggered");
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }
  else if (theDist < 25.0 && detectedIR == HIGH) {
    Serial.println("Only ultrasonic sensor was triggered");
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);  }
  else {
    Serial.println("No object");
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);
}