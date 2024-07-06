unsigned long start;
bool on = false;
bool flag = false;
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); // デジタルピン8を出力モードに設定
}

void loop() {
  if (Serial.available() > 0) {
    if (Serial.read() == 'a') {
      on = !on;

    }
  }
  if (on) {
    Serial.println ("on");
    if (!flag) {
      start = millis();
      flag = true;

    }
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW); // LOWに戻す
    if (flag) {
      Serial.println(millis() - start);
      flag = false;
    }
  }

}
