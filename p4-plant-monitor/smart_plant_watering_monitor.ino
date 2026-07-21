/*************************************************
 Smart Plant Watering Monitor
 Rephrased Version
 IIT Jammu Summer School 2026
*************************************************/

#include <Wire.h>
#include <DHTesp.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------------- OLED ----------------
#define OLED_WIDTH   128
#define OLED_HEIGHT   64

Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

// ---------------- DHT -----------------
DHTesp climate;

// ---------------- Pin Definitions ----------------
const int SOIL_SENSOR = 34;
const int DHT_SENSOR  = 4;

const int PUMP_RELAY  = 26;
const int RELAY_UNUSED = 27;

const int PUSH_BUTTON = 13;

const int LED_RED   = 25;
const int LED_GREEN = 33;

const int BUZZER_PIN = 32;

// ---------------- Calibration ----------------
const int DRY_SOIL = 3200;
const int WET_SOIL = 1200;

// ---------------- Variables ----------------
int moisture = 0;

float temp = 0;
float hum  = 0;

bool pumpState = false;
bool manualPump = false;

unsigned long previousMillis = 0;
unsigned long manualTimer = 0;

const unsigned long updateTime = 5000;

String plantCondition = "OPTIMAL";

// -------------------------------------------------

void setup()
{
  Serial.begin(115200);

  pinMode(PUMP_RELAY, OUTPUT);
  pinMode(RELAY_UNUSED, OUTPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(PUSH_BUTTON, INPUT_PULLUP);

  digitalWrite(PUMP_RELAY, HIGH);
  digitalWrite(RELAY_UNUSED, HIGH);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);

  climate.setup(DHT_SENSOR, DHTesp::DHT11);

  Wire.begin(21,22);

  if(!oled.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    Serial.println("OLED Initialization Failed");
    while(true);
  }

  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);

  oled.setCursor(18,20);
  oled.println("Plant Monitor");
  oled.display();

  delay(2000);
}

// -------------------------------------------------

void loop()
{
  if(millis()-previousMillis >= updateTime)
  {
    previousMillis = millis();

    readValues();

    autoPumpControl();

    showOLED();

    serialOutput();
  }

  detectButton();

  manualPumpControl();
}

// -------------------------------------------------

void readValues()
{
  int sensorValue = analogRead(SOIL_SENSOR);

  moisture = map(sensorValue, DRY_SOIL, WET_SOIL, 0, 100);
  moisture = constrain(moisture,0,100);

  TempAndHumidity reading = climate.getTempAndHumidity();

  temp = reading.temperature;
  hum  = reading.humidity;
}

// -------------------------------------------------

void autoPumpControl()
{
  if(manualPump)
    return;

  if(moisture < 30 && !pumpState)
    pumpState = true;

  if(moisture > 40 && pumpState)
    pumpState = false;

  digitalWrite(PUMP_RELAY, pumpState ? LOW : HIGH);

  updateIndicators();
}

// -------------------------------------------------

void updateIndicators()
{
  if(moisture < 30)
  {
    plantCondition = "DRY";

    digitalWrite(LED_RED,HIGH);
    digitalWrite(LED_GREEN,LOW);
    digitalWrite(BUZZER_PIN,HIGH);
  }
  else if(moisture <= 70)
  {
    plantCondition = "OPTIMAL";

    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_GREEN,HIGH);
    digitalWrite(BUZZER_PIN,LOW);
  }
  else
  {
    plantCondition = "WET";

    digitalWrite(LED_RED,LOW);
    digitalWrite(LED_GREEN,HIGH);
    digitalWrite(BUZZER_PIN,LOW);
  }
}

// -------------------------------------------------

void detectButton()
{
  static bool oldButton = HIGH;

  bool newButton = digitalRead(PUSH_BUTTON);

  if(oldButton == HIGH && newButton == LOW)
  {
    manualPump = true;

    manualTimer = millis();

    digitalWrite(PUMP_RELAY,LOW);

    Serial.println("Manual Watering Started");

    delay(200);
  }

  oldButton = newButton;
}

// -------------------------------------------------

void manualPumpControl()
{
  if(!manualPump)
    return;

  if(millis()-manualTimer >= 5000)
  {
    manualPump = false;

    digitalWrite(PUMP_RELAY,HIGH);

    Serial.println("Manual Watering Finished");
  }
}

// -------------------------------------------------

void showOLED()
{
  oled.clearDisplay();

  oled.setCursor(0,0);
  oled.print("Soil:");
  oled.print(moisture);
  oled.println("%");

  oled.print("Temp:");
  oled.print(temp,1);
  oled.println(" C");

  oled.print("Status:");
  oled.println(plantCondition);

  oled.drawRect(5,52,100,8,WHITE);

  int level = map(moisture,0,100,0,98);

  oled.fillRect(6,53,level,6,WHITE);

  oled.display();
}

// -------------------------------------------------

void serialOutput()
{
  Serial.print("SOIL:");
  Serial.print(moisture);
  Serial.print("% | ");

  Serial.print("TEMP:");
  Serial.print(temp);
  Serial.print(" C | ");

  Serial.print("HUM:");
  Serial.print(hum);
  Serial.print("% | ");

  Serial.print("STATUS:");
  Serial.println(plantCondition);
}
