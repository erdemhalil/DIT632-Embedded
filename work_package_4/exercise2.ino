// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 4
// Exercise 2
// Submission code: tuesday49

int seconds = 0; // Initiate the seconds variable
int n = 0;
int i = 0;

void setup()
{
    // Make sure everything is diabled in the control register
    TCCR1A = 0;
    TCCR1B = 0;
    // Set CS12 to 256 so that it counts one every time 256 pulses pass in the internal timer
    // Every new pulse is now 0.016ms
    TCCR1B |= B00000100;
    // Enable compare match with OCR1A
    TIMSK1 |= B00000010;
    // Create an intrerump every 1 second ( = 62.5ns * 256 * 62500)
    OCR1A = 62500;
    // Start the serial port
    Serial.begin(9600);
    // Set the led pin to output
    pinMode(10, OUTPUT);
}

void loop() {}

// Function to trigger an action 
// ISR will trigger every 300ms because we use TIMER1_COMPA_vect
ISR(TIMER1_COMPA_vect)
{
    // Reset the timer
    TCNT1 = 0;
    // Increment the seconds
    seconds++;
    // Print the seconds to the serial port
    Serial.println(seconds);
    // Check if the value of i is 60
    if (i == 60)
    {
        // Reset the value of n
        n = 0;
    }
    // If n is 60 rotate the servo backwords
    if (n == 60)
    {
        // Make the servo rotate clockwise
        digitalWrite(10, HIGH);
        digitalWrite(10, LOW);
        i++;
    }
    // If n is lower than 60
    // Rotate the servo nomally
    if (n < 60)
    {
        // Make the servo rotate counterclockwise
        digitalWrite(10, LOW);
        digitalWrite(10, HIGH);
        // Increment n
        n++;
        // Reset i
        i = 0;
    }
}
