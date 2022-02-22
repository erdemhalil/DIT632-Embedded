// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 4
// Exercise 3
// Submission code: tuesday49

#include <Adafruit_NeoPixel.h>

// Initialize the temperature thresholds for when the leds power
int temp1 = 0;
int temp2 = 20;
int temp3 = 40;
int temp4 = 60;
int temp5 = 80;

// Initiate the light thresholds 
int light1 = 10;
int light2 = 30;
int light3 = 50;
int light4 = 70;
int light5 = 90;

// Initiate the neopixel variable
Adafruit_NeoPixel ring(12, 12, NEO_GRB + NEO_KHZ800);

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
    // Set the red led pin to output
    pinMode(13, OUTPUT);
}

void loop() {}

// Function to trigger an action 
// ISR will trigger every 300ms because we use TIMER1_COMPA_vect
ISR(TIMER1_COMPA_vect)
{
    // Reset the timer
    TCNT1 = 0;
    // Read the data from the photoresistor
    int lightValue = analogRead(A1);
    // Map the data on a scale from 0% to 100%
    lightValue = map(lightValue, 1, 310, 0, 100);
    // Print the light persentage to serial
    Serial.print("Light value: ");
    Serial.println(lightValue);
    // Get the temperature from the termometer
    double temp = analogRead(A0);
    // Convert the sensor reading to temperature
    temp = temp / 1024;
    temp = ((temp * 5) - 0.5) * 100;
    // Print the temperature reading to the serial output
    Serial.print("temp: ");
    Serial.println(temp);

    // We use half of the ring to indicate the temperature and the other half to indicate the light intensity 
    // Check if the temperature is lower than temp1 
    if (temp < temp1)
    {
        // We use red to indicate the temperature
        // Power on the first led
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 0, 0, 0);
        ring.setPixelColor(3, 0, 0, 0);
        ring.setPixelColor(4, 0, 0, 0);
        ring.setPixelColor(5, 0, 0, 0);
        ring.setPixelColor(6, 0, 0, 0);
    }
    // Check if the temperature is between temp1 and temp2
    else if (temp >= temp1 && temp < temp2)
    {
        // Light the first two leds
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 255, 0, 0);
        ring.setPixelColor(3, 0, 0, 0);
        ring.setPixelColor(4, 0, 0, 0);
        ring.setPixelColor(5, 0, 0, 0);
        ring.setPixelColor(6, 0, 0, 0);
    }
    // Check if the temperature is between temp2 and temp3
    else if (temp >= temp2 && temp < temp3)
    {
        // Light the first three leds
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 255, 0, 0);
        ring.setPixelColor(3, 255, 0, 0);
        ring.setPixelColor(4, 0, 0, 0);
        ring.setPixelColor(5, 0, 0, 0);
        ring.setPixelColor(6, 0, 0, 0);
    }
    // Check if the temperature is between temp3 and temp4
    else if (temp >= temp3 && temp < temp4)
    {
        // Light the first four leds
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 255, 0, 0);
        ring.setPixelColor(3, 255, 0, 0);
        ring.setPixelColor(4, 255, 0, 0);
        ring.setPixelColor(5, 0, 0, 0);
        ring.setPixelColor(6, 0, 0, 0);
    }
    // Check if the temperature is between temp4 and temp5
    else if (temp >= temp4 && temp < temp5)
    {
        // Power the first five leds
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 255, 0, 0);
        ring.setPixelColor(3, 255, 0, 0);
        ring.setPixelColor(4, 255, 0, 0);
        ring.setPixelColor(5, 255, 0, 0);
        ring.setPixelColor(6, 0, 0, 0);
    }
    // Check if the temperature is higher than temp5
    else if (temp >= temp5)
    {
        // Power all the leds on the left half of the ring
        ring.setPixelColor(1, 255, 0, 0);
        ring.setPixelColor(2, 255, 0, 0);
        ring.setPixelColor(3, 255, 0, 0);
        ring.setPixelColor(4, 255, 0, 0);
        ring.setPixelColor(5, 255, 0, 0);
        ring.setPixelColor(6, 255, 0, 0);
    }

    // Check if the light is lower than light1
    if (lightValue < light1)
    {
        // We use blue to indicate the light intensity 
        // Power on the first led
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 0);
        ring.setPixelColor(10, 0, 0, 0);
        ring.setPixelColor(9, 0, 0, 0);
        ring.setPixelColor(8, 0, 0, 0);
        ring.setPixelColor(7, 0, 0, 0);
    }
    // Check if the light is between light1 and light2
    else if (lightValue >= light1 && lightValue < light2)
    {
        // Light the first two leds
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 255);
        ring.setPixelColor(10, 0, 0, 0);
        ring.setPixelColor(9, 0, 0, 0);
        ring.setPixelColor(8, 0, 0, 0);
        ring.setPixelColor(7, 0, 0, 0);
    }
    // Check if the light is between light2 and light3
    else if (lightValue >= light2 && lightValue < light3)
    {
        // Light the first three leds
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 255);
        ring.setPixelColor(10, 0, 0, 255);
        ring.setPixelColor(9, 0, 0, 0);
        ring.setPixelColor(8, 0, 0, 0);
        ring.setPixelColor(7, 0, 0, 0);
    }
    // Check if the light is between light3 and light4
    else if (lightValue >= light3 && lightValue < light4)
    {
        // Light the first four leds
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 255);
        ring.setPixelColor(10, 0, 0, 255);
        ring.setPixelColor(9, 0, 0, 255);
        ring.setPixelColor(8, 0, 0, 0);
        ring.setPixelColor(7, 0, 0, 0);
    }
    // Check if the light is between light4 and light5
    else if (lightValue >= light4 && lightValue < light5)
    {
        // Power the first five leds
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 255);
        ring.setPixelColor(10, 0, 0, 255);
        ring.setPixelColor(9, 0, 0, 255);
        ring.setPixelColor(8, 0, 0, 255);
        ring.setPixelColor(7, 0, 0, 0);
    }
    // Check if the light is higher than light5
    else if (lightValue >= light5)
    {
        // Power on all the leds on the right half of the ring
        ring.setPixelColor(0, 0, 0, 255);
        ring.setPixelColor(11, 0, 0, 255);
        ring.setPixelColor(10, 0, 0, 255);
        ring.setPixelColor(9, 0, 0, 255);
        ring.setPixelColor(8, 0, 0, 255);
        ring.setPixelColor(7, 0, 0, 255);
    }
    // send the information to the ring
    ring.show();

    // Check if all the leds for temp or light are on 
    if (lightValue >= light5 || temp >= temp5)
    {
        // Power on the red led
        digitalWrite(13, HIGH);
    }
    // If not all the leds for temp or light are on 
    else
    {
        // Power off the red led
        digitalWrite(13, LOW);
    }
}
