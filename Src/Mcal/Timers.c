
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
#include "Timers.h"

static const uint32  GPT_Port_Base_Addresses[12] ={

     GPT_16_32_bit_Timer_0_BASEADDRESS          ,     
     GPT_16_32_bit_Timer_1_BASEADDRESS          ,
     GPT_16_32_bit_Timer_2_BASEADDRESS          ,
     GPT_16_32_bit_Timer_3_BASEADDRESS          ,
     GPT_16_32_bit_Timer_4_BASEADDRESS          ,
     GPT_16_32_bit_Timer_5_BASEADDRESS          ,
     GPT_32_64_bit_Wide_Timer_0_BASEADDRESS     ,
     GPT_32_64_bit_Wide_Timer_1_BASEADDRESS     ,
     GPT_32_64_bit_Wide_Timer_2_BASEADDRESS     ,
     GPT_32_64_bit_Wide_Timer_3_BASEADDRESS     ,
     GPT_32_64_bit_Wide_Timer_4_BASEADDRESS     ,
     GPT_32_64_bit_Wide_Timer_5_BASEADDRESS     
};




/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
GptNotification  ISR_ARRAY[12];

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

void Gpt_Init(const Gpt_ConfigType* ConfigPtr){

   int i=0;
  for(i;i<GPT_ARRAYSIZE;i++)
  {   
      Gpt_ChannelType  Channel =ConfigPtr[i].channel;
	    Gpt_ValueType  Value=ConfigPtr[i].channelTickFreq;
	    GptChannelTickValueMax  	ChannelTickMaxValue=ConfigPtr[i].channelTickMaxValue;
	    ChannelMode		ChannelMode=ConfigPtr[i].channelMode;
	    ISR_ARRAY[Channel]=ConfigPtr[i].gptNotification;

      SET_BIT(RCGCTIMER,Channel);
      //TODO STOP TIMER/
      Gpt_StopTimer(Channel);
      //TODO SET 16/32 OR 32/64 MODE IN GPTMCFG REGISTER/
      GPTMCFG(GPT_Port_Base_Addresses[Channel]) =0x0;
      //TODO SELECT ONE SHOT OR PERIODIC MODE FROM TAMR FEILD IN GPTMTAMR FOR TIMER A/
      if(ChannelMode==GPT_CH_MODE_PERIODIC)
      {
          GPTMTAMR(GPT_Port_Base_Addresses[Channel]) |=0x2;


      }
      else if (ChannelMode==GPT_CH_MODE_ONESHOT)
      {
          GPTMTAMR(GPT_Port_Base_Addresses[Channel]) |=0x1;

      }
      //TODO SELECT ONE SHOT OR PERIODIC MODE FROM TBMR FEILD IN GPTMTBMR FOR TIMER B/
      //TODO SELECT COUNT UP OR DOWN FROM TACDIR FEILD ON GPTMTAMR FOR TIMER A/
    
      CLR_BIT(GPTMTAMR(GPT_Port_Base_Addresses[Channel]),TACDIR);
      //TODO SELECT COUNT UP OR DOWN FROM TBCDIR FEILD ON GPTMTBMR FOR TIMER B/
      //TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTAILR/
      //Enable interupt
      if (ISR_ARRAY[Channel] != NULL)
      {
         Gpt_EnableNotification(Channel);

      }
     
      //TODO LOAD INITIAL VALUE FOR TIMER IN GPTMTBILR/
      Gpt_StartTimer (Channel,Value);
      
  }
//   #if GPT_PREDEF_TIMER_1US_16BIT_STATUS == Enable
// 	gptBaseAddress =GPT_Port_Base_Addresses[Channel];
// 	GPTMCTL(gptBaseAddress) =	0;
// 	GPTMCFG(gptBaseAddress) = 0x4;
// 	/* counting up */
// 	GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
// 	/* continuous mode*/
// 	GPTMTAMR(gptBaseAddress) |= 0x2;
// 	/* Disablling interupt notifation */
// 	Gpt_DisableNotification(PREDEF_TIMER);	
	
// 	Gpt_StartTimer (Channel,Value);
		
// #endif
	
// #if GPT_PREDEF_TIMER_1US_24BIT_STATUS == Enable
// 	gptBaseAddress = GPT_Port_Base_Addresses[Channel];
// 	GPTMCTL(gptBaseAddress) =	0;
// 	GPTMCFG(gptBaseAddress) = 0x4;
// 	/* counting up */
// 	GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
// 	/* continuous mode*/
// 	GPTMTAMR(gptBaseAddress) |= 0x2; 
// 	/* Disablling interupt notifation */
// 	Gpt_DisableNotification(Channel);	
	
// 	Gpt_StartTimer (Channel,Value);
	
// #endif

// #if GPT_PREDEF_TIMER_1US_32BIT_STATUS == Enable
// 	gptBaseAddress = GPT_Port_Base_Addresses[Channel];
// 	GPTMCTL(gptBaseAddress) =	0;
// 	GPTMCFG(gptBaseAddress) = 0x4;
// 	/* counting up */
// 	GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);	
// 	/* continuous mode*/
// 	GPTMTAMR(gptBaseAddress) |= 0x2; 
// 	/* Disablling interupt notifation */
// 	Gpt_DisableNotification(Channel);
	
// 	Gpt_StartTimer (Channel,Value);
	
// #endif
		
// #if GPT_PREDEF_TIMER_100US_32BIT_STATUS == Enable
// 	gptBaseAddress = GPT_Port_Base_Addresses[Channel];
// 	GPTMCTL(gptBaseAddress) =	0;
// 	GPTMCFG(gptBaseAddress) = 0x4;
// 	/* counting up */
// 	GPTMTAMR(gptBaseAddress) |= (1<<TACDIR);
// 		/* continuous mode*/
// 	GPTMTAMR(gptBaseAddress) |= 0x2;
// 	/* Disablling interupt notifation */
// 	Gpt_DisableNotification(Channel);
	
// 	Gpt_StartTimer (Channel,Value);
	
// #endif	

}

