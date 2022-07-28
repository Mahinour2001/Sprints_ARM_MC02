/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  
 *
 *********************************************************************************************************************/



#ifndef TIMERS_H
#define TIMERS_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"
#include "Timers_Cfg.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef enum {

    GPT_16_32_bit_Timer_0         ,
    GPT_16_32_bit_Timer_1         ,
    GPT_16_32_bit_Timer_2         ,
    GPT_16_32_bit_Timer_3         ,
    GPT_16_32_bit_Timer_4         ,
    GPT_16_32_bit_Timer_5         ,
    GPT_32_64_bit_Wide_Timer_0    ,
    GPT_32_64_bit_Wide_Timer_1    ,
    GPT_32_64_bit_Wide_Timer_2    ,
    GPT_32_64_bit_Wide_Timer_3    ,
    GPT_32_64_bit_Wide_Timer_4    ,
    GPT_32_64_bit_Wide_Timer_5
	
}Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef enum
{
	GPT_MODE_NORMAL,
	GPT_MODE_SLEEP 

}Gpt_ModeType;

typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef uint32 Gpt_ChannelTickFrequency;
typedef uint32 GptChannelTickValueMax;

typedef enum
{
	GPT_CH_MODE_PERIODIC,
	GPT_CH_MODE_ONESHOT
}ChannelMode;

typedef void(*GptNotification)(void);

typedef struct
{
	Gpt_ChannelType  					channel;
	Gpt_ValueType                 channelTickFreq;
	GptChannelTickValueMax  	channelTickMaxValue;
	ChannelMode								channelMode;
	GptNotification						gptNotification;
}Gpt_ConfigType;

extern const Gpt_ConfigType Gpt_Config[];

extern DIO_LevelType Timer_Flag ;


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr);

void Gpt_DisableNotification( Gpt_ChannelType Channel );

void Gpt_EnableNotification( Gpt_ChannelType Channel );

Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

//Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr);

Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );

void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

void Gpt_StopTimer( Gpt_ChannelType Channel );

void Gpt_Notification(void);



#endif /* TIMERS_H */
/**********************************************************************************************************************
 *  END OF FILE: Timera.h
 *********************************************************************************************************************/