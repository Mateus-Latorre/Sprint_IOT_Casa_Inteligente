#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPINO A3
#define DHTTYPE DHT11

DHT dht(DHTPINO, DHT11);

const int PIR = 2;  //pino digital que o PIR esta plugado
const int ledAmarelo = 13;

const int MQ135 = A0;
const int buzzer = 12;


void acenderLed() {
  int estadoPIR = digitalRead(PIR);  //Le o pino digital 2
  if (estadoPIR == HIGH) {
    digitalWrite(ledAmarelo, HIGH);
    Serial.println("Led ligado");
  } else {
    digitalWrite(ledAmarelo, LOW);
    Serial.println("Led apagado");
  }

  Serial.println(estadoPIR);
}

void vereficarVazDeGas() {
  int estadoMQ135 = analogRead(MQ135);

  if (estadoMQ135 >= 400) {
    alarme_dois_tons();
  } else {
    noTone(buzzer);
  }

  Serial.println(estadoMQ135);
  //delay(500);
}

void alarme_dois_tons() {
  int freqAlta = 2000;
  int freqBaixa = 800;
  int duracaoTom = 250;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

void verificarTemperaturaEUmidade(){
 float umidade = dht.readHumidity();
 float temperatura = dht.readTemperature();

 Serial.println("Umidade: " + String(umidade) + "%");
 Serial.println("Temperatura: " + String(temperatura) + "C");

delay(10000);
}

void setup() {
  Serial.begin(9600);

  pinMode(ledAmarelo, OUTPUT);
  pinMode(MQ135, INPUT);
  pinMode(buzzer, OUTPUT);

  dht.begin();

  Serial.println("Calibrando os sensores");
  delay(10000);
  Serial.println("Sensores calibrados!!!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //acenderLed();
  //vereficarVazDeGas();
  verificarTemperaturaEUmidade();

}
