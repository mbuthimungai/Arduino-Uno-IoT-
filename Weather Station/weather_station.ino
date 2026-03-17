#include <DHT.h>
#include <LiquidCrystal.h>

// --- Pin Definitions ---
#define DHTPIN 2
#define DHTTYPE DHT11  // Change to DHT22 if yours is labeled DHT22

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);       // 16 columns, 2 rows
  dht.begin();
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  lcd.setCursor(0, 1);
  lcd.print("  Starting...  ");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000); // DHT needs ~2s between readings

  float humidity = dht.readHumidity();
  float tempC    = dht.readTemperature();     // Celsius
  float tempF    = dht.readTemperature(true); // Fahrenheit

  // Check if reading failed
  if (isnan(humidity) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    lcd.setCursor(0, 1);
    lcd.print("Check wiring... ");
    return;
  }

  // --- Display on LCD ---
  // Row 1: Temperature
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);   // 1 decimal place
  lcd.print((char)223);  // degree symbol °
  lcd.print("C  ");

  // Row 2: Humidity
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%  ");

  // Also print to Serial Monitor for debugging
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print("°C  Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}