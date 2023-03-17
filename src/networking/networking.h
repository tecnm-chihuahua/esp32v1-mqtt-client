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

void setup_wifi();

void setup_mqtt();

void reconnect();

String serialized_lecture(
  int device_id,
  float frecuencia,
  float energia,
  float potencia,
  float fp,
  float corriente
);

bool is_client_connected();

void reconnect_client();

void client_loop();

void publish_lecture();
