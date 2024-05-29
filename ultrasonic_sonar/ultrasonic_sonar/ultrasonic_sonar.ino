void setup()
{
	Serial.begin(9600);
	pinMode(4, OUTPUT);
	pinMode(5,  OUTPUT);
	pinMode(6, OUTPUT);
	digitalWrite(4, HIGH);
	delay(500);
	digitalWrite(5,  HIGH);
	delay(500);
	digitalWrite(6, HIGH);
	delay(500);
}

void  loop()
{
	if (analogRead(A0) > 60)
	{
		digitalWrite(6, HIGH);
	}
	else
	{
		digitalWrite(6,  LOW);
	}
	if (analogRead(A0) > 20)
	{
		digitalWrite(4, HIGH);
	}
	else
	{
		digitalWrite(4,  LOW);
	}
	if (analogRead(A0) > 45)
	{
		digitalWrite(5, HIGH);
	}
	else
	{
		digitalWrite(5,  LOW);
	}

	Serial.println(analogRead(A0));
	delay(20);
}
