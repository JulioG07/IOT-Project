//LED's
int wait = 10;
int ready = 11; 
int detect = 12; 
int found = 4; 

//Motion Sensor
int motion = 2; 
int motionDetected = 0; 
int motionValue;

//Magnet Reed Switch 
int magnet = 7;
int magnetValue;

//Core Signals
bool sig1 = false; 
bool sig2 = false; 

void setup() {

  Serial.begin(9600);

  //Sensor
  pinMode(wait, OUTPUT);
  pinMode(ready, OUTPUT);
  pinMode(detect, OUTPUT);
  pinMode(motion, INPUT);
  //Magnet
  pinMode(found, OUTPUT);
  pinMode(magnet, INPUT);

  // Initial Delay
  digitalWrite(ready, LOW);
  digitalWrite(detect, LOW);
  digitalWrite(wait, HIGH);
  delay(15000);
  digitalWrite(ready, HIGH);
  digitalWrite(wait, LOW);
  
}

void loop() {
  //Checks if magnet is 1 or 0
  magnetValue = digitalRead(magnet);
     
  Serial.print("Magnet Status: ");
  Serial.println(magnetValue);

  if(magnetValue == HIGH){
    digitalWrite(found, HIGH);
    sig1 = false; 
  } else {
    digitalWrite(found, LOW);
    sig1 = true; 
  }

  //Checks if sensor is 1 or 0
  motionValue = digitalRead(motion);

  if(motionValue == 1){
    digitalWrite(detect, HIGH);
    motionDetected = 1;
    sig2 = true;  
  }else{
    digitalWrite(detect, LOW);
    sig2 = false; 
  }

  if(sig1 && sig2){
    Serial.println("Conditions has been meet");
  }

  if(motionDetected == 1){
    digitalWrite(wait, HIGH);
    digitalWrite(ready, LOW);
    digitalWrite(detect, LOW);
    delay(5000);
    digitalWrite(ready, HIGH);
    digitalWrite(wait, LOW);
    motionDetected = 0; 
  }
}
