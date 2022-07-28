
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"
#include "Mcu_Hw.h"
#include "Dio.h"

static const uint32  Port_Base_Addresses[6] ={

     GPIO_Port_A_AHB_BaseAdd     ,   
     GPIO_Port_B_AHB_BaseAdd     ,
     GPIO_Port_C_AHB_BaseAdd     ,
     GPIO_Port_D_AHB_BaseAdd     ,
     GPIO_Port_E_AHB_BaseAdd     ,
     GPIO_Port_F_AHB_BaseAdd     
};



DIO_LevelType Dio_ReadChannel(Channel_Id_Types ChannelId)
{
    DIO_PortType Port_Id=  ChannelId.Port_num;
    DIO_ChannelType  PIN_Id= ChannelId.Chann_n;
    uint32 Port_Base_Add=Port_Base_Addresses[Port_Id];
    uint32 PIN_Bit_Mask_Off =(1<<PIN_Id) <<2 ;
    DIO_PortLevelType PIN_Level =GET_HWREG(Port_Base_Add,PIN_Bit_Mask_Off)>>PIN_Id;
    
    return PIN_Level;

}

void Dio_WriteChannel(Channel_Id_Types ChannelId,DIO_LevelType Level)
{
    DIO_PortType Port_Id=  ChannelId.Port_num;
    DIO_ChannelType  PIN_Id= ChannelId.Chann_n;
    uint32 Port_Base_Add=Port_Base_Addresses[Port_Id];
    uint32 PIN_Bit_Mask_Off =(1<<PIN_Id) <<2 ;
    GET_HWREG(Port_Base_Add,PIN_Bit_Mask_Off) = Level<<PIN_Id;

}

DIO_PortType Dio_ReadPort(DIO_PortType PortId)
{
    
    uint32 Port_Base_Add=Port_Base_Addresses[PortId];
    uint32 Bit_Mask_Off = 0xFF <<2 ;
    DIO_PortLevelType Port_Level =GET_HWREG(Port_Base_Add,Bit_Mask_Off);

    return Port_Level;

}

void Dio_WritePort(DIO_PortType PortId,DIO_PortLevelType Level)
{    
    uint32 Port_Base_Add=Port_Base_Addresses[PortId];
    uint32 Bit_Mask_Off = 0xFF <<2 ;
    GET_HWREG(Port_Base_Add,Bit_Mask_Off)=Level;
}

DIO_LevelType Dio_FlipChannel(Channel_Id_Types ChannelId)
{
    DIO_LevelType level;
    
    if(Dio_ReadChannel(ChannelId)==LOW)
    {
       // Dio_WriteChannel(ChannelId,HIGH);
        Dio_WritePort(ChannelId.Port_num, HIGH);
        DIO_LevelType level =HIGH;

    }
    else
    {
        //Dio_WriteChannel(ChannelId,LOW);
        Dio_WritePort(ChannelId.Port_num, LOW);
        DIO_LevelType level =LOW;

    }
    return level;


}


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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



/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

