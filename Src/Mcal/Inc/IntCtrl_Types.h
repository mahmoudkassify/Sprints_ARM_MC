/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

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
typedef enum {/*From page 16 in Tiva™ TM4C123GH6PM Microcontroller Datasheet */
  Reset_IRQ                    = -15,
  NonMaskableInt_IRQ           = -14,
  HardFault_IRQ                = -13,
  MemoryManagement_IRQ         = -12,
  BusFault_IRQ                 = -11,
  UsageFault_IRQ               = -10,
  SVCall_IRQ                   =  -5,
  DebugMonitor_IRQ             =  -4,
  PendSV_IRQ                   =  -2,
  SysTick_IRQ                  =  -1,
  GPIOA_IRQ                    =   0,
  GPIOB_IRQ                    =   1,
  GPIOC_IRQ                    =   2,
  GPIOD_IRQ                    =   3,
  GPIOE_IRQ                    =   4,
  UART0_IRQ                    =   5,
  UART1_IRQ                    =   6,
  SSI0_IRQ                     =   7,
  I2C0_IRQ                     =   8,
  PWM0_FAULT_IRQ               =   9,
  PWM0_0_IRQ                   =  10,
  PWM0_1_IRQ                   =  11,
  PWM0_2_IRQ                   =  12,
  QEI0_IRQ                     =  13,
  ADC0SS0_IRQ                  =  14,
  ADC0SS1_IRQ                  =  15,
  ADC0SS2_IRQ                  =  16,
  ADC0SS3_IRQ                  =  17,
  WATCHDOG0_1_IRQ              =  18,
  TIMER0A_IRQ                  =  19,
  TIMER0B_IRQ                  =  20,
  TIMER1A_IRQ                  =  21,
  TIMER1B_IRQ                  =  22,
  TIMER2A_IRQ                  =  23,
  TIMER2B_IRQ                  =  24,
  COMP0_IRQ                    =  25,
  COMP1_IRQ                    =  26,
  SYSCTL_IRQ                   =  28,
  FLASH_CTRL_IRQ               =  29,
  GPIOF_IRQ                    =  30,
  UART2_IRQ                    =  33,
  SSI1_IRQ                     =  34,
  TIMER3A_IRQ                  =  35,
  TIMER3B_IRQ                  =  36,
  I2C1_IRQ                     =  37,
  QEI1_IRQ                     =  38,
  CAN0_IRQ                     =  39,
  CAN1_IRQ                     =  40,
  HIB_IRQ                      =  43,
  USB0_IRQ                     =  44,
  PWM0_3_IRQ                   =  45,
  UDMA_IRQ                     =  46,
  UDMAERR_IRQ                  =  47,
  ADC1SS0_IRQ                  =  48,
  ADC1SS1_IRQ                  =  49,
  ADC1SS2_IRQ                  =  50,
  ADC1SS3_IRQ                  =  51,
  SSI2_IRQ                     =  57,
  SSI3_IRQ                     =  58,
  UART3_IRQ                    =  59,
  UART4_IRQ                    =  60,
  UART5_IRQ                    =  61,
  UART6_IRQ                    =  62,
  UART7_IRQ                    =  63,
  I2C2_IRQ                     =  68,
  I2C3_IRQ                     =  69,
  TIMER4A_IRQ                  =  70,
  TIMER4B_IRQ                  =  71,
  TIMER5A_IRQ                  =  92,
  TIMER5B_IRQ                  =  93,
  WTIMER0A_IRQ                 =  94,
  WTIMER0B_IRQ                 =  95,
  WTIMER1A_IRQ                 =  96,
  WTIMER1B_IRQ                 =  97,
  WTIMER2A_IRQ                 =  98,
  WTIMER2B_IRQ                 =  99,
  WTIMER3A_IRQ                 = 100,
  WTIMER3B_IRQ                 = 101,
  WTIMER4A_IRQ                 = 102,
  WTIMER4B_IRQ                 = 103,
  WTIMER5A_IRQ                 = 104,
  WTIMER5B_IRQ                 = 105,
  SYSEXC_IRQ                   = 106,
  PWM1_0_IRQ                   = 134,
  PWM1_1_IRQ                   = 135,
  PWM1_2_IRQ                   = 136,
  PWM1_3_IRQ                   = 137,
  PWM1_FAULT_IRQ               = 138,
}IntCtrl_InterruptType;

typedef enum {
    PriGroup_XXX = 4,
    PriGroup_XXY = 5,
    PriGroup_XYY = 6,
    PriGroup_YYY = 7, 
}IntCtrl_PriGroup;

typedef enum {
    GroupPriorityNum_0      = 0,
    GroupPriorityNum_1      = 1,
    GroupPriorityNum_2      = 2,
    GroupPriorityNum_3      = 3,
    GroupPriorityNum_4      = 4,
    GroupPriorityNum_5      = 5,
    GroupPriorityNum_6      = 6,
    GroupPriorityNum_7      = 7,
}IntCtrl_GroupPriorityNum;

typedef enum {
    SubGroupPriorityNum_0   = 0,
    SubGroupPriorityNum_1   = 1,
    SubGroupPriorityNum_2   = 2,
    SubGroupPriorityNum_3   = 3,
    SubGroupPriorityNum_4   = 4,
    SubGroupPriorityNum_5   = 5,
    SubGroupPriorityNum_6   = 6,
    SubGroupPriorityNum_7   = 7,
}IntCtrl_SubGroupPriorityNum;

typedef struct{
  IntCtrl_InterruptType         InterruptType;
  IntCtrl_GroupPriorityNum      GroupPriority;
  IntCtrl_SubGroupPriorityNum   SubGroupPriority;
}IntCtrl_InterConfig;


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
