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
  tron(40, 2, 3);
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

  delay(100);
  color_mode++;
  color_mode %= 3;
}


int n = 0;
void tron(int length, int speed, int trails) {

  for (int trail = 0; trail < trails; trail++) {
    int offset = trail * LED_COUNT / trails;

    for (int led = 0; led < length; led++) {
      int brightness = led * (255/length);
      int index = (n+led+offset) % LED_COUNT;
      leds.setPixelColor(index, brightness/1.25, brightness/1.25, brightness);
    }

    for (int off = 0; off < speed; off++) {
      int index = (n+offset+off) % LED_COUNT;
      leds.setPixelColor(index, 0, 0, 0);
    }
  }

  n += speed;
  n %= LED_COUNT;
}

void ryan() {
  for (int i = n; i < n+LED_COUNT/3; i++) {
    leds.setPixelColor(i%LED_COUNT, 255, 0, 0);
    leds.setPixelColor((i+100)%LED_COUNT, 0, 255, 0);
    leds.setPixelColor((i+200)%LED_COUNT, 0, 0, 255);
  }
  n++;
}

void circus() {
  leds.setPixelColor((n+200)%300, 255, 0, 0);
  leds.setPixelColor((n+200-2)%300, 0, 0, 0);
  leds.setPixelColor((n+100)%300, 0, 255, 0);
  leds.setPixelColor((n+100-2)%300, 0, 0, 0);
  leds.setPixelColor(n%300, 0, 0, 255);
  leds.setPixelColor((n-2)%300, 0, 0, 0);

  leds.setPixelColor((n+250)%300, 255, 255, 0);
  leds.setPixelColor((n+250-2)%300, 0, 0, 0);
  leds.setPixelColor((n+150)%300, 0, 255, 255);
  leds.setPixelColor((n+150-2)%300, 0, 0, 0);
  leds.setPixelColor((n+50)%300, 255, 0, 255);
  leds.setPixelColor((n+50-2)%300, 0, 0, 0);

  n += 2;
}

void starTrek() {
  for (int i = 0; i < 255; i++) {
    leds.setPixelColor((i+n)%LED_COUNT, i%255, i%255, i%255);
  }

  n += 2;
}

void usa() {
  for (int i = 0; i < LED_COUNT; i++) {
    leds.setPixelColor(i%300, 0, 0, 0);
  }
  for (int i = n; i < LED_COUNT+n; i+=30) {
    leds.setPixelColor(i%300, 255, 0, 0);
    leds.setPixelColor((i+10)%300, 255, 255, 255);
    leds.setPixelColor((i+20)%300, 0, 0, 255);
  }

  n++;
}

void christmas() {
  for (int i = 0; i < LED_COUNT; i+=40) {
    if (n%100 < 50){
      leds.setPixelColor(i, 255, 0, 0);
      leds.setPixelColor(i+20, 0, 255, 0);
    }
    else {
      leds.setPixelColor(i+20, 255, 0, 0);
      leds.setPixelColor(i, 0, 255, 0);
    }
  }

  n++;
}

void stoplight() {
  for (int i = 0; i < LED_COUNT; i+=30) {
    if (n%99 < 33) {
      leds.setPixelColor(i, 0, 255, 0);
      leds.setPixelColor(i+10, 255, 255, 0);
      leds.setPixelColor(i+20, 255, 0, 0);
    }
    else if (n%99 < 66) {
      leds.setPixelColor(i+10, 0, 255, 0);
      leds.setPixelColor(i+20, 255, 255, 0);
      leds.setPixelColor(i, 255, 0, 0);
    }
    else {
      leds.setPixelColor(i+20, 0, 255, 0);
      leds.setPixelColor(i, 255, 255, 0);
      leds.setPixelColor(i+10, 255, 0, 0);
    }
  }

  n++;
}

void racecar() {
  leds.setPixelColor((n/4-1)%LED_COUNT, 0, 0, 0);
  leds.setPixelColor((n/4)%LED_COUNT, 255, 0, 0);

  leds.setPixelColor((n/2-1)%LED_COUNT, 0, 0, 0);
  leds.setPixelColor((n/2)%LED_COUNT, 255, 255, 0);

  leds.setPixelColor((n-1)%LED_COUNT, 0, 0, 0);
  leds.setPixelColor((n)%LED_COUNT, 0, 255, 0);

  n++;
}

void blinky() {
  for (int i = 0; i < LED_COUNT; i+=20) {
    if (n%60 < 30) {
      leds.setPixelColor(i, 255, 0, 0);
      leds.setPixelColor(i+10, 0, 0, 255);
    }
    else {
      leds.setPixelColor(i+10, 255, 0, 0);
      leds.setPixelColor(i, 0, 0, 255);
    }
  }

  n++;
}

void primepowers() {
  for (int i = 2; i < LED_COUNT; i=i*2) {
    leds.setPixelColor(i, 0, 0, 255);
  }

  for (int i = 3; i < LED_COUNT; i=i*3) {
    leds.setPixelColor(i, 0, 255, 0);
  }

  for (int i = 5; i < LED_COUNT; i=i*5) {
    leds.setPixelColor(i, 255, 0, 0);
  }
}


void fib() {
  int a = 1;
  int b = 2;
  leds.setPixelColor(1, 255, 0, 0);
  leds.setPixelColor(2, 255, 0, 0);

  while(a+b < LED_COUNT) {
    int c = a + b;
    leds.setPixelColor(c, 255, 0, 0);
    a = b;
    b = c;
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
