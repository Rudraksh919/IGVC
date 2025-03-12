void setup() {
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(A0, OUTPUT);
  	pinMode(A1,OUTPUT);
    
    // Ensure the motor is off at the beginning
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A0, 0);
  	analogWrite(A1, 0);
}

void loop() {
    // Forward rotation (13 HIGH, 12 LOW)
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    analogWrite(A0, 150); // Adjust speed (0-255)
    delay(2000); // Run for 2 seconds

    // Stop the motor
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A0, 0);
    delay(1000);

    // Reverse rotation (13 LOW, 12 HIGH)
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    analogWrite(A1, 150);
    delay(2000);

    // Stop the motor again
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A1, 0);
    delay(1000);
}
