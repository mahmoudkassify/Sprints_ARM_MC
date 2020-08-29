/****************************************************************************/
/** Copyright (c) 2020 Mahmoud Kassify. All Rights Reserved. 			   **/
/****************************************************************************/

/*---------------------------------------------------------*/
/*- INCLUDES ----------------------------------------------*/
/*---------------------------------------------------------*/
#include <stdint.h>
/*---------------------------------------------------------*/
/*- LOCAL MACROS ------------------------------------------*/
/*---------------------------------------------------------*/
#define COMPILER_ATTRIBUTE              (1)                                         /** @brief: Enable Compiler arrtribue or not*/

#if defined(COMPILER_ATTRIBUTE) && (COMPILER_ATTRIBUTE == 1)
    #define SPRINTS_SECTION             __attribute__((section(".sprints")))        /** @brief: Compiler attribute puts the variable in .sprints section*/    
#else
    #define SPRINTS_SECTION
#endif

#define ARR_SIZE                        (6)                                        /** @brief: The size of the global array*/
/*-***********************************************************/
/*- GLOBAL VARIABLES ----------------------------------------*/
/*-***********************************************************/
SPRINTS_SECTION uint8_t     gu8MainArray[ARR_SIZE] = {1};                          /** @brief: Global variable array should be declared in a defined section in Flash*/
SPRINTS_SECTION uint32_t    gu32MainVar = 0;                                        /** @brief: Global variable should be declared in a defined section in Flash*/

uint8_t gu8MainTempVar = 0;                                                         /** @brief: Global variable should be declared in the default place*/ 
/*-***********************************************************/
/*- APIs IMPLEMENTATION -------------------------------------*/
/*-***********************************************************/

uint32_t main(void)
{    
    if(1 == gu8MainArray[0])
    {
        gu8MainTempVar = 0;
    }
    else
    {
        gu8MainTempVar = 4;
    }

    for(;;);
    
    return 0;
}
