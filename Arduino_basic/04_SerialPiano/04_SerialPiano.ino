int incomingByte = 0;    // for incoming serial data
int speak=9;
//int note[]={2093, 2349, 2637, 2793, 3136, 3520, 3951, 4186};
void setup() {
    pinMode(incomingByte, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
  
    // read the incoming byte:
    //incomingByte = Serial.read();
    //incomingByte = incomingByte+1;
    /*if(incomingByte=='1'){
      digitalWrite(LED_BUILTIN, HIGH);
      for(int i=0; i<8; i++){
        tone(speak,note[i], 500);
        delay(750);
      }
      Serial.print("On");
    }
    else if(incomingByte=='0'){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.print("Off");
    }*/
    switch(incomingByte){
      
      case '1':
      tone(speak, 261.6256,500);
      break;
      case '2':
      tone(speak, 293.6648,500);
      break;
      case '3':
      tone(speak, 329.6276,500);
      break;
      case '4':
      tone(speak, 349.2282,500);
      break;
      case '5':
      tone(speak, 391.9954,500);1
      break;
      case '6':
      tone(speak, 440.0000,500);
      break;
      case '7':
      tone(speak, 493.8833,500);
      break;
    }
  
    // say what you got:
    //Serial.print((char)incomingByte);
  }
  
}
