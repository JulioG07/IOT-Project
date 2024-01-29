int buzzerPin = 4;
int buttonPin = 8;

void setup() {
 
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
    int buttonState = digitalRead(buttonPin);
    
    if(buttonState == LOW){
      digitalWrite(buzzerPin, HIGH);
      tone(4,277);
    }

    if(buttonState == HIGH){
      noTone(buzzerPin);
      digitalWrite(buzzerPin, LOW);
    }
   
}
