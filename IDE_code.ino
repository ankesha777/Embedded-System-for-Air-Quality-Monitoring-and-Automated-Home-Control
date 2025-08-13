const int b=12;
const int i1=2;
const int i2=3;
const int e=5;
const int fanPin = 4;
const int gasPin = A1;
const int ldrPin = A0;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(i2,OUTPUT);
  pinMode(i1,OUTPUT);
  pinMode(e,OUTPUT);

  Serial.begin(9600);

}

void loop() {

int gasValue = analogRead(gasPin);   // Gas sensor value
Serial.println(" | Gas: ");
Serial.print(gasValue);

  // ----- GAS DETECTION LOGIC -----
  if(gasValue > 150) { // You can calibrate this threshold
    digitalWrite(13, HIGH); // Flash LED as alert
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(b, HIGH); // Flash LED as alert
    delay(100);
      digitalWrite(b, LOW); // Flash LED as alert
    delay(100);
     digitalWrite(b, HIGH); // Flash LED as alert
    delay(100);
      digitalWrite(b, LOW); // Flash LED as alert
    delay(100);
    return; // Skip rest of loop to prioritize gas alert
  }

    // ----- FAN CONTROL -----
  if (gasValue>100) {
   analogWrite(e,150);
   digitalWrite(i1,HIGH);
   digitalWrite(i2,LOW);
}

  int ldrValue = analogRead(ldrPin);  // Light level 
  Serial.println("LDR: ");
  Serial.println(ldrValue);


   // ----- LIGHT CONTROL -----
  if (ldrValue < 1000 ) {
    digitalWrite(13, HIGH); // Turn on light
  } else {
    digitalWrite(13, LOW); // Turn off light
  }
  
  }
