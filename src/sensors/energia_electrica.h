/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es usado para crear un cliente MQTT en la tablilla ESP32 V1, se encarga de leer los
  datos del sensor y mandarlos mediante un protocolo MQTT.

  @author Jose Alejandro Melendez Garcia

*/

/**
 * Una estructura que define el esquema para lectura de datos de sensor
 * NOTE: NO MODIFICAR
*/
struct EnergyLecture {
    int device_id;
    float frecuencia;
    float energia;
    float potencia;
    float fp;
    float corriente;
};

EnergyLecture get_data_lecture(const int MQTT_CLIENT_ID);
