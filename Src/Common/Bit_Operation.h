/****************************************************************************/
/** Copyright (c) 2020 Mahmoud Kassify. All Rights Reserved. 			   **/
/****************************************************************************/
#ifndef _H_BIT_OPERATION_
#define _H_BIT_OPERATION_

/*---------------------------------------------------------*/
/*- INCLUDES ----------------------------------------------*/
/*---------------------------------------------------------*/
#include "Platform_Types.h" 
#include "Platform_Defines.h" 
/*---------------------------------------------------------*/
/*- MACROS ------------------------------------------------*/
/*---------------------------------------------------------*/

#define SET_BIT(var, bit_num)                               (var) |= (1UL << (bit_num))

#define CLR_BIT(var, bit_num)                               (var) &= (~(1UL << (bit_num)))

#define TOG_BIT(var, bit_num)                               (var) ^= (1UL << (bit_num))

#define GET_BIT_STATUS(var, bit_num)                        (0UL != ((var) & (1UL << (bit_num))))

#define WRITE_BITBAND(alias_base, base_add, add, bit_num)   (alias_base +( 32 * (add - base_add) ) + bit_num * 4)  

#define PERIPHERAL_BITBAND(add, bit_num)                    WRITE_BITBAND(PERIPHERAL_BITBAND_ALIAS, PERIPHERAL_BITBAND_REGION, add, bit_num)  

#define RAM_BITBAND(add, bit_num)                           WRITE_BITBAND(RAM_BITBAND_ALIAS, RAM_BITBAND_REGION, add, bit_num)  

#endif /*_H_BIT_OPERATION_*/

