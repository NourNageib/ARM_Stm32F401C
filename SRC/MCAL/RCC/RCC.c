/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : RCC   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : Febraury 8 , 2024  */
/*	Last Edit : N/A                */
/***********************************/



/*********************************************************************************************************************************************************/
/**************************************************           SYSCLK RCC DRIVER                    *******************************************************/
/*********************************************************************************************************************************************************/
#include "RCC.h"
/*********************************************************************************************************************************************************/
/**************************************************             Defines Region                     *******************************************************/
/*********************************************************************************************************************************************************/


/************************************************/
/********          Data  Types                ***/
/************************************************/

typedef unsigned int uint32_t;
#define vp32		  volatile uint32_t* 

/* Defining all registers in RCC with offset 32bit  */
typedef struct 
{
	volatile uint32_t CR;          		// Clock control register
	volatile uint32_t PLLCFGR;     		// PLL configuration register
	volatile uint32_t CFGR;        		// Clock configuration register
	volatile uint32_t CIR;         		// Clock interrupt register
	volatile uint32_t AHB1RSTR;    		// AHB1 peripheral reset register
	volatile uint32_t AHB2RSTR;    		// AHB2 peripheral reset register
	volatile uint32_t RESERVED0;   		// Reserved
	volatile uint32_t RESERVED1;   		// Reserved
	volatile uint32_t APB1RSTR;    		// APB1 peripheral reset register
	volatile uint32_t APB2RSTR;    		// APB2 peripheral reset register
	volatile uint32_t RESERVED2;		// Reserved
	volatile uint32_t RESERVED3;		// Reserved
	volatile uint32_t AHB1ENR;     		// AHB1 peripheral clock enable register
	volatile uint32_t AHB2ENR;     		// AHB2 peripheral clock enable register
	volatile uint32_t RESERVED4;		// Reserved
	volatile uint32_t RESERVED5;   		// Reserved
	volatile uint32_t APB1ENR;     		// APB1 peripheral clock enable register
	volatile uint32_t APB2ENR;     		// APB2 peripheral clock enable register
	volatile uint32_t RESERVED6;		// Reserved
	volatile uint32_t RESERVED7;		// Reserved
	volatile uint32_t AHB1LPENR;   		// AHB1 peripheral clock enable in low power mode register
	volatile uint32_t AHB2LPENR;   		// AHB2 peripheral clock enable in low power mode register
	volatile uint32_t RESERVED8;		// Reserved
	volatile uint32_t RESERVED9;   		// Reserved
	volatile uint32_t APB1LPENR;   		// APB1 peripheral clock enable in low power mode register
	volatile uint32_t APB2LPENR;   		// APB2 peripheral clock enable in low power mode register
	volatile uint32_t RESERVED10;		// Reserved
	volatile uint32_t RESERVED11;		// Reserved
	volatile uint32_t BDCR;        		// Backup domain control register
	volatile uint32_t CSR;         		// Clock control & status register
	volatile uint32_t RESERVED12;		// Reserved
	volatile uint32_t RESERVED13;		// Reserved
	volatile uint32_t SSCGR;       		// Spread spectrum clock generation register
	volatile uint32_t PLLI2SCFGR;  		// PLLI2S configuration register
	volatile uint32_t DCKCFGR;  		// DCK configuration register
	
} RCC_StructTypeDef;

#define RCC_CR_BASE   0x40023800
#define RCC           ((RCC_StructTypeDef *) RCC_CR_BASE)

/************************************************/
/**         RCC_Regisers_Addresses            ***/
/************************************************/
#define RCC_ADD(X)              ((uint32_t)(X+RCC_CR_BASE))

#define RCC_CR                  (*((vp32)RCC_ADD(0x00)))
#define RCC_PLLCFGR             (*((vp32)RCC_ADD(0x04)))
#define RCC_CFGR                (*((vp32)RCC_ADD(0x08)))
#define RCC_CIR                 (*((vp32)RCC_ADD(0x0C)))
#define RCC_AHB1RSTR            (*((vp32)RCC_ADD(0x10)))
#define RCC_AHB2RSTR            (*((vp32)RCC_ADD(0x14)))
#define RCC_APB1RSTR            (*((vp32)RCC_ADD(0x20)))
#define RCC_APB2RSTR            (*((vp32)RCC_ADD(0x24)))
#define RCC_AHB1ENR             (*((vp32)RCC_ADD(0x30)))
#define RCC_AHB2ENR             (*((vp32)RCC_ADD(0x34)))
#define RCC_APB1ENR             (*((vp32)RCC_ADD(0x40)))
#define RCC_APB2ENR             (*((vp32)RCC_ADD(0x44)))
#define RCC_AHB1LPENR           (*((vp32)RCC_ADD(0x50)))
#define RCC_AHB2LPENR           (*((vp32)RCC_ADD(0x54)))
#define RCC_APB1LPENR           (*((vp32)RCC_ADD(0x60)))
#define RCC_APB2LPENR           (*((vp32)RCC_ADD(0x64)))
#define RCC_BDCR                (*((vp32)RCC_ADD(0x70)))
#define RCC_CSR                 (*((vp32)RCC_ADD(0x74)))
#define RCC_SSCGR               (*((vp32)RCC_ADD(0x80)))
#define RCC_PLLI2SCFGR          (*((vp32)RCC_ADD(0x84)))
#define RCC_DCKCFGR             (*((vp32)RCC_ADD(0x8C)))

