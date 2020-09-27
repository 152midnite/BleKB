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

void sweep(int in_pins[], int out_pins[], char keys[][13]) {
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
}

int in_pins[13] = {};
int out_pins[4] = {};
char keys[4][13] = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'},
                    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';'},
                    {'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'},
                    {}
};


void loop() {
  if (bleKeyboard.isConnected()) {
    sweep(in_pins, out_pins, keys);



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
  delay(5000);
}
