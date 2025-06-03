const int PIR = 2;

void acenderLED() {
  int estadoPIR = digitalRead(PIR);
  if (estadoPIR == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Led Acesso");
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Led Apagado");
  }
  delay(500);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(PIR, INPUT);
  Serial.begin(9600);
  delay(10000);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  acenderLED();
}
