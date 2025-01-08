// Pin configuration
const int pwmPin = 9;       // PWM output pin
const int potPin = A0;      // Potentiometer input pin

// Constants
const int minPulse = 1000;  // Minimum pulse width in microseconds
const int maxPulse = 2000;  // Maximum pulse width in microseconds
const int pwmFrequency = 50; // PWM frequency in Hz (50Hz = 20ms period)

void setup() {
  pinMode(pwmPin, OUTPUT); // Set PWM pin as output
}

void loop() {
  // Read potentiometer value (0 to 1023)
  int potValue = analogRead(potPin);

  // Map potentiometer value to pulse width range (1000 to 2000 microseconds)
  int pulseWidth = map(potValue, 0, 1023, minPulse, maxPulse);

  // Generate PWM signal
  digitalWrite(pwmPin, HIGH);         // Set PWM pin HIGH
  delayMicroseconds(pulseWidth);      // Wait for the pulse width
  digitalWrite(pwmPin, LOW);          // Set PWM pin LOW
  delayMicroseconds(20000 - pulseWidth); // Wait for the rest of the 20ms period
  
  Serial.println(analogRead(potPin));
}