/********************************************************/
/*#define RCC_CR                *((vp32)0x40023800)
#define RCC_PLLCFGR             *((vp32)0x40023804)
#define RCC_CFGR                *((vp32)0x40023808)
#define RCC_CIR                 *((vp32)0x4002380C)
#define RCC_AHB1RSTR            *((vp32)0x40023810)
#define RCC_AHB2RSTR            *((vp32)0x40023814)
#define RCC_APB1RSTR            *((vp32)0x40023820)
#define RCC_APB2RSTR            *((vp32)0x40023824)
#define RCC_AHB1ENR             *((vp32)0x40023830)
#define RCC_AHB2ENR             *((vp32)0x40023834)
#define RCC_APB1ENR             *((vp32)0x40023840)
#define RCC_APB2ENR             *((vp32)0x40023844)
#define RCC_AHB1LPENR           *((vp32)0x40023850)
#define RCC_AHB2LPENR           *((vp32)0x40023854)
#define RCC_APB1LPENR           *((vp32)0x40023860)
#define RCC_APB2LPENR           *((vp32)0x40023864)
#define RCC_BDCR                *((vp32)0x40023870)
#define RCC_CSR                 *((vp32)0x40023874)
#define RCC_SSCGR               *((vp32)0x40023880)
#define RCC_PLLI2SCFGR          *((vp32)0x40023884)
#define RCC_DCKCFGR             *((vp32)0x4002388C)
*/
/************************************************/
/***               Masks                      ***/
/************************************************/
/* For Bits position in register ( RCC_CR )     */

#define RCC_CR_HSION       0x00000001
#define RCC_CR_HSIRDY      0x00000002


#define RCC_CR_HSEON       0x00010000
#define RCC_CR_HSERDY      0x00020000


#define RCC_CR_PLLON       0x01000000
#define RCC_CR_PLLRDY      0x02000000

/* Masks RCC_CR  "  ON   -   RDY  "   */

#define RCC_MASK_HSION     0x00000001
#define RCC_MASK_HSIRDY    0x00000002


#define RCC_MASK_HSEON     0x00010000
#define RCC_MASK_HSERDY    0x00020000


#define RCC_MASK_PLLON     0x01000000
#define RCC_MASK_PLLRDY    0x02000000
/************************************************/
/* SWS_MASK : Read System clock switch status   */
/************************************************/
#define  RCC_MASK_SWS      0x00000006

#define  RCC_SWS_HSI       0
#define  RCC_SWS_HSE       1
#define  RCC_SWS_PLL       2

#define  RCC_SWS_CLK        ((RCC_CFGR & RCC_MASK_SWS)>>2)

/*
#define RCC_MASK_SWS_HSI   0x00000000
#define RCC_MASK_SWS_HSE   0x00000004
#define RCC_MASK_SWS_PLL   0x00000008
*/

/************************************************/
/* SW_MASK  : System clock switch               */
/************************************************/
#define RCC_MASK_SW        0x00000003

#define RCC_MASK_SW_HSI    0x00000000
#define RCC_MASK_SW_HSE    0x00000001
#define RCC_MASK_SW_PLL    0x00000002

/************************************************/
/* RCC_AHB1RSTR  : for peripheral reset mask    */
/************************************************/
#define RCC_MASK_GPIOARST   0x00000001
#define RCC_MASK_GPIOBRST   0x00000002
#define RCC_MASK_GPIOCRST   0x00000004
#define RCC_MASK_GPIODRST   0x00000008
#define RCC_MASK_GPIOERST   0x00000010
#define RCC_MASK_GPIOHRST   0x00000080

#define RCC_MASK_DMA1RST    0x00200000
#define RCC_MASK_DMA2RST    0x00400000

#define RCC_MASK_CRCRST     0x00001000

/************************************************/
/* RCC_APB1RSTR  : for peripheral reset mask    */
/************************************************/
#define RCC_MASK_TIM2RST    0x00000001
#define RCC_MASK_TIM3RST    0x00000001
#define RCC_MASK_TIM4RST    0x00000001
#define RCC_MASK_TIM5RST    0x00000001

#define RCC_MASK_WWDGRST    0x00000080

#define RCC_MASK_SPI1RST    0x00000080
#define RCC_MASK_SPI2RST    0x00000080

#define RCC_MASK_USART2RST  0x00000080

#define RCC_MASK_I2C1RST    0x00000080
#define RCC_MASK_I2C2RST    0x00000080
#define RCC_MASK_I2C3RST    0x00000080

#define RCC_MASK_PWRRST     0x00001000

/************************************************/
/***            32 Pins Masks                 ***/
/************************************************/
#define RCC_MASK_PIN0       0x00000001
#define RCC_MASK_PIN1       0x00000002
#define RCC_MASK_PIN2       0x00000004
#define RCC_MASK_PIN3       0x00000008

#define RCC_MASK_PIN4       0x00000010
#define RCC_MASK_PIN5       0x00000020
#define RCC_MASK_PIN6       0x00000040
#define RCC_MASK_PIN7       0x00000080

#define RCC_MASK_PIN8       0x00000100
#define RCC_MASK_PIN9       0x00000200
#define RCC_MASK_PIN10      0x00000400
#define RCC_MASK_PIN11      0x00000800

#define RCC_MASK_PIN12      0x00001000
#define RCC_MASK_PIN13      0x00002000
#define RCC_MASK_PIN14      0x00004000
#define RCC_MASK_PIN15      0x00008000

