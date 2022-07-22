/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Int_Port.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  
 *
 *********************************************************************************************************************/



#ifndef Int_Port_H
#define Int_Port_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"
#include "Mcu_Hw.h"
#include "Dio.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
static const uint32  Port_Base_Addresses[6] ={

     GPIO_Port_A_AHB_BaseAdd     ,   
     GPIO_Port_B_AHB_BaseAdd     ,
     GPIO_Port_C_AHB_BaseAdd     ,
     GPIO_Port_D_AHB_BaseAdd     ,
     GPIO_Port_E_AHB_BaseAdd     ,
     GPIO_Port_F_AHB_BaseAdd     
};
//Port_PinMode 

#define Port_PinMode_DIO					0
#define Port_PinMode_PA0_U0RX				1
#define Port_PinMode_PA1_U0TX				1
#define Port_PinMode_PA0_CAN1Rx			    8
#define Port_PinMode_PA1_CAN1Tx			    8
#define Port_PinMode_PA2_SSI0Clk		    2
#define Port_PinMode_PA3_SSI0Fss		    2
#define Port_PinMode_PA4_SSI0Rx			    2
#define Port_PinMode_PA5_SSI0Tx			    2
#define Port_PinMode_PA6_I2C1SCL		    3
#define Port_PinMode_PA7_I2C1SDA		    3
#define Port_PinMode_PA6_M1PWM2			    5
#define Port_PinMode_PA7_M1PWM3			    5

#define Port_PinMode_PB0_U1Rx				1
#define Port_PinMode_PB1_U1Tx				1
#define Port_PinMode_PB2_I2C0SCL		    3
#define Port_PinMode_PB3_I2C0SDA		    3
#define Port_PinMode_PB4_SSI2Clk		    2
#define Port_PinMode_PB5_SSI2Fss		    2
#define Port_PinMode_PB6_SSI2Rx			    2
#define Port_PinMode_PB7_SSI2Tx			    2
#define Port_PinMode_PB4_M0PWM2			    4
#define Port_PinMode_PB5_M0PWM3			    4
#define Port_PinMode_PB6_M0PWM0			    4
#define Port_PinMode_PB7_M0PWM1			    4
#define Port_PinMode_PB4_CAN0Rx			    8
#define Port_PinMode_PB5_CAN0Tx			    8
#define Port_PinMode_PB0_T2CCP0			    7
#define Port_PinMode_PB1_T2CCP1			    7
#define Port_PinMode_PB2_T3CCP0			    7
#define Port_PinMode_PB3_T3CCP1			    7
#define Port_PinMode_PB4_T1CCP0			    7
#define Port_PinMode_PB5_T1CCP1			    7
#define Port_PinMode_PB6_T0CCP0			    7
#define Port_PinMode_PB7_T0CCP1			    7

#define Port_PinMode_PC0_TCK_SWCLK	        1
#define Port_PinMode_PC1_TMS_SWDIO	        1
#define Port_PinMode_PC2_TDI				1
#define Port_PinMode_PC3_TDO_SWO		    1	
#define Port_PinMode_PC4_U4Rx				1
#define Port_PinMode_PC5_U4Tx				1
#define Port_PinMode_PC6_U3Rx				1
#define Port_PinMode_PC7_U3Tx				1
#define Port_PinMode_PC4_M0PWM2			    4
#define Port_PinMode_PC5_M0PWM3			    4
#define Port_PinMode_PC6_M0PWM0			    4
#define Port_PinMode_PC7_M0PWM1			    4
#define Port_PinMode_PC4_IDX1				6
#define Port_PinMode_PC5_PhA1				6
#define Port_PinMode_PC6_PhB1				6
#define Port_PinMode_PC4_U1RTS			    8
#define Port_PinMode_PC5_U1CTS			    8
#define Port_PinMode_PC6_USB0EPEN		    8
#define Port_PinMode_PC7_USB0PFLT		    8
#define Port_PinMode_PC0_T4CCP0			    7
#define Port_PinMode_PC1_T4CCP1			    7
#define Port_PinMode_PC2_T5CCP0			    7
#define Port_PinMode_PC3_T5CCP1			    7	
#define Port_PinMode_PC4_WT0CCP0		    7
#define Port_PinMode_PC5_WT0CCP1		    7
#define Port_PinMode_PC6_WT1CCP0		    7
#define Port_PinMode_PC7_WT1CCP1		    7

