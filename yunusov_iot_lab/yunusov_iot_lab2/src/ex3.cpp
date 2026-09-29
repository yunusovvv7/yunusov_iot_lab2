#include "Arduino.h"

#define BUTTON_PIN 25

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN   14

int pressCount = 0;

int lastButtonState = LOW;


/****************************************************/
void setup(void)
{
    pinMode(BUTTON_PIN, INPUT);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    Serial.begin(115200);

    // Boshlanishida barcha LEDlar o'chirilgan
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}


/****************************************************/
void loop(void)
{
    int buttonState = digitalRead(BUTTON_PIN);

    // Tugma LOW dan HIGH ga o'tganini aniqlash
    if (buttonState == HIGH && lastButtonState == LOW)
    {
        // Counterni oshirish
        pressCount++;

        // 4 dan keyin yana 0 ga qaytish
        if (pressCount > 4)
        {
            pressCount = 0;
        }

        // Counter o'zgarganini Serial Monitor'ga chiqarish
        Serial.print("count=");
        Serial.println(pressCount);

        // Avval barcha LEDlarni o'chirish
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(YELLOW_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);

        // Counterga qarab LEDlarni yoqish
        if (pressCount >= 1)
        {
            digitalWrite(RED_LED_PIN, HIGH);
        }

        if (pressCount >= 2)
        {
            digitalWrite(GREEN_LED_PIN, HIGH);
        }

        if (pressCount >= 3)
        {
            digitalWrite(YELLOW_LED_PIN, HIGH);
        }

        if (pressCount >= 4)
        {
            digitalWrite(BLUE_LED_PIN, HIGH);
        }
    }

    // Oldingi tugma holatini saqlash
    lastButtonState = buttonState;

    delay(20);
}