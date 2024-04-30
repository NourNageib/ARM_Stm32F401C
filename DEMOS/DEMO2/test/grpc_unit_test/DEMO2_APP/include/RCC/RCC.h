/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : RCC   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : Febraury 8 , 2024  */
/*	Last Edit : N/A                */
/***********************************/




/*****************************************************************************************************/
/*****************************            RCC DRIVER          ****************************************/
/*****************************************************************************************************/
typedef unsigned int uint32_t;
/* 

#define RCC_AHB1_BUS                    0
#define RCC_AHB2_BUS                    1
#define RCC_APB1_BUS                    2
#define RCC_APB2_BUS                    3 
*/
/**************************************************/
/**           RCC APIs Implementaion             **/
/**************************************************/

#define RCC_GPIOA                       0
#define RCC_GPIOB                       1
#define RCC_GPIOC                       2
#define RCC_GPIOD                       3
#define RCC_GPIOE                       4
#define RCC_GPIOH                       7

#define RCC_CRC                         12

#define RCC_DMA1                        21
#define RCC_DMA2                        22

#define RCC_OTGFS                        7

/*          APB1  Prescaler            */

#define RCC_NO_PREAPB1      0x00000000
#define RCC_PREAPB1_2       0x00001000
#define RCC_PREAPB1_4       0x00001400
#define RCC_PREAPB1_8       0x00001800
#define RCC_PREAPB1_16      0x00001C00

/*         APB2  Prescaler              */

#define RCC_NO_PREAPB2      0x00000000
#define RCC_PREAPB2_2       0x00008000
#define RCC_PREAPB2_4       0x0000A000
#define RCC_PREAPB2_8       0x0000C000
#define RCC_PREAPB2_16      0x0000E000

/*         AHB1  Prescaler           */

#define RCC_NO_PREAHB1      0x00000000
#define RCC_PREAHB1_2       0x00000080
#define RCC_PREAHB1_4       0x00000090
#define RCC_PREAHB1_8       0x000000A0
#define RCC_PREAHB1_16      0x000000B0
#define RCC_PREAHB1_64      0x000000C0
#define RCC_PREAHB1_128     0x000000D0
#define RCC_PREAHB1_256     0x000000E0
#define RCC_PREAHB1_512     0x000000F0
/**************************************************/
/**                  RCC typedefs                **/
/**************************************************/
/*******************************************************/
/*For user system clock options*/
typedef enum
{
	RCC_SYSCLK_HSI = 0,
	RCC_SYSCLK_HSE,
	RCC_SYSCLK_PLL
	
}RCC_SYSCLK;
/*For user clk state options*/
typedef enum
{
	RCC_SYSCLK_Disable =0,
	RCC_SYSCLK_Enable 
	
	
}RCC_SYSCLKState;

typedef enum
{
	RCC_Disable_Peripheral = 0,
	RCC_Enable_Peripheral
	
}RCC_State;

typedef enum 
{
	RCC_PLL_HSE,
	RCC_PLL_HSI
	
}RCC_PLL_SRC;

/*For user system clock options*/
typedef enum
{
	RCC_AHB_CB,
	RCC_APB1_CB,
	RCC_APB2_CB
	
}RCC_CONTROL_BUS;

typedef enum
{
	RCC_SYSCLKEnable_OK,
	RCC_SYSCLKDisable_OK,
	RCC_SYSCLKEnable_ERROR,
	RCC_SYSCLKDisable_ERROR,
	RCC_SYSCLK_ERROR,
	RCC_SelectSYSCLK_ERROR,
	RCC_PeripheralEnable_OK,
	RCC_PeripheralDisable_OK,
	RCC_Peripheral_CTRL_ERROR,
	RCC_PLLCFG_FAILED,
	RCC_PLLCFG_OK,
	RCC_PLLCFG_COMPLETED,
	RCC_SYSCLK_SWITCHED,
	RCC_PRE_ERROR,
	RCC_PRE_OK

}RCC_ErrorStatus;




