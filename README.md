# Código fuente de MQTT de sensor IoT

Este es el código fuente del sensor de IoT que efectua las lecturas, para
acceder al puerto de carga de código actualizar la variable en platformio.ini
en Linux es necesario ejectutar setup.sh con permisos sudo para permitir al puerto
escribir datos.

## TODO

Toda la implementacion de MQTT, conexion a wifi y apis de acceso a metodos estan hechas, la unica funcion a editar es get_data_lecture() en src/sensors/energia_electrica.cpp, debemos de llenar el struct con la informacion requerida; antes de desplegar se debe de modificar la configuracion de ssid y password (del modem a usar) y MQTT_CLIENT_NAME (nombre de la tablilla en el broker de mqtt DEBE SER DIFERENTE Y UNICO), MQTT_CLIENT_ID (el numero de tablilla, sirve para identificarla).

## Tablilla usada

Nodem cu Esp32 Devkit V1

## IDE Recomendado

[Editor: VSCode](https://code.visualstudio.com/)
[Extension de VSCode: platform.io](https://platformio.org/)

## Librerías y Frameworks

[Arduino-Espressif32](https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html#tutorial-espressif32-arduino-debugging-unit-testing/)
[PubSubClient](https://github.com/jalexmelendez/pubsubclient)
[ArduinoJSON](https://arduinojson.org/v6/example/string/)

## Setup de puerto para Linux

```bash
sudo chmod +x setup.sh
```

## Configuracion global y estructura de proyecto

El codigo fuente se encuentra en src/main.cpp, hay dos directorios en src: networking y sensors.

NOTA: El codigo fuente esta preconfigurado, la unica configuracion que se recomienda modificar en el modulo de networking en configuration.h es:

- MQTT_CLIENT_ID: (el id o numero de nuestra tablilla)
- MQTT_CLIENT_NAME: (El nombre del sensor (cliente) se recomienda modificarlo para cada sensor.)
- LECTURE_FREQUENCY: (la frecuencia de lectura, default 1s o 1000ms)
- ssid: (el ssid de nuestro modem wifi)
- password: (el password de nuestro modem wifi)

### main.cpp

En este archivo encontramos la configuracion de lecturas, no se recomienda modificarlo mas que la variable de frecuencia de lectura.

## src/newtworking/networking.cpp

Aqui estan todas las funciones para conectarnos al internet mediante wifi y para serializar, recibir y mandar datos mediante mqtt.

## src/sensors/energia_electrica.cpp

Este es el archivo que vamos a editar para tomar las lecturas, la funcion que toma la lectura y retorna los datos es get_data_lecture() y es llamada cada vez que recolectemos datos (por defecto es 1s, se encuentra en main.cpp).
