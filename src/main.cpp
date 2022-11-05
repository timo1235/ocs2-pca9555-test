#include <Arduino.h>
#include <Wire.h>

const byte u18Address = 0x20;
const byte u19Address = 0x24;

bool u18Found = false;
bool u19Found = false;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    Wire.begin(21, 22);

    Serial.begin(9600);
}

void i2cScan()
{
    Serial.println("Scanning...");
    byte u18Error, u19Error;
    // use the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(u18Address);
    u18Error = Wire.endTransmission();
    if(u18Error == 0) {
        u18Found = true;
        Serial.println("U18 found");
    } 
    else  {
        u18Found = false;
        Serial.println("U18 not found");
    }

    Wire.beginTransmission(u19Address);
    u19Error = Wire.endTransmission();
    if(u19Error == 0) {
        u19Found = true;
        Serial.println("U19 found");
    } 
    else  {
        u19Found = false;
        Serial.println("U19 not found");
    }
}

void loop()
{
    i2cScan();
    if(!u18Found && !u19Found) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else if (!u18Found) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    } else if (!u19Found) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
        delay(100);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
    delay(1000);
}