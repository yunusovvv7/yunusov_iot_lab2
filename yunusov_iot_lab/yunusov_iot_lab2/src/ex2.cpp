#include "Arduino.h"

#define LIGHT_PIN 33

void setup(void)
{
    Serial.begin(115200);
    pinMode(LIGHT_PIN, INPUT);
}

void loop(void)
{
    int minValue = 4095;
    int maxValue = 0;
    long sum = 0;

    // Take 10 back-to-back samples with no delay
    for (int i = 0; i < 10; i++)
    {
        int value = analogRead(LIGHT_PIN);

        if (value < minValue)
            minValue = value;

        if (value > maxValue)
            maxValue = value;

        sum += value;
    }

    int average = sum / 10;

    Serial.print("min=");
    Serial.print(minValue);
    Serial.print(" max=");
    Serial.print(maxValue);
    Serial.print(" avg=");
    Serial.println(average);

    // Wait 1000 ms before the next batch
    delay(1000);
}

