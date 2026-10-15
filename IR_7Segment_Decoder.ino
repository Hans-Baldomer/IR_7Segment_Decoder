// GPIO Pins
const uint8_t IR_PIN = 36;

const uint8_t LED_1[] = {19, 18, 5, 17, 16, 4, 0};
const uint8_t NUM_ONES = sizeof(LED_1) / sizeof(LED_1[0]);

const uint8_t LED_2[] = {32, 33, 25, 26, 27, 14, 12};
const uint8_t NUM_TENS = sizeof(LED_2) / sizeof(LED_2[0]);

// Variables
int ir_counter = 0;
int ir_previousState = 1;

#include "decoder.h"

void setup() {
    pinMode(IR_PIN, INPUT);

    for (int i = 0; i < NUM_ONES; i++) {
        pinMode(LED_1[i], OUTPUT);
    }

    for (int i = 0; i < NUM_TENS; i++) {
        pinMode(LED_2[i], OUTPUT);
    }

    ir_previousState = digitalRead(IR_PIN);
    displayCounter(ir_counter);
}

void loop() {
    decoder(ir_previousState);
}
