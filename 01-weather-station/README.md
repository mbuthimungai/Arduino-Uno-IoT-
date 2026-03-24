# Weather Station

A real-time weather monitoring system built with an Arduino Uno. It reads temperature and humidity from a DHT11 sensor and displays the data live on a 16x2 LCD screen — refreshing every 2 seconds.

<img src="weather-station-setup.jpg" alt="Weather Station Setup" width="500">

## Features

- Real-time temperature reading in Celsius
- Real-time humidity percentage
- 16x2 LCD display with live updates every 2 seconds
- Serial Monitor output for debugging
- Sensor error detection with on-screen warning

## Components

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| 16x2 LCD Display | 1 |
| Potentiometer (10KΩ, for contrast) | 1 |
| Breadboard | 1 |
| Jumper Wires | Several |
| USB Cable (Type-B) | 1 |

## Wiring

### DHT11 Sensor → Arduino

| DHT11 Pin | Arduino Pin |
|-----------|-------------|
| DATA | Digital Pin 2 |
| VCC | 5V |
| GND | GND |

### 16x2 LCD (4-bit mode) → Arduino

| LCD Pin | Arduino Pin |
|---------|-------------|
| RS | Digital Pin 7 |
| E | Digital Pin 8 |
| D4 | Digital Pin 9 |
| D5 | Digital Pin 10 |
| D6 | Digital Pin 11 |
| D7 | Digital Pin 12 |
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer wiper (contrast) |
| A (Backlight+) | 5V |
| K (Backlight-) | GND |

## Required Libraries

Install via the Arduino IDE Library Manager:

- **DHT sensor library** by Adafruit
- **LiquidCrystal** (built-in with Arduino IDE)

## How It Works

The DHT11 is a digital sensor that measures both temperature and humidity using an internal thermistor and a capacitive humidity sensor. It communicates with the Arduino over a single data wire using a proprietary one-wire protocol — the Arduino sends a start signal, and the DHT11 responds with 40 bits of data containing the humidity and temperature readings.

The Arduino reads these values every 2 seconds (the minimum interval the DHT11 supports), formats them, and pushes the output to both the LCD and the Serial Monitor. The LCD operates in 4-bit mode to save pins — instead of sending a full byte at once, it sends data in two 4-bit nibbles. The potentiometer adjusts the LCD contrast voltage so the text is clearly visible.

If the sensor fails to return valid data (e.g. a loose wire), the sketch detects the `NaN` values and displays an error message instead of garbage readings.

## Getting Started

1. Wire the components as described above
2. Open `weather_station.ino` in the Arduino IDE
3. Install the required libraries via **Sketch → Include Library → Manage Libraries**
4. Select **Arduino Uno** as the board and the correct COM port
5. Upload the sketch
6. The LCD will display temperature (°C) on the top row and humidity (%) on the bottom row

## Serial Monitor Output

Open the Serial Monitor at **9600 baud** to see readings:

```
Temp: 27.1°C  Humidity: 54.0%
Temp: 27.2°C  Humidity: 53.0%
```

## License

This project is open source and available under the [MIT License](../LICENSE).
