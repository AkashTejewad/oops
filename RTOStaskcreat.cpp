#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Task function
void printTask(void *pvParameters)
{
    while (1)
    {
        printf("AKASH\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// VERY IMPORTANT: extern "C"
extern "C" void app_main(void)
{
    xTaskCreate(
        printTask,
        "PrintTask",
        2048,
        NULL,
        1,
        NULL
    );
}
