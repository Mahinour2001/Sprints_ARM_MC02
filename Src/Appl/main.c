





int main(void)
{
    
	  
      NVIC_USER();
      PORT_USER();
      TIMERS_USER();
    
     
	while(1)
	{
      
		//Dio_FlipChannel(ChannelId);
      SetTimer_User_switches();
      Blink_Led();

		
	}
	
   return 0u;
}