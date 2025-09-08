void setup() {
  Serial.begin(9600);
  // Assign the pin as INPUT 
  pinMode(A0, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
}

void loop(){
   if((digitalRead(2) == 1) || (digitalRead(3) == 1)){
      Serial.println('!');
    } else {
        Serial.println(analogRead(A0));
      }
      delay(500);
  }
