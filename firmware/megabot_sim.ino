#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// pins
#define TFT_DC   3
#define TFT_RST  4
#define TFT_CS   5
#define TFT_SCK  8
#define TFT_MOSI 10
#define BTN1 6   // changes the face
#define BTN2 7   // shows the time
// BTN3 does nothing yet (future feauture)

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

// colors
#define BLACK  0x0000
#define WHITE  0xFFFF
#define GREY   0x7BEF
#define GREEN  0x07E0
#define YELLOW 0xFFE0
#define RED    0xF800

// middle of the screen (use 120 and 120 on the real round display for the project)
int CX = 160;
int CY = 120;

int face = 0;          // 0 = green (happy), 1 = yellow (neutral), 2 = red (angry)
bool showTime = false;
int lastSecond = -1;

void drawFace(int f) {
  int color = GREEN;
  if (f == 1) color = YELLOW;
  if (f == 2) color = RED;

  tft.fillCircle(CX, CY, 118, color);   // a round block of color (later will be modified to actaul face of Megabot)
}

void startClock() {
  tft.fillCircle(CX, CY, 118, BLACK);
  tft.drawCircle(CX, CY, 118, GREY);
  lastSecond = -1;
}

void drawClock() {
  int total = millis() / 1000;   // seconds since the program started
  int seconds = total % 60;
  if (seconds == lastSecond) return;   // only redraw when the second changes
  lastSecond = seconds;

  int minutes = (total / 60) % 60;
  int hours = (12 + total / 3600) % 24;   // for testing,pretend it started at 12:00 for the meantime, later on real time will be pulled using the wifi)

  char text[9];
  sprintf(text, "%02d:%02d:%02d", hours, minutes, seconds);
  tft.setTextSize(3);
  tft.setTextColor(WHITE, BLACK);
  tft.setCursor(CX - 72, CY - 12
  );
  tft.print(text);
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  SPI.begin(TFT_SCK, -1, TFT_MOSI, TFT_CS);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  drawFace(face);
}

void loop() {
  // BTN1: next face color
  if (digitalRead(BTN1) == LOW) {
    face = (face + 1) % 3;
    showTime = false;
    drawFace(face);
    delay(250);
  }

  // BTN2: switch between time and face
  if (digitalRead(BTN2) == LOW) {
    showTime = !showTime;
    if (showTime) startClock();
    else drawFace(face);
    delay(250);
  }

  if (showTime) drawClock();
}
