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
#define USING_BIT_BAND  (1)

#define TAEN            (0)
#define TBEN            (8)
        
#define TAMIE           (5)
#define TACDIR          (4)
        
#define TATOIM          (0)
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

static Gpt_Notification User_CB(Gpt_ChannelType Channel)
{
    uint16      u16_idx = 0;
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
	Gpt_Notification user_cb = NULL;
    
    for(u16_idx = 0; u16_idx < GPT_ACTIVATED_TIMERS; u16_idx++)
    {
        if(Channel == GlobalTimersConfigPtr[u16_idx].ChannelType)
        {
            break;
        }
	}

    if(GPT_ACTIVATED_TIMERS != u16_idx)
    {
		user_cb = GlobalTimersConfigPtr[u16_idx].UserNotificationCB;
	}
	
	return user_cb;
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
    uint16      u16_idx = 0;
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
    for(u16_idx = 0; u16_idx < GPT_ACTIVATED_TIMERS; u16_idx++)
    {
        if(Channel == GlobalTimersConfigPtr[u16_idx].ChannelType)
        {
            break;
        }
	}
    
    if(GPT_ACTIVATED_TIMERS != u16_idx)
    {
        uint32 u32_prescalar = (uint32)GPT_DEFAULT_FREQ / (uint32)GlobalTimersConfigPtr[u16_idx].TickFrequency;
        
        if(Value > (GlobalTimersConfigPtr[u16_idx].TickValueMax))
        {
            Value = GlobalTimersConfigPtr[u16_idx].TickValueMax;
        }
        
        /*The ticks is multiplied by the prescalar*/
        PtrTimerReg->Timer_GPTMTAILR = Value * u32_prescalar;
        
        /*Start timer*/
#if USING_BIT_BAND
        PERIPHERAL_BITBAND((uint32)(&(PtrTimerReg->Timer_GPTMCTL)),TAEN) = 1;
#else        
        SET_BIT(PtrTimerReg->Timer_GPTMCTL,TAEN);
#endif        
    }
    
}
     
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
#if USING_BIT_BAND
    PERIPHERAL_BITBAND((uint32)(&(PtrTimerReg->Timer_GPTMCTL)),TAEN) = 0;
#else        
    CLR_BIT(PtrTimerReg->Timer_GPTMCTL,TAEN);
#endif    
}
     

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType RetVal = 0;
    uint16      u16_idx = 0;
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
    for(u16_idx = 0; u16_idx < GPT_ACTIVATED_TIMERS; u16_idx++)
    {
        if(Channel == GlobalTimersConfigPtr[u16_idx].ChannelType)
        {
            break;
        }
	}
    
    if(GPT_ACTIVATED_TIMERS != u16_idx)
    {
        uint32 u32_prescalar = (uint32)GPT_DEFAULT_FREQ / (uint32)GlobalTimersConfigPtr[u16_idx].TickFrequency;
        
        RetVal = PtrTimerReg->Timer_GPTMTAV / u32_prescalar;
    }        
    
    return RetVal;
}

Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType RetVal = 0;
    uint16      u16_idx = 0;
    Timer_Type * PtrTimerReg = (Timer_Type  *)get_BaseAdd(Channel);
    
    for(u16_idx = 0; u16_idx < GPT_ACTIVATED_TIMERS; u16_idx++)
    {
        if(Channel == GlobalTimersConfigPtr[u16_idx].ChannelType)
        {
            break;
        }
	}
    
    if(GPT_ACTIVATED_TIMERS != u16_idx)
    {
        uint32 u32_prescalar = (uint32)GPT_DEFAULT_FREQ / (uint32)GlobalTimersConfigPtr[u16_idx].TickFrequency;
        
        Gpt_ValueType OrignalTime = PtrTimerReg->Timer_GPTMTAILR;
        Gpt_ValueType CurrentTime = PtrTimerReg->Timer_GPTMTAV;
        
        RetVal = (OrignalTime - CurrentTime) / u32_prescalar;
    }        
    
    return RetVal;   
}

Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
    Std_ReturnType RetError = E_OK;
    
    *TimeValuePtr = 0x00000;
    
    /*TODO*/
    
    return RetError;    
}


void TIMER0A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER0);
}

void TIMER1A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER1);
}

void TIMER2A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER2);
}

void TIMER3A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER3);
}

void TIMER4A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER4);
}

void TIMER5A_Handler(void)
{
    User_CB(Gpt_ChannelType_16_32_TIMER5);
}

void WTIMER0A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER0);
}

void WTIMER1A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER1);
}

void WTIMER2A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER2);
}

void WTIMER3A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER3);
}

void WTIMER4A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER4);
}

void WTIMER5A_Handler(void)
{
    User_CB(Gpt_ChannelType_32_64_WIDE_TIMER5);
}
/**********************************************************************************************************************
 *  END OF FILE: WDTDriver.c
 *********************************************************************************************************************/
