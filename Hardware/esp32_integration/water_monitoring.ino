#define PhPin A0
#define TurbidityPin A1
#define TdsPin A2

float calibration = 21.34; // calibration for pH

void setup() {
  Serial.begin(115200);
}

void loop() {
  int phRaw = analogRead(PhPin);
  int turbidityRaw = analogRead(TurbidityPin);
  int tdsRaw = analogRead(TdsPin);

  float phVoltage = phRaw * (5.0 / 1024.0);
  float phValue = 7 + ((2.5 - phVoltage) / calibration);

  float turbidityVoltage = turbidityRaw * (5.0 / 1024.0);

  float tdsVoltage = tdsRaw * (5.0 / 1024.0);
  float tdsValue = (133.42 * tdsVoltage * tdsVoltage * tdsVoltage 
                   - 255.86 * tdsVoltage * tdsVoltage 
                   + 857.39 * tdsVoltage) * 0.5;

  Serial.print("pH: "); Serial.print(phValue);
  Serial.print(" | Turbidity: "); Serial.print(turbidityVoltage);
  Serial.print(" | TDS: "); Serial.println(tdsValue);

  delay(3000);
}
