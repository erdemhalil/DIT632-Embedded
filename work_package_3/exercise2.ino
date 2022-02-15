// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 2
// Submission code: Q7rQleQt

// Initiate the delay variable
int periodicity = 500;

void setup()
{
    // Initate the serial port
    Serial.begin(9600);
    // Initiate the red pin
    pinMode(13, OUTPUT);
    // Initiate the yellow pin
    pinMode(12, OUTPUT);
    // Initiate the green pin
    pinMode(11, OUTPUT);
}

void loop()
{
    // Read the data from the photoresistor
    int lightValue = analogRead(A0);
    // Map the data on a scale from 0% to 100%
    lightValue = map(lightValue, 54, 974, 0, 100);
    // Print the light persentage to serial
    Serial.println("Light value : ");
    Serial.print(lightValue);
    Serial.println("%");

    // Read the data from the termometer
    double temp = analogRead(A1);
    // Convert the data to temperature
    temp = temp / 1024;
    temp = ((temp * 5) - 0.5) * 100;

    // Print the data to the serual output
    Serial.print("Current Temperature: ");
    Serial.println(temp);

    // Check if the light value is 0
    if (lightValue == 0)
    {
        // Check if the temperature is lower than -12C
        if (temp < -12)
        {
            // If it is then power on the green led and power off the other ones
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        }
        else
        {
            // If the temperature is higher than -12
            // Power on the red led and power off the other ones
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
        }
    }
    // Check if the light value is between 1 and 20
    else if (lightValue >= 1 && lightValue <= 20)
    {
        // Check if the temperature is between -12 and 0
        if (temp >= -12 && temp <= 0)
        {
            // Power on the green led if it is
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        }
        // If the temperature is higher than 0
        else if (temp > 0)
        {
            // Power on the red led
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
        }
        // If the temperature is lower than -12
        else if (temp < -12)
        {
            // Power on the yellow led
            digitalWrite(11, LOW);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
        }
    }
    // Check if the light value is between 21% and 60%
    else if (lightValue >= 21 && lightValue <= 60)
    {
        // Check if the temperature is between 0 and 20C
        if (temp >= 0 && temp <= 20)
        {
            // Power on the green led
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        }
        // If the temperature is higher than 20C
        else if (temp > 20)
        {
            // Power on the red led
            digitalWrite(11, LOW);
            digitalWrite(12, LOW);
            digitalWrite(13, HIGH);
        }
        // If the temperature is lower than 0C
        else if (temp < 0)
        {
            // Power on the yellow led
            digitalWrite(11, LOW);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
        }
    }
    // Check if the current light value is between 61 and 100%
    else if (lightValue >= 61 && lightValue <= 100)
    {
        // Check if the temperature is higher than 21C including
        if (temp >= 21)
        {
            // Power on the green led
            digitalWrite(11, HIGH);
            digitalWrite(12, LOW);
            digitalWrite(13, LOW);
        }
        // If the temperature is lower than 21C
        else if (temp < 21)
        {
            // Power on the yellow led
            digitalWrite(11, LOW);
            digitalWrite(12, HIGH);
            digitalWrite(13, LOW);
        }
    }

    // Add a delay to the program
    delay(periodicity);
}