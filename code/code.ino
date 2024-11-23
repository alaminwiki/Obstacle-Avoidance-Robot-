// Define pins for L298 motor driver
int motorA1 = 8;  // IN1
int motorA2 = 9;  // IN2
int motorB1 = 10; // IN3
int motorB2 = 11; // IN4

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  // Initialize serial communication with Bluetooth
  Serial.begin(9600);  // Default baud rate for HC-05 Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the Bluetooth data

    // Control motors based on the Bluetooth command
    if (command == 'F') { // Forward
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else if (command == 'B') { // Backward
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
    }
    else if (command == 'L') { // Left
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
    }
    else if (command == 'R') { // Right
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
    }
    else if (command == 'S') { // Stop
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
    }
  }
}
