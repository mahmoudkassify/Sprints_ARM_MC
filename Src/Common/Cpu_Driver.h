/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Cpu_Driver.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _CPU_DRIVER_H_
#define _CPU_DRIVER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define CPUDRIVER_SWITCH_TO_PRIVMODE()   		__asm("SVC #0")


#define CPUDRIVER_SWITCH_TO_USERMODE()  	 	do{__asm("MRS R0, CONTROL");\
												__asm("OR R0, 0x1");\
												__asm("MSR CONTROL, R0");}while(0)


#define CPUDRIVER_DISABLE_ALL_Interupts()		__asm ("CPSID i")
#define CPUDRIVER_ENABLE_ALL_Interupts()		__asm ("CPSIE i")


#define CPUDRIVER_SW_RESET()                    CpuDriver_SoftwareReset()
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void CpuDriver_StartCriticalSection(void);
void CpuDriver_StopCriticalSection(void);
void CpuDriver_SoftwareReset(void);

#endif  /* _CPU_DRIVER_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Cpu_Driver.h
 *********************************************************************************************************************/
