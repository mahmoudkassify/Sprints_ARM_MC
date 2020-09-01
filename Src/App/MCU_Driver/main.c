/****************************************************************************/
/** Copyright (c) 2020 Mahmoud Kassify. All Rights Reserved. 			   **/
/****************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  main.c
 *        \brief  This file is an example for intrCtrl driver.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Operation.h"
#include "Cpu_Driver.h"
#include "Platform_Types.h"
#include "IntCtrl.h"

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

int main(void)
{
	CPUDRIVER_ENABLE_ALL_Interupts();
    
	for(;;);	
}


/**********************************************************************************************************************
 *  END OF FILE: main.c
 *********************************************************************************************************************/



