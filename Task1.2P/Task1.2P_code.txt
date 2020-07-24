int celsius = 0;
const int interruptPin= 2;
volatile boolean ledOn = false;

void setup()
{
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop()
{
  temperatureMeasurement();
}

void temperatureMeasurement()
{
  // set threshold temperature to activate LEDs
  int baselineTemp = 40;
  
  // measure temperature in Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  if (celsius < baselineTemp) 
  {
    ledOn = true;
    digitalWrite(11, ledOn);
    digitalWrite(12, LOW);
  }
  else 
  {
    digitalWrite(11, LOW);
    digitalWrite(12, ledOn);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}

void blink() 
{
  // if button has been pressed, ledOn = true and led lights activate
  if (ledOn)
  {
    ledOn = true;
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(5000);
    Serial.println("Temperature detection interrupted");
  }
  else
  {
    ledOn = false;
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
}
