/*
Ultrasonic sensor
LED Turns on when object is less than 20 cm away from sensor
*/


const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PINB  = 11;  // Any digital pin
const int LED_PINO  = 12;  // Any digital pin

const int THRESHOLD = 20;  // LED turns ON when closer than 20cm

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PINB, OUTPUT);
  pinMode(LED_PINO, OUTPUT);

}

void loop() {
  float distance = getDistance();

  if (distance < THRESHOLD) {
    digitalWrite(LED_PINB, HIGH);  // Object detected — LED ON
    digitalWrite(LED_PINO, LOW);
  } else {
    digitalWrite(LED_PINB, LOW);
    digitalWrite(LED_PINO, HIGH);
  }

  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  delay(100);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.0470 / 2.0;
}