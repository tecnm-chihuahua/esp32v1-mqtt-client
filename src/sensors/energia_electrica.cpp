/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es usado para crear un cliente MQTT en la tablilla ESP32 V1, se encarga de leer los
  datos del sensor y mandarlos mediante un protocolo MQTT.

  @author Jose Alejandro Melendez Garcia

*/

#include <Arduino.h>
#include "energia_electrica.h"

/**
 * Genera un numero float aleatorio
 * NOTE: es solo para tests.
*/
float get_random_float_number() {
    return (float) random(1, 50)/10;
}

/**
 * Returna la lectura para ser serializada a JSON, aqui incluimos la
 * logica para leer datos del sensor.
*/
EnergyLecture get_data_lecture(const int MQTT_CLIENT_ID) {
    EnergyLecture lecture; 
    lecture.device_id = MQTT_CLIENT_ID;
    lecture.frecuencia = get_random_float_number();
    lecture.energia = get_random_float_number();
    lecture.potencia = get_random_float_number();
    lecture.fp = get_random_float_number();
    lecture.corriente = get_random_float_number();

    return lecture;
}
