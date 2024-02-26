//LED's
int wait = 10;
int ready = 11; 
int detect = 12; 

//Motion Sensor
int motion = 2; 
int motionDetected = 0; 
int motionValue;

//Magnet Reed Switch 


void setup() {

  Serial.begin(9600);

  pinMode(wait, OUTPUT);
  pinMode(ready, OUTPUT);
  pinMode(detect, OUTPUT);
  pinMode(motion, INPUT);

  // Initial Delay
  digitalWrite(ready, LOW);
  digitalWrite(detect, LOW);
  digitalWrite(wait, HIGH);
  delay(15000);
  digitalWrite(ready, HIGH);
  digitalWrite(wait, LOW);
  
}

void loop() {
  //Checks if sensor is 1 or 0
  motionValue = digitalRead(motion);

  //
  if(motionValue == 1){
    digitalWrite(detect, HIGH);
    motionDetected = 1; 
    delay(3000);
  }else{
    digitalWrite(detect, LOW);
  }

  if(motionDetected == 1){
    digitalWrite(wait, HIGH);
    digitalWrite(ready, LOW);
    digitalWrite(detect, LOW);
    delay(10000);
    digitalWrite(ready, HIGH);
    digitalWrite(wait, LOW);
    motionDetected = 0; 
  }
  
}
