/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  -
 *
 *  Description:  Contains all MCU Registers Definitions     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include  "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
typedef struct{
	
	 uint32   VECACT     :8;
	 uint32              :3;
	 uint32   RETBASE    :1;
	 uint32   VECPEND    :8;
	 uint32              :2;
	 uint32   ISRPEND    :1;
	 uint32   ISRPRE     :1;
	 uint32              :1;
	 uint32   PENDSTCLR  :1;
	 uint32   PENDSTSET  :1;
	 uint32   UNPENDSV   :1;
	 uint32   PENDSV     :1;
	 uint32              :2;
	 uint32   NMISET     :1;

}INTCTRL_Reg;

typedef struct{
	
	 uint32    MEMA       :1;
	 uint32    BUSA       :1;
	 uint32               :1;
	 uint32    USGA       :1;
	 uint32               :3;
	 uint32    SVCA       :1;
	 uint32    MON        :1;
	 uint32               :1;
	 uint32    PNDSV      :1;
	 uint32    TICK       :1;
	 uint32    USAGEP     :1;
	 uint32    MEMP       :1;
	 uint32    BUSP       :1;
	 uint32    SVC        :1;
	 uint32    MEM        :1;
	 uint32    BUS        :1;
	 uint32    USAGE      :1;
	 uint32               :13;
	   

}SYSHNDCTRL_Reg;


typedef struct{
	 
	 uint32   VECTRESE     :1 ;
	 uint32   VECTCLRACT   :1 ;
	 uint32   SYSRESREQ    :1 ;
	 uint32                :5 ;
	 uint32   PRIGROUP     :3 ;
	 uint32                :4 ;
	 uint32   ENDIANESS    :1 ;
	 uint32   VECTKEY      :16 ;
	
}APINT_Reg;

typedef union{
	INTCTRL_Reg B;
	uint32      R;
	
}Reg_Bit_type;

typedef union{
	APINT_Reg B;
	uint32    R;
	
}APINT_Reg_type;

#define  CorePeripherals_base_address     0xE000E000
/**************************************
*   NVIC REGISTRE
***************************************/
//Priorities on the system handlers are set with the NVIC System Handler Priority n (SYSPRIn)
//Interrupts are enabled through the NVIC Interrupt Set Enable n (ENn)
//prioritized with the NVIC Interrupt Priority n (PRIn)
 #define  SWTRIG                                       ((volatile uint32*)(CorePeripherals_base_address+0xF00))
 #define  EN0                                          ((volatile uint32*)(CorePeripherals_base_address+0x100))
 #define  EN1                                          ((volatile uint32*)(CorePeripherals_base_address+0x104))
 #define  EN2                                          ((volatile uint32*)(CorePeripherals_base_address+0x108))
 #define  EN3                                          ((volatile uint32*)(CorePeripherals_base_address+0x10C))
 #define  EN4                                          ((volatile uint32*)(CorePeripherals_base_address+0x110))
 #define  PRIx_NVIC                                    ((volatile uint32*)(CorePeripherals_base_address+0x400))

/**************************************
*   SYSTEM CONTROL REGISTRES
***************************************/
#define  INTCTRL                                       ((volatile Reg_Bit_type*)(CorePeripherals_base_address+0xD04))
#define  APINT                                         ((volatile APINT_Reg_type*)(CorePeripherals_base_address+0xD0C))
#define  VECTKEY_num                                    0x05FA
#define  VTABLE                                        ((volatile uint32*)(CorePeripherals_base_address+0xD08))
#define  SYSPRI1                                       ((volatile uint32*)(CorePeripherals_base_address+0xD18))
#define  SYSPRI2                                       ((volatile uint32*)(CorePeripherals_base_address+0xD1C))
#define  SYSPRI3                                       ((volatile uint32*)(CorePeripherals_base_address+0xD20))
#define  SYSHNDCTRL                                    ((volatile uint32*)(CorePeripherals_base_address+0xD24))
#define  FAULTSTAT                                     ((volatile uint32*)(CorePeripherals_base_address+0xD28))
#define  HFAULTSTAT                                    ((volatile uint32*)(CorePeripherals_base_address+0xD2C))

// core registers
#define DISABLE_INT_PRIMASK()                          __asm__("CPSID i");         /*  Disable interrupts and configurable fault handlers (set PRIMASK) */
#define DISABLE_INT_FH()                               __asm__("CPSID f");         /*  Disable interrupts and all fault handlers (set PRIMASK)          */
                       
#define ENABLE_INT_PRIMASK()                           __asm__("CPSIE i");         /* Enable interrupts and configurable fault handlers (clear PRIMASK) */
#define ENABLE_INT_FH()                                __asm__("CPSIE f");         /* Enable interrupts and configurable fault handlers (clear PRIMASK) */



