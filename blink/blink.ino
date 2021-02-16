#include <BleKeyboard.h>
#include <SPI.h>
BleKeyboard bleKeyboard;


int in_pins[13] = {36,39,34,35,23,19,21,22};
int out_pins[10] = {5,13,12,4,32,33,25,26,27,14};
char keys[8][6] = {{'q', 'w', 'e', 'r', 't', 'y'}, 
										{'u', 'i', 'o', 'p', '[', ']'},
                    {KEY_TAB, 'a', 's', 'd', 'f', 'g'}, 
									  {'h', 'j', 'k', 'l', ';', KEY_RETURN},
                    {'/', 'z', 'x', 'c', 'v', 'b'}, 
										{'n', 'm', ',', '.', '/', KEY_RIGHT_SHIFT},
                    {' ', ' ', ' ', ' ', ' ', ' '},
										{KEY_LEFT_CTRL, KEY_LEFT_GUI, KEY_LEFT_ALT,
										 KEY_LEFT_SHIFT, ' ', ' '}};



void setup() {
  Serial.begin(115200);
  pinMode(36, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);

  pinMode(23, INPUT_PULLDOWN);
  pinMode(19, INPUT_PULLDOWN);
  pinMode(21, INPUT_PULLDOWN);
  pinMode(22, INPUT_PULLDOWN);

 

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
	int n = sizeof(out_pins);
	int m = sizeof(in_pins);
	int i, j;
	

  for (i=0;i<n;i++){pinMode(out_pins[i], OUTPUT);}
 // for (i=0;i<n;i++){digitalWrite(out_pins[i], HIGH);}
}


void loop() {
	int n = sizeof(out_pins);
	int m = sizeof(in_pins);
	int i, j;
  if (bleKeyboard.isConnected()) {
  	for (i=0;i<n;i++){
			digitalWrite(out_pins[i], HIGH);
			for(j=0;j<m;j++){
				delay(10);
				if(digitalRead(in_pins[j]) == HIGH){bleKeyboard.press(keys[j][i]);}
				else{bleKeyboard.release(keys[j][i]);}
			}
			digitalWrite(out_pins[i], LOW);
		}
//		if (digitalRead(23) == HIGH){bleKeyboard.press('a');}
//		else{bleKeyboard.release('a');}
//		if (digitalRead(19) == HIGH){bleKeyboard.press('b');}
//		else{bleKeyboard.release('b');}
//		if (digitalRead(21) == HIGH){bleKeyboard.press('c');}
//		else{bleKeyboard.release('c');}
//		if (digitalRead(22) == HIGH){bleKeyboard.press(KEY_BACKSPACE);}
//		else{bleKeyboard.release(KEY_BACKSPACE);}
  }

}
