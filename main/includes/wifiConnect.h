#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
void fast_scan(char[], char[]);
static void event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
int string_ln(char *p);
void connectWifi(void);