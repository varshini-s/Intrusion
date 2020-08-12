#define pingTrig 6        		 //choose trigpin
#define pingEcho 7      		 //choose echopin

int cameratrigger = 2 ; 		//choose pin for camera trigger
int led = 3 ;                  		 //choose pin for LED
 
 void setup()
{  Serial.begin(9600);
   pinMode(pingTrig, OUTPUT); 	 //declaring pin trig as output
   pinMode(pingEcho, INPUT);   	 //declaring echo pin as input
   delay(200);
   pinMode(led, OUTPUT);		 //declare LED as output
  pinMode(cameratrigger, OUTPUT); 	 //declare camera as output
  
}
  void loop()
{
  long duration, inches, cm;
  digitalWrite(pingTrig, LOW);	//turn off trigpin initially for 2 ms
  delayMicroseconds(2);
  digitalWrite(pingTrig, HIGH); 	//turn on trig pin for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(pingTrig, LOW); 		// turn off trigpin
  
  duration = pulseIn(pingEcho, HIGH);  	  //turn on echo pin 
                                                                                         
  cm = duration / 29 / 2;			//to calculate distance in cm
  
  Serial.print("-->");Serial.println(cm);     // to begin serialprint


   if(cm < 30 ){				//to set limit for motion detection
digitalWrite(cameratrigger,HIGH);	//turn on the cameratrig once motion detected
digitalWrite(led,HIGH);    		//turn on the LED
    delay(200);
    digitalWrite(cameratrigger,LOW);	//turn off camera after a delay  of 200 ms
digitalWrite (led,LOW);    		// turn off LED after a delay of 200 ms
delay(200);}} 
 
