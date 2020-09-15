/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  WDTDriver.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Common.h"
#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define TAEN    (0)
#define TBEN    (8)

#define TAMIE   (5)
#define TACDIR  (4)

#define TATOIM  (0)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Gpt_ConfigType* GlobalTimersConfigPtr = NULL;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static uint32 get_BaseAdd(Gpt_ChannelType Channel)
{
    uint32 address = 0x00000000;
    
    switch(Channel)
    {   
        case Gpt_ChannelType_16_32_TIMER0:
            address = (uint32)Timer_0_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_16_32_TIMER1:
            address = (uint32)Timer_1_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_16_32_TIMER2:
            address = (uint32)Timer_2_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_16_32_TIMER3:
            address = (uint32)Timer_3_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_16_32_TIMER4:
            address = (uint32)Timer_4_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_16_32_TIMER5:
            address = (uint32)Timer_5_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER0:
            address = (uint32)Wide_Timer_0_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER1:
            address = (uint32)Wide_Timer_1_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER2:
            address = (uint32)Wide_Timer_2_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER3:
            address = (uint32)Wide_Timer_3_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER4:
            address = (uint32)Wide_Timer_4_BASE_ADDRESS;
            break;
        case Gpt_ChannelType_32_64_WIDE_TIMER5:
            address = (uint32)Wide_Timer_5_BASE_ADDRESS;
            break;
        default:
            break;
    }
    
    return address;
}
 
static void Gpt_EnablePredefinedTimers(void)
{
#if (defined(GPT_PREDEF_TIMER_100US_32BIT) && (GPT_PREDEF_TIMER_100US_32BIT == ENABLE))
    /*TODO: Enable the predefined timers*/    
#endif
    
#if (defined(GPT_PREDEF_TIMER_1US_16BIT)   && (GPT_PREDEF_TIMER_1US_16BIT == ENABLE))
    /*TODO: Enable the predefined timers*/    
#endif
    
#if (defined(GPT_PREDEF_TIMER_1US_24BIT)   && (GPT_PREDEF_TIMER_1US_24BIT == ENABLE))
    /*TODO: Enable the predefined timers*/    
#endif
    
#if (defined(GPT_PREDEF_TIMER_1US_32BIT)   && (GPT_PREDEF_TIMER_1US_32BIT == ENABLE))
    /*TODO: Enable the predefined timers*/    
#endif
    
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void Gpt_Init(const Gpt_ConfigType* ConfigPtr)
{
    uint16          u16_idx = 0;
    Timer_Type      * PtrTimerReg = NULL;
    
    GlobalTimersConfigPtr = ConfigPtr;
    
    /*Note: The Clock Gates for timers should be activated*/
    
    for(u16_idx = 0; u16_idx < GPT_ACTIVATED_TIMERS; u16_idx++)
    {
        PtrTimerReg = (Timer_Type  *)get_BaseAdd(GlobalTimersConfigPtr[u16_idx].ChannelType);
        
        /*Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes.*/
        CLR_BIT(PtrTimerReg->Timer_GPTMCTL,TAEN);
        CLR_BIT(PtrTimerReg->Timer_GPTMCTL,TBEN);
        
        /*Clear the first 3 bits*/
        PtrTimerReg->Timer_GPTMCFG &= 0xFFFFFFF8;

        /*  For a 16/32-bit timer, this value selects the 16-bit time configuration.
            For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
        */
        PtrTimerReg->Timer_GPTMCFG |= 0x04;
        
        PtrTimerReg->Timer_GPTMTAMR = 0; 
        
        /*Count up | one shot or periodic
        */        
        PtrTimerReg->Timer_GPTMTAMR |= (1 << TACDIR) | (((uint8)GlobalTimersConfigPtr[u16_idx].ChannelMode) & 0xFC);
                                        
        PtrTimerReg->Timer_GPTMIMR = 0;       
    }
    
    
    
    /*Enable predefined timers*/
    Gpt_EnablePredefinedTimers();
}
     
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
    CLR_BIT(PtrTimerReg->Timer_GPTMIMR,TATOIM);
}
     
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
    SET_BIT(PtrTimerReg->Timer_GPTMIMR,TATOIM);    
}
     
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    
}
     
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    
}
     
void Gpt_Notification_Channel(void)
{
    
}

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType RetVal = 0;
    
    
    return RetVal;
}

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType RetVal = 0;
    
    
    return RetVal;    
}

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
    Std_ReturnType RetError = E_OK;
    
    
    return RetError;    
}

/**********************************************************************************************************************
 *  END OF FILE: WDTDriver.c
 *********************************************************************************************************************/
