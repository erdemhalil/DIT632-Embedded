// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 3
// Exercise 4
// Submission code: 

const int maxColspins[4] = {2, 3, 4, 5};
const int maxRowspins[4] = {8, 9, 10, 11};

char values[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

void setup()
{
  Serial.begin(9600);

  for (char mrp = 0; mrp < 4; mrp++)
  {
    pinMode(maxRowspins[mrp], INPUT);     
    digitalWrite(maxRowspins[mrp], HIGH); 
    pinMode(maxColspins[mrp], OUTPUT); 
  }
}


void loop()
{
  char value = pressedValue();
  if (value != 0)
  {
    delay(1000);
    Serial.print("Keypad pressed: ");
    Serial.println(value);
  }
  
}


char pressedValue()
{
  char v = 0;

  for (char mcp = 0; mcp < 4; mcp++)
  {
    digitalWrite(maxColspins[mcp], LOW);
    for (char mrp = 0; mrp < 4; mrp++)
    {
      if (digitalRead(maxRowspins[mrp]) == LOW)
      {
        while (digitalRead(maxRowspins[mrp]) == LOW){
          v = values[mrp][mcp];
        }
      }
    }
    digitalWrite(maxColspins[mcp], HIGH);
  }
  return v;
}