#define Port_PinMode_PD0_SSI3Clk		    1
#define Port_PinMode_PD1_SSI3Fss		    1
#define Port_PinMode_PD2_SSI3Rx			    1
#define Port_PinMode_PD3_SSI3Tx			    1
#define Port_PinMode_PD4_U6Rx				1
#define Port_PinMode_PD5_U6Tx				1
#define Port_PinMode_PD6_U2Rx				1
#define Port_PinMode_PD7_U2Tx				1
#define Port_PinMode_PD0_SSI1Clk		    2
#define Port_PinMode_PD1_SSI1Fss		    2
#define Port_PinMode_PD2_SSI1Rx			    2
#define Port_PinMode_PD3_SSI1Tx			    2
#define Port_PinMode_PD0_I2C3SCL		    3
#define Port_PinMode_PD1_I2C3SDA		    3
#define Port_PinMode_PD0_M0PWM6			    4
#define Port_PinMode_PD1_M0PWM7			    4
#define Port_PinMode_PD2_M0FAULT0		    4
#define Port_PinMode_PD0_M1PWM0			    5
#define Port_PinMode_PD1_M1PWM1			    5
#define Port_PinMode_PD2_USB0EPEN		    8
#define Port_PinMode_PD3_USB0PFLT		    8
#define Port_PinMode_PD3_IDX0				6
#define Port_PinMode_PD6_PhA0 			    6
#define Port_PinMode_PD7_PhB0				6
#define Port_PinMode_PD7_NMI 				8
#define Port_PinMode_PD0_WT2CCP0		    7
#define Port_PinMode_PD1_WT2CCP1		    7
#define Port_PinMode_PD2_WT3CCP0		    7
#define Port_PinMode_PD3_WT3CCP1		    7
#define Port_PinMode_PD4_WT4CCP0		    7
#define Port_PinMode_PD5_WT4CCP1		    7
#define Port_PinMode_PD6_WT5CCP0		    7
#define Port_PinMode_PD7_WT5CCP1		    7

#define Port_PinMode_PE0_U7Rx				1
#define Port_PinMode_PE1_U7Tx				1
#define Port_PinMode_PE4_U5Rx				1
#define Port_PinMode_PE5_U5Tx				1
#define Port_PinMode_PE4_I2C2SCL		    3
#define Port_PinMode_PE5_I2C2SDA		    3
#define Port_PinMode_PE4_M0PWM4			    4
#define Port_PinMode_PE5_M0PWM5			    4
#define Port_PinMode_PE4_M1PWM2			    5
#define Port_PinMode_PE5_M1PWM3			    5
#define Port_PinMode_PE4_CAN0Rx			    8
#define Port_PinMode_PE5_CAN0Tx			    8

