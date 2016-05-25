/* 
Innovativetom.com
Flower Pot Soil Mosture Sensor
A0 - Soil Mosture Sensor
D2:D6 - LEDS 1,2,3,4,5
LED1 - Green
LED2 - Green
LED3 - Green
LED4 - YELLOW
LED5 - RED
Connect the Soil Mosture Sensor to anolog input pin 0, 
and your 5 led to digital out 2-6
//Adding logic for starting / stopping an motor for watering the plansts.
*/
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

int repetitions = 0;

int max_run = 60; //60 seconds

int mostureSensor = 0;

void setup() {
  // Serial Begin so we can see the data from the mosture sensor in our serial input window. 
  Serial.begin(9600);
  // setting the led pins to outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(mostureSensor);
  // print out the value you read:

  Serial.println(sensorValue);
  
 if (sensorValue >= 820)
 {

 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, HIGH);
 digitalWrite(led5, LOW);
}
else if (sensorValue >= 615  && sensorValue < 820)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);
}  
else if (sensorValue >= 410 && sensorValue < 615)
 {
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW); 
}    
///We're dry!!!
else if (sensorValue >= 250 && sensorValue < 410)
 {
  if(repetitions < max_run) {
   digitalWrite(led1, HIGH);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   digitalWrite(led4, LOW);
   digitalWrite(led5, LOW);
   //This counter makes sure the pump doesnt run more than 60 seconds to flood your life.
   repetitions++;
 }
}
//Don't run here. This probably means that we tried to run but it didnt help! out of water?
else if (sensorValue >= 0 && sensorValue < 250)
 {
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);

 
 
}
if (sensorValue >= 250){
  delay(30000);        // delay 300 second between reads
 if(repetitions > 0) { //Reset water timer if needed
   repetitions = 0;
 }
}
else
{
  delay(1000); //Check more repeatedly to not overflow the plant while pump is on
}
}
