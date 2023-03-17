/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es usado para crear un cliente MQTT en la tablilla ESP32 V1, se encarga de leer los
  datos del sensor y mandarlos mediante un protocolo MQTT.

  @author Jose Alejandro Melendez Garcia

*/

#include <Arduino.h>
#include <networking/networking.h>
#include <sensors/energia_electrica.h>
#include <sensors/led_indicator.h>

////////////////////////
// Variables Globales //
////////////////////////

// Frecuencia de lecturas (en ms)
const int LECTURE_FREQUENCY = 3000;

///////////////////////
// Logica de Arduino //
///////////////////////

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  setup_wifi();
  setup_mqtt();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (!is_client_connected()) {
    reconnect_client();
  }
  client_loop();
  publish_lecture();
  blink_led();

  delay(LECTURE_FREQUENCY);
}
