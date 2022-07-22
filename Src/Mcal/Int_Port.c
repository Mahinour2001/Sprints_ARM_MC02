
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Int_Port.c
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
#include "Int_Port.h"
#include "Port_cfg.h"



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
* \Syntax          : void Set_PortPin_Mode(Channel_Id_Types PortPin , uint32 Mode , PortPinDirection direction, DIO_LevelType level)                                     
* \Description     : Set Mode which is dio or analogue or from pcm                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr [array from configuration containing port , pin , direction , current , level , mode , attach , interuptlevel ]                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

 void Set_PortPin_Mode(Channel_Id_Types PortPin , uint32 Mode , PortPinDirection direction, DIO_LevelType level)
 {
     DIO_PortType Port=  PortPin.Port_num;
     DIO_ChannelType  Pin= PortPin.Chann_n;

     if (Mode == Port_PinMode_DIO)
     {
         CLR_BIT(GPIOAFSEL(Port_Base_Addresses[Port]),Pin) ;
         GPIODEN(Port_Base_Addresses[Port]) |= (1<<Pin) ;
         
         if(direction==OUTPUT)
         {
              Dio_WriteChannel(PortPin,level);

         }
     }
     
     else if (Mode == ANALOG)
     {
         GPIOAFSEL(Port_Base_Addresses[Port]) |= (0<<Pin) ;
         CLR_BIT( GPIODEN(Port_Base_Addresses[Port]),Pin) ;
         GPIOAMSEL(Port_Base_Addresses[Port]) |= (1<<Pin) ;
         
     }
     else
     {
         GPIOAFSEL(Port_Base_Addresses[Port]) |= (1<<Pin) ;
         GPIODEN(Port_Base_Addresses[Port]) |= (1<<Pin) ;
         GPIOPCTL(Port_Base_Addresses[Port]) |= (Mode<<Pin*4) ;

     }

 }
 /******************************************************************************
* \Syntax          : void Set_PortPin_Direction(Channel_Id_Types PortPin , PortPinDirection direction)                                     
* \Description     : Set direction which is input or output                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr [array from configuration containing port , pin , direction , current , level , mode , attach , interuptlevel ]                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

 void Set_PortPin_Direction(Channel_Id_Types PortPin , PortPinDirection direction)
 {
     DIO_PortType Port=  PortPin.Port_num;
     DIO_ChannelType  Pin= PortPin.Chann_n;
     if (direction == INPUT)
      {
          CLR_BIT(GPIODIR(Port_Base_Addresses[Port]),Pin) ;

      }
      else
      {
           GPIODIR(Port_Base_Addresses[Port]) |= (1<<Pin);

      }


 }
 /******************************************************************************
* \Syntax          : Set_PortPin_Current(Channel_Id_Types PortPin , PortPinDirection current)                                    
* \Description     : Set Current which is R2R 2mA or R4R 4mA or R8R 8mA                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr [array from configuration containing port , pin , direction , current , level , mode , attach , interuptlevel ]                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

 void Set_PortPin_Current(Channel_Id_Types PortPin , PortPinDirection current)
 {
     DIO_PortType Port=  PortPin.Port_num;
     DIO_ChannelType  Pin= PortPin.Chann_n;

     if (current==R2R)
    {
        GPIODR2R(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (current==R4R)
    {
        GPIODR4R(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (current==R8R)
    {
        GPIODR8R(Port_Base_Addresses[Port]) |= (1<<Pin);

    }


 }
  /******************************************************************************
* \Syntax          : Set_PortPin_Attach(Channel_Id_Types PortPin , PortPinDirection attach)                                   
* \Description     : Set Attach which is R2R 2mA or R4R 4mA or R8R 8mA                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr [array from configuration containing port , pin , direction , current , level , mode , attach , interuptlevel ]                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

 void Set_PortPin_Attach(Channel_Id_Types PortPin , PortPinDirection attach)
 {
     DIO_PortType Port=  PortPin.Port_num;
     DIO_ChannelType  Pin= PortPin.Chann_n;

     if (attach == PULL_UP)
    {
        GPIOPUR(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (attach == PULL_DOWN)
    {
        GPIOPDR(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (attach == OPEN_DRAIN)
    {
        GPIOODR(Port_Base_Addresses[Port]) |= (1<<Pin);

    }


 }


/******************************************************************************
* \Syntax          : void Port_init(void)                                      
* \Description     : Port intialization for port , pin , direction , current , level , mode , attach , interuptlevel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr [array from configuration containing port , pin , direction , current , level , mode , attach , interuptlevel ]                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_ConfigTypes* ConfigPtr){
    
    for(int i=0;i<Port_arr_size;i++)
    {
        Channel_Id_Types  channel =ConfigPtr[i].CHANNEL;
        DIO_PortType Port =  ConfigPtr[i].CHANNEL.Port_num;
        DIO_ChannelType  Pin = ConfigPtr[i].CHANNEL.Chann_n;
        PortPinDirection direction = ConfigPtr[i].DIRECTION;
        PortPinOutputCurrent  current = ConfigPtr[i].CURRENT;
        uint32 mode =ConfigPtr[i].Mode ;
        PortPinInternalAttach  attach =ConfigPtr[i].ATTACH;
        DIO_LevelType level =ConfigPtr[i].VALUE;
        PortPin_interuptlevel interrupt = ConfigPtr[i].INTERRUPT;


        //    /TODO ENABLE AHB ON GPIOHBCTL REGISTER/

        GPIOHBCTL |=(1<<Port);
        
        ///TODO ENABLE CLOCK ON RCGCGPIO REGISTER/
        RCGCGPIO |=(1<<Port);
        
//    /TODO SET PIN DIRECTION ON GPIODIR REGISTER/
       Set_PortPin_Direction(channel,direction);

//    /TODO ENABLE DIGITAL I/O ON GPIODEN REGISTER/ >     
//    /TODO MAKE CONDITION IF FUNCTION NOT EQUAL ZERO ENABLE GPIOAFSEL/  >
//    /TODO MAKE CONDITION IF FUNCTION EQUAL ANALOG ENABLE GPIOAFSEL AND DIABLE GPIODENS/  >
//    /TODO SET ALTERNAT FUNCTION ON GPIOPCTL AND GPIOAFSEL REGISTERS/ >

     Set_PortPin_Mode(channel,mode,direction,level);

//    /TODO SET PIN CURRENT ON GPIODR2R , GPIODR4R OR GPIODR8R REGISTERS/

      Set_PortPin_Current(channel,current);

//    /TODO SET PIN INTERNAL ATTACHMENT ON GPIOPUR , GPIODPDR OR GPIOODP REGISTER/

      Set_PortPin_Attach(channel,attach);
    
   
//    /TODO ENABLE INTERRUPTS ON GPIOIM , GPIOIS , GPIOIBE AND GPIOLCR REGISTERS/
      // GPIOIM   //SET allows interrupts that are generated by the corresponding pin to be sent to the interrupt controller on the combined interrupt signal.
	  // GPIOIS   // Setting a bit in the GPIOIS register configures the corresponding pin to detect levels, while clearing a bit configures the corresponding pin to detect edges, RESET IS CLEARED (EDGE)
	  // GPIOIBE  //register allows both edges to cause interrupts
	  // GPIOIEV  //Setting a bit in the GPIOIEV register configures the corresponding pin to detect rising edges or high levels 
                  //Clearing a bit configures the pin to detect falling edges or low levels depends on GPIOIS REG
	  // GPIORIS  //For edge-detect interrupts, this bit is cleared by writing a 1 to the corresponding bit in the GPIOICR register
	  // GPIOICR    

      // TODO: Mask the corresponding port by clearing the IME field in the GPIOIM register.
      CLR_BIT(GPIOIM(Port_Base_Addresses[Port]),Pin) ;

      // TODO: Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.
      if (interrupt == NO_INTERUPT)
    {
       CLR_BIT(GPIOIM(Port_Base_Addresses[Port]),Pin) ;

    }
    else if (interrupt == FALLING_EDGE)
    {
        CLR_BIT(GPIOIS(Port_Base_Addresses[Port]),Pin) ;
        CLR_BIT(GPIOIEV(Port_Base_Addresses[Port]),Pin) ;
        

    }
    else if (interrupt == RISING_EDGE)
    {
        CLR_BIT(GPIOIS(Port_Base_Addresses[Port]),Pin) ;
        GPIOIEV(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (interrupt == LOW_LEVEL)
    {
        GPIOIS(Port_Base_Addresses[Port]) |= (1<<Pin);
        CLR_BIT(GPIOIEV(Port_Base_Addresses[Port]),Pin) ;

    }
    else if (interrupt == HIGH_LEVEL)
    {
        GPIOIS(Port_Base_Addresses[Port]) |= (1<<Pin);
        GPIOIEV(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    else if (interrupt == BOTH_INTERUPTS)
    {
        CLR_BIT(GPIOIS(Port_Base_Addresses[Port]),Pin) ;
        GPIOIBE(Port_Base_Addresses[Port]) |= (1<<Pin);

    }

      // TODO: Clear the GPIORIS register.
      SET_BIT(GPIOICR(Port_Base_Addresses[Port]),Pin) ;


      // TODO: Unmask the port by setting the IME field in the GPIOIM register.
      GPIOIM(Port_Base_Addresses[Port]) |= (1<<Pin);

    }
    

}




/**********************************************************************************************************************
 *  END OF FILE: Int_Port.c
 *********************************************************************************************************************/

