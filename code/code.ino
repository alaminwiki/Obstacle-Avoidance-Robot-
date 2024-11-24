// Define pins for L298 motor driver

int trig = 5, echo = 6;
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
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  // Initialize serial communication with Bluetooth
  Serial.begin(9600);  // Default baud rate for HC-05 Bluetooth module
}

void loop() {
  int distance=calculateDistance(trig,echo);
  //Serial.println(distance);
  if(distance < 17){
    right();
  }
 else{forward();}
  
}
int calculateDistance(int trig_pin,int echo_pin)
{
  digitalWrite(trig_pin, LOW);
  delay(2);
  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin,LOW);
  int duration = pulseIn(echo_pin,HIGH);
  int distance=(0.034*duration)/2;
  return distance;
}

void backward(){
  digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);

}
void forward(){
  digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);

}
void left(){
  digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
}
void right(){
  digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);

}
void stop(){
  digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);

}
