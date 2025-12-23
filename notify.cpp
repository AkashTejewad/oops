#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Task handle
static TaskHandle_t receiver_task_handle = NULL;

/* Task that waits for notification and prints */
void receiver_task(void *arg)
{
    while (1) {
        // Wait for notification
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // Print when notification received
        printf("Notification received!\n");
    }
}

/* Task that sends notification */
void sender_task(void *arg)
{
    while (1) {
        // Send notification
        xTaskNotifyGive(receiver_task_handle);

        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 seconds delay
    }
}

/* REQUIRED ENTRY POINT FOR ESP-IDF */
extern "C" void app_main(void)

{
    // Create receiver task
    xTaskCreate(
        receiver_task,
        "receiver_task",
        2048,
        NULL,
        5,
        &receiver_task_handle
    );

    // Create sender task
    xTaskCreate(
        sender_task,
        "sender_task",
        2048,
        NULL,
        5,
        NULL
    );
}