/**************************************
*   SYSTEMCONTROL REGISTERS
***************************************/

#define  SYSTEM_CONTROL_BASEADD                         0x400FE000
#define GPIOHBCTL                                       *((volatile uint32*)(SYSTEM_CONTROL_BASEADD+0x06C))
#define RCGCGPIO                                        *((volatile uint32*)(SYSTEM_CONTROL_BASEADD+0x608))


/**************************************
*   GPIO REGISTRE
***************************************/

#define GPIO_Port_A_AHB_BaseAdd                         0x40058000  
#define GPIO_Port_B_AHB_BaseAdd                         0x40059000
#define GPIO_Port_C_AHB_BaseAdd                         0x4005A000
#define GPIO_Port_D_AHB_BaseAdd                         0x4005B000
#define GPIO_Port_E_AHB_BaseAdd                         0x4005C000
#define GPIO_Port_F_AHB_BaseAdd                         0x4005D000
                
                
                
#define GPIO_Port_B_APB_BaseAdd                         0x40005000
#define GPIO_Port_C_APB_BaseAdd                         0x40006000
#define GPIO_Port_D_APB_BaseAdd                         0x40007000
#define GPIO_Port_E_APB_BaseAdd                         0x40024000
#define GPIO_Port_F_APB_BaseAdd                         0x40025000




#define  GPIODIR(base_address)                          *((volatile uint32*)(base_address+0x400))                                 
#define  GPIOIS(base_address)                           *((volatile uint32*)(base_address+0x404))
#define  GPIOIBE(base_address)                          *((volatile uint32*)(base_address+0x408))
#define  GPIOIEV(base_address)                          *((volatile uint32*)(base_address+0x40C))
#define  GPIOIM(base_address)                           *((volatile uint32*)(base_address+0x410))
#define  GPIORIS(base_address)                          *((volatile uint32*)(base_address+0x414))
#define  GPIOMIS(base_address)                          *((volatile uint32*)(base_address+0x418))
#define  GPIOICR(base_address)                          *((volatile uint32*)(base_address+0x41C))
#define  GPIOAFSEL(base_address)                        *((volatile uint32*)(base_address+0x420))
#define  GPIODR2R(base_address)                         *((volatile uint32*)(base_address+0x500))
#define  GPIODR4R(base_address)                         *((volatile uint32*)(base_address+0x504))
#define  GPIODR8R(base_address)                         *((volatile uint32*)(base_address+0x508))
#define  GPIOODR(base_address)                          *((volatile uint32*)(base_address+0x50C))
#define  GPIOPUR(base_address)                          *((volatile uint32*)(base_address+0x510))
#define  GPIOPDR(base_address)                          *((volatile uint32*)(base_address+0x514))
#define  GPIOSLR(base_address)                          *((volatile uint32*)(base_address+0x518))
#define  GPIODEN(base_address)                          *((volatile uint32*)(base_address+0x51C))
#define  GPIOLOCK(base_address)                         *((volatile uint32*)(base_address+0x520))
#define  GPIOCR(base_address)                           *((volatile uint32*)(base_address+0x524))
#define  GPIOAMSEL(base_address)                        *((volatile uint32*)(base_address+0x528))
#define  GPIOPCTL(base_address)                         *((volatile uint32*)(base_address+0x52C))
#define  GPIOADCCTL(base_address)                       *((volatile uint32*)(base_address+0x530))
#define  GPIODMACTL(base_address)                       *((volatile uint32*)(base_address+0x534))
#define  GPIOPeriphID4(base_address)                    *((volatile uint32*)(base_address+0xFD0))
#define  GPIOPeriphID5(base_address)                    *((volatile uint32*)(base_address+0xFD4))
#define  GPIOPeriphID6(base_address)                    *((volatile uint32*)(base_address+0xFD8))
#define  GPIOPeriphID7(base_address)                    *((volatile uint32*)(base_address+0xFDC))
#define  GPIOPeriphID0(base_address)                    *((volatile uint32*)(base_address+0xFE0))
#define  GPIOPeriphID1(base_address)                    *((volatile uint32*)(base_address+0xFE4))
#define  GPIOPeriphID2(base_address)                    *((volatile uint32*)(base_address+0xFE8))
#define  GPIOPeriphID3(base_address)                    *((volatile uint32*)(base_address+0xFEC))
#define  GPIOPCell_ID_0(base_address)                   *((volatile uint32*)(base_address+0xFF0))
#define  GPIOPCell_ID_1(base_address)                   *((volatile uint32*)(base_address+0xFF4))
#define  GPIOPCell_ID_2(base_address)                   *((volatile uint32*)(base_address+0xFF8))
#define  GPIOPCell_ID_3(base_address)                   *((volatile uint32*)(base_address+0xFFC))


