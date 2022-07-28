/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  INT_CTRL_LCFG.c
 *    Component:  -
 *       Module:  -
 *
 *  Description:  
 *
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include  "Int_Port.h"
#include  "Port_cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES

 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 void Gpio_NotificationFn(DIO_ChannelType  Pin);
const  Port_ConfigTypes GPIO_ARR_INPUT[Port_arr_size]=
{
	/* CHANNELId        portpinlevel      pinDir          pinMode                     currentStrength        internalAttach   interuptlevel       */
	{ {PortF,PIN0}     , LOW          ,  INPUT    ,      Port_PinMode_DIO      ,        R2R             ,      PULL_UP       , FALLING_EDGE   , NULL     },
	{ {PortF,PIN4}     , LOW          ,  INPUT    ,      Port_PinMode_DIO      ,        R2R             ,      PULL_UP       , FALLING_EDGE   , NULL     },
	{ {PortF,PIN2}     , LOW          ,  OUTPUT    ,      Port_PinMode_DIO      ,        R2R            ,      PULL_UP       , FALLING_EDGE   , NULL     }


	
}; 
void Gpio_NotificationFn(DIO_ChannelType  Pin)
{

	

}
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

