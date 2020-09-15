/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  McuDriver_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef McuDriver_CFG_H
#define McuDriver_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

typedef enum
{
    Mcu_Clock_0,
    Mcu_Clock_1,
}Mcu_ClockType;

#define MCUDRIVER_CLOCK_SUPPORTED_NUMBER            (2)

#define ACTIVATED_CLOCK_GATES                       (13)

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


 
#endif  /* McuDriver_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: McuDriver_Cfg.h
 *********************************************************************************************************************/
