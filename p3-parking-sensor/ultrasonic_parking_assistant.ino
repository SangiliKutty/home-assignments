#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int TRIG = 9;
const int ECHO = 10;

const int GREEN_LED = 2;
const int YELLOW_LED = 3;
const int RED_LED = 4;
const int BUZZER = 5;

// Timing variables
unsigned long lastBeep = 0;
unsigned long lastSerial = 0;

// Function to measure distance
float measureDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);

  float distance = duration * 0.034 / 2.0;

  if (distance == 0)
    distance = 400;

  return distance;
}

// Average of 5 readings
float getAverageDistance()
{
  float sum = 0;

  for (int i = 0; i < 5; i++)
  {
    sum += measureDistance();
  }

  return sum / 5.0;
}

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop()
{
  float distance = getAverageDistance();

  String zone = "";

  bool green = false;
  bool yellow = false;
  bool red = false;

  bool continuous = false;

  unsigned long beepInterval = 0;

  // Parking Zones

  if (distance > 60)
  {
    zone = "SAFE";
    green = true;
  }
  else if (distance > 30)
  {
    zone = "CAUTION";
    yellow = true;
    beepInterval = 800;
  }
  else if (distance > 15)
  {
    zone = "CLOSE";
    yellow = true;
    red = true;
    beepInterval = 300;
  }
  else
  {
    zone = "DANGER";
    red = true;
    continuous = true;
  }

  // LEDs

  digitalWrite(GREEN_LED, green);
  digitalWrite(YELLOW_LED, yellow);
  digitalWrite(RED_LED, red);

  // Buzzer using millis()

  if (continuous)
  {
    tone(BUZZER, 1000);
  }
  else
  {
    noTone(BUZZER);

    if (beepInterval > 0)
    {
      if (millis() - lastBeep >= beepInterval)
      {
        tone(BUZZER, 1000, 100);
        lastBeep = millis();
      }
    }
  }

  // OLED Display

  display.clearDisplay();

  display.setTextColor(WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Parking Sensor");

  display.setTextSize(3);
  display.setCursor(10, 18);
  display.print((int)distance);
  display.print("cm");

  // Bar Graph

  int barLength = map((int)distance, 0, 100, 128, 0);

  if (barLength < 0)
    barLength = 0;

  if (barLength > 128)
    barLength = 128;

  display.drawRect(0, 56, 128, 8, WHITE);
  display.fillRect(0, 56, barLength, 8, WHITE);

  display.display();

  // Serial Monitor every 500ms

  if (millis() - lastSerial >= 500)
  {
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.print(" cm");

    Serial.print("    Zone : ");
    Serial.println(zone);

    lastSerial = millis();
  }
}