typedef struct 
{
	RCC_PLL_SRC RCC_PLL_ClkSrc;
	uint32_t    RCC_PLL_M;
	uint32_t    RCC_PLL_N;
	uint32_t    RCC_PLL_P;
	uint32_t    RCC_PLL_Q;
	
} RCC_PLLConfig ;

typedef enum
{
	RCC_GPIOA_AHB1,
	RCC_GPIOB_AHB1,
    RCC_GPIOC_AHB1,
	RCC_GPIOD_AHB1, 
	RCC_GPIOE_AHB1, 
	RCC_GPIOH_AHB1     =  7,
	RCC_CRC_AHB1       = 12,
	RCC_DMA1_AHB1      = 21,
	RCC_DMA2_AHB1,
	RCC_OTGFS_AHB2     = 39,
	RCC_TIM2_APB1      = 63,
	RCC_TIM3_APB1,
	RCC_TIM4_APB1,
	RCC_TIM5_APB1,
	RCC_WWDG_APB1      = 74,
	RCC_SPI2_APB1      = 77,
	RCC_SPI3_APB1,
	RCC_USART2_APB1    = 80,
	RCC_I2C1_APB1      = 84,
	RCC_I2C2_APB1 ,
	RCC_I2C3_APB1,
	RCC_PWR_APB1       = 91,
	RCC_TIM1_APB2      = 95,
	RCC_USART1_APB2    = 99,
	RCC_USART6_APB2,
	RCC_ADC1_APB2      = 103,
	RCC_SDIO_APB2      = 106,
	RCC_SPI1_APB2,
	RCC_SPI4_APB2,
	RCC_SYSCF_APB2,
	RCC_TIM9_APB2      = 111,
	RCC_TIM10_APB2,
	RCC_TIM11_APB2,
	RCC_GPIOALP_AHB1LP = 127,
	RCC_GPIOBLP_AHB1LP,
	RCC_GPIOCLP_AHB1LP,
	RCC_GPIODLP_AHB1LP,
	RCC_GPIOELP_AHB1LP,
	RCC_GPIOHLP_AHB1LP = 134,
	RCC_CRCLP_AHB1LP   = 139,
	RCC_FLITFLP_AHB1LP = 142,
	RCC_SRAM1LP_AHB1LP,
	RCC_DMA1LP_AHB1LP  = 150,
	RCC_DMA2LP_AHB1LP,
	RCC_OTGFSLP_AHB2LP = 168,
	RCC_TIM2LP_APB1LP  = 193,
	RCC_TIM3LP_APB1LP  ,
	RCC_TIM4LP_APB1LP,
	RCC_TIM5LP_APB1LP,
	RCC_WWDGLP_APB1LP  = 204,
	RCC_SPI2LP_APB1LP  = 207,
	RCC_SPI3LP_APB1LP,
	RCC_USART2LP_APB1LP= 210,
	RCC_I2C1LP_APB1LP  = 214,
	RCC_I2C2LP_APB1LP,
	RCC_I2C3LP_APB1LP,
	RCC_PWRLP_APB1LP   = 221,
	RCC_TIM1LP_APB2LP  = 225,
	RCC_USART1LP_APB2LP= 229,
	RCC_USART6LP_APB2LP,
	RCC_ADC1LP_APB2LP  = 233,
	RCC_SDIOLP_APB2LP  = 236,
	RCC_SPI1LP_APB2LP,
	RCC_SPI4LP_APB2LP,
	RCC_SYSCFLP_APB2LP,
	RCC_TIM9LP_APB2LP  = 240,
	RCC_TIM10LP_APB2LP,
	RCC_TIM11LP_APB2LP

}RCC_Peripherals_opts;
/**************************************************/
/**           RCC APIs Implementaion             **/
/**************************************************/

/************ RCC_SelectSYSCLK ********************/
/* Functionality    : Select sysclk to enable or 
                      disable    
   Input Parameters : 1- System clock
                      2- State required enable and 
					     disable 			      */