#define RCC_MASK_PIN16      0x00010000
#define RCC_MASK_PIN17      0x00020000
#define RCC_MASK_PIN18      0x00040000
#define RCC_MASK_PIN19      0x00080000

#define RCC_MASK_PIN20      0x00100000
#define RCC_MASK_PIN21      0x00200000
#define RCC_MASK_PIN22      0x00400000
#define RCC_MASK_PIN23      0x00800000

#define RCC_MASK_PIN24      0x01000000
#define RCC_MASK_PIN25      0x02000000
#define RCC_MASK_PIN26      0x04000000
#define RCC_MASK_PIN27      0x08000000

#define RCC_MASK_PIN28      0x10000000
#define RCC_MASK_PIN29      0x20000000
#define RCC_MASK_PIN30      0x40000000
#define RCC_MASK_PIN31      0x80000000
/***************************************/
/*         peripheral enable           */
/***************************************/
#define RCC_AHB1ENR_Start_IDX        0
#define RCC_AHB1ENR_End_IDX         31
#define RCC_AHB2ENR_Start_IDX       32
#define RCC_APB1ENR_Start_IDX       64
#define RCC_APB2ENR_Start_IDX       96
#define RCC_AHB1LPENR_Start_IDX    128
#define RCC_AHB2LPENR_Start_IDX    160
#define RCC_APB1LPENR_Start_IDX    192
#define RCC_APB2LPENR_Start_IDX    224
#define RCC_APB2LPENR_End_IDX      255

/*
0   - 31   (RCC_AHB1ENR)
32  - 63   (RCC_AHB2ENR)
64  - 95   (RCC_APB1ENR)
96  - 127  (RCC_APB2ENR)
128 - 159  (RCC_AHB1LPENR)
160 - 191  (RCC_AHB2LPENR)
192 - 223  (RCC_APB1LPENR)
224 - 255  (RCC_APB2LPENR)
*/

/***************************************/
/*         PLL Configuration           */
/***************************************/
#define RCC_PLL_NCFG_SHIFT   6
#define RCC_PLL_PCFG_SHIFT  16
#define RCC_PLLSRCCFG_SHIFT 22
#define RCC_PLL_QCFG_SHIFT  24

/***************************************/
/*      Prescaler Mask for buses       */
/***************************************/
#define RCC_MASK_PPRE1      0x00001C00
#define RCC_MASK_PPRE2      0x0000E000
#define RCC_MASK_HPRE       0x000000F0

/***************************************/
/*      Prescaler Values for buses     */
/***************************************/




/*********************************************************************************************************************************************************/
/**************************************************               New Types Region                 *******************************************************/
/*********************************************************************************************************************************************************/
typedef enum
{
	RCC_CLEAR,
	RCC_SET,
	RCC_TOGGLE

}RCC_REG_OPER;



typedef enum
{
	RCC_RDY = 0,
	RCC_NOTRDY
	
}RCC_RDY_State;

typedef enum
{
	RCC_OFF = 0,
	RCC_ON
	
}RCC_ON_OFF_State;
/*********************************************************************************************************************************************************/
/*********************************************         Static Functions Prototypes Region        *****************************************************/
/*********************************************************************************************************************************************************/
static RCC_ON_OFF_State RCC_GET_SYSCLK_ON_BIT ( RCC_SYSCLK   RCC_CopySYSCLK);
static RCC_RDY_State    RCC_GET_ReadyFlag     ( RCC_SYSCLK   RCC_CopySYSCLK);
static RCC_ErrorStatus  RCC_SwitchToSYSCLK    ( RCC_SYSCLK   RCC_CopySYSCLK);
static uint32_t         RCC_EDIT_Bit_Reg      (uint32_t RCC_REG_EDIT,uint32_t BIT_NUM,RCC_REG_OPER OPERA);
static uint32_t         RCC_EDIT_REG_MASK     (uint32_t RCC_REG_EDIT,uint32_t RCC_MASK,RCC_REG_OPER OPERA);

/*********************************************************************************************************************************************************/
/***************************************************************** Functions Implementation **************************************************************/
/*********************************************************************************************************************************************************/

/*by default HSI CLOCK IS SYSCLK*/

/************ RCC_GET_ReadyFlag ********************/
/* 
   
   Functionality    : Check rdy flag in RCC_CR
   Input Parameters : 1- System clock	

 */
