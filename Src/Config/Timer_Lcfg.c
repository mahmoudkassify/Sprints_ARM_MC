/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  WDTDriver_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer.h"
#include "Timer_cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static void Timer0_16_32_cb(void)
{
    
}

static void WTimer0_32_64_cb(void)
{
    
}
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

const Gpt_ConfigType Gpt_Config[GPT_ACTIVATED_TIMERS] =
{
    {
        .ChannelType            = Gpt_ChannelType_16_32_TIMER0,
        .ChannelMode            = GPT_CH_MODE_ONESHOT,
        .TickFrequency          = 1000000,
        .TickValueMax           = 0xFFFF,
        .UserNotificationCB     = Timer0_16_32_cb,
    },
    
    {
        .ChannelType            = Gpt_ChannelType_32_64_WIDE_TIMER0,
        .ChannelMode            = GPT_CH_MODE_CONTINUOUS,
        .TickFrequency          = 16000000,
        .TickValueMax           = 0xFFFFFFFF,
        .UserNotificationCB     = WTimer0_32_64_cb,
    },
};


/**********************************************************************************************************************
 *  END OF FILE: Timer_Lcfg.c
 *********************************************************************************************************************/
