# ocs2-pca9555-test
project to test the two pca9555 chips on the open cnc shield 2

### How to test
![test setup](/assets/ocs2.jpg "Test setup")

### How to see status
The blue ESP32 LED is indicating the chip status. 
The chips are checked every 1 second.

- blue LED stay on: U18 and U19 are broken
- blue LED blinks once: U18 is broken
- blue LED blinks twice: U19 is broken
