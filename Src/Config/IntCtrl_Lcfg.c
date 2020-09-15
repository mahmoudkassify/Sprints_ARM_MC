/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
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
const IntCtrl_Config IntCtrl_Sys_Config = 
{
    .PriorityGrouping = PriGroup_YYY,
    
    .InterConfig = 
    {
        /*WDT_IRQ*/
        {
            .InterruptType       = WATCHDOG0_1_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },
        /*TIMER0A_IRQ*/
        {
            .InterruptType       = TIMER0A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },
        /*TIMER1A_IRQ*/
        {
            .InterruptType       = TIMER1A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },
        /*TIMER2A_IRQ*/
        {
            .InterruptType       = TIMER2A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
        /*TIMER3A_IRQ*/
        {
            .InterruptType       = TIMER3A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*TIMER4A_IRQ*/
        {
            .InterruptType       = TIMER4A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },
         /*TIMER5A_IRQ*/
        {
            .InterruptType       = TIMER5A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },         
         /*WTIMER0A_IRQ*/
        {
            .InterruptType       = WTIMER0A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*WTIMER1A_IRQ*/
        {
            .InterruptType       = WTIMER1A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*WTIMER2A_IRQ*/
        {
            .InterruptType       = WTIMER2A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*WTIMER3A_IRQ*/
        {
            .InterruptType       = WTIMER3A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*WTIMER4A_IRQ*/
        {
            .InterruptType       = WTIMER4A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        }, 
         /*WTIMER5A_IRQ*/
        {
            .InterruptType       = WTIMER5A_IRQ,
            .GroupPriority       = GroupPriorityNum_0,
            .SubGroupPriority    = SubGroupPriorityNum_0, 
        },         
    }
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
