int IN1 = 9;
int IN2 = 10;
int enA = 11;

int motorSpeedA = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  
  
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);    
  pinMode(IN2, OUTPUT);


  // Set initial rotation direction
  // forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Initial speed
  motorSpeedA = 50; // 0~255
  
}
 
void loop() {
  
  
  if (motorSpeedA < 0) 
  {
    motorSpeedA = 0;
  }
  if (motorSpeedA > 255) 
  {
    motorSpeedA = 255;
  }
  Serial.println(motorSpeedA);  
  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
}



void serialEvent() {
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if(inChar == '0')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      
    }
    else if(inChar == 's')
    {
      motorSpeedA-=10;
      
    }
    else if(inChar == 'w')
    {
      motorSpeedA+=10;
      
    }
  }
}