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
typedef unsigned long uint32_t;

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

#define RCC_CR_HSION        0x00000001
#define RCC_CR_HSIRDY       0x00000002


#define RCC_CR_HSEON        0x00010000
#define RCC_CR_HSERDY       0x00020000


#define RCC_CR_PLLON        0x01000000
#define RCC_CR_PLLRDY       0x02000000

/* Masks RCC_CR  "  ON   -   RDY  "   */

#define RCC_MASK_HSION      0x00000001
#define RCC_MASK_HSIRDY     0x00000002


#define RCC_MASK_HSEON      0x00010000
#define RCC_MASK_HSERDY     0x00020000


#define RCC_MASK_PLLON      0x01000000
#define RCC_MASK_PLLRDY     0x02000000
/************************************************/
/* SWS_MASK : Read System clock switch status   */
/************************************************/
#define  RCC_MASK_SWS       0x00000006

#define  RCC_SWS_CLK        ((RCC_CFGR & RCC_MASK_SWS)>>2)

/*
#define RCC_MASK_SWS_HSI    0x00000000
#define RCC_MASK_SWS_HSE    0x00000004
#define RCC_MASK_SWS_PLL    0x00000008
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
#define RCC_MASK_GPIOARST    0x00000001
#define RCC_MASK_GPIOBRST    0x00000002
#define RCC_MASK_GPIOCRST    0x00000004
#define RCC_MASK_GPIODRST    0x00000008
#define RCC_MASK_GPIOERST    0x00000010
#define RCC_MASK_GPIOHRST    0x00000080

#define RCC_MASK_DMA1RST     0x00200000
#define RCC_MASK_DMA1RST     0x00400000

#define RCC_MASK_CRCRST      0x00001000

/************************************************/
/* RCC_APB1RSTR  : for peripheral reset mask    */
/************************************************/
#define RCC_MASK_TIM2RST     0x00000001
#define RCC_MASK_TIM3RST     0x00000001
#define RCC_MASK_TIM4RST     0x00000001
#define RCC_MASK_TIM5RST     0x00000001

#define RCC_MASK_WWDGRST     0x00000080

#define RCC_MASK_SPI1RST     0x00000080
#define RCC_MASK_SPI2RST     0x00000080

#define RCC_MASK_USART2RST   0x00000080

#define RCC_MASK_I2C1RST     0x00000080
#define RCC_MASK_I2C2RST     0x00000080
#define RCC_MASK_I2C3RST     0x00000080

#define RCC_MASK_PWRRST      0x00001000

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

/*********************************************************************************************************************************************************/
/**************************************************               New Types Region                 *******************************************************/
/*********************************************************************************************************************************************************/


/*********************************************************************************************************************************************************/
/*********************************************         Static Functions Prototypes Region        *****************************************************/
/*********************************************************************************************************************************************************/
static RCC_ON_OFF_State RCC_GET_SYSCLK_ON_BIT ( RCC_SYSCLK   RCC_CopySYSCLK);
static RCC_RDY_State    RCC_GET_ReadyFlag     ( RCC_SYSCLK   RCC_CopySYSCLK);
static RCC_ErrorStatus  RCC_SwitchToSYSCLK    ( RCC_SYSCLK   RCC_CopySYSCLK);

/*********************************************************************************************************************************************************/
/***************************************************************** Functions Implementation **************************************************************/
/*********************************************************************************************************************************************************/

/*by default HSI CLOCK IS SYSCLK*/

