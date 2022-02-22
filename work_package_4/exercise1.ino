// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 4
// Exercise 1
// Submission code: tuesday49

// Initialize the temperatures when the leds power
int temp1 = 0;
int temp2 = 20;
int temp3 = 40;
int temp4 = 60;

void setup()
{
    // Make sure everything is diabled in the control register
    TCCR1A = 0;
    TCCR1B = 0;
    // Set CS12 to 256 so that it counts one every time 256 pulses pass in the internal timer
    TCCR1B |= B00000100;
    // Enable compare match with OCR1A
    TIMSK1 |= B00000010;
    // Create an intrerump every 300ms ( = 62.5ns * 256 * 18750)
    OCR1A = 18750;
    // Start the serial port
    Serial.begin(9600);
    // Set the led pins to output
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
}

void loop() {}

// Function to trigger an action 
// ISR will trigger every 300ms because we use TIMER1_COMPA_vect
ISR(TIMER1_COMPA_vect)
{
    // Reset the timer
    TCNT1 = 0;
    // Get the temperature from the termometer
    double temp = analogRead(A0);
    // Convert the sensor reading to temperature
    temp = temp / 1024;
    temp = ((temp * 5) - 0.5) * 100;
    // Print the temperature reading to the serial output
    Serial.print("Current Temperature: ");
    Serial.println(temp);

    // Check if the temperature is lower than the first temp
    if (temp < temp1)
    {
        // Only light one led
        digitalWrite(13, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
    }
    // Check if the temperature is between temp1 and temp2
    else if (temp >= temp1 && temp < temp2)
    {
        // Light the first two leds
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
    }
    // Check if the temperature is between temp2 and temp3
    else if (temp >= temp2 && temp < temp3)
    {
        // Light the first three leds
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
    }
    // Check if the temperature is between temp3 and temp4
    else if (temp >= temp3 && temp < temp4)
    {
        // Light the first four leds
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, LOW);
    }
    // Check if the temperature higher than temp4
    else if (temp >= temp4)
    {
        // Power all the leds
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(9, HIGH);
    }
}
