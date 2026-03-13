#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// xTaskCreate serve para a adição da task  af ila de execução
// vTaskDelay serve para liberar a execução da task do processador
// pdMS_TO_TICKS transforma um valor em ms para os ticks do processador
void TaskHigh(void *pv){
  while(true){
    Serial.println("[HIGH] prio = 1 - running");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void TaskLow(void *pv){
  while(true){
    Serial.println("[LOW] prio = 1 - running");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void setup() {
  Serial.begin(115200);
  xTaskCreate(TaskHigh, "High", 2048, nullptr, 1, nullptr);

  xTaskCreate(TaskLow, "Low", 2048, nullptr, 2, nullptr);

}

void loop() {
}
