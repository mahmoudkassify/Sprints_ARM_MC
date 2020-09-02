/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  McuDriver.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Common.h"
#include "McuDriver.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

const Mcu_ConfigType * gPtrMcu_Config = NULL;

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType * PtrMcu_Config)
{
    gPtrMcu_Config = PtrMcu_Config;
}

void Mcu_PerformReset(void)
{
    CPUDRIVER_SW_RESET();
}

Mcu_Reset_Cause_Type Mcu_RawResetType(void)
{
    Mcu_Reset_Cause_Type Reset_type = Reset_Cause_Invalid;

    if(STD_HIGH == RESC->BitAcess.RESC_EXT)
    {
        RESC->BitAcess.RESC_EXT = STD_LOW;
        Reset_type = Reset_Cause_External;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_POR)
    {
        RESC->BitAcess.RESC_POR = STD_LOW;
        Reset_type = Reset_Cause_Power_on;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_BOR)
    {
        RESC->BitAcess.RESC_BOR = STD_LOW;
        Reset_type = Reset_Cause_Brown_out;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_WDT0)
    {
        RESC->BitAcess.RESC_WDT0 = STD_LOW;
        Reset_type = Reset_Cause_WDT0;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_SW)
    {
        RESC->BitAcess.RESC_SW = STD_LOW;
        Reset_type = Reset_Cause_Software;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_WDT1)
    {
        RESC->BitAcess.RESC_WDT1 = STD_LOW;
        Reset_type = Reset_Cause_WDT1;
    }
    else if(STD_HIGH == RESC->BitAcess.RESC_MOSCFAIL)
    {
        RESC->BitAcess.RESC_MOSCFAIL = STD_LOW;
        Reset_type = Reset_Cause_MOSC_failure;
    }
    else
    {
        /*Do nothing*/
    }
   
    return Reset_type;    
}

Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockType)
{
    //gPtrMcu_Config[(uint8)ClockType];
    
    return E_OK;
}
/**********************************************************************************************************************
 *  END OF FILE: McuDriver.c
 *********************************************************************************************************************/
