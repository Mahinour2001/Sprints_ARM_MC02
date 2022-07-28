#include "Std_Types.h"
#include "Int_Port.h"
#include "Dio.h"
#include "Timers.h"

extern uint32 TIMER_ON=0xF42400;
extern uint32 TIMER_OFF=0xF42400;
extern uint32 MODE =0 ;

void SetTimer_User_switches(void)
{
   DIO_PortLevelType switch_statues ;
   DIO_PortLevelType timer_pin0_statues ;
   DIO_PortLevelType mode_pin4_statues ;
   switch_statues=Dio_ReadPort(PortF);
   timer_pin0_statues=GET_BIT(switch_statues,PIN0)  ;
   mode_pin4_statues=GET_BIT(switch_statues,PIN4)  ;

   if(mode_pin4_statues == HIGH)
   {
       MODE++;
       MODE=MODE%3;
       Dio_WritePort(PortF,0x00);
       mode_pin4_statues = LOW;
      //while(mode_pin4_statues == HIGH);
   }
   
     if(timer_pin0_statues ==HIGH)
      {
           Dio_WritePort(PortF,0x00);
          timer_pin0_statues = LOW;

      
      if( MODE ==1)
      {
         TIMER_ON=TIMER_ON+(0xF42400);

      }
      else if ( MODE ==2)
      {
         TIMER_OFF=TIMER_OFF+0xF42400;

      }
      
      }
      if(MODE == 1 || MODE ==2)
      {
         Gpt_StopTimer(GPT_16_32_bit_Timer_0);
      }
      else
      {
         Timer_Flag=HIGH;

      }
   

}