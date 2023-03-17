/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es usado para crear un cliente MQTT en la tablilla ESP32 V1, se encarga de leer los
  datos del sensor y mandarlos mediante un protocolo MQTT.

  @author Jose Alejandro Melendez Garcia

*/

#include <Arduino.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <sensors/energia_electrica.h>
#include "configuration.h"
#include "networking.h"

WiFiClient espClient;
PubSubClient client(espClient);

/**
 * Crea una conexion al wifi.
*/
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

/**
 * El callback de MQTT
*/
void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.println();
  Serial.print(". Message: ");
  Serial.println();
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  /*if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
    if(messageTemp == "on"){
      Serial.println("on");
    }
    else if(messageTemp == "off"){
      Serial.println("off");
    }
  }*/
}

void setup_mqtt() {
  client.setServer(mqtt_server, MQTT_PORT);
  client.setCallback(callback);
}

void client_loop() {
  client.loop();
}

/*
 * Convierte los datos de la lectura en un json serializado para el cliente pubsub mqtt.
*/
String serialized_lecture(
  int device_id,
  float frecuencia,
  float energia,
  float potencia,
  float fp,
  float corriente
) {

  DynamicJsonDocument json(200);

  json["device_id"] = device_id;
  json["frecuencia"] = frecuencia;
  json["energia"] = energia;
  json["potencia"] = potencia;
  json["fp"] = fp;
  json["corriente"] = corriente;

  //size_t serializedJSON = serializeJson(json, Serial);

  return json.as<String>();  
}

/**
 * Verifica si el cliente mqtt esta conectado
*/
bool is_client_connected() {
  return client.connected();
}

/**
 * Reconecta al cliente
*/
void reconnect_client() {
  reconnect();
}

/**
 * Se encarga de reconectarse.
*/
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(MQTT_CLIENT_NAME)) {
      Serial.println("connected");
      // Subscribe
      client.subscribe(MQTT_CHANNEL);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void publish_lecture() {
  EnergyLecture energy_lecture = get_data_lecture(MQTT_CLIENT_ID);

  String lecture = serialized_lecture(
    energy_lecture.device_id, 
    energy_lecture.frecuencia,
    energy_lecture.energia,
    energy_lecture.potencia,
    energy_lecture.fp,
    energy_lecture.corriente
  );

  client.publish(MQTT_CHANNEL, lecture.c_str());
}
