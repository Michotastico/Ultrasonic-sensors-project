/*
Pines of the first sensor.
*/
#define S1echo 7
#define S1trig 8

/*
Pines of the second sensor.
*/
#define S2echo 10
#define S2trig 11

long duration, distance;
void setup() {
  Serial.begin(9600);   
  /*
  Setup of the echo & trig of everysensor.
  */
  pinMode(S1echo, INPUT);
  //pinMode(S2echo, INPUT);
  
  pinMode(S1trig, OUTPUT);
  //pinMode(S2trig, OUTPUT);

}

void loop() {
  printString("Testing");
  estimateDistance(S1trig, S1echo);
  delay(10000);
}

void printReadings(String label, long value){
  String phrase = label+": "+value;
  printString(phrase);
}
void printString(String phrase){
  Serial.println(phrase);
  Serial.println(" ");
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
  
  //Calculate Duration of pulse.
  duration = pulseIn(echo,HIGH);
  printReadings("Duration", duration);
  
  //Distance in centimeters
  distance = duration/58.2;
  printReadings("Distance", distance);
  
  return distance;
}




