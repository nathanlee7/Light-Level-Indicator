# Light Level Indicator (Arduino + Shift Register)

This Arduino project uses a **photoresistor (LDR)** to detect ambient light and control up to **8 LEDs** using a **74HC595 shift register**. The brighter the light, the more LEDs turn on, visually representing light intensity in a bar-graph style.

![Circuit Photo](circuit_photo.jpg)

## Project Behavior

- Bright light → more LEDs light up
- Dim light → fewer LEDs light up
- Uses a shift register to control LEDs with fewer Arduino pins

## Components Used

- Arduino Uno (or compatible)
- LDR (photoresistor)
- 10kΩ Resistor (for LDR voltage divider)
- 74HC595 Shift Register
- 8 LEDs
- 8x 220Ω Resistors (for LEDs)
- Breadboard + Jumper wires

## Circuit Connections

### LDR (Voltage Divider):
- One leg of LDR → **5V**
- Other leg → **Analog pin A0 (lightPin = 0)** and to **GND** through a **10kΩ resistor**

### 74HC595 Shift Register:
- **Pin 11** (latchPin) → Arduino **D11**
- **Pin 12** (clockPin) → Arduino **D12**
- **Pin 14** (dataPin) → Arduino **D9**
- **Pin 10 (SRCLR)** → **5V**
- **Pin 13 (OE)** → **GND**
- **Pin 8 (GND)** → **GND**
- **Pin 16 (VCC)** → **5V**

Connect the 8 output pins (Q0–Q7) of the shift register to the **LEDs** with 220Ω resistors to GND.

## How It Works

1. The LDR’s analog reading (0–1023) is divided by 57 to calculate how many LEDs (0–8) to light.
2. A loop sets the corresponding number of bits in an 8-bit value (`leds`).
3. `shiftOut()` sends this value to the shift register to update the LEDs.

---