RCC_ErrorStatus RCC_SelectSYSCLK ( RCC_SYSCLK   RCC_CopySYSCLK  , RCC_SYSCLKState RCC_CopySYSCLKState )
{
	 RCC_ErrorStatus RCC_LocReturnSYSCLK  = RCC_SYSCLKEnable_ERROR;
	 /*To avoid loc_timeout var optimization*/
	 volatile uint32_t loc_timeout = 60000;

	 /*Check input from user within Range*/
	 if((RCC_CopySYSCLK >= RCC_SYSCLK_HSE) && (RCC_CopySYSCLK <= RCC_SYSCLK_PLL))
	 {
		  switch(RCC_CopySYSCLK)
		  {

			  case RCC_SYSCLK_HSE :
			  {
				if(RCC_CopySYSCLKState)/*ENABLE*/
				{
					/*
					 SET RC_CR        -> HSEON   
					 RCC_Local_SYSCLK  = RCC_CR;
					 RCC_Local_SYSCLK |= RCC_MASK_HSEON;
					 RCC->CR           = RCC_Local_SYSCLK;
					 */
					RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_HSEON,RCC_SET);
					/* 
					    #busywait till HSE oscillator to be stable and ready   
					 */
					 while (!(RCC->CR & RCC_MASK_HSERDY) && loc_timeout)
					 {
						loc_timeout--;
					 }

					 /*check reson of breaking the busywait */
					 /*if timeout*/
					if(!loc_timeout)
					{
						RCC_LocReturnSYSCLK  = RCC_SYSCLKEnable_ERROR;
					}
					else
					{
				    	RCC_SwitchToSYSCLK (RCC_CopySYSCLK);
					    RCC_LocReturnSYSCLK = RCC_SYSCLKEnable_OK ;
					}
					 
				}
				else if(!RCC_CopySYSCLKState)/*DIABLE*/
				{
				/* CLEAR RC_CR -> HSEON  */
				/* 
					RCC_Local_SYSCLK  = RCC->CR;
					RCC_Local_SYSCLK &= ~RCC_MASK_HSEON;
					RCC->CR           = RCC_Local_SYSCLK;
				 */
					RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_HSEON,RCC_CLEAR);
					RCC_LocReturnSYSCLK = RCC_SYSCLKDisable_OK ;
				}
				else
				{
					RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				}
			  } break ;
			  
			  case RCC_SYSCLK_HSI :
			  {
				  if(RCC_CopySYSCLKState)
				  {
					  /* SET RC_CR -> HSION   */
					  /* 
					     RCC_Local_SYSCLK  = RCC->CR;
					     RCC_Local_SYSCLK |= RCC_MASK_HSION;
					     RCC->CR           = RCC_Local_SYSCLK;
					 */
					  RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_HSION,RCC_SET);
					  /* #busywait till HSI oscillator to be stable and ready   */
					  while (!(RCC->CR & RCC_MASK_HSIRDY)) 
					{
						loc_timeout--;
					 }

					 /*check reson of breaking the busywait */
					 /*if timeout*/
					if(!loc_timeout)
					{
						RCC_LocReturnSYSCLK  = RCC_SYSCLKEnable_ERROR;
					}
					else
					{
				    	RCC_SwitchToSYSCLK (RCC_CopySYSCLK);
					    RCC_LocReturnSYSCLK = RCC_SYSCLKEnable_OK ;
					}
				  }
				  else if(!RCC_CopySYSCLKState)
				  {
					  /* CLEAR RC_CR -> HSION  */
					  /* 
						RCC_Local_SYSCLK  =  RCC->CR;
						RCC_Local_SYSCLK &= ~RCC_MASK_HSION;
						RCC->CR           =  RCC_Local_SYSCLK; 
					  */
					  RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_HSION,RCC_CLEAR);
					  RCC_LocReturnSYSCLK = RCC_SYSCLKDisable_OK ;
				  }
				  else
				  {
					  RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				  }
				  
			  } break ;
			  
			  case RCC_SYSCLK_PLL :
			  {
				  if(RCC_CopySYSCLKState)
				  {
					  /* SET RC_CR -> main PLLON   */
				    /*
					    RCC_Local_SYSCLK  = RCC->CR;
						RCC_Local_SYSCLK |= RCC_MASK_PLLON;
						RCC->CR           = RCC_Local_SYSCLK; 
					*/
					
					RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_PLLON,RCC_SET);
					/* #busywait till PLL oscillator to be stable and ready   */
					  while (!(RCC->CR & RCC_MASK_PLLRDY))
					{
						loc_timeout--;
					}

					 /*check reson of breaking the busywait */
					 /*if timeout*/
					if(!loc_timeout)
					{
						RCC_LocReturnSYSCLK  = RCC_SYSCLKEnable_ERROR;
					}
					else
					{
				    	RCC_SwitchToSYSCLK (RCC_CopySYSCLK);
					    RCC_LocReturnSYSCLK = RCC_SYSCLKEnable_OK ;
					}
				  }
				  else if(!RCC_CopySYSCLKState)
				  {
					/* CLEAR RC_CR -> PLLON  */
					/*
						RCC_Local_SYSCLK  =  RCC->CR;
						RCC_Local_SYSCLK &= ~RCC_MASK_PLLON;
						RCC->CR           =  RCC_Local_SYSCLK; 
					*/
				      RCC_CR = RCC_EDIT_REG_MASK(RCC_CR,RCC_MASK_HSION,RCC_CLEAR);
					  RCC_LocReturnSYSCLK = RCC_SYSCLKDisable_OK ;
				  }
				  else
				  {
					  RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				  }
				  
			  } break ;
			  
			  default :
			  {
				  RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				   
			  } break ;
			  
		 
	        }
	 }
	 else
	 {
		 /* input from user out of Range*/
		 RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
		 
	 }
	 return RCC_LocReturnSYSCLK ;
	
}

