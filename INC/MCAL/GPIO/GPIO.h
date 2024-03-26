/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : GPIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : Febraury 14 , 2024 */
/*	Last Edit : N/A                */
/***********************************/


#ifndef GPIO_H_
#define GPIO_H_

/******************************************************************************************************************************************/
/**************************************************           GPIO   DRIVER         *******************************************************/
/******************************************************************************************************************************************/

/************************************************/
/***         Configuration options            ***/
/************************************************/



#define  GPIO_PORTA  (volatile uint32_t*)0x40020000
#define  GPIO_PORTB  (volatile uint32_t*)0x40020400
#define  GPIO_PORTC  (volatile uint32_t*)0x40020800
#define  GPIO_PORTD  (volatile uint32_t*)0x40020C00
#define  GPIO_PORTE  (volatile uint32_t*)0x40021000
#define  GPIO_PORTH  (volatile uint32_t*)0x40021C00  

typedef  enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15

}GPIO_PINs;
  


typedef enum
{
   GPIO_INPUT_FLOATING = 0,
   GPIO_INPUT_PULLUP,
   GPIO_INPUT_PULLDOWN,
   GPIO_OUTPUT_OPENDRAIN,
   GPIO_OUTPUT_OPENDRAIN_PULLUP,
   GPIO_OUTPUT_OPENDRAIN_PULLDOWN,
   GPIO_OUTPUT_PUSHPULL_PULLUP,
   GPIO_OUTPUT_PUSHPULL_PULLDOWN,
   GPIO_ANALOG,
   GPIO_AF_OPENDRAIN_PULLUP,
   GPIO_AF_OPENDRAIN_PULLDOWN,
   GPIO_AF_PUSHPULL_PULLDOWN,
   GPIO_AF_PUSHPULL_PULLUP

}GPIO_MODE_Direction;


typedef enum
{
   GPIO_LOW_SPEED,
   GPIO_MEDIUM_SPEED,
   GPIO_HIGH_SPEED,
   GPIO_VERY_HIGH_SPEED

}GPIO_IN_OUT_Speed;

typedef enum 
{
    GPIO_AF0_System = 0 ,
    GPIO_AF1_TIM1_2,
    GPIO_AF2_TIM3_5,
    GPIO_AF3_TIM9_11,
    GPIO_AF4_I2C1_3,
    GPIO_AF5_SPI1_4,
    GPIO_AF6_SPI3,
    GPIO_AF7_USART1_2,
    GPIO_AF8_USART6,
    GPIO_AF9_I2C2_3,
    GPIO_AF10_OTG_FS,
    GPIO_AF11,
    GPIO_AF12_SDIO,
    GPIO_AF13,
    GPIO_AF14,
    GPIO_AF15_EVENTOUT,
    GPIO_NOT_AF_MODE

}GPIO_AF_Peripheral;

typedef struct
{
	GPIO_MODE_Direction GPIO_MODE;
	GPIO_IN_OUT_Speed   GPIO_Speed;
	void*               GPIO_PORT;
	GPIO_PINs           GPIO_PIN;
    GPIO_AF_Peripheral  GPIO_AF_PER;

}GPIO_pin_Confguration;



typedef enum
{
    GPIO_Init_ERROR,
    GPIO_Init_NOK,
    GPIO_NULL_PTR,
    GPIO_Init_OK,
    GPIO_SETRESET_NOK,
    GPIO_SETRESET_OK,
    GPIO_READ_OK,
    GPIO_READ_NOK

}GPIO_ErrorStatus;


typedef enum
{
   GPIO_RESET_PIN,
   GPIO_SET_PIN,
   GPIO_NOACTIOM_PIN

}GPIO_SET_opts;


/***************** GPIO_InitPin ********************/
/* Functionality    : Gpio Initialization Function    
   Input Parameters : 1- set port,pin ,pup/down
                         OD , PP ,Speed			   */
