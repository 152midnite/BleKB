#include <BleKeyboard.h>
#include <stdio.h>
using namespace std;
BleKeyboard bleKeyboard;


void sweep(int rows, int columns[], int buttons[]) {
	// go through whole matrix and press/depress buttons
	int i, time2, time = 100;
	
	for (i=0;i<rows;i++){
		time2 = time * i;
		blink(time2);
}
}


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(22, OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void blink(int milisec) {
  digitalWrite(22, LOW);
  delay(milisec);
  digitalWrite(22, HIGH);
  delay(milisec);
}


void loop() {
	digitalWrite(22, HIGH);
	int rows = 4;
	int columns[3];
	int buttons[12];

  if(bleKeyboard.isConnected()) {

		sweep(rows, columns, buttons);




//    bleKeyboard.write(KEY_RETURN);
//    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
//    Serial.println("Sending Ctrl+Alt+Delete...");
//    bleKeyboard.press(KEY_LEFT_CTRL);
//    bleKeyboard.press(KEY_LEFT_ALT);
//    bleKeyboard.press(KEY_DELETE);
//    bleKeyboard.releaseAll();

  }
}
