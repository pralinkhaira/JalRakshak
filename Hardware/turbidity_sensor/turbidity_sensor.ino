#define TurbiditySensor A1 

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(TurbiditySensor);
  float voltage = sensorValue * (5.0 / 1024.0);
  Serial.print("Turbidity Voltage: ");
  Serial.println(voltage);
  delay(2000);
}
