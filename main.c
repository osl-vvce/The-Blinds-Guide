#define trigPin1 A5
#define echoPin1 A4

#define trigPin2 A3
#define echoPin2 A2

#define trigPin3 A1
#define echoPin3 A0

#define buzzer 3
#define vibrator1 5
#define vibrator2 6

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(vibrator1, OUTPUT);
  pinMode(vibrator2, OUTPUT);
}

void loop()

{
  long duration, distance;

  // Read distance for buzzer
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(1);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  distance = (duration/2) / 29.1;
  
  // Actuate Buzzer
  if (distance < 50)
  { 
    Serial.println(distance);
    digitalWrite(buzzer,HIGH);
    Serial.println("Buzzer - HIGH");
  }
  else
  {
    Serial.println(distance);
    digitalWrite(buzzer,LOW);
    Serial.println("Buzzer - LOW");
  }
  delay(50);

  // Read distance for Vibrator 1
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1); 
  digitalWrite(trigPin2, LOW);

  duration = pulseIn(echoPin2, HIGH);
  distance = (duration/2) / 29.1;

  // Actuate Vibrator1
  if (distance < 20)
  { 
    Serial.println(distance);
    digitalWrite(vibrator1,HIGH);
    Serial.println("Vibrator1 - HIGH");
  }
  else
  {
    Serial.println(distance);
    digitalWrite(vibrator1,LOW);
    Serial.println("vibrator 2 LOW");
  }
  delay(50);

  // Read distance for Vibrator 2
  digitalWrite(trigPin3, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(1); 
  digitalWrite(trigPin3, LOW);

  duration = pulseIn(echoPin3, HIGH);
  distance = (duration/2) / 29.1;

  // Actuate Vibrator 2
  if (distance < 20)
  {
    Serial.println(distance);
    digitalWrite(vibrator2, HIGH); 
    Serial.println("Vibrator 2 - HIGH");
  }
  else
  {
    Serial.println(distance);
    digitalWrite(vibrator2, LOW);
    Serial.println("Vibrator 2 - LOW");
  }
  delay(50);
}