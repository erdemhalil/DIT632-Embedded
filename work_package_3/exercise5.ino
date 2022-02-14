// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 5
// Submission code: 

// header file for Keypad library
#include <Keypad.h>

unsigned char rows = 4; // initiate number of rows on the keypad
unsigned char cols = 4; // initiate number of columns on the keypad

unsigned char maxColspins[4] = {2, 3, 4, 5}; // pin numbers on the column
unsigned char maxRowspins[4] = {8, 9, 10, 11}; // pin numbers on the row

char values[4][4] = {  
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},  // matrix for the buttons to keep them in a particular order
    {'7', '8', '9', 'C'},  
    {'*', '0', '#', 'D'}};


// Initiate the keypad 
Keypad keypad = Keypad(makeKeymap(values), maxRowspins, maxColspins, rows, cols);

void setup()
{
  // Start the serial port
  Serial.begin(9600);
}


void loop()
{
  // Get the current pressed key from the keypad
  char pressedKey = keypad.getKey();
  // Check if any key is pressed
  if (pressedKey)
  {
    // Delay the output
    delay(1000);
    // Print the pressed key to the serial
    Serial.print("Keypad pressed: ");
    Serial.println(pressedKey);
  }
}
