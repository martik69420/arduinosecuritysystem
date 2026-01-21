const int TempSensor = A0;
const int LightSensor = A1;
const int TouchSensor = 9;
const int TiltSensor = 8;
const int CrashSensor = 7;
const int LedPin = 6;
const int BuzzerPin = 5;


const int templimit = 400;
const int lightlimit = 800;

bool Alarm = false;

void setup() {
  Serial.begin(9600);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
  pinMode(TiltSensor, INPUT_PULLUP);
  pinMode(TouchSensor, INPUT);
}

void loop() {
  int temp = analogRead(TempSensor);
  int lightLevel = analogRead(LightSensor);
  int tilt = digitalRead(TiltSensor);
  int touch = digitalRead(TouchSensor);
  int crash = digitalRead(CrashSensor);

  Serial.println("Temp: " + String(temp));
  Serial.println("Light: " + String(lightLevel));
  Serial.println("tilt: " + String(tilt));

  if (tilt == LOW) {
    Alarm = true;
  }

  if (crash == LOW) {
    Alarm = true;
  }

  if (touch == HIGH ){
    Alarm = false;
    }

  if (temp > templimit) {
    tone(BuzzerPin, 1000);
  } else {
    noTone(BuzzerPin);
  }

  if (Alarm) {
    tone(BuzzerPin, 1000);
  }

  if (lightLevel > lightlimit) {
    digitalWrite(LedPin, HIGH);
    } else {
      digitalWrite(LedPin, LOW);
      }

  delay(700);
}
