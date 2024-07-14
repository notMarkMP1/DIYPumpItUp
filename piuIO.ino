/*
 Select Arduino Uno/Mega HID-Bridge as board.

 After upload make sure the 16u2 sketch runs, not the HoodLoader2 bootloader.
 This example will print random chars via serial to the USB MCU.
 If the USB MCU has the other bridge sketch uploaded
 it should type those chars via keyboardhyx.
*/

const int farLeft = 2;
const int left = 3;
const int center = 4;
const int right = 5;
const int farRight = 6;

bool FLPrev = false; // 1 for pressed
bool leftPrev = false;
bool centerPrev = false;
bool rightPrev = false;
bool FRPrev = false;


int buttonState[] = {0,0,0,0,0};
int lastButtonState[] = {0,0,0,0,0};

void setup() {
  // Start the Serial which is connected with the USB MCU.
  // Make sure both baud rates are the same
  // you can go up to 2000000 for very fast data transmission.
  Serial.begin(115200);
  pinMode(farLeft, INPUT);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);
  pinMode(farRight, INPUT);
}

void loop() {
  for(int i = 2; i <= 6; i++){
    buttonState[i-2] = digitalRead(i);
    if(buttonState[i-2] != lastButtonState[i-2]){
      if(buttonState[i-2] == HIGH){
        Serial.write(95+i);
      } else{
        Serial.write(63+i);
      }
    }
    lastButtonState[i-2] = buttonState[i-2];
  }
}
