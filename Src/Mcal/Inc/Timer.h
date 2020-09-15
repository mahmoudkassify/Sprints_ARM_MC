/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_H
#define TIMER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Common.h"
#include "Timer_cfg.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 Gpt_GptChannelTickFrequency;
typedef uint32 Gpt_ChannelTickValueMax;

typedef uint32 Gpt_ValueType;

typedef void (* Gpt_Notification)(void);

typedef enum
{
	Gpt_ChannelType_16_32_TIMER0,
	Gpt_ChannelType_16_32_TIMER1,
	Gpt_ChannelType_16_32_TIMER2,
	Gpt_ChannelType_16_32_TIMER3,
	Gpt_ChannelType_16_32_TIMER4,
	Gpt_ChannelType_16_32_TIMER5,
	Gpt_ChannelType_32_64_WIDE_TIMER0,
	Gpt_ChannelType_32_64_WIDE_TIMER1,
	Gpt_ChannelType_32_64_WIDE_TIMER2,
	Gpt_ChannelType_32_64_WIDE_TIMER3,
	Gpt_ChannelType_32_64_WIDE_TIMER4,
	Gpt_ChannelType_32_64_WIDE_TIMER5,
}Gpt_ChannelType;

typedef enum
{
	GPT_CH_MODE_ONESHOT = 0x01,
	GPT_CH_MODE_CONTINUOUS = 0x02,
}Gpt_ChannelMode;

typedef enum
{
	GPT_PREDEF_1US_16BIT,
	GPT_PREDEF_1US_24BIT,
	GPT_PREDEF_1US_32BIT,
	GPT_PREDEF_100US_32BIT
}Gpt_PredefTimerType;

typedef struct
{
    Gpt_ChannelType                 ChannelType;
    Gpt_ChannelMode                 ChannelMode;
    Gpt_GptChannelTickFrequency     TickFrequency;
    Gpt_ChannelTickValueMax         TickValueMax;
    Gpt_Notification                UserNotificationCB;
    
}Gpt_ConfigType;
/**********************************************************************************************************************
 *  API IMPLEMENTATION
 *********************************************************************************************************************/

void Gpt_Init(const Gpt_ConfigType* ConfigPtr);
     
void Gpt_DisableNotification(Gpt_ChannelType Channel);
     
void Gpt_EnableNotification(Gpt_ChannelType Channel);
     
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);
     
void Gpt_StopTimer(Gpt_ChannelType Channel);
     
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);


#endif  /* TIMER_H */

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/
