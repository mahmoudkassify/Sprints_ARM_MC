/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   	:8;
    uint32          	:3;
    uint32 RETBASE  	:1;
    uint32 VECPEND  	:7;
    uint32          	:2;
    uint32 ISRPEND  	:1;
    uint32 ISRPRE   	:1;
    uint32          	:1;
    uint32 PENDSTCLR	:1;
    uint32 PENDSTSET	:1;
    uint32 UNPENDSV 	:1;
    uint32 PENDSV   	:1;
    uint32          	:2;
    uint32 NMISET   	:1; 
}INTCTRL_BF;

typedef union 
{
    uint32 Register;
    INTCTRL_BF BitAcess;
}INTCTRL_Tag;

typedef struct
{
  uint32    ENINT[5U];       
  uint32    RSV0[27U];
  uint32    DISINT[5U];       
  uint32    RSV1[27U];
  uint32    SETPEN[5U];       
  uint32    RSV2[27U];
  uint32    CLRPEN[5U];       
  uint32    RSV3[27U];
  uint32    ISACTPRI[5U];       
  uint32    RSV4[59U];
  uint8     SETPRI[140U];       
  uint32    RSV5[669U];
  uint32    SWTRIG;           
}NVIC_Type;

typedef struct
{
   uint8    SYSPRI_SET[12U];
}SYSPRI_Type;
typedef struct
{
   uint32   SysCtrlHandler;
}SYSHNDCTRL_Type;

typedef struct
{
    uint32 RESC_EXT     : 1;
    uint32 RESC_POR     : 1;
    uint32 RESC_BOR     : 1;
    uint32 RESC_WDT0    : 1;
    uint32 RESC_SW      : 1;
    uint32 RESC_WDT1    : 1;
    uint32              : 10;
    uint32 RESC_MOSCFAIL: 1;
    uint32              : 15;
}RESC_BF;

typedef union 
{
    uint32 Register;
    RESC_BF BitAcess;
}RESC_Type;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_SYS_CNTRL_BASE_ADDRESS         (0x400FE000)
#define CORTEXM4_PERI_BASE_ADDRESS				(0xE000E000)
#define CORTEXM4_PERI_INTCTRL_OFFSET			(0xD04)
#define CORTEXM4_PERI_APINT_OFFSET				(0xD0C)
#define CORTEXM4_PERI_SYSPRI_OFFSET             (0xD18)
#define CORTEXM4_PERI_SYSHNDCTRL_OFFSET         (0xD24)
#define CORTEXM4_SYS_CNTRL_RESC_OFFSET          (0x05C)

#define CORTEXM4_PERI_NVIC_OFFSET				(0x100)

#define CORTEXM4_APINT_VECTKEY_Pos              (16U)
#define CORTEXM4_APINT_VECTKEY_Msk              (0xFFFFUL << CORTEXM4_APINT_VECTKEY_Pos)

#define CORTEXM4_APINT_VECTKEY_VAL              (0x05FAul)
#define CORTEXM4_APINT_VECTKEY                  ((uint32)(CORTEXM4_APINT_VECTKEY_VAL << CORTEXM4_APINT_VECTKEY_Pos))

#define CORTEXM4_APINT_ENDIANESS_Pos            (15U)
#define CORTEXM4_APINT_ENDIANESS_Msk            (1UL << CORTEXM4_APINT_ENDIANESS_Pos)

#define CORTEXM4_APINT_PRIGROUP_Pos             (8U)
#define CORTEXM4_APINT_PRIGROUP_Msk             (7UL << CORTEXM4_APINT_PRIGROUP_Pos)

#define CORTEXM4_APINT_SYSRESETREQ_Pos          (2U)
#define CORTEXM4_APINT_SYSRESETREQ_Msk          (1UL << CORTEXM4_APINT_SYSRESETREQ_Pos)

#define CORTEXM4_APINT_VECTCLRACTIVE_Pos        (1U)
#define CORTEXM4_APINT_VECTCLRACTIVE_Msk        (1UL << CORTEXM4_APINT_VECTCLRACTIVE_Pos)

#define CORTEXM4_APINT_VECTRESET_Pos            (0U)
#define CORTEXM4_APINT_VECTRESET_Msk            (1UL << CORTEXM4_APINT_VECTRESET_Pos)

#define CORTEXM4_APINT_SW_RESET_Pos             (0U)
#define CORTEXM4_APINT_SW_RESET_Msk             (7UL << CORTEXM4_APINT_SW_RESET_Pos)

#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + CORTEXM4_PERI_APINT_OFFSET))
#define INTCTRL                                ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + CORTEXM4_PERI_INTCTRL_OFFSET))
#define NVIC                                   ((volatile NVIC_Type*)(CORTEXM4_PERI_BASE_ADDRESS + CORTEXM4_PERI_NVIC_OFFSET))
#define SYSPRI                                 ((volatile SYSPRI_Type*)(CORTEXM4_PERI_BASE_ADDRESS + CORTEXM4_PERI_SYSPRI_OFFSET))
#define SYSHNDCTRL                             ((volatile SYSHNDCTRL_Type*)(CORTEXM4_PERI_BASE_ADDRESS + CORTEXM4_PERI_SYSHNDCTRL_OFFSET))

#define RESC                                   ((volatile RESC_Type*)(CORTEXM4_SYS_CNTRL_BASE_ADDRESS + CORTEXM4_SYS_CNTRL_RESC_OFFSET))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
