// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 4
// Submission code: Q7rQleQt

const int maxColspins[4] = {2, 3, 4, 5}; //pin numbers on the column
const int maxRowspins[4] = {8, 9, 10, 11}; //pin numbers on the row

char values[4][4] = {	// matrix for the buttons to keep them in a particular order
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

void setup()
{
  // Start the serial port
  Serial.begin(9600);
	 
  for (char mrp = 0; mrp < 4; mrp++) //loop through all pins 
  {
    pinMode(maxRowspins[mrp], INPUT);   // set the rowsPins as input
    digitalWrite(maxRowspins[mrp], HIGH);  // turn on and set the pullUp resistors to high
    pinMode(maxColspins[mrp], OUTPUT);  // set the colPins as output
  }
}


void loop()
{
  // Set a char value for the pressedValue function and call it 
  char value = pressedValue();
  if (value != 0) //if statment to see if the value does not equall zero
  {
    // Delay the output
    delay(1000);
    // Print the pressed key to the serial
    Serial.print("Keypad pressed: ");
    Serial.println(value);
  }
  
}

// pressedValue function for scanning and displaing key pressed 
char pressedValue()
{
  char v = 0; // define varabile v

  for (char mcp = 0; mcp < 4; mcp++) // loop through columns
  {
    digitalWrite(maxColspins[mcp], LOW); // set columns to low 
    for (char mrp = 0; mrp < 4; mrp++) // loop through rows
    {
      if (digitalRead(maxRowspins[mrp]) == LOW) // checks if rows are equall to low
      {
        while (digitalRead(maxRowspins[mrp]) == LOW){ // checks the state of the rows if they are equall to low
          v = values[mrp][mcp]; // save the values in the v variable  
        }
      }
    }
    digitalWrite(maxColspins[mcp], HIGH); // set colums to high 
  }
  return v; // return varabile 
}
