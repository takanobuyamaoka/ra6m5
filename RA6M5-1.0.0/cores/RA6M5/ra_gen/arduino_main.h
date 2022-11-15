/* generated thread header file - do not edit */
#ifndef ARDUINO_MAIN_H_
#define ARDUINO_MAIN_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void arduino_main_entry(void * pvParameters);
                #else
extern void arduino_main_entry(void *pvParameters);
#endif
FSP_HEADER
FSP_FOOTER
#endif /* ARDUINO_MAIN_H_ */
