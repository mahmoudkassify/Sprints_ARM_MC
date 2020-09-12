/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  McuDriver_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef McuDriver_TYPES_H
#define McuDriver_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    Mcu_Clock_Gate_WD0      = 0U,
    Mcu_Clock_Gate_WD1      = 1U,
    Mcu_Clock_Gate_GPIOA    = 20U,
    Mcu_Clock_Gate_GPIOB    = 21U,
    Mcu_Clock_Gate_GPIOE    = 24U,
}Mcu_Clock_Gate;

typedef enum
{
    Mcu_Clock_16MHZ = 16000,
    Mcu_Clock_25MHZ = 25000,    
}Mcu_Clock_Supported_Freq;

typedef enum
{
    Mcu_Clock_PLL_Disabled,
    Mcu_Clock_PLL_Enabled,
    
}Mcu_Clock_PLL_used;

typedef enum
{
    Mcu_Clock_Source_Mosc,
    Mcu_Clock_Source_PIosc,
}Mcu_Clock_Source;

typedef struct
{
    Mcu_Clock_Source            Clock_Source;
    Mcu_Clock_PLL_used          Clock_PLL_used;
    Mcu_Clock_Supported_Freq    Clock_Supported_Freq;
}Mcu_ConfigType;


typedef enum
{
    Reset_Cause_External,
    Reset_Cause_Power_on,
    Reset_Cause_Brown_out,
    Reset_Cause_WDT0,
    Reset_Cause_Software,
    Reset_Cause_WDT1,
    Reset_Cause_MOSC_failure,
    Reset_Cause_Invalid,
}Mcu_Reset_Cause_Type;

#endif  /* McuDriver_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: McuDriver_Types.h
 *********************************************************************************************************************/
