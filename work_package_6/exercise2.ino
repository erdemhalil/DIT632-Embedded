// Initialize the time variables for the speaker 
// The lower the value the higher the frequency of the speaker 
unsigned long speakerInterval1 = 9;
unsigned long speakerInterval2 = 8;
unsigned long speakerInterval3 = 7;
unsigned long speakerInterval4 = 5;
unsigned long speakerInterval5 = 1;
// Initialize the led blinking interval
unsigned long ledInterval = 200;
// Initialize the interval for how often we get the distance from the sensor
unsigned long intervalDistance = 200;
// Initialize the time variables to calculate the time interval 
unsigned long previousSpeaker = 0;
unsigned long previousDist = 0;
unsigned long previousLed = 0;
// Initiate the distance variable 
// Default value is 300 to avoid a breef speaker sound before getting the actual value
int distance = 300;

// Initiate the state of the speaker and leds
// false = LOW & true = HIGH
bool speakerState = false;
bool ledState = false;

void setup()
{
    // Start the serial pport
    Serial.begin(9600);
    // Set the leds and the speaker pins to output
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
    // Calculate the time interval
    // Check if 200ms have passed
    if ((unsigned long)(currentMillis - previousDist) >= intervalDistance)
    {
        // set the previousDist to the current time 
        previousDist = millis();
        // Call the distance function to get the current distance
        // Convert the ping time to cm
        distance = 0.01723 * Distance();
        // Print the distance to the serial port
        Serial.print(distance);
        Serial.println(" cm");
    }
    // Call the speaker control function 
    speakerControl(distance, currentMillis);
    // Call the ledControl function to activate the leds
    ledControl(distance, currentMillis);
}

// Distance sensor control function
long Distance()
{
    // Set the sensor pin to output
    pinMode(7, OUTPUT);
    // Clear the system by setting the pin to low
    digitalWrite(7, LOW);
    // 2 microsecond delay
    delayMicroseconds(2);
    // Send a ping by setting the pin to high
    digitalWrite(7, HIGH);
    // Wait 10 microseconds
    delayMicroseconds(10);
    // Stop sending a ping
    digitalWrite(7, LOW);
    // Set the sensor pin to input to receive the answer
    pinMode(7, INPUT);
    // Listen to input, it returns the sound travel time in microseconds
    return pulseIn(7, HIGH);
}

// Led control function 
// Takes the current time and the current distance as arguments 
void ledControl(int distance, unsigned long currentMillis)
{
    // Check if the distance is higher than 200cm 
    if (distance > 200)
    {
        // Set all the leds to off 
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    // If the distance is between 200 and 130 
    else if (distance <= 200 && distance > 130)
    {
        // Turn on the first led from the left
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    // If  the distance is between 130 and 80
    else if (distance <= 130 && distance > 80)
    {
        // Turn on the first 2 leds
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
    }
    // If the distance is between 80 and 30 
    else if (distance <= 80 && distance > 30)
    {
        // Turn on the first 3 leds 
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
    }
    // If the distance is between 30 and 25
    else if (distance <= 30 && distance > 25)
    {
        // Turn all the leds on 
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
    }
    // If the distance is lower than 25cm
    else if (distance <= 25)
    {
        // Check if 200ms have passed
        // Make the leds blink
        if ((unsigned long)(currentMillis - previousLed) >= ledInterval)
        {
            // Invert the state of the led (eg. from HIGH to LOW)
            ledState = !ledState;
            // Set all the leds to the state
            digitalWrite(5, ledState);
            digitalWrite(4, ledState);
            digitalWrite(3, ledState);
            digitalWrite(2, ledState);
            // Set previousLed to the current time
            previousLed = millis();
        }
    }
}

// Speaker control function 
// Takes the current distance and the current time as arguments
void speakerControl(int distance, unsigned long currentMillis)
{
    // Check if the distance is higher than 200cm
    if (distance > 200)
    {
        // Turn off the speaker 
        digitalWrite(9, LOW);
    }
    // If the distance if between 200 and 130 
    else if (distance <= 200 && distance > 130)
    {
        // The speaker will make a sount every 9ms making a sound at around 10hz
        // Check if 9ms have passed
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval1)
        {
            // Invert the state of the speaker 
            speakerState = !speakerState;
            // Set the speaker to the current state
            digitalWrite(9, speakerState);
            // Set the previousSpeaker variable to the current time
            previousSpeaker = millis();
        }
    }
    // Check if the distance is between 130 and 80
    else if (distance <= 130 && distance > 80)
    {
        // The speaker will make a sound around 125hz
        // Check if 8ms have passed
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval2)
        {
            // Invert the state of the speaker 
            speakerState = !speakerState;
            // Set the speaker to the current state
            digitalWrite(9, speakerState);
            // Set the previousSpeaker variable to the current time
            previousSpeaker = millis();
        }
    }
    // Check if the distance is between 80 and 30
    else if (distance <= 80 && distance > 30)
    {
        // The speaker will make a sound around 140hz
        // Check if 7ms have passed
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval3)
        {
            // Invert the state of the speaker
            speakerState = !speakerState;
            // Set the speaker to the current state
            digitalWrite(9, speakerState);
            // Set the previousSpeaker variable to the current time
            previousSpeaker = millis();
        }
    }
    // Check if the distance is between 30 and 25
    else if (distance <= 30 && distance > 25)
    {
        // The speaker will make a sound around 200hz
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval4)
        {
            // Invert the state of the speaker
            speakerState = !speakerState;
            // Set the speaker to the current state
            digitalWrite(9, speakerState);
            // Set the previousSpeaker variable to the current time
            previousSpeaker = millis();
        }
    }
    // Check if the distance is bellow 25cm
    else if (distance <= 25)
    {
        // The speaker will make a sound around 1000hz
        // Check if 1ms has passed
        if ((unsigned long)(currentMillis - previousSpeaker) >= speakerInterval5)
        {
            // Invert the state of the speaker
            speakerState = !speakerState;
            // Set the speaker to the current state
            digitalWrite(9, speakerState);
            // Set the previousSpeaker variable to the current time
            previousSpeaker = millis();
        }
    }
}