/**************************************************/
/**           USER available options             **/
/**************************************************/
/*  
    RCC_CopySYSCLK:       1- RCC_SYSCLK_HSE 
					      2- RCC_SYSCLK_HSI
	                      3- sRCC_SYSCLK_PLL
   
   RCC_CopySYSCLKState :  1- RCC_SYSCLK_Enable
                          2- RCC_SYSCLK_Disable
						  
*/
RCC_ErrorStatus RCC_SelectSYSCLK ( RCC_SYSCLK   RCC_CopySYSCLK  , RCC_SYSCLKState RCC_CopySYSCLKState );

/***************** RCC_PLL_CFG ********************/
/* Functionality    : Configuration for PLL    
   Input Parameters : 1- Input Clock source for PLL :

                         a- RCC_PLL_HSE
	                     b- RCC_PLL_HSI

                      2- State required enable and 
					     disable 			      */
/**************************************************/
/**           USER available options             **/
/**************************************************/
/*  
    RCC_CopySYSCLK:       1- RCC_SYSCLK_HSE 
					      2- RCC_SYSCLK_HSI
	                      3- sRCC_SYSCLK_PLL
   
   RCC_CopySYSCLKState :  1- RCC_SYSCLK_Enable
                          2- RCC_SYSCLK_Disable
						  
   Warning !!          : Make Sure to Disable PLL  
                         CLOCK Before configuring 
						 PLL			  
*/
RCC_ErrorStatus RCC_CFG_PLL(RCC_PLL_SRC Input_PLL_ClkSrc, uint32_t Input_PLL_M, uint32_t Input_PLL_N, uint32_t Input_PLL_P, uint32_t Input_PLL_Q);

/****************************************** RCC_EN_DIS_Peripheral *************************************************/
/* 
   
   Functionality    : Enable or Disable peripheral (sysclk)
   Input Parameters : 1- Peripheral :

									RCC_GPIOA_AHB1     ,RCC_GPIOB_AHB1     ,RCC_CRC_AHB1,      ,RCC_TIM3_APB1 ,
									RCC_GPIOC_AHB1     ,RCC_GPIOD_AHB1     ,RCC_GPIOE_AHB1     ,RCC_GPIOH_AHB1,
									RCC_DMA1_AHB1      ,RCC_DMA2_AHB1      ,RCC_OTGFS_AHB2     ,RCC_TIM2_APB1 ,
									RCC_TIM4_APB1c     ,RCC_TIM5_APB1      ,RCC_WWDG_APB1      ,RCC_SPI2_APB1      ,RCC_SPI3_APB1,
									RCC_USART2_APB1    ,RCC_I2C1_APB1      ,RCC_I2C2_APB1      ,RCC_I2C3_APB1      ,RCC_PWR_APB1,
									RCC_TIM1_APB2      ,RCC_USART1_APB2    ,RCC_USART6_APB2    ,RCC_ADC1_APB2      ,RCC_SDIO_APB2,
									RCC_SPI1_APB2      ,RCC_SPI4_APB2      ,RCC_SYSCF_APB2     ,RCC_TIM9_APB2      ,RCC_TIM10_APB2,
									RCC_TIM11_APB2     ,RCC_GPIOALP_AHB1LP ,RCC_GPIOBLP_AHB1LP ,RCC_GPIOCLP_AHB1LP ,
									RCC_GPIODLP_AHB1LP ,RCC_GPIOELP_AHB1LP ,RCC_GPIOHLP_AHB1LP ,RCC_CRCLP_AHB1LP   ,
									RCC_FLITFLP_AHB1LP ,RCC_SRAM1LP_AHB1LP ,RCC_DMA1LP_AHB1LP  ,RCC_DMA2LP_AHB1LP  ,
									RCC_OTGFSLP_AHB2LP ,RCC_TIM2LP_APB1LP  ,RCC_TIM3LP_APB1LP  ,RCC_TIM4LP_APB1LP  ,
									RCC_TIM5LP_APB1LP  ,RCC_WWDGLP_APB1LP  ,RCC_SPI2LP_APB1LP  ,RCC_SPI3LP_APB1LP  ,
									RCC_USART2LP_APB1LP,RCC_I2C1LP_APB1LP  ,RCC_I2C2LP_APB1LP  ,RCC_I2C3LP_APB1LP  ,
									RCC_PWRLP_APB1LP   ,RCC_TIM1LP_APB2LP  ,RCC_USART1LP_APB2LP,RCC_USART6LP_APB2LP,
									RCC_ADC1LP_APB2LP  ,RCC_SDIOLP_APB2LP  ,RCC_SPI1LP_APB2LP  ,RCC_SPI4LP_APB2LP  ,
									RCC_SYSCFLP_APB2LP ,RCC_TIM9LP_APB2LP  ,RCC_TIM10LP_APB2LP ,RCC_TIM11LP_APB2LP
														
   					  2- peripheral State :

					                a- RCC_Disable_Peripheral 
									b- RCC_Enable_Peripheral


 */
