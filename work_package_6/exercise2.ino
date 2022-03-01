unsigned long speakerInterval1 = 9;
unsigned long speakerInterval2 = 8;
unsigned long speakerInterval3 = 7;
unsigned long speakerInterval4 = 5;
unsigned long speakerInterval5 = 1;
unsigned long ledInterval = 200;
unsigned long intervalDistance = 200;
unsigned long previousSpeaker = 0;
unsigned long previousDist = 0;
unsigned long previousLed = 0;
int distance;

bool speakerState = false;
bool ledState = false;

void setup()
{
    Serial.begin(9600);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(9, OUTPUT);
}

void loop()
{
    // Get the curent time
    unsigned long currentMillis = millis();
    if ((unsigned long)(currentMillis - previousDist) >= intervalDistance)
    {
        previousDist = millis();
        // Convert the ping time to cm
        distance = 0.01723 * Distance();
        // Print the distance to the serial port
        Serial.print(distance);
        Serial.println(" cm");
    }
    speakerControl(distance, currentMillis);
    // Call the ledControl function to activate the leds
    ledControl(distance, currentMillis);
}

long Distance()
{
    pinMode(7, OUTPUT);
    // Clear the system
    digitalWrite(7, LOW);
    delayMicroseconds(2);
    // Send a ping
    digitalWrite(7, HIGH);
    delayMicroseconds(10);
    // Stop sending a ping
    digitalWrite(7, LOW);
    pinMode(7, INPUT);
    // Listen to input, it returns the sound travel time in microseconds
    return pulseIn(7, HIGH);
}

void ledControl(int distance, unsigned long currentMillis)
{
    if (distance > 200)
    {
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    else if (distance <= 200 && distance > 130)
    {
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    else if (distance <= 130 && distance > 80)
    {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    else if (distance <= 80 && distance > 30)
    {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
    }
    else if (distance <= 30 && distance > 25)
    {
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
    }
    else if (distance <= 25)
    {
        if ((unsigned long)(currentMillis - previousLed) >= ledInterval)
        {
            ledState = !ledState;
            digitalWrite(5, ledState);
            digitalWrite(4, ledState);
            digitalWrite(3, ledState);
            digitalWrite(2, ledState);
            previousLed = millis();
        }
    }
}

void speakerControl(int distance, unsigned long currentMillis)
{
    if (distance > 200)
    {
        digitalWrite(9, LOW);
    }
    else if (distance <= 200 && distance > 130)
    {
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval1)
        {
            speakerState = !speakerState;
            digitalWrite(9, speakerState);
            previousSpeaker = millis();
        }
    }
    else if (distance <= 130 && distance > 80)
    {
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval2)
        {
            speakerState = !speakerState;
            digitalWrite(9, speakerState);
            previousSpeaker = millis();
        }
    }
    else if (distance <= 80 && distance > 30)
    {
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval3)
        {
            speakerState = !speakerState;
            digitalWrite(9, speakerState);
            previousSpeaker = millis();
        }
    }
    else if (distance <= 30 && distance > 25)
    {
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval4)
        {
            speakerState = !speakerState;
            digitalWrite(9, speakerState);
            previousSpeaker = millis();
        }
    }
    else if (distance <= 25)
    {
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval5)
        {
            speakerState = !speakerState;
            digitalWrite(9, speakerState);
            previousSpeaker = millis();
        }
    }
}
