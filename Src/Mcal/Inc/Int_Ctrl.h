/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Int_Ctrl.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef INT_CTRL_H
#define INT_CTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	
 GPIO_Port_A = 0                                     ,
 GPIO_Port_B                                         ,
 GPIO_Port_C                                         ,
 GPIO_Port_D                                         ,
 GPIO_Port_E                                         ,
 UART0                                               ,
 UART1                                               ,
 SSI0                                                ,
 I2C0                                                ,
 PWM0_Fault                                          ,
 PWM0_Generator_0                                      ,
 PWM0_Generator_1                                      ,
 PWM0_Generator_2                                      ,
 QEI0                                                ,
 ADC0_Sequence_0                                     ,
 ADC0_Sequence_1                                       ,
 ADC0_Sequence_2                                       ,
 ADC0_Sequence_3                                       ,
 Watchdog_Timers0and1                                ,
 _16_32_Bit_Timer0A                                   ,
 _16_32_Bit_Timer0B                                   ,
 _16_32_Bit_Timer1A                                   ,
 _16_32_Bit_Timer1B                                   ,
 _16_32_Bit_Timer2A                                   ,
 _16_32_Bit_Timer2B                                   ,
 Analog_Comparator0                                  ,
 Analog_Comparator1                                  ,
 //- Reserved                                        
 System_Control=28                                   ,
 Flash_Memory_Control_EEPROM_Control                 ,
 GPIO_Port_F                                         ,
 // Reserved                                         
 UART2  =33                                          ,
 SSI1                                                ,
 _16_32_Bit_Timer3A                                   ,
 _16_32_Bit_Timer3B                       			 ,
 I2C1                                                ,
 QEI1                                                ,
 CAN0                                                ,
 CAN1                                                ,
// Reserved                                          ,
 Hibernation_Module =43                              ,
 USB                                                 ,
 PWM_Generator3                                      ,
 uDMA_Software                                       ,
 uDMA_Error                                          ,
 ADC1_Sequence0                                      ,
 ADC1_Sequence1                                      ,
 ADC1_Sequence2                                      ,
 ADC1_Sequence3                                      ,
 //Reserved                                          ,
 SSI2 =57                                            ,
 SSI3                                                ,
 UART3                                               ,
 UART4                                               ,
 UART5                                               ,
 UART6                                               ,
 UART7                                               ,
 //Reserved                                          ,
 I2C2 =68                                			 ,
 I2C3                                                ,
 _16_32_Bit_Timer4A                                   ,
 _16_32_Bit_Timer4B                                   ,
 //Reserved                                          ,
 _16_32_Bit_Timer5A =92                               ,
 _16_32_Bit_Timer5B                                   ,
 _32_64_Bit_Timer0A                                   ,
 _32_64_Bit_Timer0B                                   ,
 _32_64_Bit_Timer1                                    ,
 _32_64_Bit_Timer_1B                                  ,
 _32_64_Bit_Timer_2A                                  ,
 _32_64_Bit_Timer_2B                                  ,
 _32_64_Bit_Timer_3A                                  ,
 _32_64_Bit_Timer_3B                                  ,
 _32_64_Bit_Timer_4A                                  ,
 _32_64_Bit_Timer_4B                                  ,
 _32_64_Bit_Timer_5A                                  ,
 _32_64_Bit_Timer_5B                                  ,
 System_Exception_imprecise                          ,
 //Reserved                                          ,
 PWM1_Generator_0 =134                               ,
 PWM1_Generator_1                                    ,
 PWM1_Generator_2                                    ,
 PWM1_Generator_3                                    ,
 PWM1_Fault                                          ,
													
}INT_Types;


typedef struct {
	INT_Types Int_num;
	uint32  group_priority;
	uint32  sub_priority;
	
}NVIC_PRIO;

extern const NVIC_PRIO NVIC_ARR_INPUT[];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 
 *********************************************************************************************************************/
void INTCTRL_init(void);

#endif /* INT_CTRL_H */
/**********************************************************************************************************************
 *  END OF FILE: Int_Ctrl.h
 *********************************************************************************************************************/