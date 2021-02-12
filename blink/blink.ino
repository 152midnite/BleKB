#include <BleKeyboard.h>
#include <SPI.h>
BleKeyboard bleKeyboard;


int output_pins(int out_pins[4]) {
	return 0;
  }


int sweep(int in_pins[], int out_pins[], char keys[][13]) {
  int i, j, n_rows = sizeof(out_pins);
  for (i = 0; i < n_rows; i++) {
    digitalWrite(out_pins[i], HIGH);
    int row_lenght = sizeof(keys[i]);
    for (j = 0; j < row_lenght; j++) {
      char key = keys[i][j];
      if (key) {
        int pin = in_pins[i];
        if (digitalRead(pin) == HIGH) {
          bleKeyboard.press(key);
          Serial.println("Sending key");
        }
        else {
          bleKeyboard.release(keys[i][j]);
        }
      }
    }
    digitalWrite(out_pins[i], LOW);
  }
return 0;}


int in_pins[13] = {36,39,34,35,23,19,21,22};
int out_pins[10] = {5,13,12,4,32,33,25,26,27,14};
char keys[4][13] = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'},
                    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'},
                    {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};



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
	int i, j;
  for (j=0;j<n;j++){pinMode(out_pins[j], OUTPUT);}
  for (i=0;i<n;i++){digitalWrite(out_pins[i], HIGH);}
}


void loop() {
  if (bleKeyboard.isConnected()) {
    //bleKeyboard.print("Hello world");
		if (digitalRead(23) == HIGH){bleKeyboard.press('a');}
		else{bleKeyboard.release('a');}
		if (digitalRead(19) == HIGH){bleKeyboard.press('b');}
		else{bleKeyboard.release('b');}
		if (digitalRead(21) == HIGH){bleKeyboard.press('c');}
		else{bleKeyboard.release('c');}
		if (digitalRead(22) == HIGH){bleKeyboard.press(KEY_BACKSPACE);}
		else{bleKeyboard.release(KEY_BACKSPACE);}
		        //bleKeyboard.write('a');
  }
  delay(5);
}
