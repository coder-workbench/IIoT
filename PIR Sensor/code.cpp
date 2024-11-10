const int led = 12;        // Define the pin number for the LED
const int pir_sensor = 2;  // Define the pin number for the PIR sensor

void setup() {
  pinMode(led, OUTPUT);    // Set the LED pin as an OUTPUT
  pinMode(pir_sensor, INPUT); // Set the PIR sensor pin as an INPUT
  Serial.begin(9600);      // Initialize serial communication at 9600 baud rate
  
  // Test LED at startup
  digitalWrite(led, HIGH); // Turn the LED ON for a visual test
  delay(5000);             // Keep the LED ON for 5 seconds
  digitalWrite(led, LOW);  // Turn the LED OFF after the test
}

void loop() {
  int sensor_val = digitalRead(pir_sensor); // Read the value from the PIR sensor
  
  // Debug print
  Serial.print("Sensor value: "); // Print a message to the Serial Monitor
  Serial.println(sensor_val);      // Print the current sensor value
  
  if (sensor_val == HIGH) {        // Check if motion is detected
    digitalWrite(led, HIGH);       // Turn the LED ON if motion is detected
    Serial.println("Motion detected - LED ON"); // Print a message indicating motion detected
  } else {
    digitalWrite(led, LOW);        // Turn the LED OFF if no motion is detected
    Serial.println("No motion - LED OFF"); // Print a message indicating no motion
  }
  
  delay(500);                      // Wait for 500 milliseconds before the next loop iteration
}
