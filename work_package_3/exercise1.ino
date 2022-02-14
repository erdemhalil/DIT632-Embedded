// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 1
// Submission code: 

void setup()
{
    // Initiate the pin for the blinking led
    pinMode(13, OUTPUT);
    // Initiate the pin for the led with a button
    pinMode(12, OUTPUT);
}

void loop()
{
    // Power on the button led
    digitalWrite(12, HIGH);

    // Power on the linking led
    digitalWrite(13, HIGH);
    // Wait for 1000 millisecond(s)
    delay(1000);
    // Power off the blinking led
    digitalWrite(13, LOW);
    // Wait for 1000 millisecond(s)
    delay(1000);
}
