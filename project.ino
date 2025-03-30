#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int slot;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.noCursor();
  lcd.noBlink();

  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(8, OUTPUT);
  pinMode(3, INPUT);
  pinMode(9, OUTPUT);
  pinMode(4, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, INPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  lcd.clear();
  digitalWrite(8, LOW);
  slot = 4;
  if (digitalRead(2) == HIGH) {
    digitalWrite(8, HIGH);
    slot = slot + 0;

  } else {
    digitalWrite(8, LOW);
    slot = slot + -1;

  }
  if (digitalRead(3) == HIGH) {
    digitalWrite(9, HIGH);
    slot = slot + 0;

  } else {
    digitalWrite(9, LOW);
    slot = slot + -1;

  }
  if (digitalRead(4) == HIGH) {
    digitalWrite(6, HIGH);
    slot = slot + 0;

  } else {
    digitalWrite(6, LOW);
    slot = slot + -1;

  }
  if (digitalRead(5) == HIGH) {
    digitalWrite(7, HIGH);
    slot = slot + 0;

  } else {
    digitalWrite(7, LOW);
    slot = slot + -1;

  }
  lcd.setCursor(0,0);
  lcd.print((String("Empty Slots : ") + String(slot)));
  delay(500);
}