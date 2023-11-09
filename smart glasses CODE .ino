#define trigPin1 5
#define echoPin1 6
#define buzzer1 8
#define trigPin2 9
#define echoPin2 10
#define buzzer2 12

long duration, distance, UltraSensor1, UltraSensor2;
char data;
String SerialData="";
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(buzzer1, OUTPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(buzzer2, OUTPUT);
digitalWrite(buzzer1,LOW);
digitalWrite(buzzer2,LOW);
}
void loop()
{
SonarSensor(trigPin1, echoPin1);
UltraSensor1 = distance;
SonarSensor(trigPin2,echoPin2);
UltraSensor2 = distance;
while(Serial.available())


{
delay(10);
data=Serial.read();
SerialData+=data;
}
SerialData="";
if(UltraSensor1 <=70)
{
digitalWrite(buzzer1,HIGH);
}
else
{
digitalWrite(buzzer1,LOW);
}
if(UltraSensor2 <=70)
{
digitalWrite(buzzer2,HIGH);
}
else
{
digitalWrite(buzzer2,LOW);
}
}
void SonarSensor(int trigPinSensor,int echoPinSensor)
{
digitalWrite(trigPinSensor, LOW);
delayMicroseconds(2);
digitalWrite(trigPinSensor, HIGH);
delayMicroseconds(10);




digitalWrite(trigPinSensor, LOW);
duration = pulseIn(echoPinSensor, HIGH);
distance= (duration/2) / 29.1;
}