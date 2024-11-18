# ESP32
Descrição do Projeto
Este projeto utiliza um ESP32 para monitorar a temperatura ambiente por meio de um sensor TMP36 e acionar um LED quando a temperatura ultrapassar um valor crítico (25°C). Além disso, a temperatura é enviada periodicamente para um broker MQTT para monitoramento remoto. O projeto inclui esquemática de hardware e código-fonte totalmente documentado, permitindo que qualquer pessoa o reproduza.

Requisitos

##**Hardware**

-ESP32: Microcontrolador com suporte a Wi-Fi. 

-Sensor de Temperatura TMP36: Sensor analógico para leitura de temperatura ambiente.

-LED Vermelho: Indica temperatura acima do limite crítico.

-Resistor de 220Ω: Protege o LED.

-Protoboard e Cabos Jumper: Para montagem das conexões.



##**Software**

Arduino IDE: Ambiente de desenvolvimento.

Broker MQTT (Mosquitto): Para transmissão dos dados de temperatura.



##**Bibliotecas Necessárias:**
WiFi.h
PubSubClient.h



##**Documentação do Código**

O código principal foi dividido em etapas para organização e fácil compreensão. O arquivo principal é main.ino, que contém:

Conexão Wi-Fi: Configuração da rede sem fio.

Conexão com o Broker MQTT: Estabelecimento de conexão e tratamento de erros.

Leitura de Temperatura: Monitoramento do sensor TMP36.

Acionamento do LED: Ligação do LED caso a temperatura ultrapasse um valor X.

Envio de Dados MQTT: Publicação da temperatura no broker.


##**Conexões de Hardware**
As conexões físicas foram feitas da seguinte maneira:

1-	GND do ESP32 – Ânodo do LED (por meio de um resistor de 220 Ω)

2-	GND do ESP32 – GND do TMP36

3-	3.3V do ESP32 – VCC do TMP36

4-	Pino D34 do ESP32 – OUT do TMP36

5-	Pino D2 do ESP32 – Cátodo do LED



##**Instruções para Reprodução**
Montagem do Circuito: Siga o esquema acima para montar os componentes em uma protoboard.

Mudança no código: Insira o seu ssid e a senha de sua rede wi-fi nas linhas 8 e 9 do código. Caso deseje, altere a temperatura alvo na linha 55.

Upload do Código: Utilize a Arduino IDE para carregar o código no ESP32.

Monitoramento: Acompanhe os valores no Serial Monitor ou em um cliente MQTT, lembrando que o host é **"test.mosquitto.org"**, a porta é **"8081"**, e o tópico é **"esp32/temperatura"**
