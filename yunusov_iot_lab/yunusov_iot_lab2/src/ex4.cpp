#include "Arduino.h"

#define BUTTON_PIN 25

#define RED_LED_PIN     26
#define GREEN_LED_PIN   27
#define YELLOW_LED_PIN  12
#define BLUE_LED_PIN    14

int count = 0;
int previousButtonState = HIGH;

void setup(void)
{
    Serial.begin(115200);

    pinMode(BUTTON_PIN, INPUT_PULLUP);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    // All LEDs start OFF
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void loop(void)
{
    int buttonState = digitalRead(BUTTON_PIN);

    // Detect one press: HIGH -> LOW
    if (previousButtonState == HIGH && buttonState == LOW)
    {
        count++;

        // Wrap back to 0 after 4
        if (count > 4)
        {
            count = 0;
        }

        // Light exactly 'count' LEDs
        digitalWrite(RED_LED_PIN,    count >= 1 ? HIGH : LOW);
        digitalWrite(GREEN_LED_PIN,  count >= 2 ? HIGH : LOW);
        digitalWrite(YELLOW_LED_PIN, count >= 3 ? HIGH : LOW);
        digitalWrite(BLUE_LED_PIN,   count >= 4 ? HIGH : LOW);

        Serial.print("count=");
        Serial.println(count);
    }

    // Save current state for edge detection
    previousButtonState = buttonState;

    delay(10);
}
