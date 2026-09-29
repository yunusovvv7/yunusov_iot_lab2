#include "Arduino.h"

#define RED_LED_PIN     26
#define GREEN_LED_PIN   27
#define YELLOW_LED_PIN  12
#define BLUE_LED_PIN    14

// LED sequence: RED → GREEN → YELLOW → BLUE → YELLOW → GREEN
const int ledPins[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};

const char* ledNames[] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "YELLOW",
    "GREEN"
};

const int NUM_STEPS = 6;

// Keep track of the current step
int stepIndex = 0;

/****************************************************/
void setup(void)
{
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    Serial.begin(115200);

    // Make sure all LEDs start OFF
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

/****************************************************/
void loop(void)
{
    // Turn all LEDs OFF
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    // Turn on the LED for the current step
    digitalWrite(ledPins[stepIndex], HIGH);

    // Print the LED that just turned on
    Serial.print("chase=");
    Serial.println(ledNames[stepIndex]);

    // Keep it on for 150 ms
    delay(150);

    // Move to the next step
    stepIndex++;

    // Repeat the sequence after the last step
    if (stepIndex >= NUM_STEPS)
    {
        stepIndex = 0;
    }
}
