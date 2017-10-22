#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial XBee(2, 3); // RX, TX
LiquidCrystal lcd(8,9,4,5,6,7);

char msg = ' '; //contains the message from arduino sender
const int led = 13; //led at pin 13

void setup()
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("  BEGIN");
  lcd.setCursor(0,1);
  lcd.print("   EOG");
  lcd.setCursor(0,0);
  XBee.begin(9600);
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
    msg=XBee.read();
           if(msg=='H') {
               lcd.clear();
               lcd.print("   HIGH");
           }
           if(msg=='J') {
               lcd.clear();
               lcd.print("   LOW");
            }
}