/**************************************
*   GPT REGISTRES
***************************************/

#define GPT_16_32_bit_Timer_0_BASEADDRESS                              0x40030000
#define GPT_16_32_bit_Timer_1_BASEADDRESS                              0x40031000
#define GPT_16_32_bit_Timer_2_BASEADDRESS                              0x40032000
#define GPT_16_32_bit_Timer_3_BASEADDRESS                              0x40033000
#define GPT_16_32_bit_Timer_4_BASEADDRESS                              0x40034000
#define GPT_16_32_bit_Timer_5_BASEADDRESS                              0x40035000
#define GPT_32_64_bit_Wide_Timer_0_BASEADDRESS                         0x40036000
#define GPT_32_64_bit_Wide_Timer_1_BASEADDRESS                         0x40037000
#define GPT_32_64_bit_Wide_Timer_2_BASEADDRESS                         0x4004C000
#define GPT_32_64_bit_Wide_Timer_3_BASEADDRESS                         0x4004D000
#define GPT_32_64_bit_Wide_Timer_4_BASEADDRESS                         0x4004E000
#define GPT_32_64_bit_Wide_Timer_5_BASEADDRESS                         0x4004F000


#define GPTMCFG(base_address)                           *((volatile uint32*)(base_address+0x000))            
#define GPTMTAMR(base_address)                          *((volatile uint32*)(base_address+0x004))
#define GPTMTBMR(base_address)                          *((volatile uint32*)(base_address+0x008))
#define GPTMCTL(base_address)                           *((volatile uint32*)(base_address+0x00C))
#define GPTMSYNC(base_address)                          *((volatile uint32*)(base_address+0x010))
#define GPTMIMR(base_address)                           *((volatile uint32*)(base_address+0x018))
#define GPTMRIS(base_address)                           *((volatile uint32*)(base_address+0x01C))
#define GPTMMIS(base_address)                           *((volatile uint32*)(base_address+0x020))
#define GPTMICR(base_address)                           *((volatile uint32*)(base_address+0x024))
#define GPTMTAILR(base_address)                         *((volatile uint32*)(base_address+0x028))
#define GPTMTBILR(base_address)                         *((volatile uint32*)(base_address+0x02C))
#define GPTMTAMATCHR(base_address)                      *((volatile uint32*)(base_address+0x030))
#define GPTMTBMATCHR(base_address)                      *((volatile uint32*)(base_address+0x034))
#define GPTMTAPR(base_address)                          *((volatile uint32*)(base_address+0x038))
#define GPTMTBPR(base_address)                          *((volatile uint32*)(base_address+0x03C))
#define GPTMTAPMR(base_address)                         *((volatile uint32*)(base_address+0x040))
#define GPTMTBPMR(base_address)                         *((volatile uint32*)(base_address+0x044))
#define GPTMTAR(base_address)                           *((volatile uint32*)(base_address+0x048))
#define GPTMTBR(base_address)                           *((volatile uint32*)(base_address+0x04C))
#define GPTMTAV(base_address)                           *((volatile uint32*)(base_address+0x050))
#define GPTMTBV(base_address)                           *((volatile uint32*)(base_address+0x054))
#define GPTMRTCP(base_address)                          *((volatile uint32*)(base_address+0x058)) 
#define GPTMTAPS(base_address)                          *((volatile uint32*)(base_address+0x05C)) 
#define GPTMTBPS(base_address)                          *((volatile uint32*)(base_address+0x060)) 
#define GPTMTAPV(base_address)                          *((volatile uint32*)(base_address+0x064)) 
#define GPTMTBPV(base_address)                          *((volatile uint32*)(base_address+0x068)) 
#define GPTMPP(base_address)                            *((volatile uint32*)(base_address+0xFC0))


#define RCGCTIMER                                        *((volatile uint32*)(SYSTEM_CONTROL_BASEADD+0x604))
#define RCGC1                                        *((volatile uint32*)(SYSTEM_CONTROL_BASEADD+0x104))
#define  TAEN    0
#define  TBEN    8
#define  TATOIM  0
#define  TAMR    0
#define  TACDIR  4

 



   


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#define SET_BIT(VAR,BITNO)                             ((VAR) |=  (1 << (BITNO)))
#define CLR_BIT(VAR,BITNO)                             ((VAR) &= ~(1 << (BITNO)))
#define TOG_BIT(VAR,BITNO)                             (VAR ^=  (1 << BITNO))
#define GET_BIT(VAR,BITNO)                             ((VAR >> (BITNO)) & 0x01)
#define GET_HWREG(BaseAddr,RegOffset)                  *((volatile uint32*)(BaseAddr+RegOffset))

/**********************************************************************************************************************

 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/