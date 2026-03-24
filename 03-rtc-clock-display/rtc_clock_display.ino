#include <Ds1302.h>
#include <LiquidCrystal.h>

Ds1302 rtc(A2, A1, A0);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void printTwoDigits(int number) {
  if (number < 10) lcd.print("0");
  lcd.print(number);
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  rtc.init();

  Ds1302::DateTime dt;
  dt.year   = 26;
  dt.month  = 3;
  dt.day    = 24;
  dt.hour   = 22;
  dt.minute = 0;
  dt.second = 0;
  dt.dow    = 3;
  rtc.setDateTime(&dt);

  delay(200);

  Ds1302::DateTime check;
  rtc.getDateTime(&check);
  Serial.print("Verify hour: ");
  Serial.println(check.hour);
  Serial.print("Verify min: ");
  Serial.println(check.minute);
}

void loop() {
  Ds1302::DateTime dt;
  rtc.getDateTime(&dt);

  Serial.print(dt.hour);
  Serial.print(":");
  Serial.print(dt.minute);
  Serial.print(":");
  Serial.println(dt.second);

  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  printTwoDigits(dt.hour);
  lcd.print(":");
  printTwoDigits(dt.minute);
  lcd.print(":");
  printTwoDigits(dt.second);

  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  printTwoDigits(dt.day);
  lcd.print("/");
  printTwoDigits(dt.month);
  lcd.print("/20");
  printTwoDigits(dt.year);

  delay(1000);
}