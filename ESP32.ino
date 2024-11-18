#include <WiFi.h>
#include <PubSubClient.h>

#define TEMPERATURE_SENSOR_PIN 34  // TMP36
#define LED_PIN 2  // LED
//tópico "esp32/temperatura"
// Credenciais Wi-Fi
const char* ssid = "NOMEdaREDE";
const char* password = "SENHAdaREDE";

// Endereço do broker MQTT
const char* mqtt_server = "test.mosquitto.org";  // Broker público Mosquitto
const int mqtt_port = 1883;  // Porta do broker

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); // Configura o pino do LED

  // Conecta-se à rede Wi-Fi
  Serial.print("Conectando-se ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("."); // Imprime um ponto a cada segundo que passa conectando
  }
  Serial.println("Conectado ao WiFi");

  client.setServer(mqtt_server, mqtt_port);// Configura o cliente MQTT
}

void loop() {
  // Conecta-se ao broker MQTT
  if (!client.connected()) {
    Serial.println("Tentando se conectar ao broker MQTT...");
    reconnect();
  }
  client.loop();

  //Leitura da Temperatura
  int sensorValue = analogRead(TEMPERATURE_SENSOR_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);  
  float temperature = (voltage - 0.5) * 100.0; 


  Serial.print("Temperatura: "); // Imprime a temperatura no serial monitor
  Serial.print(temperature);
  Serial.println(" °C");

  char tempStr[8];
  dtostrf(temperature, 1, 2, tempStr);  // Converte o valor de temperatura para string
  client.publish("esp32/temperatura", tempStr);  // Envia para o tópico "esp32/temperatura"
  if (temperature > 19.0) {
    digitalWrite(LED_PIN, HIGH); // Acende o LED
  } else {
    digitalWrite(LED_PIN, LOW); // Apaga o LED
  }
  delay(1000);
}

void reconnect() { //Função que faz a reconexão ao broker, e imprime o erro caso falhe.
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    String IdClient = "ESP32Arthur";
    IdClient += String(random(0xffff), HEX); //Cria-se um clientID aleatório
    if (client.connect(IdClient.c_str())) {  
      Serial.println("Conectado ao MQTT!");
    } else {
      Serial.print("Falha na conexão, erro: ");
      Serial.println(client.state());
      Serial.print("Tentando novamente em 5 segundos...");
      delay(5000);
    }
  }
}