RCC_ErrorStatus RCC_EN_DIS_Peripheral(RCC_Peripherals_opts RCC_Peripheral_EN_opts , RCC_State RCC_Peripheral_State );

/************************************* RCC_Set_Prescaler ********************************/
/* 
	Functionality    : Set BUS PRESCLER value
   
    Input Parameters : 1- Control Bus :
	                                    RCC_AHB_CB,
										RCC_APB1_CB,
										RCC_APB2_CB 
						2- PRESCALER OPTIONS :
*/
						 /*         APB1  Prescaler           */
/*
                         RCC_NO_PREAPB1             RCC_PREAPB1_2  
						 RCC_PREAPB1_4              RCC_PREAPB1_8  
					     RCC_PREAPB1_16   
*/                      

                        /*         APB2  Prescaler           */
/*
                        RCC_NO_PREAPB2              RCC_PREAPB2_2 
					    RCC_PREAPB2_4               RCC_PREAPB2_8 
					    RCC_PREAPB2_16      

*/                        /*         AHB1  Prescaler           */
/*
                       RCC_NO_PREAHB1              RCC_PREAHB1_2    
					   RCC_PREAHB1_4               RCC_PREAHB1_8  
					   RCC_PREAHB1_16              RCC_PREAHB1_64  
					   RCC_PREAHB1_128             RCC_PREAHB1_256    
					   RCC_PREAHB1_512    
*/ 
/*
    Warning          :
	                   1 - when configure  APB prescaler
	                      Caution: 
						    The software has to set
						  these bits correctly not to exceed 
						  84 MHz on this domain. The clocks 
						  are divided with the new prescaler
						  factor from 1 to 16 AHB cycles after 
                          PPRE2 write.

                        2 - when configure  APB1 prescaler
	                      Caution: 
						     The software has to set
						  these bits correctly not to exceed 
						  84 MHz on this domain. The clocks 
						  are divided with the new prescaler
						  factor from 1 to 16 AHB cycles after 
                          PPRE2 write.
	Several prescalers are used to configure the AHB frequency, the high-speed APB (APB2) 
	and the low-speed APB (APB1) domains. The maximum frequency of the AHB domain is 
	84 MHz. The maximum allowed frequency of the high-speed APB2 domain is 84 MHz. The 
	maximum allowed frequency of the low-speed APB1 domain is 42 MHz 
*/
RCC_ErrorStatus RCC_Set_Prescaler(RCC_CONTROL_BUS RCC_ConrolBus ,uint32_t RCC_PrescalerValue);

/************ RCC_GET_SYSCLK ********************/
/* 
   
   Functionality    : Determine what is your 
                      current System clock
   Return           : Current system clock	

 */
RCC_SYSCLK      RCC_GET_SYSCLK(void);