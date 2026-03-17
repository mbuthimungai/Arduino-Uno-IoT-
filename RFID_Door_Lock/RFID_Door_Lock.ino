#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN  10
#define GREEN_LED 6
#define RED_LED   7

MFRC522 rfid(SS_PIN, RST_PIN);

// Store your authorized card UID here (we'll fill this after first scan)
String authorizedUID = ""; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("RFID Door Lock Ready!");
  Serial.println("Scan your card to register it...");
}

void loop() {
  // Wait for a card
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  // Read UID
  String scannedUID = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    scannedUID += String(rfid.uid.uidByte[i] < 0x10 ? "0" : "");
    scannedUID += String(rfid.uid.uidByte[i], HEX);
  }
  scannedUID.toUpperCase();

  Serial.print("Card UID: ");
  Serial.println(scannedUID);

  // First scan = register the card
  if (authorizedUID == "") {
    authorizedUID = scannedUID;
    Serial.println("Card REGISTERED as authorized!");
    flashLED(GREEN_LED, 3);
    return;
  }

  // Check if authorized
  if (scannedUID == authorizedUID) {
    Serial.println("ACCESS GRANTED!");
    accessGranted();
  } else {
    Serial.println("ACCESS DENIED!");
    accessDenied();
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void accessGranted() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  delay(2000);
  digitalWrite(GREEN_LED, LOW);
}

void accessDenied() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  delay(2000);
  digitalWrite(RED_LED, LOW);
}

void flashLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
}