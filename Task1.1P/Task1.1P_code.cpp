//TMP36 Pin Variables
int sensPin = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
   //getting the voltage reading from the temperature sensor
   int reading = analogRead(sensPin);  

   // converting that reading to voltage
   float voltage = reading * 4.48;
   voltage /= 1024.0; 

   // now print out the temperature
   float temperatureC = (voltage - 0.5) * 100 ;
   Serial.print(temperatureC); Serial.println(" degrees C");
  
   delay(1000);
}
