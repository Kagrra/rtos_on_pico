#include "pico/stdlib.h"
#include <FreeRTOS.h>
#include <stdio.h>
#include <task.h>

constexpr uint led_pin{PICO_DEFAULT_LED_PIN};

void led_task(void *) {
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  while (true) {
    gpio_put(LED_PIN, 1);
    vTaskDelay(100);
    gpio_put(LED_PIN, 0);
    vTaskDelay(100);
  }
}

void led_init() {
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);
}

void led_on(void *) {
  while (true) {
    gpio_put(led_pin, 2);
    vTaskDelay(500);
  }
}

void led_off(void *) {
  while (true) {
    vTaskDelay(250);
    gpio_put(led_pin, 0);
    vTaskDelay(250);
  }
}

int main() {
  stdio_init_all();
  led_init();

  xTaskCreate(led_on, "LED_Task_on", 32, NULL, 2, NULL);
  xTaskCreate(led_off, "LED_Task_off", 32, NULL, 1, NULL);

  vTaskStartScheduler();

  while (1) {
  };
}