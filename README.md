# ESP32
Este projeto utiliza um ESP32 para monitorar a temperatura ambiente por meio de um sensor TMP36 e acionar um LED quando a temperatura ultrapassar um valor crítico. Além disso, a temperatura é enviada periodicamente para um broker MQTT para monitoramento remoto. O projeto inclui esquemática de hardware e código-fonte totalmente documentado, permitindo que qualquer pessoa o reproduza.


## **Hardware**

-ESP32: Microcontrolador com suporte a Wi-Fi. 

-Sensor de Temperatura TMP36: Sensor analógico para leitura de temperatura ambiente.

-LED Vermelho: Indica temperatura acima do limite crítico.

-Resistor de 220Ω: Protege o LED.

-Protoboard e Cabos Jumper: Para montagem das conexões.



## **Software**

Arduino IDE: Ambiente de desenvolvimento.

Broker MQTT (Mosquitto): Para transmissão dos dados de temperatura.



## **Bibliotecas Necessárias:**
WiFi.h

PubSubClient.h



## **Documentação do Código**

O arquivo principal é ESP32.ino, que foi dividido em algumas etapas, sendo 

1- A conexão wi-fi

2- A conexão com o broker MQTT Mosquitto. (via função reconnect()) 

3- A leitura de temperatura, onde é definido no código uma temperatura em celsius. 

4- Se o sensor de temperatura TMP36 detectar uma temperatura maior que o número definido, o led irá acender. 

5- Seus valores são impressos no Serial Monitor do Arduino IDE

6- Os valores são enviados via protocolo MQTT ao broker.


## **Conexões de Hardware**
As conexões físicas foram feitas da seguinte maneira:

1-	GND do ESP32 – Ânodo do LED (por meio de um resistor de 220 Ω)

2-	GND do ESP32 – GND do TMP36

3-	3.3V do ESP32 – VCC do TMP36

4-	Pino D34 do ESP32 – OUT do TMP36

5-	Pino D2 do ESP32 – Cátodo do LED



## **Instruções para Reprodução**
Montagem do Circuito: Siga o esquema acima para montar os componentes em uma protoboard.

Mudança no código: Insira o seu ssid e a senha de sua rede wi-fi nas linhas 8 e 9 do código. Caso deseje, altere a temperatura crítica na linha 55.

Upload do Código: Utilize a Arduino IDE para carregar o código no ESP32. É importante ressaltar que o arquivo do código deve estar em uma pasta de mesmo nome.

Monitoramento: Acompanhe os valores no Serial Monitor ou em um cliente MQTT, lembrando que o host é **"test.mosquitto.org"**, a porta é **"8081"**, e o tópico é **"esp32/temperatura"**
