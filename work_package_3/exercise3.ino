// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 3
// Submission code:

// Initiate the delay variable
int periodicity = 500;

void setup()
{
  // Initate the serial port
  Serial.begin(9600);
}

void loop()
{
  // Get the information from pin A0
  double temp = analogRead(A0);
  // Convert the readout to voltage
  temp = temp * (5000 / 1024);
  // Convert the voltage to temperature
  temp = (temp - 500) / 10;

  /*
  // The code above should be running correctry but the output seems to be wrong
  // I think there might be some limitation with tinkercad
  // The code bellow gives a more accurate temperature reading
    temp = temp / 1024;
    temp = ((temp * 5) - 0.5) * 100;
  */
  // Print the temperature to the serial output
  Serial.print("Current Temperature: ");
  Serial.println(temp);

  // Add delay to the program
  delay(periodicity);
}
