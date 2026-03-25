#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define WATER_SENSOR A3
#define GREEN_LED  3
#define YELLOW_LED 4
#define RED_LED    5

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(GREEN_LED,  OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED,    OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Rain Alert Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  int waterLevel = analogRead(WATER_SENSOR);

  Serial.print("Water level: ");
  Serial.println(waterLevel);

  // Turn all LEDs off first
  digitalWrite(GREEN_LED,  LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED,    LOW);

  lcd.clear();

  if (waterLevel < 300) {
    // No rain
    digitalWrite(GREEN_LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Stat: All Clear");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(waterLevel);

  } else if (waterLevel < 600) {
    // Light rain
    digitalWrite(YELLOW_LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Stat: Light Rain");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(waterLevel);

  } else {
    // Heavy rain
    digitalWrite(RED_LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Stat: Heavy Rain!");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(waterLevel);
  }

  delay(500);
}