// Analog pin connected to the LDR
int lightPin = 0; // A0

// Pins connected to the 74HC595 shift register
int latchPin = 11;
int clockPin = 12;
int dataPin = 9;

// Variable to store the LED pattern (as an 8-bit binary number)
int leds = 0;

void setup() {
  // Set shift register control pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

// Function to send the 'leds' value to the shift register and update the LEDs
void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // Start data transmission
  shiftOut(dataPin, clockPin, LSBFIRST, leds); // Send 8 bits (LSB first)
  digitalWrite(latchPin, HIGH); // Output the new data to the LEDs
}

void loop() {
  // Read light level from the LDR (value between 0 and 1023)
  int reading = analogRead(lightPin);

  // Convert the light level to the number of LEDs to light up (max 8)
  // 1023 / 57 ≈ 18; so about every 57 points lights 1 more LED
  int numLEDSLit = reading / 57;

  // Cap the number of LEDs at 8
  if (numLEDSLit > 8) numLEDSLit = 8;

  // Reset LED pattern to 0 (no LEDs on)
  leds = 0;

  // Turn on the correct number of LEDs by setting the appropriate bits
  for (int i = 0; i < numLEDSLit; i++) {
    leds = leds + (1 << i); // Set the i-th bit (e.g., 00000011 for 2 LEDs)
  }

  // Send updated LED pattern to the shift register
  updateShiftRegister();
}
