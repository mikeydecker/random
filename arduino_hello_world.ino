// Simple Hello World File for Arduino - HiLetgo BadUsb Beetle
#include <HID-Project.h>
#include <HID-Settings.h>
// !! Didn't work with string, but did work with 'KeyboardKeycode' !!
// !! It worked! !!
// Reworking script to try and get the typeKey function working with strings and integers
// Adding Keyboard.h to see if it makes the typeKey thing work
// Didn't work - removing (commenting out)
// #include <Keyboard.h>

// Utility function
// Doesn't work for KEY_ keys
// maybe because int is declared but the KEY_ keys are a string?
// trying typeKeyString function for strings
void typeKey(int key){
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// Ended up using KeyboardKeycode instead of string, worked!

void typeKeyKeycode(KeyboardKeycode key){
    Keyboard.press(key);
    delay(50);
    Keyboard.release(key);
}

void setup()
{
  // Start Keyboard and Mouse
  AbsoluteMouse.begin();
  Keyboard.begin();

  // Start Payload
  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("Notepad");

  delay(1000);
  // typeKey not working - commenting out, trying Keyboard.press instead
  //typeKey(KEY_ENTER);
  // trying to get typeKey to work as a string
  // Keyboard.press(KEY_ENTER);
  // Keyboard.releaseAll();
  typeKeyKeycode(KEY_ENTER);


  delay(1000);

  Keyboard.print("Hello World!");

  delay(1000);

  // typeKey not working - commenting out, trying Keyboard.press instead
  //typeKey(KEY_ENTER);
  // trying to get typeKey to work as a string
  // Keyboard.press(KEY_ENTER);
  // Keyboard.releaseAll();
  typeKeyKeycode(KEY_ENTER);

  delay(1000);

  Keyboard.print("Never gonna give you up... Never gonna let you down...");

  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();

  // End Payload

  // Stop Keyboard and Mouse
  Keyboard.end();
  AbsoluteMouse.end();
}

// Unused
void loop() {}
