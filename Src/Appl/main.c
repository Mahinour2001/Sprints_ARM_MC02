
int main(void)
{
    
	  
      NVIC_USER();
      PORT_USER();
      TIMERS_USER();
      
     
	while(1)
	{
      //Dio_WritePort(PortB,GPTMTAILR(GPT_16_32_bit_Timer_0_BASEADDRESS));
      SetTimer_User_switches();
      Blink_Led();

		
	}
	
   return 0u;
}