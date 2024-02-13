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


#define RCC_AHB1_BUS                    0
#define RCC_AHB2_BUS                    1
#define RCC_APB1_BUS                    2
#define RCC_APB2_BUS                    3


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


/*******************************************************/
/*For user system clock options*/
typedef enum
{
	RCC_SYSCLK_HSE = 0,
	RCC_SYSCLK_HSI,
	RCC_SYSCLK_PLL
	
}RCC_SYSCLK;
/*For user clk state options*/
typedef enum
{
	RCC_SYSCLK_Enable = 0,
	RCC_SYSCLK_Disable
	
}RCC_SYSCLKState;

typedef enum
{
	RCC_Enable = 0,
	RCC_Disable
	
}RCC_State;

typedef struct
{
	RCC_PLL_HSE;
	RCC_PLL_HSI;
	
}RCC_PLL_SRC;


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
typedef enum
{
	RCC_SYSCLKEnable_OK,
	RCC_SYSCLKDisable_OK,
	RCC_SYSCLKEnable_ERROR,
	RCC_SYSCLKDisable_ERROR,
	RCC_SelectSYSCLK_ERROR,
	RCC_PeripheralEnable_OK,
	RCC_PeripheralEnable_ERROR,
	RCC_PeripheralDisable_OK,
	RCC_PeripheralDisable_ERROR,
	RCC_RDY,
	RCC_NRDY,
	RCC_PLLCFG_FAILED,
	RCC_PLLCFG_OK,
	RCC_PLLCFG_COMPLETED,
	RCC_SYSCLK_SWITCHED

}RCC_ErrorStatus;
typedef unsigned long uint32_t;

typedef struct RCC_PLLConfig
{
	RCC_PLL_SRC RCC_PLL_ClkSrc;
	uint32_t    RCC_PLL_M;
	uint32_t    RCC_PLL_N;
	uint32_t    RCC_PLL_P;
	uint32_t    RCC_PLL_Q;
	
} RCC_PLLConfig ;


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
						  
   Warning !!          : Make Sure to Disable PLL  
                         CLOCK Before configuring 
						 PLL			  
*/
RCC_ErrorStatus RCC_CFG_PLL      ( RCC_PLLConfig.RCC_PLL_ClkSrc   Input_PLL_ClkSrc  , RCC_PLLConfig.RCC_PLL_M Input_PLL_M, RCC_PLLConfig.RCC_PLL_N Input_PLL_N, RCC_PLLConfig.RCC_PLL_P Input_PLL_P , RCC_PLLConfig.RCC_PLL_Q  Input_PLL_Q );

RCC_ErrorStatus RCC_Control_Peripheral(uint32_t RCC_Peripheral_EN , uint32_t RCC_Peripheral_BUS , RCC_State RCC_Peripheral_State );

RCC_ErrorStatus RCC_Set_AHB_Prescaler(uint32_t RCC_AHBPrescalerValue);

RCC_ErrorStatus RCC_Set_APB1_Prescaler(uint32_t RCC_APB1PrescalerValue);

RCC_ErrorStatus RCC_Set_APB2_Prescaler(uint32_t RCC_APB2PrescalerValue);