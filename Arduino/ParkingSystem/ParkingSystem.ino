
/*
Simulate a parking spot.
Use the ultrasonic sensor to detect if a car (any object) is parked within 15cm. 
If the spot is empty, LED stays OFF. 
If occupied, LED turns ON. Print "Spot OCCUPIED" or "Spot EMPTY" on Serial Monitor.
*/

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN  = 11;  // Any digital pin

const int THRESHOLD = 15;  // LED turns ON when closer than 20cm

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  float distance = getDistance();

  if (distance < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);  // Object detected — LED ON
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm, Spot OCCUPIED");

  } else {
    digitalWrite(LED_PIN, LOW);   // Nothing close — LED OFF
    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm, Spot EMPTY");

  }


  delay(100);
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