/***************** RCC_CFG_PLL ********************/
/* 
   
   Functionality    : 
   Input Parameters : 	

*/
RCC_SYSCLK RCC_GET_SYSCLK(void)
{
	uint32_t RCC_Loc_Sysclk_Var;
	RCC_Loc_Sysclk_Var = RCC_SWS_CLK;
	RCC_SYSCLK RCC_Current_SYSCLK = RCC_SYSCLK_ERROR;
	switch (RCC_Loc_Sysclk_Var)
	{
		case RCC_SWS_HSI:
			{
				RCC_Current_SYSCLK = RCC_SYSCLK_HSI;
			}break;

		case RCC_SWS_HSE:
			{
				RCC_Current_SYSCLK = RCC_SYSCLK_HSE;
			}break;

		case RCC_SWS_PLL:
			{
				RCC_Current_SYSCLK = RCC_SYSCLK_PLL;
			}break;
		default:
			break;
	}

	return RCC_Current_SYSCLK;

}
/********************************* RCC_CFG_PLL ****************************/
/* 
   
   Functionality    :    Configure PLL Parameters 
   Input Parameters : 1- PLLSRC : Main PLL(PLL) and audio
    					          PLL (PLLI2S) entry clock source.
                      2- PLLQ   : Main PLL division factor
					  3- PLLP   : Main PLL division factor 
					              for main system clock.
					  4- PLLN   : Main PLL (PLL) multiplication 
					              factor for VCO.
					  5- PLLM   : Division factor for the main PLL 
					              (PLL) and audio PLL (PLLI2S) input clock
    Warning!        : PLL Must not be SYSCLK during Configuration.

 */
RCC_ErrorStatus RCC_CFG_PLL(RCC_PLL_SRC Input_PLL_ClkSrc, uint32_t Input_PLL_Q, uint32_t Input_PLL_P, uint32_t Input_PLL_N , uint32_t Input_PLL_M)
{

	RCC_ErrorStatus RCC_LocReturnSYSCLK  = RCC_PLLCFG_OK;
	RCC_SYSCLK RCC_Current_SYSCLK = RCC_GET_SYSCLK();
	/*PLLCFGR Reset Value*/
	RCC_PLLCFGR = 0x24003010;
	uint32_t RCC_PLLCGG_Loc ;

	/* Check on sysclk and pll sysclk source */
	if(( RCC_Current_SYSCLK  == RCC_SYSCLK_PLL) || !(Input_PLL_ClkSrc == RCC_PLL_HSE || Input_PLL_ClkSrc == RCC_PLL_HSE))
	{
		RCC_LocReturnSYSCLK = RCC_PLLCFG_FAILED ;
	}
	else if( !(Input_PLL_Q >= 2 && Input_PLL_Q <=15)  )
	{
	     RCC_LocReturnSYSCLK = RCC_PLLCFG_FAILED ;
	}
	else if (!(Input_PLL_P == 2 || Input_PLL_P == 4 || Input_PLL_P == 6 || Input_PLL_P == 8 ))
	{
		RCC_LocReturnSYSCLK = RCC_PLLCFG_FAILED ;
	}
    else if (!(Input_PLL_M >= 2 && Input_PLL_M <=63))
	{
		RCC_LocReturnSYSCLK = RCC_PLLCFG_FAILED ;
	}
	else if (!(Input_PLL_N >= 192 && Input_PLL_N <= 432))
	{
		RCC_LocReturnSYSCLK = RCC_PLLCFG_FAILED ;
	}
	else
	{
		/* Reset all pllcfgr values and will disable PLL clock */
		RCC_PLLCGG_Loc = ((RCC_PLLCFGR) | (Input_PLL_ClkSrc<<RCC_PLLSRCCFG_SHIFT) | (Input_PLL_P<<RCC_PLL_PCFG_SHIFT) | (Input_PLL_N<<RCC_PLL_NCFG_SHIFT) | (Input_PLL_M) | (Input_PLL_Q<<RCC_PLL_QCFG_SHIFT)) ;
		RCC_PLLCFGR    = RCC_PLLCGG_Loc;

		RCC_LocReturnSYSCLK = RCC_PLLCFG_COMPLETED ;
	}

	
	
	return RCC_LocReturnSYSCLK;
}

