/*
Pines of the first sensor.
*/
#define S1-echo 7
#define S1-trig 8

/*
Pines of the second sensor.
*/
#define S2-echo 10
#define S2-trig 11

long duration, distance;
void setup() {
  /*
  Setup of the echo & trig of everysensor.
  */
  pinMode(S1-echo, INPUT);
  pinMode(S2-echo, INPUT);
  
  pinMode(S1-trig, OUTPUT);
  pinMode(S2-trig, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void printReadings(String label, long value){
  String phrase = label+": "+value;
  Serial.print(phrase);
}

/*
Estimate the distance received from the ultrasonic sensor.
*/
int estimateDistance(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  
  //Distance in centimeters
  distance = duration/58.2;
  return distance;
}




