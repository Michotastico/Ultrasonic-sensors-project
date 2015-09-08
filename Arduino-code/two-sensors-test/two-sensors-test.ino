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
  estimateDistance(S1-trig, S1-echo);
  delayMicroseconds(1000);
}

void printReadings(String label, long value){
  String phrase = label+": "+value;
  Serial.print(phrase);
}

/*
Estimate the distance received from the ultrasonic sensor.
*/
int estimateDistance(int trig, int echo){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trig,LOW);
  
  //Claculate Duration of pulse.
  duration = pulseIn(echo,HIGH);
  printReadings("Duration", duration);
  
  //Distance in centimeters
  distance = duration/58.2;
  printReadings("Distance", distance);
  
  return distance;
}




