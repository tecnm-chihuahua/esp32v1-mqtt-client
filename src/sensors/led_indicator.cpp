/**
  Source code del cliente mqtt de lecturas del sensor.

  Name: mqtt-esp32
  Purpose: Este codigo es el indicador led.

  @author Jose Alejandro Melendez Garcia

*/

#include <driver/gpio.h>
// Include FreeRTOS for delay
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define LED GPIO_NUM_2 // LED connected to GPIO2

void blink_led() {
    // Configure pin
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << LED);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    gpio_set_level(LED, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(LED, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(LED, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
}
