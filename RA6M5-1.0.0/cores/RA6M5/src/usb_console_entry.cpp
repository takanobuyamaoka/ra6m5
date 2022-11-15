extern "C"{
#include "usb_console.h"
#include "usb_console_main.h"
}
/* USB Console entry function */
/* pvParameters contains TaskHandle_t */
void usb_console_entry(void *pvParameters) {
	FSP_PARAMETER_NOT_USED(pvParameters);

    usb_console_main();

    while (1) {
		vTaskDelay(1);
	}
}
