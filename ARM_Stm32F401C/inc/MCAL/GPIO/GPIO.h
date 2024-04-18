/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : GPIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : Febraury 14 , 2024 */
/*	Last Edit : N/A                */
/***********************************/

/*************************************************************/
/****************    GPIO   DRIVER    ************************/
/*************************************************************/
#include "Typedefs.h"
/************************************************/
/***         Configuration options            ***/
/************************************************/

#define GPIO_PORTA_v2    (void*)0x40020000
#define GPIO_PORTB_v2    (void*)0x40020400
#define GPIO_PORTC_v2    (void*)0x40020800
#define GPIO_PORTD_v2    (void*)0x40020C00
#define GPIO_PORTE_v2    (void*)0x40021000
#define GPIO_PORTH_v2    (void*)0x40021C00

/*
       5   4   3   2   1   0
     -------------------------
     | 0 | 0 | 0 | 0 | 0 | 0 | 
     -------------------------
              
    ---------------------------    
    |   [0:1]   |  I/O/AF/ANA |
    --------------------------|
    |   00 ->   |  INPUT      |
    |   01 ->   |  OUTPUT     |
    |   10 ->   |  AF         |
    |   11 ->   |  ANALOG     |
    ---------------------------
    -----------------------------    
    |   [3:2]    |   PU/PD/FL   |
    ----------------------------|
    |   00 ->    |  FOATING     |
    |   01 ->    |  PULLUP      |
    |   10 ->    |  PULLDOWN    |
    |   11 ->    |  RESERVED    |
    -----------------------------

    ----------------------------    
    |    [4]    |    OD-PP     |
    ---------------------------|
    |    0 ->   |   PUSHPULL   |
    |    1 ->   |  OPENDRAIN   |
    ----------------------------

    ----------------------------    
    |    [5]    | LOCK-UNLOCK  |
    ---------------------------|
    |    0 ->   |  NOT ACTIVE  |
    |    1 ->   |    ACTIVE    |
    ----------------------------
*/

#define GPIO_INPUT_FLOATING_V2            0X00000000
#define GPIO_INPUT_PULLUP_V2              0X00000004
#define GPIO_INPUT_PULLDOWN_V2            0X00000008
#define GPIO_OUTPUT_OPENDRAIN_V2          0X00000011
#define GPIO_OUTPUT_OPENDRAIN_PULLUP_V2   0X00000015
#define GPIO_OUTPUT_OPENDRAIN_PULLDOWN_V2 0X00000019
#define GPIO_OUTPUT_PUSHPULL_PULLUP_V2    0X00000005
#define GPIO_OUTPUT_PUSHPULL_PULLDOWN_V2  0X00000009
#define GPIO_OUTPUT_PUSHPULL_NOPUPD_V2    0X00000001
#define GPIO_ANALOG_V2                    0X00000003    
#define GPIO_AF_OPENDRAIN_PULLUP_V2       0X00000016
#define GPIO_AF_OPENDRAIN_PULLDOWN_V2     0X0000001A
#define GPIO_AF_PUSHPULL_PULLDOWN_V2      0X0000000A
#define GPIO_AF_PUSHPULL_PULLUP_V2        0X00000006
#define GPIO_AF_PUSHPULL_NOPUPD_V2        0X00000002

/************************************************/
/***         Configuration options            ***/
/************************************************/

//typedef unsigned int uint32_t;
typedef  enum
{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTH

}GPIO_PORTs;

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

typedef enum
{
    GPIO_PIN_LOW,
    GPIO_PIN_HIGH

}GPIO_PIN_STATE_t;

typedef struct
{
	uint32_t            GPIO_MODE;
	GPIO_IN_OUT_Speed   GPIO_Speed;
	GPIO_PORTs          GPIO_PORT;
	GPIO_PINs           GPIO_PIN;
    GPIO_AF_Peripheral  GPIO_AF_PER;

}GPIO_pin_Confguration;

/*V2-> With new edit */
typedef struct
{
	uint32_t            GPIO_MODE;
	GPIO_IN_OUT_Speed   GPIO_Speed;
	void*               GPIO_PORT;/*Pointer user through #define send dir the reg address*/
	GPIO_PINs           GPIO_PIN;
    GPIO_AF_Peripheral  GPIO_AF_PER;

}GPIO_pin_Confguration_V2;

typedef enum
{
    GPIO_Init_ERROR,
    GPIO_Init_NOK,
    GPIO_NULL_PTR,
    GPIO_Init_OK,
    GPIO_SETRESET_NOK,
    GPIO_SETRESET_OK,
    GPIO_READ_OK,
    GPIO_READ_NOK,
    GPIO_INVALID_PORT_PIN,
    GPIO_INVALID_MODE,
    GPIO_INVALID_STATE

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

/***************** GPIO_InitPin_v2 ********************/
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
                                     GPIO_PORTA_v2, GPIO_PORTB_v2,
                                     GPIO_PORTC_v2, GPIO_PORTD_v2,
                                     GPIO_PORTE_v2, GPIO_PORTH_v2
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
GPIO_ErrorStatus GPIO_InitPin_v2(GPIO_pin_Confguration_V2* GPIO_Arg_PinConfg);
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
GPIO_ErrorStatus GPIO_SetPin_Value(GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t GPIO_Arg_SET_VAL);
GPIO_ErrorStatus GPIO_SetPin_Value_V2(void* GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t GPIO_Arg_SET_VAL);

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
GPIO_ErrorStatus GPIO_GetPin_Value_V2(void* GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t *GPIO_Arg_Value);