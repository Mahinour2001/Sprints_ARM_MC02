
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Int_Ctrl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable and Disable Navic Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"
#include "Mcu_Hw.h"
#include "Int_Ctrl.h"
#include "Int_Ctrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define NVIC_bxxx   0x4
#define NVIC_bxxy   0x5
#define NVIC_bxyy   0x6
#define NVIC_byyy   0x7
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


/******************************************************************************
* \Syntax          : void INTCTRL_init(void)                                      
* \Description     : initialize Nvic Module by parsing the Configuration 
*                    into Nvic registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void INTCTRL_init(void)
{
	//PRIMASK and FAULTMASK (core registers) must be cleared for delay interupt handler purposes
	ENABLE_INT_PRIMASK()
    ENABLE_INT_FH()

	INT_Types int_num ;
	uint32 Grp_Pri,SubGrp_Pri;
	uint32 Pri_RegNum,Pri_RegOffset,Int_PriRegNum,IntPri_BitOffset,Pri_GroupField;
    uint32 En_RegNum,En_RegOffset,IntEn_BitOffset;
	uint32 i ;
	
	APINT->R |=VECTKEY_num<<16 |(PRI_REG<<8);
	// APINT->B.VECTKEY=VECTKEY_num;
	// APINT->B.PRIGROUP=PRI_REG;
     /*TODO Configure Grouping\SubGrouping System in APINT register in SCB */
	for(i=0;i<arr_size;i++)
	{
		 int_num=NVIC_ARR_INPUT[i].Int_num;
		 Grp_Pri=NVIC_ARR_INPUT[i].group_priority;
		 SubGrp_Pri=NVIC_ARR_INPUT[i].sub_priority;

		Pri_RegNum    = (uint32)(int_num/4);
        Pri_RegOffset = Pri_RegNum*4;
        Int_PriRegNum = int_num%4;
        IntPri_BitOffset = 5*(Int_PriRegNum+1)+3*Int_PriRegNum;

		#if (PRI_REG==NVIC_bxxx)
            Pri_GroupField=Grp_Pri;
        #elif (PRI_REG==NVIC_bxxy)
            Pri_GroupField=(Grp_Pri<<1&0x6)|(SubGrp_Pri&0x1);
        #elif (PRI_REG==NVIC_bxyy)
            Pri_GroupField=(Grp_Pri<<2&0x4)|(SubGrp_Pri&0x3);            
        #elif(PRI_REG==NVIC_byyy)
            Pri_GroupField=SubGrp_Pri;
		 #else 
            #error
        #endif

		GET_HWREG(PRIx_NVIC,Pri_RegOffset) |= Pri_GroupField << IntPri_BitOffset;
    
        /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers*/
        En_RegNum = (uint32)(int_num/32);
        En_RegOffset = En_RegNum*4;
        IntEn_BitOffset = int_num%32;

        GET_HWREG(EN0,En_RegOffset) |= (1<<IntEn_BitOffset);

	}

}
    

/**********************************************************************************************************************
 *  END OF FILE: Int_Ctrl.c
 *********************************************************************************************************************/

