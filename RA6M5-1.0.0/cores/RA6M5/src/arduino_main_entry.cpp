#include <arduino_main.h>
#include <Arduino.h>
#include "common_init.h"

/* Arduino Main entry function */
/* pvParameters contains TaskHandle_t */
void arduino_main_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED (pvParameters);

    fsp_err_t err;
    // for millis, delay in wiring.c
    err = R_GPT_Open(&g_timer0_ctrl, &g_timer0_cfg);
    if(err != FSP_SUCCESS) while(1);
    (void) R_GPT_Start(&g_timer0_ctrl);

    setup();

    while (1)
    {
        loop();
    }
}
