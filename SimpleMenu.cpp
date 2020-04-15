/**
 * Sketch       SimpleMenu.cpp
 * Author       2020-04-14 Charles Geiser
 * 
 * Purpose      The example shows how to define a menu array and call 
 *              the individual menu items consisting of a pair of
 *              menutext and associated menufunction
 * 
 * Board        Any Arduino / ESP8266 / ESP32
 * Remarks      All menu functions must have the same signature, e.g. void f(void).
 *              In a real application the menu texts are shown on a display.
 *              The user selects one and the corresponding function is called.
 * References
 */
#include <Arduino.h>

#define COMPORT_SPEED   9600

// Define the structure of menuitems as a pair 
// consisting of text and associated function
typedef struct 
{
  const char *txt; 
  uint16_t (&func)(uint16_t, uint16_t);  // reference to a function taking 2 int arguments and returning an int
} MenuItem;

// Define a first test function
uint16_t funcTest1(uint16_t a, uint16_t b)
{
  return a + b;   
}

// Define a second test function
uint16_t funcTest2(uint16_t a, uint16_t b)
{ 
  return a * b;
}

// Define the menu
MenuItem menu[] =           
{
  {"Test 1 ", funcTest1},
  {"Test 2 ", funcTest2},
};

// Calculate the number of menuitems
uint8_t nbrMenuItems = sizeof(menu) / sizeof(menu[0]);  

// Define a variable f as a reference of funcTest1
uint16_t (&f)(uint16_t, uint16_t) = funcTest1;

void setup() 
{
  Serial.begin(COMPORT_SPEED);

  Serial.print("Number of menuitems: "); Serial.println(nbrMenuItems);
 
  // Call the function referenced by variable f
  Serial.println((*f)(13, 14));

  // Call all menuitems defined in menu
  for (uint8_t i = 0; i < nbrMenuItems; i++)
  {
    Serial.print(menu[i].txt);
    Serial.println((menu[i].func)(13, 14));
  }
}

void loop() 
{
  // nothing to do here
}
