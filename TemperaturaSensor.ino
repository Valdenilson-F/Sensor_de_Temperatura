#include <OneWire.h>
#include <DallasTemperature.h>

// Definição do pino de dados do DS18B20
#define ONE_WIRE_BUS 3 // Pino D3 do Arduino

// Configuração do barramento OneWire e do sensor DallasTemperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // Inicialização do monitor serial
  Serial.begin(9600);
  Serial.println("Iniciando sensor DS18B20...");

  // Inicialização do sensor
  sensors.begin();
}

void loop() {
  // Solicita a temperatura do sensor
  sensors.requestTemperatures();

  // Obtém a temperatura em Celsius
  float temperaturaC = sensors.getTempCByIndex(0);

  // Verifica se a leitura é válida
  if (temperaturaC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperatura: ");
    Serial.print(temperaturaC);
    Serial.println(" °C");
  } else {
    Serial.println("Erro: Sensor desconectado!");
  }

  // Pequeno atraso para leituras
  delay(100);
}
