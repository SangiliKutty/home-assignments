/*****************************************************
      ESP32 Bluetooth Home Automation
      Output & Logic Same
      Structure Completely Modified
*****************************************************/

#include <BluetoothSerial.h>

BluetoothSerial BT;

//--------------- Pin Configuration ----------------

const byte LIGHT1_PIN = 26;
const byte LIGHT2_PIN = 27;

const byte SW1 = 0;
const byte SW2 = 35;

const byte BUZZ_PIN = 25;
const byte LED_PIN = 2;

const bool RELAY_ENABLE = LOW;
const bool RELAY_DISABLE = HIGH;

//--------------- Variables ----------------

bool roomLight1 = false;
bool roomLight2 = false;

bool oldSW1 = LOW;
bool oldSW2 = LOW;

unsigned long previousBT = 0;
const unsigned long AUTO_OFF_TIME = 1800000UL;

//---------------------------------------------------

enum CommandType
{
  CMD_INVALID,
  L1_ON,
  L1_OFF,
  L2_ON,
  L2_OFF,
  ALL_ON,
  ALL_OFF,
  STATUS
};

//---------------------------------------------------

CommandType decodeCommand(char c)
{
  switch (c)
  {
    case '1': return L1_ON;
    case '2': return L1_OFF;
    case '3': return L2_ON;
    case '4': return L2_OFF;
    case '5': return ALL_ON;
    case '6': return ALL_OFF;
    case '?': return STATUS;
    default : return CMD_INVALID;
  }
}

//---------------------------------------------------

void relayOutput()
{
  digitalWrite(LIGHT1_PIN, roomLight1 ? RELAY_ENABLE : RELAY_DISABLE);
  digitalWrite(LIGHT2_PIN, roomLight2 ? RELAY_ENABLE : RELAY_DISABLE);
}

//---------------------------------------------------

void buzzerTone()
{
  digitalWrite(BUZZ_PIN, HIGH);
  delay(50);
  digitalWrite(BUZZ_PIN, LOW);
}

//---------------------------------------------------

String createStatus()
{
  String txt = "L1:";
  txt += roomLight1 ? "ON " : "OFF ";

  txt += "L2:";
  txt += roomLight2 ? "ON" : "OFF";

  return txt;
}

//---------------------------------------------------

void printStatus()
{
  String info = createStatus();

  Serial.println(info);
  BT.println(info);
}

//---------------------------------------------------

void executeCommand(CommandType cmd)
{
  switch (cmd)
  {
    case L1_ON:
      roomLight1 = true;
      break;

    case L1_OFF:
      roomLight1 = false;
      break;

    case L2_ON:
      roomLight2 = true;
      break;

    case L2_OFF:
      roomLight2 = false;
      break;

    case ALL_ON:
      roomLight1 = true;
      roomLight2 = true;
      break;

    case ALL_OFF:
      roomLight1 = false;
      roomLight2 = false;
      break;

    case STATUS:
      printStatus();
      return;

    default:
      BT.println("Invalid Command");
      return;
  }

  relayOutput();
  buzzerTone();
  printStatus();
}

//---------------------------------------------------

void bluetoothTask()
{
  if (!BT.available())
    return;

  char incoming = BT.read();

  previousBT = millis();

  executeCommand(decodeCommand(incoming));
}

//---------------------------------------------------

void switchTask()
{
  bool currentSW1 = digitalRead(SW1);

  if (oldSW1 == HIGH && currentSW1 == LOW)
  {
    roomLight1 = !roomLight1;

    relayOutput();
    buzzerTone();
    printStatus();

    delay(200);
  }

  oldSW1 = currentSW1;

  bool currentSW2 = digitalRead(SW2);

  if (oldSW2 == LOW && currentSW2 == HIGH)
  {
    roomLight2 = !roomLight2;

    relayOutput();
    buzzerTone();
    printStatus();

    delay(200);
  }

  oldSW2 = currentSW2;
}

//---------------------------------------------------

void timeoutTask()
{
  if (millis() - previousBT > AUTO_OFF_TIME)
  {
    roomLight1 = false;
    roomLight2 = false;

    relayOutput();
  }
}

//---------------------------------------------------

void bluetoothIndicator()
{
  digitalWrite(LED_PIN, BT.hasClient());
}

//---------------------------------------------------

void setup()
{
  Serial.begin(115200);

  BT.begin("IIT_IoT_HomeCtrl");

  pinMode(LIGHT1_PIN, OUTPUT);
  pinMode(LIGHT2_PIN, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT);

  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  relayOutput();

  digitalWrite(BUZZ_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Bluetooth Home Controller Ready");
}

//---------------------------------------------------

void loop()
{
  bluetoothIndicator();

  bluetoothTask();

  switchTask();

  timeoutTask();
}
