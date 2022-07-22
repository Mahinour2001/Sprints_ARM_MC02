#include "Std_Types.h"
#include "Int_Port.h"
#include "Dio.h"

int main(void)
{
	   //Channel_Id_Types ChannelId ={PortA,PIN0};
     //Dio_FlipChannel( ChannelId);
    Port_Init(GPIO_ARR_INPUT);
	// INTCTRL_init();
	// Dio_ReadChannel(Channel_Id_Types ChannelId);

    // Dio_WriteChannel(Channel_Id_Types ChannelId,DIO_LevelType Level);

    // Dio_ReadPort(DIO_PortType PortId);
    
    //  Dio_WritePort(DIO_PortType PortId,DIO_PortLevelType Level);
     
    
	while(1)
	{
		
		
	}
	
   return 0u;
}