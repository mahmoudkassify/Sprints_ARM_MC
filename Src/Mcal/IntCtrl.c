/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "Bit_Operation.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern const IntCtrl_Config IntCtrl_Sys_Config;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void IntCrtl_SetPriorityGrouping(IntCtrl_PriGroup PriorityGrouping);
static void IntCrtl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriority);
static void IntCrtl_EnableInterrupt(IntCtrl_InterruptType IntrNum);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static void IntCrtl_SetPriorityGrouping(IntCtrl_PriGroup PriorityGrouping)
{
    uint32 APINT_Temp = APINT;
    uint32 u32_PriorityGroupingTemp = ((uint32)PriorityGrouping & 7UL);
    
    APINT_Temp &= ~((uint32)(CORTEXM4_APINT_VECTKEY_Msk | CORTEXM4_APINT_PRIGROUP_Msk));
    
    APINT = (APINT_Temp                                                         |
             CORTEXM4_APINT_VECTKEY                                             |
            (u32_PriorityGroupingTemp << CORTEXM4_APINT_PRIGROUP_Pos)           );
}

static void IntCrtl_SetPriority(IntCtrl_InterruptType IntrNum, uint8 u8_IntPriority)
{
    uint8 InterruptPriority = ((u8_IntPriority & 0x07) << 5);
    /*NVIC_PRIx*/
    if(SysTick_IRQ < IntrNum)
    {
        NVIC->SETPRI[IntrNum] = InterruptPriority;
    }
    /*SCB_SYSPRIx*/
    else
    {
        switch(IntrNum)
        {
            case MemoryManagement_IRQ:
                SYSPRI->SYSPRI_SET[0] = InterruptPriority;
                break;
            case BusFault_IRQ:
                SYSPRI->SYSPRI_SET[1] = InterruptPriority;
                break;
            case UsageFault_IRQ:
                SYSPRI->SYSPRI_SET[2] = InterruptPriority;
                break;
            case SVCall_IRQ:
                SYSPRI->SYSPRI_SET[7] = InterruptPriority;
                break;
            case DebugMonitor_IRQ:
                SYSPRI->SYSPRI_SET[8] = InterruptPriority;
                break;
            case PendSV_IRQ:
                 SYSPRI->SYSPRI_SET[10] = InterruptPriority;
               break;
            case SysTick_IRQ:
                 SYSPRI->SYSPRI_SET[11] = InterruptPriority;
               break;            
            default:
                break;
        }
    }
}

static void IntCrtl_EnableInterrupt(IntCtrl_InterruptType IntrNum)
{    
    /*NVIC_ENx*/
    if(SysTick_IRQ < IntrNum)
    {
        SET_BIT(NVIC->ENINT[((uint8)IntrNum >> 5)] , (IntrNum % 32));
    }
    /*SCB_Sys*/
    else
    {
        switch(IntrNum)
        {
            case MemoryManagement_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 16);
                break;
            case BusFault_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 17);
                break;
            case UsageFault_IRQ:
                SET_BIT(SYSHNDCTRL->SysCtrlHandler , 18);
               break;
            /* case SysTick_IRQ:
                 SYSPRI->SYSPRI_SET[11] = ;
               break;*/            
            default:
                break;
        } 
        
    }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


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
void IntCrtl_Init(void)
{
    uint8   u8_idx = 0;
    
	/*Configure Grouping\SubGrouping System in APINT register in SCB*/
    IntCrtl_SetPriorityGrouping(IntCtrl_Sys_Config.PriorityGrouping);
    
    /*Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    for(u8_idx = 0; u8_idx < INTCTRL_SUPPORTED_NUMBER; u8_idx++)
    {
        uint8 u8_IntrPrioriity          = 0;
        uint8 u8_GroupPriority          = (uint8)IntCtrl_Sys_Config.InterConfig[u8_idx].GroupPriority;
        uint8 u8_SubGroupPriority       = (uint8)IntCtrl_Sys_Config.InterConfig[u8_idx].SubGroupPriority;
        
        IntCtrl_InterruptType IntrNum   = IntCtrl_Sys_Config.InterConfig[u8_idx].InterruptType;
        
        if(PriGroup_XXX == IntCtrl_Sys_Config.PriorityGrouping)
        {
            u8_IntrPrioriity = u8_GroupPriority;
        }
        else if(PriGroup_XXY == IntCtrl_Sys_Config.PriorityGrouping)
        {
            u8_IntrPrioriity = ((u8_GroupPriority & 0x03) << 1UL) | ((u8_SubGroupPriority & 0x01) << 0);
        }
        else if(PriGroup_XYY == IntCtrl_Sys_Config.PriorityGrouping)
        {
            u8_IntrPrioriity = ((u8_GroupPriority & 0x01) << 2UL) | ((u8_SubGroupPriority & 0x03) << 0);
        }
        else if(PriGroup_YYY == IntCtrl_Sys_Config.PriorityGrouping)
        {
            u8_IntrPrioriity = u8_SubGroupPriority;           
        }
        else
        {
            /*Do nothing*/
        }
        
        /*Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/ 
        IntCrtl_SetPriority(IntrNum, u8_IntrPrioriity);
        
        
        /*Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        IntCrtl_EnableInterrupt(IntrNum);
    

    }



	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
