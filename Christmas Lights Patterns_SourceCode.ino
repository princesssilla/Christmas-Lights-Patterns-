int led[] = {2,3,4,5,6,7,8,9}; //array
int led_total; //store the total number of LEDs


void setup() {
  led_total = sizeof(led) / sizeof(int); // (size of (int) = number of bytes used by a single integer) calculates the number of elements in the array led 
  for (int i = 0; i < led_total; i++) { //initializes each LED pin as an output, necessary to control the LEDs (on and off)
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  delay(200);
  led_on();
  delay(200);
  led_off();
  delay(200);
  for (int i = 0; i < 3; i++) {pattern1();} //executed 10 times
  for (int i = 0; i < 3; i++) {pattern2();} //executed 10 times
  for (int i = 0; i < 3; i++) {pattern3();} //executed 10 times
  for (int i = 0; i < 3; i++) {pattern4();} //executed 10 times
  for (int i = 0; i < 50; i++){pattern5();} //executed 30 times

  led_off();
  delay(200);
}

//TURN ON ALL LEDs
void led_on() { 
  for (int i = 0; i < led_total; i++) { //iterates over each LED, turning on one by one
    digitalWrite(led[i], HIGH); // setting each pin in the led array to HIGH
  }
}

//TURN OFF ALL LEDs
void led_off() {
  for (int i = 0; i < led_total; i++) { // iterates over each LED, turning off one by one
    digitalWrite(led[i], LOW); //setting each pin in the led array to LOW
  }
}

//LEFT TO RIGHT
void pattern1() { 
  for (int i = 0; i < led_total; i++) { //iterates over each LED pin in the led array, 
    digitalWrite(led[i], HIGH); // turns on the LED at index i
    delay(300);
    digitalWrite(led[i], LOW); // turns off the LED
  }
}

//RIGHT TO LEFT
void pattern2() {
  for (int i = led_total; i > 0; i--) { // starts from the last LED and moves backwards
    digitalWrite(led[i - 1], HIGH); // turns on the LED at index i-1
    delay(300);
    digitalWrite(led[i - 1], LOW); // turns off the LED at index i-1
  }
}

//LEFT TO RIGHT FILL
void pattern3() {
  for (int i = 0; i < led_total; i++) { 
    digitalWrite(led[i], HIGH); // turns on each LED one by one from left to right
    delay(300);
  }
  for (int i = led_total; i > 0; i--) {
    digitalWrite(led[i - 1], LOW);  // turns off each LED one by one from right to left
    delay(300);
  }
}

//RIGHT TO LEFT FILL
void pattern4() {
  led_on();
  delay(300);
  for (int i = 0; i < led_total; i++) { // turns off each LED from left to right
    digitalWrite(led[i], LOW);
    delay(300);
  }
  for (int i = led_total; i > 0; i--) { // turns LEDs back on from right to left
    digitalWrite(led[i - 1], HIGH);
    delay(300);
  }
  led_off();
}

//ALTERNATE LEDs
void pattern5() {
  for (int i = 0; i < led_total; i = i + 2) { // lights every even-indexed LED and turns off every odd-indexed LED
    digitalWrite(led[i], HIGH);
    digitalWrite(led[i + 1], LOW); //if i is 0, i + 1 is 1, so the loop controls LED[0] and LED[1]. If i is 2, i + 1 is 3, controlling LED[2] and LED[3], and so on
  }
  delay(50);
  for (int i = 0; i < led_total; i = i + 2) { // reverses the LED states: turns off every even-indexed LED and lights every odd-indexed LED
    digitalWrite(led[i], LOW);
    digitalWrite(led[i + 1], HIGH); //If i is 0, i + 1 is 1, so the loop controls LED[0] and LED[1]. If i is 2, i + 1 is 3, controlling LED[2] and LED[3], and so on
  }
  delay(50);
}




