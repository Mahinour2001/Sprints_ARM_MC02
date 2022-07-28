#include "Std_Types.h"
#include "Int_Port.h"
#include "Dio.h"
#include "Timers.h"

extern uint32 TIMER_ON=0x9896800;
extern uint32 TIMER_OFF=0x9896800;
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
       mode_pin4_statues == LOW;
      //while(mode_pin4_statues == HIGH);
      if(MODE == 1 || MODE ==2)
      {
         Gpt_StopTimer(GPT_16_32_bit_Timer_0);
      }
      if(timer_pin0_statues ==HIGH && MODE ==1)
      {
         TIMER_ON=TIMER_ON+0x9896800;

      }
      else if (timer_pin0_statues ==HIGH && MODE ==2)
      {
         TIMER_OFF=TIMER_OFF+0x9896800;

      }
      else if(MODE ==0)
      {
         //Gpt_StartTimer(GPT_16_32_bit_Timer_0,0x100);
         Timer_Flag=HIGH;

      }
     
   }

}