# Task-3 Evidence

## 1.UART Evidence
### Sample UART log showing LED blinks:
```text
Phase 1 - Interval: 0.5 s
LED_ON
LED_OFF
LED_ON
LED_OFF
LED_ON
LED_OFF
Phase 2 - Interval: 1 s
LED_ON
LED_OFF
LED_ON
LED_OFF
LED_ON
LED_OFF
Phase 3 - Interval: 2 s
LED_ON
LED_OFF
LED_ON
LED_OFF
LED_ON
LED_OFF
LED_ON
LED_OFF
```

## 2.Hardware Evidence
- On-board LED (PD6) blinks according to the demo pattern.
- Video showing LED blinking and the board layout.
- Image of monitor UART log showing LED blinks.

## 3.Explanation
- **Application uses GPIO library**: `gpio_set()` turns LED ON, `gpio_clear()` turns LED OFF.
- **Application uses UART library** to log phase number and LED state.
- LED blink pattern matches UART output, confirming correct operation of the libraries.
- Firmware demonstrates **clean separation of hardware and application logic**, using only library APIs.
- Verified on real hardware: the LED blinks and UART logs match exactly, showing successful execution of the demo application.