void Gpt_DisableNotification (Gpt_ChannelType Channel){

  //TODO DISABLE TIME OUT INTERRUPT FOR TIMER A BY CLEARING TATOIM BIT ON GPTMIMR REGISTER/

  //TODO DISABLE TIME OUT INTERRUPT FOR TIMER B BY CLEARING TBTOIM BIT ON GPTMIMR REGISTER*/
  CLR_BIT(GPTMIMR(GPT_Port_Base_Addresses[Channel]),TATOIM);

}
void Gpt_EnableNotification (Gpt_ChannelType Channel){

  //TODO ENABLE TIME OUT INTERRUPT FOR TIMER A BY SETTING TATOIM BIT ON GPTMIMR REGISTER/
  //TODO ENABLE TIME OUT INTERRUPT FOR TIMER B BY SETTING TBTOIM BIT ON GPTMIMR REGISTER/
  SET_BIT(GPTMIMR(GPT_Port_Base_Addresses[Channel]),TATOIM);

}

void Gpt_StartTimer (Gpt_ChannelType Channel,Gpt_ValueType Value){

  //TODO LOAD VALUE OF TIMER IN LOAD REGISTER
  GPTMTAILR(GPT_Port_Base_Addresses[Channel]) = Value ;

  //TODO START TIMER BY WRITING 1 ON TAEN FEILD IN GPTMCTL REGISTER/
   SET_BIT(GPTMCTL(GPT_Port_Base_Addresses[Channel]),TAEN);
   
  //TODO START TIMER BY WRITING 1 ON TBEN FEILD IN GPTMCTL REGISTER/
  //SET_BIT(GPTMCTL(GPT_Port_Base_Addresses[Channel]),TBEN);

  



}

