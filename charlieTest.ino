/*
Gemma connected to 360 ohms resistors on PINS 0,1,2 running 6 LEDs 
For more connection info look for the Schematic
powered by a ~360 mAH lipo 
Battery lasted 5 hrs 30 min w/no sleep mode implemented

*/

//Change the numbers here to match the PIN number you use on your Arduino 
#define LED_A 0
#define LED_B 2
#define LED_C 1

void setup()
{
  // first set all pins to input, or high impedance
  // (not strictly necessary as all pins are inputs by default)
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
}

void loop()
{
  // run through a sample loop, lighting each LED

  // in turn and holding for half a second.
  set_pins(LED_A, LED_B);
  delay(100);

  set_pins(LED_B, LED_A);
  delay(100);

  set_pins(LED_C, LED_A); 
  delay(100);

  set_pins(LED_A, LED_C);
  delay(100);

  set_pins(LED_B, LED_C);
  delay(100);

  set_pins(LED_C, LED_B);
  delay(100); 
}

void set_pins(int high_pin, int low_pin)
{
  // reset all the pins
  reset_pins();

  // set the high and low pins to output
  pinMode(high_pin, OUTPUT);
  pinMode(low_pin, OUTPUT);

  // set high pin to logic high, low to logic low
  digitalWrite(high_pin, HIGH);
  digitalWrite(low_pin,LOW);
}

void reset_pins()
{
  // start by ensuring all pins are at input and low
  pinMode(LED_A, INPUT); 
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);

  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
}
