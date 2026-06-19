#include <DHT.h>

#define DHTPIN 2          // Digital pin connected to the DHT11 sensor data pin
#define DHTTYPE DHT22     // Specifies the sensor type as DHT11
#define BUZZER 8

// Initialize the DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);     // Open serial communications at 9600 bps
  Serial.println(F("DHT11 Sensor Initializing..."));
  
  dht.begin();            // Start the DHT sensor
  pinMode(BUZZER, OUTPUT);

}

void loop() {
  // Wait 2 seconds between measurements (DHT11 is a slow sensor)
  delay(2000);

  // Read humidity percentage
  float humidity = dht.readHumidity();
  // Read temperature in Celsius (default)
  float temperatureC = dht.readTemperature();
  // Read temperature in Fahrenheit (isFahrenheit = true)
  float temperatureF = dht.readTemperature(true);

  // Validate if any readings failed (returns NaN if failed)
  if (isnan(humidity) || isnan(temperatureC) || isnan(temperatureF)) {
    Serial.println(F("Error: Failed to read data from DHT11 sensor!"));
    return;
  }
  if (temperatureC > 43.00){
    tone(BUZZER, 1000);
    delay(500);    
    noTone(BUZZER);
    delay(500);
  } else {
    noTone(BUZZER);
    delay(500);

  }

  // Print results to the Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(humidity, 1);
  Serial.print(F("%  |  "));
  
  Serial.print(F("Temperature: "));
  Serial.print(temperatureC, 1);
  Serial.print(F("°C / "));
  Serial.print(temperatureF, 1);
  Serial.println(F("°F"));
}