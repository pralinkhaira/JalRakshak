#define SensorPin A0 
float calibration = 21.34; // calibration value

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(SensorPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  float phValue = 7 + ((2.5 - voltage) / calibration);
  Serial.print("pH Value: ");
  Serial.println(phValue);
  delay(2000);
}