RCC_ErrorStatus RCC_EN_DIS_Peripheral(RCC_Peripherals_opts RCC_Peripheral_EN_opts , RCC_State RCC_Peripheral_State )
{
	/*uint32_t RCC_Local_Peri_EN =0;*/
	RCC_ErrorStatus RCC_LocReturStatus = RCC_Peripheral_CTRL_ERROR;

	if (RCC_Peripheral_EN_opts >= RCC_AHB1ENR_Start_IDX && RCC_Peripheral_EN_opts < RCC_AHB2ENR_Start_IDX )
	{
		
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			/* RCC_Local_Peri_EN  = RCC_AHB1ENR ;
			RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts);
			RCC_AHB1ENR        = RCC_Local_Peri_EN ; */
			RCC_AHB1ENR = RCC_EDIT_Bit_Reg(RCC_AHB1ENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		} 
		else if(RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			/* RCC_Local_Peri_EN  = RCC_AHB1ENR ;
			RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts);
			RCC_AHB1ENR        = RCC_Local_Peri_EN ; */
			RCC_AHB1ENR = RCC_EDIT_Bit_Reg(RCC_AHB1ENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;
		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}
		
	}
	else if(RCC_Peripheral_EN_opts >= RCC_AHB2ENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_APB1ENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			
			RCC_Peripheral_EN_opts -= RCC_AHB2ENR_Start_IDX ;
		    
			/*Takig a copy from register to set the assignn at a atime
			RCC_Local_Peri_EN  = RCC_AHB2ENR;
		     Extracting the peripheral bit	
		    RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts);
			RCC_AHB2ENR        = RCC_Local_Peri_EN;   
			*/
			RCC_AHB2ENR = RCC_EDIT_Bit_Reg(RCC_AHB2ENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -= RCC_AHB2ENR_Start_IDX ;
			/* RCC_Local_Peri_EN  = RCC_AHB2ENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts);
			RCC_AHB2ENR        = RCC_Local_Peri_EN;  */
			RCC_AHB2ENR = RCC_EDIT_Bit_Reg(RCC_AHB2ENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;
		}
     	else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}
	}
	else if(RCC_Peripheral_EN_opts >= RCC_APB1ENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_APB2ENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -= RCC_APB1ENR_Start_IDX ;
			/* RCC_Local_Peri_EN  = RCC_APB1ENR;	
		    RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts);
			RCC_APB1ENR        = RCC_Local_Peri_EN;  */
			RCC_APB1ENR = RCC_EDIT_Bit_Reg(RCC_APB1ENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -= RCC_APB1ENR_Start_IDX ;
			/* RCC_Local_Peri_EN  = RCC_APB1ENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts);
			RCC_APB1ENR        = RCC_Local_Peri_EN;  */
			RCC_APB1ENR = RCC_EDIT_Bit_Reg(RCC_APB1ENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else if(RCC_Peripheral_EN_opts >= RCC_APB2ENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_AHB1LPENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -= RCC_APB2ENR_Start_IDX ;
		/* 	RCC_Local_Peri_EN  = RCC_APB2ENR;
		    RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts);
			RCC_APB2ENR        = RCC_Local_Peri_EN;  */
			RCC_APB2ENR = RCC_EDIT_Bit_Reg(RCC_APB2ENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -= RCC_APB2ENR_Start_IDX ;
			/* RCC_Local_Peri_EN  = RCC_APB2ENR	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts); */
			RCC_APB2ENR = RCC_EDIT_Bit_Reg(RCC_APB2ENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else if(RCC_Peripheral_EN_opts >= RCC_AHB1LPENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_AHB2LPENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_AHB1LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  = RCC_AHB1LPENR;	
		    RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts); */
			RCC_AHB1LPENR = RCC_EDIT_Bit_Reg(RCC_AHB1LPENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_AHB1LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  =  RCC_AHB1LPENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts); */
			RCC_AHB1LPENR = RCC_EDIT_Bit_Reg(RCC_AHB1LPENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK; 

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else if(RCC_Peripheral_EN_opts >= RCC_AHB2LPENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_APB1LPENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_AHB2LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  =  RCC_AHB2LPENR;	
		    RCC_Local_Peri_EN |= (1<<RCC_Peripheral_EN_opts); */
			RCC_AHB2LPENR = RCC_EDIT_Bit_Reg(RCC_AHB2LPENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_AHB2LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  =  RCC_AHB2LPENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts); */
			RCC_AHB2LPENR = RCC_EDIT_Bit_Reg(RCC_AHB2LPENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;  

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else if(RCC_Peripheral_EN_opts >= RCC_APB1LPENR_Start_IDX  && RCC_Peripheral_EN_opts < RCC_APB2LPENR_Start_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_APB1LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  =  RCC_APB1LPENR;	
		    RCC_Local_Peri_EN |=  (1<<RCC_Peripheral_EN_opts); */
			RCC_APB1LPENR = RCC_EDIT_Bit_Reg(RCC_APB1LPENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_APB1LPENR_Start_IDX ;
		/* 	RCC_Local_Peri_EN  =  RCC_APB1LPENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts); */
			RCC_APB1LPENR = RCC_EDIT_Bit_Reg(RCC_APB1LPENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK;  

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else if(RCC_Peripheral_EN_opts >= RCC_APB2LPENR_Start_IDX  && RCC_Peripheral_EN_opts <= RCC_APB2LPENR_End_IDX)
	{
		if(RCC_Peripheral_State == RCC_Enable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_APB1LPENR_Start_IDX ;	
			/* RCC_Local_Peri_EN  =  RCC_APB2LPENR;
		    RCC_Local_Peri_EN |=  (1<<RCC_Peripheral_EN_opts); */
			RCC_APB2LPENR = RCC_EDIT_Bit_Reg(RCC_APB2LPENR,RCC_Peripheral_EN_opts,RCC_SET);
			RCC_LocReturStatus = RCC_PeripheralEnable_OK;
		}
		else if (RCC_Peripheral_State == RCC_Disable_Peripheral)
		{
			RCC_Peripheral_EN_opts -=  RCC_APB2LPENR_Start_IDX ;
			/* RCC_Local_Peri_EN  =  RCC_APB2LPENR;	
		    RCC_Local_Peri_EN &= ~(1<<RCC_Peripheral_EN_opts); */
			RCC_APB2LPENR = RCC_EDIT_Bit_Reg(RCC_APB2LPENR,RCC_Peripheral_EN_opts,RCC_CLEAR);
			RCC_LocReturStatus = RCC_PeripheralDisable_OK; 

		}
		else
		{
			RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
		}

	}
	else
	{
		RCC_LocReturStatus =RCC_Peripheral_CTRL_ERROR;
	}

	return RCC_LocReturStatus ;
}



RCC_ErrorStatus RCC_Set_Prescaler(RCC_CONTROL_BUS RCC_ConrolBus ,uint32_t RCC_PrescalerValue)
{
	volatile uint32_t loc_timeout = 1000000;
	uint32_t RCC_PrescalerValue_LOC=0x00000000;
	RCC_ErrorStatus RCC_LocPrescaer_status = RCC_PRE_ERROR;
	char loc_flag_setprescaler = 1 ;

	/*Error handling in case user enter unaplicable prescaler rage for selected bus */
	if((RCC_ConrolBus == RCC_AHB_CB) && (RCC_PrescalerValue < RCC_PREAHB1_2  || RCC_PrescalerValue > RCC_PREAHB1_512 ))
	{
         RCC_LocPrescaer_status = RCC_PRE_ERROR;
		 loc_flag_setprescaler = 0 ;
	}  
	else if ((RCC_ConrolBus == RCC_APB1_CB) && !((RCC_PrescalerValue >= RCC_PREAPB1_2  && RCC_PrescalerValue <= RCC_PREAPB1_16 )))
	{
         RCC_LocPrescaer_status = RCC_PRE_ERROR;
		 loc_flag_setprescaler = 0 ;
	}  
	else if ((RCC_ConrolBus == RCC_APB2_CB) && !((RCC_PrescalerValue >= RCC_PREAPB2_2  && RCC_PrescalerValue <= RCC_PREAPB2_16 )))
	{
	    RCC_LocPrescaer_status = RCC_PRE_ERROR;
		loc_flag_setprescaler = 0 ;	
	}
	if(loc_flag_setprescaler)
	{
	  switch (RCC_ConrolBus)
		{
		case RCC_AHB_CB:
		{
			RCC_PrescalerValue_LOC  = RCC_EDIT_REG_MASK(RCC_CFGR ,RCC_MASK_HPRE,RCC_CLEAR);
			RCC_CFGR                = RCC_EDIT_REG_MASK(RCC_PrescalerValue_LOC ,RCC_PrescalerValue,RCC_SET);
			RCC_LocPrescaer_status = RCC_PRE_OK;

		}break;

		case RCC_APB1_CB:
		{
			RCC_PrescalerValue_LOC = RCC_EDIT_REG_MASK(RCC_CFGR ,RCC_MASK_HPRE,RCC_CLEAR);
			RCC_CFGR           = RCC_EDIT_REG_MASK(RCC_PrescalerValue_LOC,RCC_PrescalerValue,RCC_SET);
			RCC_LocPrescaer_status = RCC_PRE_OK;

		}break;
		case RCC_APB2_CB:
		{
			RCC_PrescalerValue_LOC = RCC_EDIT_REG_MASK(RCC_CFGR ,RCC_MASK_HPRE,RCC_CLEAR);
			RCC_CFGR           = RCC_EDIT_REG_MASK(RCC_PrescalerValue_LOC,RCC_PrescalerValue,RCC_SET);
			RCC_LocPrescaer_status = RCC_PRE_OK;
		}break;
		
		default:
		{
			RCC_LocPrescaer_status = RCC_PRE_ERROR;
		} break;
		}
	}
	
	
    /* Introduce a fixed delay to ensure the new clock configuration takes effect */
	while(loc_timeout);

	return RCC_LocPrescaer_status;


}

/************ RCC_GET_ReadyFlag ********************/
/* 
   
   Functionality    : Check rdy flag in RCC_CR
   Input Parameters : 1- System clock	

 */
static RCC_RDY_State RCC_GET_ReadyFlag ( RCC_SYSCLK   RCC_CopySYSCLK)
{
	 RCC_RDY_State RCC_LocRDY_STATUS = RCC_NOTRDY ;

	switch (RCC_CopySYSCLK)
	{
			case RCC_SYSCLK_HSE:
			{
				if(RCC_CR & RCC_MASK_HSERDY)
				{
					RCC_LocRDY_STATUS = RCC_RDY;
				}
				else
				{
					RCC_LocRDY_STATUS = RCC_NOTRDY;
				}

			} break;

			case RCC_SYSCLK_HSI:
			{
				if(RCC_CR & RCC_MASK_HSIRDY)
				{
					RCC_LocRDY_STATUS = RCC_RDY;
				}
				else
				{
					RCC_LocRDY_STATUS = RCC_NOTRDY; 
				}

			} break;

			case RCC_SYSCLK_PLL:
			{
				if(RCC_CR & RCC_MASK_PLLRDY)
				{
					RCC_LocRDY_STATUS = RCC_RDY;
				}
				else
				{
					RCC_LocRDY_STATUS = RCC_NOTRDY;
				}
			} break;
			
			default :
			{
				RCC_LocRDY_STATUS = RCC_NOTRDY;
			}break;
	
	}
	
	return RCC_LocRDY_STATUS ;

}

/************ RCC_GET_SYSCLK_ON_BIT ********************/
/* 

    Functionality    : Check Input System clock ON flag 
	                   in RCC_CR.
    Input Parameters : 1- System clock.		   

*/
static RCC_ON_OFF_State RCC_GET_SYSCLK_ON_BIT ( RCC_SYSCLK   RCC_CopySYSCLK)
{
	RCC_ON_OFF_State RCC_LocON_STATUS = RCC_OFF ;

	switch (RCC_CopySYSCLK)
	{
			case RCC_SYSCLK_HSE:
			{
				if(RCC_CR & RCC_MASK_HSEON)
				{
					RCC_LocON_STATUS = RCC_ON;
				}
				else
				{
					RCC_LocON_STATUS = RCC_OFF;
				}

			} break;

			case RCC_SYSCLK_HSI:
			{
				if(RCC_CR & RCC_MASK_HSION)
				{
					RCC_LocON_STATUS = RCC_ON;
				}
				else
				{
					RCC_LocON_STATUS = RCC_OFF;
				}



			} break;

			case RCC_SYSCLK_PLL:
			{

				if(RCC_CR & RCC_MASK_PLLON)
				{
					RCC_LocON_STATUS = RCC_ON;
				}
				else
				{
					RCC_LocON_STATUS = RCC_OFF;
				}


			} break;
			default :
			{
				RCC_LocON_STATUS = RCC_ON;
			}break;
	
	}

	return RCC_LocON_STATUS ;
	 
}
/************************************** RCC_SwitchToSYSCLK **********************************/

/* 
   
   * Functionality    : Switch sysclk using RCC_CFGR
                        Writing on sw bits But first check sws bits of RCC_CFGR Reg.
   
   * Input Parameters : 1- System clock	
   
   * NOTE             : you cannot directly switch
						on the system clock (SYSCLK) from the RCC_CFGR 
						register while it's already your current system 
						clock on the STM32F401C.
						The RCC_CFGR register in STM32 microcontrollers is used 
						to configure the system clock source and its division factors.
						However, changing the system clock source while it's active
						would lead to unpredictable behavior and likely disrupt the 
						operation of the microcontroller.	   
 
 */

static RCC_ErrorStatus RCC_SwitchToSYSCLK ( RCC_SYSCLK   RCC_CopySYSCLK )
{

	
	RCC_ErrorStatus RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
	
    uint32_t RCC_Loc_CurrentSYSCLK , RCC_Loc_Config_Var_CFGR = RCC_CFGR;
	RCC_Loc_CurrentSYSCLK = RCC_SWS_CLK; 

	if (RCC_Loc_CurrentSYSCLK == RCC_CopySYSCLK)
	{
		RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
	}
	else 
	{
			switch (RCC_CopySYSCLK)
			{
				case RCC_SYSCLK_HSE:
				{
					if ( ( RCC_GET_ReadyFlag(RCC_SYSCLK_HSE) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_HSE) == RCC_ON ) )
					{
						RCC_Loc_Config_Var_CFGR &= ~RCC_MASK_SW ;
						RCC_Loc_Config_Var_CFGR |= ~RCC_MASK_SW_HSE ;
						RCC_CFGR = RCC_Loc_Config_Var_CFGR ;
						RCC_LocSwitchSysClk_Status = RCC_SYSCLK_SWITCHED;
					}
					else
					{
						RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
					}

				}break;
				
				case RCC_SYSCLK_HSI:
				{
					if(( RCC_GET_ReadyFlag(RCC_SYSCLK_HSI) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_HSI) == RCC_ON ))
					{
						RCC_Loc_Config_Var_CFGR &= ~RCC_MASK_SW ;
						RCC_Loc_Config_Var_CFGR |= RCC_MASK_SW_HSI ;
						RCC_CFGR = RCC_Loc_Config_Var_CFGR ;
						RCC_LocSwitchSysClk_Status = RCC_SYSCLK_SWITCHED;
					}
					else
					{
						RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
					}

				}break;

				case RCC_SYSCLK_PLL:
				{
					if(( RCC_GET_ReadyFlag(RCC_SYSCLK_PLL) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_PLL) == RCC_ON ))
					{
						RCC_Loc_Config_Var_CFGR &= ~RCC_MASK_SW ;
						RCC_Loc_Config_Var_CFGR |= RCC_MASK_SW_PLL ;
						RCC_CFGR = RCC_Loc_Config_Var_CFGR ;
						RCC_LocSwitchSysClk_Status = RCC_SYSCLK_SWITCHED;
					}
					else
					{
						RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
					}

				}break;

				default:
				{
					  RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
				}
					break;
			}

	}
	
    return RCC_LocSwitchSysClk_Status ;
}
/************************************** RCC_EDIT_Bit_Reg **********************************/

/* 
   
   * Functionality    : EDIT bit in register
   * Input Parameters : 1- Register you want to EDIT 
   *                    2- Number of Bit you want to EDIT
   *                    3- Select Operation you want to apply.
   *                       (options : CLEAR , SET , TOGGLE) 	
   
   * NOTE             :   
 
 */
static uint32_t RCC_EDIT_Bit_Reg(uint32_t RCC_REG_EDIT,uint32_t BIT_NUM,RCC_REG_OPER OPERA)
{
	uint32_t RCC_Local_Var =0;
	switch (OPERA)
	{
	
	case RCC_CLEAR :
		{
			RCC_Local_Var  = RCC_REG_EDIT ;
			RCC_Local_Var &= ~(1<<BIT_NUM);
			
		}
		break;
	case RCC_SET :
		{
			RCC_Local_Var  = RCC_REG_EDIT ;
			RCC_Local_Var |= (1<<BIT_NUM); 
		}break;

	default:
		break;
	}
	return RCC_Local_Var;
}
/************************************** RCC_EDIT_REG_MASK **********************************/

/* 
   
   * Functionality    : Apply mask on input register
   * Input Parameters : 1- Register you want to EDIT 
   *                    2- MASK 
   *                    3- Select Operation you want to apply.
   *                       (options : CLEAR , SET , TOGGLE) 	
   
   * NOTE             :   
 
 */
static uint32_t RCC_EDIT_REG_MASK(uint32_t RCC_REG_EDIT,uint32_t RCC_MASK,RCC_REG_OPER OPERA)
{
	uint32_t RCC_Local_Var =0;
	switch (OPERA)
	{
	
		case RCC_CLEAR :
			{
				RCC_Local_Var  = RCC_REG_EDIT ;
				RCC_Local_Var &= ~RCC_MASK;
				
			}
			break;
		case RCC_SET :
			{
				RCC_Local_Var  = RCC_REG_EDIT ;
				RCC_Local_Var |= RCC_MASK; 
			}break;

		default:
			break;
	}
	return RCC_Local_Var;
}