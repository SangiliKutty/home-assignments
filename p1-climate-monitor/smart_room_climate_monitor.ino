/*************************************************
      ESP32 Mini Weather Station (Modified)
      Output & Logic Same - Code Structure Changed
*************************************************/

#include <Wire.h>
#include <DHTesp.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ------------ OLED Configuration ------------
#define OLED_WIDTH   128
#define OLED_HEIGHT   64
#define OLED_ADDR    0x3C

Adafruit_SSD1306 oled(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

// ------------ Pin Assignment ------------
const byte DHT_PIN = 4;
const byte RED = 25;
const byte GREEN = 26;
const byte BUZZ = 27;

// ------------ DHT Object ------------
DHTesp sensor;

// ------------ Global Variables ------------
float tempValue = 0;
float humValue = 0;
String weatherState = "";

unsigned long sensorTimer = 0;
unsigned long csvTimer = 0;

//====================================================
// Display Startup
//====================================================
void welcomeScreen()
{
  oled.clearDisplay();
  oled.setCursor(10,15);
  oled.println("Mini Weather");
  oled.setCursor(25,32);
  oled.println("Station");
  oled.display();
  delay(2000);
}

//====================================================
// Read Temperature & Humidity
//====================================================
void updateSensor()
{
  TempAndHumidity reading = sensor.getTempAndHumidity();

  tempValue = reading.temperature;
  humValue = reading.humidity;

  Serial.print("Temperature: ");
  Serial.print(tempValue);
  Serial.print(" C\tHumidity: ");
  Serial.print(humValue);
  Serial.println(" %");
}

//====================================================
// Decide Status
//====================================================
String checkEnvironment(float t, float h)
{
  if (t > 38 || h > 80)
    return "DANGER";

  if (t >= 34 || h >= 70)
    return "HOT";

  if ((t >= 25 && t <= 33) &&
      (h >= 40 && h <= 69))
    return "COMFORT";

  return "COOL";
}

//====================================================
// OLED Update
//====================================================
void refreshOLED()
{
  oled.clearDisplay();

  oled.setCursor(0,0);
  oled.print("Temp: ");
  oled.print(tempValue,1);
  oled.println(" C");

  oled.setCursor(0,20);
  oled.print("Hum : ");
  oled.print(humValue,0);
  oled.println(" %");

  oled.setCursor(0,40);
  oled.print("Status: ");
  oled.println(weatherState);

  oled.display();
}

//====================================================
// LED & Buzzer Control
//====================================================
void alarmControl()
{
  bool danger = (tempValue > 38 || humValue > 80);

  digitalWrite(RED, danger);
  digitalWrite(GREEN, !danger);

  if (danger)
  {
    digitalWrite(BUZZ, HIGH);
    delay(1000);
    digitalWrite(BUZZ, LOW);
  }
  else
  {
    digitalWrite(BUZZ, LOW);
  }
}

//====================================================
// CSV Output
//====================================================
void serialCSV()
{
  Serial.print(millis());
  Serial.print(",");
  Serial.print(tempValue);
  Serial.print(",");
  Serial.print(humValue);
  Serial.print(",");
  Serial.println(weatherState);
}

//====================================================
// Setup
//====================================================
void setup()
{
  Serial.begin(115200);

  Wire.begin(21,22);

  sensor.setup(DHT_PIN, DHTesp::DHT11);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR))
  {
    Serial.println("OLED not found!");
    while (true);
  }

  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BUZZ, LOW);

  welcomeScreen();
}

//====================================================
// Loop
//====================================================
void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - sensorTimer >= 2000)
  {
    sensorTimer = currentTime;

    updateSensor();

    weatherState = checkEnvironment(tempValue, humValue);

    refreshOLED();

    alarmControl();
  }

  if (currentTime - csvTimer >= 5000)
  {
    csvTimer = currentTime;

    serialCSV();
  }
}
