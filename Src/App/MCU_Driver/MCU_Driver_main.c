/****************************************************************************/
/** Copyright (c) 2020 Mahmoud Kassify. All Rights Reserved. 			   **/
/****************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MCU_Driver_main.c
 *        \brief  This file is an example for intrCtrl driver.
 *
 *      \details  
 *
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
extern const Mcu_ConfigType Mcu_Config[];
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

int main(void)
{
    Mcu_Reset_Cause_Type Reset_type = Reset_Cause_Invalid;
    
	CPUDRIVER_ENABLE_ALL_Interupts();
    
    Mcu_Init(Mcu_Config);
    
    Reset_type = Mcu_RawResetType();
    
	for(;;)
    {

    }
}

/**********************************************************************************************************************
 *  END OF FILE: MCU_Driver_main.c
 *********************************************************************************************************************/



