int inp_1 = A0;
int inp_2 = A1;
int LED_1 = A4;
int LED_2 = A5;
float threshV = 2.0;
float threshH = 2.0;
int V_Ch = 0.0;
int H_Ch = 0.0;
int ref_Period = 1000;
float cent = (1025.0/5.0)*2.5;

#include <SoftwareSerial.h>
SoftwareSerial XBee(2, 3); // TX, RX



unsigned long currentMicros = 0;
unsigned long previousMicros = 0;
const long interval = 1000;

void setup() {
  pinMode(inp_1, INPUT);
  pinMode(inp_2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  XBee.begin(9600);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMicros = micros();

  if (currentMicros - previousMicros >= interval) {
    
    previousMicros = currentMicros;

    V_Ch = analogRead(inp_1);
    analogRead(A4);
    H_Ch = analogRead(inp_2);
    
    if (V_Ch > (int)(cent + (1025.0/5.0)*threshV)) {
      XBee.write('H1');
      Serial.println('SendH');
      delay(ref_Period);
    } else if (V_Ch < (int)(cent - (1025.0/5.0)*threshV)) {
      XBee.write('H2');
      Serial.println('SendH');
      delay(ref_Period);
    }

    if (H_Ch > (int)(cent + (1025.0/5.0)*threshH)) {
      XBee.write('J1');
      Serial.println('SendJ');
      delay(ref_Period);
    } else if (H_Ch < (int)(cent - (1025.0/5.0)*threshH)) {
      XBee.write('J2');
      Serial.println('SendJ');
      delay(ref_Period);
    }
    
  }
}