void Gpt_StopTimer (Gpt_ChannelType Channel){

  //TODO STOP TIMER BY WRITING 0 ON TAEN FEILD IN GPTMCTL REGISTER/
   CLR_BIT(GPTMCTL(GPT_Port_Base_Addresses[Channel]),TAEN);
  //TODO STOP TIMER BY WRITING 0 ON TBEN FEILD IN GPTMCTL REGISTER/
   //CLR_BIT(GPTMCTL(GPT_Port_Base_Addresses[Channel]),TBEN);
   SET_BIT(GPTMICR(GPT_Port_Base_Addresses[GPT_16_32_bit_Timer_0]),0);

}
void Gpt_Notification_Channel ( void );

Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel){

  //TODO GET THE VALUE OF THE CURRENT TIMER/
  //TODO SUBTRACT CURRENT VALUE MAX REGISTER CAPACITY/
  //TODO GET THE VALUE OF PRESCALER TIMER/
  //TODO SUBTRACT PRESCALER VALUE FROM PRESCALER DIVISOR/
  //TODO MULTIPLY THE VALUE OF CURRENT TIMER BY PRESCALER DIVISER/
  //TODO ADD BOTH NUMBERS AND RETURN/
  return (0xFFFFFFFF)-(Gpt_GetTimeRemaining(Channel));


}

Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel){
   
  //TODO GET THE VALUE OF THE CURRENT TIMER/
  return GPTMTAV(GPT_Port_Base_Addresses[Channel]);
  //TODO GET THE VALUE OF PRESCALER TIMER/
  //TODO MULTIPLY THE VALUE OF CURRENT TIMER BY PRESCALER DIVISER/
  //TODO ADD BOTH NUMBERS AND RETURN/

}
/**********************************************************************************************************************
 * ISR
 *********************************************************************************************************************/
 void TIMER0A_Handler(void)
 {
    
    if (ISR_ARRAY[GPT_16_32_bit_Timer_0] !=NULL)
    {
       GptNotification  GPT_TIMER0A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_0];
      //  SET_BIT(GPTMICR(GPT_Port_Base_Addresses[GPT_16_32_bit_Timer_0]),0);
      GPT_TIMER0A_Handler();
    }
   

  }
  void TIMER1A_Handler(void)
  {
    if (ISR_ARRAY[GPT_16_32_bit_Timer_1] !=NULL)
    {
       GptNotification  GPT_TIMER1A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_1];
      GPT_TIMER1A_Handler();
    }

  }
  void TIMER2A_Handler(void)
  {
     if (ISR_ARRAY[GPT_16_32_bit_Timer_2] !=NULL)
    {
       GptNotification  GPT_TIMER2A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_2];
      GPT_TIMER2A_Handler();
    }

  }
  void TIMER3A_Handler(void)
  {
    if (ISR_ARRAY[GPT_16_32_bit_Timer_3] !=NULL)
    {
       GptNotification  GPT_TIMER3A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_3];
      GPT_TIMER3A_Handler();
    }


  }
  void TIMER4A_Handler(void)
  {
    if (ISR_ARRAY[GPT_16_32_bit_Timer_4] != NULL)
    {
       GptNotification  GPT_TIMER4A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_4];
      GPT_TIMER4A_Handler();
    }

  }
  void TIMER5A_Handler(void)
  {
    if (ISR_ARRAY[GPT_16_32_bit_Timer_5] != NULL)
    {
       GptNotification  GPT_TIMER5A_Handler =  ISR_ARRAY[GPT_16_32_bit_Timer_5];
      GPT_TIMER5A_Handler();
    }


  }







// GPTMCFG :
//  VALUE                            FUNCTION
//   0x0            //For a 16/32-bit timer, this value selects the 32-bit timer configuration.
                    //For a 32/64-bit wide timer, this value selects the 64-bit timer configuration

//   0x1              For a 16/32-bit timer, this value selects the 32-bit real-time clock (RTC) counter configuration.
                    //For a 32/64-bit wide timer, this value selects the 64-bit real-time clock (RTC) counter configuration.                

//   0x4              For a 16/32-bit timer, this value selects the 16-bit timerconfiguration.
                    //For a 32/64-bit wide timer, this value selects the 32-bit timer configuration      


//GPTMTAMR : TIMER_A_MODE
// FOR SELECTION OF ONE SHOT MODE MUST WRITE 0X1 ON TAMR (BIT 0:1 ) ON GPTMTAMR and WRITE 0x2 Periodic Timer mode
// FOR SELECTION OF TIMER UP OR DOWN FROM TACDIR ON  GPTMTAMR
//   VALUE           FUNCTION
//   -> 0       The timer counts down.
//   -> 1       The timer counts up. When counting up, the timer starts from a value of 0x0

//GPTMTBMR :TIMER_B_MODE
//// FOR SELECTION OF ONE SHOT MODE MUST WRITE 0X1 ON TBMR (BIT 0:1 ) ON GPTMTBMR
//   FOR SELECTION OF TIMER UP OR DOWN FROM TBCDIR ON  GPTMTBMR
//   VALUE           FUNCTION
//   -> 0       The timer counts down.
//   -> 1       The timer counts up. When counting up, the timer starts from a value of 0x0

//GPTMCTL :CONTROL FOR TIMER_A AND TIMER_B
// TAEN -> TIMER_A ENABLE WRITE 1 - DISABLE WRITE 0
// TBEN -> TIMER_B ENABLE WRITE 1 - DISABLE WRITE 0

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

