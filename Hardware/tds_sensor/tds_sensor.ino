#define TdsSensorPin A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(TdsSensorPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  float tdsValue = (133.42 * voltage * voltage * voltage 
                   - 255.86 * voltage * voltage 
                   + 857.39 * voltage) * 0.5;
  Serial.print("TDS Value: ");
  Serial.println(tdsValue);
  delay(2000);
}
