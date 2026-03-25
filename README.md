# Arduino Uno IoT Projects

A growing collection of Internet of Things projects built with the Arduino Uno. Each project lives in its own folder with full documentation, source code, wiring guides, and media — designed to be beginner-friendly and portfolio-ready.

## Projects

| # | Project | Description | Status |
|---|---------|-------------|--------|
| 01 | [Weather Station](01-weather-station/) | Temperature and humidity monitor using a DHT11 sensor and 16x2 LCD display | ✅ Complete |
| 02 | [RFID Door Lock](02-rfid-door-lock/) | Contactless access control system using an RC522 RFID reader with LED feedback | ✅ Complete |
| 03 | [RTC Clock Display](03-rtc-clock-display/) | Real-time clock with DS1302 RTC module displaying time and date on a 16x2 LCD | ✅ Complete |
| 04 | [Rain Alert System](04-rain-alert-system/) | Rain detection system with water sensor, traffic-light LEDs, and LCD status display | ✅ Complete |

## Hardware Requirements

All projects in this repository are built with the **Arduino Uno** as the base microcontroller. Each project folder lists its specific components, but here is what you need across the board:

| Item | Used In |
|------|---------|
| Arduino Uno | All projects |
| USB Cable (Type-B) | All projects |
| Breadboard | All projects |
| Jumper Wires | All projects |
| 16x2 LCD Display | Weather Station, RTC Clock Display, Rain Alert System |
| Potentiometer (10KΩ) | Weather Station, RTC Clock Display, Rain Alert System |
| DHT11 Sensor | Weather Station |
| RC522 RFID Module | RFID Door Lock |
| RFID Card / Key Fob | RFID Door Lock |
| LEDs + 220Ω Resistors | RFID Door Lock, Rain Alert System |
| DS1302 RTC Module | RTC Clock Display |
| Water Level Sensor | Rain Alert System |

## Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/mbuthimungai/Arduino-Uno-IoT-.git
   ```
2. Navigate to any project folder and open the `.ino` file in the [Arduino IDE](https://www.arduino.cc/en/software)
3. Install the required libraries listed in each project's README via **Sketch → Include Library → Manage Libraries**
4. Select **Arduino Uno** as the board and the correct COM port
5. Upload and enjoy

## Author

**Mbuthi Mungai** — [github.com/mbuthimungai](https://github.com/mbuthimungai)

## License

This repository is open source and available under the [MIT License](LICENSE).
