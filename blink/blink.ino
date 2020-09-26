#include <BleKeyboard.h>
#include <SPI.h>

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
	pinMode(34, INPUT);
	pinMode(35, INPUT);
	pinMode(17, OUTPUT);
	Serial.println("Starting BLE work!");
	bleKeyboard.begin();
}

void loop() {
  if(bleKeyboard.isConnected()) {
    Serial.println("Sending 'Hello world'...");
		digitalWrite(17, HIGH);
		if(digitalRead(34) == HIGH){
				Serial.println("writing a");
				bleKeyboard.press('c');
				delay(10);}
		else{bleKeyboard.release('c');}
		
		if(digitalRead(35) == HIGH){
				Serial.println("writing a");
				bleKeyboard.press(0x62);
				delay(10);}
		else{bleKeyboard.release(0x62);}

/*
    bleKeyboard.print("Hello world");
    bleKeyboard.write(KEY_RETURN);
    bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    bleKeyboard.releaseAll();
*/
  }
  Serial.println("Waiting 5 seconds...");
}
