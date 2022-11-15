
#include <Arduino.h>
#include "FreeRTOS_IP.h"
#include "FreeRTOS_TCP_IP.h"
#include "FreeRTOS_Sockets.h"
#include "common_init.h"

/**********************************************************************************************************************
 * Function Name: vApplicationPingReplyHook
 * Description  : User Hook for the Ping Reply. vApplicationPingReplyHook() is called by the TCP/IP
 *                stack when the stack receives a ping reply.
 * Arguments    : eStatus
 *              : usIdentifier Ping reply status and Identifier
 * Return Value : None
 *********************************************************************************************************************/
void vApplicationPingReplyHook(ePingReplyStatus_t eStatus, uint16_t usIdentifier)
{
    FSP_PARAMETER_NOT_USED(usIdentifier);

    switch ( eStatus )
    {
        /* A valid ping reply has been received */
        case eSuccess    :
            break;

            /* A reply was received but it was not valid. */
        case eInvalidData :
        default:
            break;
    }
}
/**********************************************************************************************************************
 End of function vApplicationPingReplyHook
 *********************************************************************************************************************/

#if( ipconfigDHCP_REGISTER_HOSTNAME == 1 )
/**********************************************************************************************************************
 * Function Name: pcApplicationHostnameHook
 * Description  : DHCP Hook function to populate the user defined Host name for the Kit
 * Return Value : Hostname
 *********************************************************************************************************************/
const char *pcApplicationHostnameHook(void)
{
    return (KIT_NAME);
}
/**********************************************************************************************************************
 End of function pcApplicationHostnameHook
 *********************************************************************************************************************/
#endif
