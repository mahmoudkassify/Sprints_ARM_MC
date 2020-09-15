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
#include "WDTDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
#define WDG_UNLOCK_VAL			(0x1ACCE551)

#define INTEN                   (0)
#define RESEN                   (1)
#define INTTYPE                 (2)
#define WRC                     (31)

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Wdg_ConfigType * gPtrWdg_Config = NULL;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define WDG_LOCK()                  (WDG1->Wdg_LOCK = 0)
#define WDG_UNLOCK()                (WDG1->Wdg_LOCK = WDG_UNLOCK_VAL)

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/



void Wdg_Init(const Wdg_ConfigType * Wdg_Config)
{   
    /*Save the Config*/
    gPtrWdg_Config = Wdg_Config;
    
    /*Unlock the control register*/
    WDG_UNLOCK();    
    
    /*Load the WDTLOAD register with the desired timer load value.*/
    WDG1->Wdg_LOAD = WDG_CONVERT_TIME_TO_TICK(Wdg_Config->WdgInitialValue_ms);
    
    /*If WDT1, wait for the WRC bit in the WDTCTL register to be set.*/
    SET_BIT(WDG1->Wdg_CTL,WRC);
    
    /*If the Watchdog is configured to trigger system resets, set the RESEN bit in the WDTCTL register.*/
    SET_BIT(WDG1->Wdg_CTL,RESEN);

    /*If WDT1, wait for the WRC bit in the WDTCTL register to be set.*/
    SET_BIT(WDG1->Wdg_CTL,WRC);

    /*Interrupt type*/
    if(WDT_InterruptStandard == Wdg_Config->WdgInterruptType)
    {
        CLR_BIT(WDG1->Wdg_CTL,INTTYPE);
    }
    else
    {
        SET_BIT(WDG1->Wdg_CTL,INTTYPE);
    }
    
    /*Set the INTEN bit in the WDTCTL register to enable the Watchdog*/
    SET_BIT(WDG1->Wdg_CTL,INTEN);

    /*lock the control register*/
    WDG_LOCK();    
}

void Wdg_SetTriggerCondition(uint16 u16_msec)
{
    if(u16_msec <= gPtrWdg_Config->WdgMaxValue_ms)
    {
        WDG_UNLOCK();
        
        WDG1->Wdg_LOAD = WDG_CONVERT_TIME_TO_TICK(u16_msec);
        
        WDG_LOCK();
    }
}

void Wdg_Reset(void)
{
    WDG_UNLOCK();
    
    WDG1->Wdg_ICR = 0;
    
    WDG_LOCK();
}

void WDT0_Handler(void)
{
    if(NULL != gPtrWdg_Config->WdgUserCB)
    {
        gPtrWdg_Config->WdgUserCB();
    }
}

/**********************************************************************************************************************
 *  END OF FILE: WDTDriver.c
 *********************************************************************************************************************/
