#include <Adafruit_NeoPixel.h>

#define PIN 4
#define LED_COUNT 300

// The strip of addressable leds.
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  leds.begin();
  leds.setBrightness(255);
}


void loop() {
  tron();
  leds.show();
}


int color_mode = 0;
void five_o() {
  for (int i = 0; i < LED_COUNT; i++) {
    if (color_mode == 0) {
      leds.setPixelColor(i, 255, 0, 0);
    } else if (color_mode == 1) {
      leds.setPixelColor(i, 0, 255, 0);
    } else {
      leds.setPixelColor(i, 0, 0, 255);
    }
  }
  color_mode++;
  color_mode %= 3;
}


int offset = 0;
void tron() {
  int size = 30;
  for (int i = offset - size; i <= offset; i++) {
    leds.setPixelColor(i, 200, 200, 255);
  }
  leds.setPixelColor(offset-size, 0, 0, 0);

  if (offset > LED_COUNT + size) {
    offset = 0;
  } else {
    offset++;
  }
}


int c_red = 255;
int c_green = 0;
int c_blue = 0;
int state = 0;
void fade() {
  for (int i = 0; i < LED_COUNT; i++) {
    leds.setPixelColor(i, c_red, c_green, c_blue);
  }

  if (c_red>=255){
    state = 0;
  }
  else if (c_green>=255) {
    state = 1;
  }
  else if (c_blue>=255) {
    state = 2;
  }

  if (state == 0){
    c_red--;
    c_green++;
  }
  else if (state == 1){
    c_green--;
    c_blue++;
  }
  else if (state == 2){
    c_red++;
    c_blue--;
  }
}