/***************************************************/
/**           USER available options              **/
/***************************************************/
/*  
    GPIO_Input_PinConfg: 
    Iput Argument      :
                        struct:
                        --------
                        GPIO_MODE;
                                 {
                        Input:      GPIO_INPUT_FLOATING            ,GPIO_INPUT_PULLUP,
                                    GPIO_INPUT_PULLDOWN       
                                   
                        Output:     GPIO_OUTPUT_OPENDRAIN,          GPIO_OUTPUT_OPENDRAIN_PULLUP  
                                    GPIO_OUTPUT_OPENDRAIN_PULLDOWN, GPIO_OUTPUT_PUSHPULL_PULLUP, 
                                    GPIO_OUTPUT_PUSHPULL_PULLDOWN,
                        
                        Analog:     GPIO_ANALOG,
           
                        Alternate 
                        Function:   GPIO_AF_OPENDRAIN_PULLUP        GPIO_AF_OPENDRAIN_PULLDOWN,
                                    GPIO_AF_PUSHPULL_PULLDOWN,      GPIO_AF_PUSHPULL_PULLUP
                                }

                        GPIO_Speed: 
                                {
                                   GPIO_LOW_SPEED,
                                   GPIO_MEDIUM_SPEED,
                                   GPIO_HIGH_SPEED,
                                   GPIO_VERY_HIGH_SPEED 
                                }
                        GPIO_PORT:
                                {
                                     GPIO_PORTA, GPIO_PORTB,
                                     GPIO_PORTC, GPIO_PORTD,
                                     GPIO_PORTE, GPIO_PORTH
                                }
                        GPIO_PIN;
                                {
                                    GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,
                                    GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,
                                    GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,
                                    GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15
                                }
                        GPIO_AF_PER;
			  
*/
GPIO_ErrorStatus GPIO_InitPin(GPIO_pin_Confguration* GPIO_Arg_PinConfg);

/********************** GPIO_SetPin_Value ********************/
/*
    Functionality    : atomic operations for setting or 
                       clearing multiple pins simultaneously
                       without affecting the other pins,whihle
                       GPIOx_ODR 
                       directly sets or clears individual
                       pin states  
*/
/************************************************************/
/**                    USER available options              **/
/************************************************************/
/*   
    GPIO_PORT:
                    {
                            GPIO_PORTA, GPIO_PORTB,
                            GPIO_PORTC, GPIO_PORTD,
                            GPIO_PORTE, GPIO_PORTH
                    }
    GPIO_PIN:
                    {
                        GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,
                        GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,
                        GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,
                        GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15
                    }
    GPIO_SET_opts:    
                    {
                        GPIO_RESET_PIN,
                        GPIO_SET_PIN,
                        GPIO_NOACTIOM_PIN
                    }  
  			  
*/
GPIO_ErrorStatus GPIO_SetPin_Value(GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_SET_opts GPIO_Arg_SET_VAL);

/**************** GPIO_GetPin_Value ***************/
/* Functionality    : return signal on pin 1 or 0    
   Input Parameters : 1- GPIO_PORT
                      2- GPIO_PIN NUMBER
                      3- ADDRESS OF VARIABLE TO 
                         RETURN VALUE IN 
                                  			      */
/**************************************************/
/**           USER available options             **/
/**************************************************/
/*  
 
    GPIO_PORT:
                {
                    GPIO_PORTA, GPIO_PORTB,
                    GPIO_PORTC, GPIO_PORTD,
                    GPIO_PORTE, GPIO_PORTH
                }
    GPIO_PIN:
                {
                    GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,
                    GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7,
                    GPIO_PIN8,GPIO_PIN9,GPIO_PIN10,GPIO_PIN11,
                    GPIO_PIN12,GPIO_PIN13,GPIO_PIN14,GPIO_PIN15
                }
	Create uint32_t local_variable_name in your function and 
    pass its address " &local_variable_name " 

*/
GPIO_ErrorStatus GPIO_GetPin_Value(GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_SET_opts *GPIO_Arg_Value);


#endif