#define Port_PinMode_PF0_U1RTS		        1
#define Port_PinMode_PF1_U1CTS		        1
#define Port_PinMode_PF0_SSI1Rx		        2
#define Port_PinMode_PF1_SSI1Tx		        2
#define Port_PinMode_PF2_SSI1Clk	        2
#define Port_PinMode_PF3_SSI1Fss	        2
#define Port_PinMode_PF0_CAN0Rx		        3
#define Port_PinMode_PF3_CAN0Tx		        3
#define Port_PinMode_PF2_M0FAULT0	        4
#define Port_PinMode_PF0_M1PWM4		        5
#define Port_PinMode_PF1_M1PWM5		        5
#define Port_PinMode_PF2_M1PWM6		        5
#define Port_PinMode_PF3_M1PWM7		        5
#define Port_PinMode_PF4_M1FAULT0	        5
#define Port_PinMode_PF0_PhA0			    6
#define Port_PinMode_PF1_PhB0			    6
#define Port_PinMode_PF4_IDX0			    6
#define Port_PinMode_PF0_T0CCP0		        7
#define Port_PinMode_PF1_T0CCP1		        7
#define Port_PinMode_PF2_T1CCP0		        7
#define Port_PinMode_PF3_T1CCP1		        7
#define Port_PinMode_PF4_T2CCP0		        7
#define Port_PinMode_PF0_NMI			    8
#define Port_PinMode_PF4_USB0EPEN	        8
#define Port_PinMode_PF0_C0o			    9
#define Port_PinMode_PF1_C1o			    9
#define Port_PinMode_PF1_TRD1			    14
#define Port_PinMode_PF2_TRD0			    14
#define Port_PinMode_PF3_TRCLK		        14


#define  ANALOG                             16
#define Port_PinMode_ANALOG_PB0_USB0ID		16
#define Port_PinMode_ANALOG_PB1_USB0VBUS	16
#define Port_PinMode_ANALOG_PB4_AIN10    	16
#define Port_PinMode_ANALOG_PB5_AIN11    	16
#define Port_PinMode_ANALOG_PC4_C1_NEG    	16
#define Port_PinMode_ANALOG_PC5_C1_POS    	16
#define Port_PinMode_ANALOG_PC6_C0_POS   	16
#define Port_PinMode_ANALOG_PC7_C0_NEG   	16
#define Port_PinMode_ANALOG_PD0_AIN7   	    16
#define Port_PinMode_ANALOG_PD1_AIN6    	16
#define Port_PinMode_ANALOG_PD2_AIN5    	16
#define Port_PinMode_ANALOG_PD3_AIN4    	16
#define Port_PinMode_ANALOG_PD4_USB0DM  	16
#define Port_PinMode_ANALOG_PD5_USB0DP    	16
#define Port_PinMode_ANALOG_PE0_AIN3   	    16
#define Port_PinMode_ANALOG_PE1_AIN2    	16
#define Port_PinMode_ANALOG_PE2_AIN1    	16
#define Port_PinMode_ANALOG_PE3_AIN0    	16
#define Port_PinMode_ANALOG_PE4_AIN9  	    16
#define Port_PinMode_ANALOG_PE5_AIN8  	    16


typedef enum{

    INPUT = 0    ,
    OUTPUT = 1

}PortPinDirection;

typedef enum{

    PULL_UP = 0  ,
    PULL_DOWN    ,
    OPEN_DRAIN

}PortPinInternalAttach;

typedef enum{

    R2R         ,
    R4R         ,
    R8R

}PortPinOutputCurrent;

typedef enum{

    NO_INTERUPT =0 ,
    FALLING_EDGE ,
    RISING_EDGE  ,
    LOW_LEVEL    ,
    HIGH_LEVEL   ,
    BOTH_INTERUPTS 

}PortPin_interuptlevel;


typedef struct {

    Channel_Id_Types      CHANNEL;
    DIO_LevelType VALUE;
    PortPinDirection       DIRECTION;
    uint32 Mode ;
    PortPinOutputCurrent  CURRENT;
    PortPinInternalAttach  ATTACH;
    PortPin_interuptlevel  INTERRUPT;
    
    

}Port_ConfigTypes;


extern const Port_ConfigTypes GPIO_ARR_INPUT[];

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 
 *********************************************************************************************************************/

void Port_Init(const Port_ConfigTypes* ConfigPtr);

#endif /* Int_Port_H */
/**********************************************************************************************************************
 *  END OF FILE: Int_Port.h
 *********************************************************************************************************************/