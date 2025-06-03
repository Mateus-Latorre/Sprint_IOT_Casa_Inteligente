int pir = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int estadoPir = digitalRead(pir);
  if (estadoPir == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Movimento detectado! LED aceso.");
    delay(500);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Sem movimento. LED apagado.");
    delay(500);
  }
}
