int IN1 = 9;

int IN2 = 6;

int enA = 5;

int IN3 = 11;

int IN4 = 10;

int enB = 3;

 

int motorSpeedA = 0;

int motorSpeedB = 0;

 

void setup() {

 

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);  

  

  pinMode(enA, OUTPUT);

  pinMode(IN1, OUTPUT);    

  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);    

  pinMode(IN4, OUTPUT);

  pinMode(enB, OUTPUT);

 

 

  // Set initial rotation direction

  // forward

  digitalWrite(IN1, HIGH);

  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);

  digitalWrite(IN4, LOW);

 

 

  // Initial speed

  motorSpeedA = 120; // 0~255

  motorSpeedB = 120;

  

}

 

void loop() {

  analogWrite(enA, motorSpeedA); // Send PWM signal to motor A

  analogWrite(enB, motorSpeedB); // Send PWM signal to motor A

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

      digitalWrite(IN3, LOW); 

      digitalWrite(IN4, LOW);

      

    }

    else if(inChar == 'f')

    {

      digitalWrite(IN1, HIGH);

      digitalWrite(IN2, LOW);

      digitalWrite(IN3, HIGH);

      digitalWrite(IN4, LOW);

      

    }

    else if(inChar == 'b')

    {

      digitalWrite(IN1, LOW);

      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, LOW);

      digitalWrite(IN4, HIGH);

    }

    else if(inChar == 'w')

    {

       motorSpeedA = motorSpeedA +10;

       motorSpeedB = motorSpeedB +10;

       Serial.println(motorSpeedA);

          if (motorSpeedA,motorSpeedB > 255) 

          {

             motorSpeedA = 255;

             motorSpeedB = 255;

          }

      }

   else if(inChar == 's')

    {

       motorSpeedA = motorSpeedA - 10;

       motorSpeedB = motorSpeedB - 10;

       Serial.println(motorSpeedA);

      if (motorSpeedA,motorSpeedB < 0) 

  {

    motorSpeedA = 0;

    motorSpeedB = 0;

  }

    }

  }

}