RCC_ErrorStatus RCC_SelectSYSCLK ( RCC_SYSCLK   RCC_CopySYSCLK  , RCC_SYSCLKState RCC_CopySYSCLKState )
{
	 RCC_ErrorStatus RCC_LocReturnSYSCLK  = RCC_SYSCLKEnable_ERROR;
	 uint32_t loc_timeout = 60000;

	 /*Check input from user within Range*/
	 if((RCC_CopySYSCLK >= RCC_SYSCLK_HSE) && (RCC_CopySYSCLK <= RCC_SYSCLK_PLL))
	 {
		  switch(RCC_CopySYSCLK)
		  {

			  case RCC_SYSCLK_HSE :
			  {
				if(RCC_SYSCLK_Enable)
				{
					/* SET RC_CR -> HSEON   */
					 RCC->CR |= RCC_MASK_HSEON;
					 /* #busywait till HSE oscillator to be stable and ready   */
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
				else if(RCC_SYSCLK_Disable)
				{
					/* CLEAR RC_CR -> HSEON  */
					RCC->CR &= ~RCC_MASK_HSEON;
					RCC_LocReturnSYSCLK = RCC_SYSCLKDisable_OK ;
				}
				else
				{
					RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				}
			  } break ;
			  
			  case RCC_SYSCLK_HSI :
			  {
				  if(RCC_SYSCLK_Enable)
				  {
					  /* SET RC_CR -> HSION   */
					  RCC->CR |= RCC_MASK_HSION;
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
				  else if(RCC_SYSCLK_Disable)
				  {
					  /* CLEAR RC_CR -> HSION  */
					  RCC->CR &= ~RCC_MASK_HSION;
					  RCC_LocReturnSYSCLK = RCC_SYSCLKDisable_OK ;
				  }
				  else
				  {
					  RCC_LocReturnSYSCLK = RCC_SelectSYSCLK_ERROR ;
				  }
				  
			  } break ;
			  
			  case RCC_SYSCLK_PLL :
			  {
				  if(RCC_SYSCLK_Enable)
				  {
					  /* SET RC_CR -> main PLLON   */
					  RCC->CR |= RCC_MASK_PLLON;
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
				  else if(RCC_SYSCLK_Disable)
				  {
					  /* CLEAR RC_CR -> PLLON  */
					  RCC->CR &= ~RCC_MASK_PLLON;
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

RCC_ErrorStatus RCC_Control_Peripheral(uint32_t RCC_Peripheral_EN , uint32_t RCC_Peripheral_BUS , RCC_State RCC_Peripheral_State )
{

	RCC_ErrorStatus RCC_LocReturStatus = RCC_PeripheralEnable_ERROR;


	switch (RCC_Peripheral_BUS)
	{
		case RCC_AHB1_BUS:
		{
			if (RCC_Peripheral_State == RCC_Enable)
			{

				RCC_LocReturStatus = RCC_PeripheralEnable_OK ;
			}
			else if (RCC_Peripheral_State == RCC_Disable)
			{

			}

		} break;
		
		case RCC_AHB2_BUS:
		{
			if (RCC_Peripheral_State == RCC_Enable)
			{

				RCC_LocReturStatus = RCC_PeripheralEnable_OK ;
			}
			else if (RCC_Peripheral_State == RCC_Disable)
			{

			}

		} break;

		case RCC_APB1_BUS:
		{
			if (RCC_Peripheral_State == RCC_Enable)
			{


				RCC_LocReturStatus = RCC_PeripheralEnable_OK ;
			}
			else if (RCC_Peripheral_State == RCC_Disable)
			{

			}

		} break;

		case RCC_APB2_BUS:
		{
			if (RCC_Peripheral_State == RCC_Enable)
			{

				
				RCC_LocReturStatus = RCC_PeripheralEnable_OK ;
			}
			else if (RCC_Peripheral_State == RCC_Disable)
			{

			}


		} break;


		default:
		{
			RCC_LocReturStatus = RCC_PeripheralEnable_ERROR;

		} break;
	}

	return RCC_LocReturStatus ;
}







/************ RCC_GET_ReadyFlag ********************/
/* 
   
   Functionality    : Check rdy flag in RCC_CR
   Input Parameters : 1- System clock	

 */
static RCC_RDY_State RCC_GET_ReadyFlag ( RCC_SYSCLK   RCC_CopySYSCLK)
{
	 RCC_RDY_State RCC_LocRDY_STATUS = RCC_NRDY ;

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
					RCC_LocRDY_STATUS = RCC_NRDY;
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
					RCC_LocRDY_STATUS = RCC_NRDY;
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
					RCC_LocRDY_STATUS = RCC_NRDY;
				}
			} break;
			
			default :
			{
				RCC_LocRDY_STATUS = RCC_NRDY;
			}break;
	
	}
	
	return RCC_LocRDY_STATUS ;

}

/************ RCC_GET_SYSCLK_ON_BIT ********************/
/* 

    Functionality    : Check rdy flag in RCC_CR
    Input Parameters : 1- System clock		   

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

	if (RCC_SWS_CLK == RCC_CopySYSCLK)
	{
		RCC_LocSwitchSysClk_Status = RCC_SelectSYSCLK_ERROR;
	}
	else 
	{
			switch (RCC_CopySYSCLK)
			{
				case RCC_SYSCLK_HSE:
				{
					if ( ( RCC_GETReadyFlag(RCC_SYSCLK_HSE) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_HSE) == RCC_ON ) )
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
					if(( RCC_GETReadyFlag(RCC_SYSCLK_HSI) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_HSI) == RCC_ON ))
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
					if(( RCC_GETReadyFlag(RCC_SYSCLK_PLL) == RCC_RDY ) && ( RCC_GET_SYSCLK_ON_BIT(RCC_SYSCLK_PLL) == RCC_ON ))
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