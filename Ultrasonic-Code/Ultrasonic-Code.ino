#define MAX_RANG 520
#define ADC 1023.0 

int ultrasonic = A5; 

int magnet = 2; 
int LED = 4; 
int detect = 0; 

float d1; 

void setup() {
  Serial.begin(9600);
  pinMode(magnet, INPUT);
  pinMode(LED, OUTPUT);

  // Initial value
  d1 = 254.00; 
}

float distance;
float sensity; 

void loop() {

    sensity = analogRead(ultrasonic);
    detect = digitalRead(magnet);  

    distance = (sensity * MAX_RANG / ADC) * 10;
    Serial.print("Reading... ");
    Serial.print(distance);
    Serial.println(" mm");
    delay(500);


    if (detect == HIGH) {            
    digitalWrite(LED, LOW);  //Close 
    delay(5000);
    d1 = distance;
    } else {
    digitalWrite(LED, HIGH); //Open
    delay(5000);

    if(d1 == distance && d1 <= distance + 0.4){
        Serial.println("Mailbox has been opened");
        //sendSignal(); 

      }else if(d1 < (distance + 0.41)  ){
        Serial.println("Someone took your email");
        //sendSignal();

      }else if(d1 > (distance + 0.41)){
        Serial.println("Mail is here");
        //sendSignal(); 

      }
    }

    Serial.print("Current Distance: ");
    Serial.print(d1);
    Serial.println(" mm");
}
