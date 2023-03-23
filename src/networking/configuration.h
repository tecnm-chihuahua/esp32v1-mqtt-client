/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es usado para crear un cliente MQTT en la tablilla ESP32 V1, se encarga de leer los
  datos del sensor y mandarlos mediante un protocolo MQTT.

  @author Jose Alejandro Melendez Garcia

*/

///////////////////
// Configuracion //
///////////////////

// Replace the next variables with your SSID/Password combination
const char* ssid = "SSID";
const char* password = "PASSWORD";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const char* MQTT_CHANNEL = "88e0f9a0/88e0f9a0-2248-41b5-bc8a-95f1484ce5ad";

// El nombre del sensor (cliente) se recomienda modificarlo para cada sensor.
const char* MQTT_CLIENT_NAME = "NOMBRE_SENSOR_IOT_ITCH";

// EL numero de sensor
const int MQTT_CLIENT_ID = 2;