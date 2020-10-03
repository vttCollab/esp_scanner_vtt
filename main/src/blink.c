/* Blink Example

*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "button.h"
#include "stringOpr.h"

#define BLINK_GPIO 2
#define WIFI_BUTTON 18
#define MAIN_BUTTON 5

button_event_t ev;
char *DEFAULT_SSID;
char *DEFAULT_PWD;

void app_main(void)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    QueueHandle_t button_events = pulled_button_init((PIN_BIT(MAIN_BUTTON) | PIN_BIT(WIFI_BUTTON)), GPIO_PULLUP_ONLY);
    gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1)
    {
        if (xQueueReceive(button_events, &ev, 50 / portTICK_PERIOD_MS))
        {

            if ((ev.pin == MAIN_BUTTON) && (ev.event == BUTTON_DOWN))
            {
                // ...
                // TODO:ADD CHECK QR OUTPUT CODE HERE
                printf("Button Pressed");
                gpio_set_level(BLINK_GPIO, 1);
                vTaskDelay(150 / portTICK_PERIOD_MS);
                gpio_set_level(BLINK_GPIO, 0);
            }
            if ((ev.pin == WIFI_BUTTON) && (ev.event == BUTTON_LONG))
            {
                // TODO:ADD CHECK QR OUTPUT CODE HERE
                char a[] = "Pi0x1cAsdfghjkl12";
                char *p;
                p = rep_str(a);
                printf("%s", p);
                // printf("%s",ssid(p));
                // printf("%s",pwd(p));
            }
        }
    }
}
