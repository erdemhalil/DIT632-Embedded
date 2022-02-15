int seconds = 0; // Initiate the seconds variable

void setup()
{
    // Make sure everything is diabled in the control register
    TCCR1A = 0;
    TCCR1B = 0;
    // Set CS12 to 256 so that it counts one every time 256 pulses pass in the internal timer
    TCCR1B |= B00000100;
    // Enable compare match A
    TIMSK1 |= B00000010;
    // Create an intrerump every 1 second ( = 62.5ns * 256 * 62500)
    OCR1A = 62500;
    // Start the serial port
    Serial.begin(9600);
    // Set the led pins to output
    pinMode(10, OUTPUT);
}

void loop()
{
    // Set the servo to high
    digitalWrite(10, HIGH);
}

ISR(TIMER1_COMPA_vect)
{
    // Reset the timer
    TCNT1 = 0;
    // Increment the seconds
    seconds++;
    // Print the seconds
    Serial.println(seconds);
    // Set the servo to low, activating it for a breaf time
    digitalWrite(10, LOW);
}
