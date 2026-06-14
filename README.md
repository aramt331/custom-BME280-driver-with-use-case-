# custom-BME280-driver-with-use-case-
# Environmental Monitor (STM32 + BME280)

A bare-metal STM32 firmware that reads temperature, pressure, and humidity
from a BME280 sensor and outputs readings over UART, with three
interrupt-driven buttons for switching, saving, and displaying values.

Custom sensor driver written from the datasheet — no external libraries.

## Features
- Custom BME280 driver (register-level, datasheet compensation math)
- Three interrupt-driven buttons with software debouncing
- UART output with retargeted printf
- ISR/main-loop separation (no blocking work in interrupts)

## Hardware
- STM32F103C8T6 (Blue Pill)
- BME280 sensor (I2C)
- 3 push-buttons with external pull-down resistors
- USB-to-UART adapter for serial output

## Wiring
### BME280 (I2C)
- VCC  → 3.3V
- GND  → GND
- SCL  → PB6        (I2C1 SCL)
- SDA  → PB7        (I2C1 SDA)

### Buttons (each with external pull-down resistor to GND)
- Button 1 (switch reading)  → PA1
- Button 2 (save values)     → PA2
- Button 3 (display saved)   → PA3

Each button: one side to 3.3V, other side to the STM32 pin and through a
10k resistor to GND. Pressed = pin reads HIGH.

### UART (serial output)
- PA9 (TX) → USB-UART adapter RX
- GND      → adapter GND
- 115200 baud, 8N1

### Power
- All grounds common (BME280, buttons, adapter, board all share GND)
## Usage
1. Flash via ST-Link
2. Open serial terminal at 115200 baud
3. Button 1 cycles readings, button 2 saves a snapshot,
   button 3 displays the saved snapshot for 5 seconds

## Build
Built with STM32CubeIDE. Open the .ioc to regenerate, or build the
Debug configuration directly.
