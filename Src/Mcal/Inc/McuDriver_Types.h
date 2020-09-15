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
    Mcu_Clock_Gate_WD0      = 00U,
    Mcu_Clock_Gate_WD1      = 01U,
	
    Mcu_Clock_Gate_GP0      = 10U,
    Mcu_Clock_Gate_GP1      = 11U,
    Mcu_Clock_Gate_GP2      = 12U,
    Mcu_Clock_Gate_GP3      = 13U,
    Mcu_Clock_Gate_GP4      = 14U,
    Mcu_Clock_Gate_GP5      = 15U,
	
    Mcu_Clock_Gate_GPIOA    = 20U,
    Mcu_Clock_Gate_GPIOB    = 21U,
    Mcu_Clock_Gate_GPIOC    = 22U,
    Mcu_Clock_Gate_GPIOD    = 23U,
    Mcu_Clock_Gate_GPIOE    = 24U,
    Mcu_Clock_Gate_GPIOF    = 25U,
	
    Mcu_Clock_Gate_DMA		= 30U,

    Mcu_Clock_Gate_HIB		= 50U,

    Mcu_Clock_Gate_UART0	= 60U,
    Mcu_Clock_Gate_UART1	= 61U,
    Mcu_Clock_Gate_UART2	= 62U,
    Mcu_Clock_Gate_UART3	= 63U,
    Mcu_Clock_Gate_UART4	= 60U,
    Mcu_Clock_Gate_UART5	= 65U,
    Mcu_Clock_Gate_UART6	= 66U,
    Mcu_Clock_Gate_UART7	= 67U,

    Mcu_Clock_Gate_SSI0		= 70U,
    Mcu_Clock_Gate_SSI1		= 71U,
    Mcu_Clock_Gate_SSI2		= 72U,
    Mcu_Clock_Gate_SSI3		= 73U,

    Mcu_Clock_Gate_I2C0		= 80U,
    Mcu_Clock_Gate_I2C1		= 81U,
    Mcu_Clock_Gate_I2C2		= 82U,
    Mcu_Clock_Gate_I2C3		= 83U,

    Mcu_Clock_Gate_USB		= 100U,

    Mcu_Clock_Gate_CAN0		= 130U,
    Mcu_Clock_Gate_CAN1		= 131U,

    Mcu_Clock_Gate_ADC0		= 140U,
    Mcu_Clock_Gate_ADC1		= 141U,

    Mcu_Clock_Gate_ACMP		= 150U,
	
	Mcu_Clock_Gate_PWM0		= 160U,
	Mcu_Clock_Gate_PWM1		= 161U,

	Mcu_Clock_Gate_QEI0		= 170U,
	Mcu_Clock_Gate_QEI1		= 171U,

	Mcu_Clock_Gate_EEPROM	= 220U,
	
	Mcu_Clock_Gate_WTIMER0	= 230U,
	Mcu_Clock_Gate_WTIMER1	= 231U,
	Mcu_Clock_Gate_WTIMER2	= 232U,
	Mcu_Clock_Gate_WTIMER3	= 233U,
	Mcu_Clock_Gate_WTIMER4	= 234U,
	Mcu_Clock_Gate_WTIMER5	= 235U,
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
