/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : GPIO   		       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : Febraury 14 , 2024 */
/*	Last Edit : N/A                */
/***********************************/



/*********************************************************************************************************************************************************/
/**************************************************           SYSCLK RCC DRIVER                    *******************************************************/
/*********************************************************************************************************************************************************/
#include "GPIO.h"
/*********************************************************************************************************************************************************/
/**************************************************             Defines Region                     *******************************************************/
/*********************************************************************************************************************************************************/

/*Start from 0->15  0-5*/
#define GPIO_PIN_NUM               15
#define GPIO_PORT_NUM              5 

#define GPIO_FLAG_OUTPUT_ON        3
#define GPIO_FLAG_AF_ON            2
#define GPIO_FLAG_ON               1
#define GPIO_FLAG_OFF              0

/*************************************************************/
/**                  GPIO_Regisers_Addresses               ***/
/*************************************************************/
/*************************************************************/
    /*Definition of GPIO_typedef Reminder :
    -----------------------------------------
    *   The GPIO_typedef is defined as a volatile pointer to
        a GPIOx_REGs structure. 

    Definition of GPIOA:
    --------------------
    *   GPIOA is defined as a static variable of type
        GPIO_typedef to limit its access to this file only,
        initialized to the base address of GPIOA 
        (GPIOA_BASEADD).

    Use of volatile:
    -----------------
    *   The use of volatile ensures that the compiler doesn't
        optimize away accesses to the GPIO registers, 
        which is essential for register-based programming.

    Use of const:
    -----------------
    *   The use of const ensures that this pointer always
        points to same Group of register address 
        become fixed to them.
*/
/*************************************************************/
#define GPIO_typedef    volatile GPIOx_REGs* const 
#define NULL            ((void*)0)

#define GPIOA_BASEADD   0x40020000
#define GPIOB_BASEADD   0x40020400
#define GPIOC_BASEADD   0x40020800
#define GPIOD_BASEADD   0x40020C00
#define GPIOE_BASEADD   0x40021000
#define GPIOH_BASEADD   0x40021C00


/************************************************/
/********          PIN  Masks                 ***/
/************************************************/
/*Mask should be 32 bit for correct config !*/
#define GPIO_MASK_1bitMODE(GPIO_MASK,BIT_NUM)     (GPIO_MASK<<(BIT_NUM))
#define GPIO_MASK_2bitMODE(GPIO_MASK,BIT_NUM)     (GPIO_MASK<<(BIT_NUM*2))
#define GPIO_MASK_4bitMODE(GPIO_MASK,BIT_NUM)     (GPIO_MASK<<(BIT_NUM*4))
#define GPIO_RESET_BITNUM(BIT_NUM)                (BIT_NUM+16)
#define GPIO_SET_BITNUM(BIT_NUM)                  (BIT_NUM)

/* CHECKS V2 */
#define GPIO_CHECK_PORT(PORT)      ((PORT == GPIO_PORTA_v2) ||\
                                    (PORT == GPIO_PORTB_v2) ||\
                                    (PORT == GPIO_PORTC_v2) ||\
                                    (PORT == GPIO_PORTD_v2) ||\
                                    (PORT == GPIO_PORTE_v2) ||\
                                    (PORT == GPIO_PORTH_v2))  

#define GPIO_CHECK_PIN(PIN)        ((PIN>=GPIO_PIN0) && (PIN <= GPIO_PIN15))
#define GPIO_CHECK_MODE(MODE)      ((MODE>=GPIO_INPUT_FLOATING) && (MODE <= GPIO_AF_PUSHPULL_PULLUP))
#define GPIO_CHECK_MODE_V2(MODE)   ((MODE == GPIO_AF_PUSHPULL_NOPUPD_V2) ||\
                                    (MODE == GPIO_OUTPUT_PUSHPULL_NOPUPD_V2) ||\
                                    (MODE==GPIO_INPUT_FLOATING_V2) || \
                                    (MODE == GPIO_INPUT_PULLUP_V2) || \
                                    (MODE == GPIO_INPUT_PULLDOWN_V2) || \
                                    (MODE == GPIO_OUTPUT_OPENDRAIN_V2) || \
                                    (MODE == GPIO_OUTPUT_OPENDRAIN_PULLUP_V2) ||\
                                    (MODE == GPIO_OUTPUT_OPENDRAIN_PULLDOWN_V2) ||\
                                    (MODE == GPIO_OUTPUT_PUSHPULL_PULLUP_V2) ||\
                                    (MODE == GPIO_OUTPUT_PUSHPULL_PULLDOWN_V2 ) ||\
                                    (MODE == GPIO_ANALOG_V2) ||\
                                    (MODE == GPIO_AF_OPENDRAIN_PULLUP_V2 ) ||\
                                    (MODE == GPIO_AF_OPENDRAIN_PULLDOWN_V2) ||\
                                    (MODE == GPIO_AF_PUSHPULL_PULLDOWN_V2) ||\
                                    (MODE == GPIO_AF_PUSHPULL_PULLUP_V2))

#define GPIO_CHECK_STATE(STATE)    ((STATE==GPIO_PIN_LOW) || (STATE == GPIO_PIN_LOW))


#define GPIO_INPUT_MASK              0X00000000
#define GPIO_OUTPUT_MASK             0X00000001
#define GPIO_AF_MASK                 0X00000002
#define GPIO_ANALOG_MASK             0X00000003

#define GPIO_NOPUPD_MASK             0X00000000
#define GPIO_PULLUP_MASK             0X00000001
#define GPIO_PULLDOWN_MASK           0X00000002

#define GPIO_PIN_MASK(PIN_NUM)      (0X00000001<<(PIN_NUM))

/* MODE V2 */

#define GPIO_MASK_2BIT        0X00000003
#define GPIO_MASK_1BIT        0X00000001
#define GPIO_MASK_4BIT        0X0000000F


#define GPIO_CFG(MODE)        ((MODE)    & GPIO_MASK_2BIT)
#define GPIO_PU_PD(MODE)      ((MODE>>2) & GPIO_MASK_2BIT)
#define GPIO_PP_OD(MODE)      ((MODE>>4) & GPIO_MASK_1BIT)
#define GPIO_LOCK(MODE)       ((MODE>>5) & GPIO_MASK_1BIT)
#define GPIO_AF_SET(MODE)     ((MODE) & GPIO_MASK_4BIT)



/************************************************/
/********          Data  Types                ***/
/************************************************/
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef enum
{
	GPIO_CLEAR,
	GPIO_SET,
	GPIO_TOGGLE

}GPIO_REG_OPER;

/***********  GPIO REG struct Typedf  ***********/

typedef struct 
{
     uint32_t GPIO_MODER;
     uint32_t GPIO_OTYPE; 
     uint32_t GPIO_OSPEEDR; 
     uint32_t GPIO_PUPDR; 
     uint32_t GPIO_IDR; 
     uint32_t GPIO_ODR; 
     uint32_t GPIO_BSRR; 
     uint32_t GPIO_LCKR; 
     uint32_t GPIO_AFRL; 
     uint32_t GPIO_AFRH; 
    
}GPIOx_REGs;

GPIOx_REGs * GPIOx = NULL;

/***********  GPIOREG pointers Typedf  ***********/

static  GPIO_typedef GPIOA = (GPIO_typedef) GPIOA_BASEADD;
static  GPIO_typedef GPIOB = (GPIO_typedef) GPIOB_BASEADD;
static  GPIO_typedef GPIOC = (GPIO_typedef) GPIOC_BASEADD;
static  GPIO_typedef GPIOD = (GPIO_typedef) GPIOD_BASEADD;
static  GPIO_typedef GPIOE = (GPIO_typedef) GPIOE_BASEADD;
static  GPIO_typedef GPIOH = (GPIO_typedef) GPIOH_BASEADD;



/*********************************************************************************************************************************************************/
/*********************************************         Static Functions Prototypes Region        *****************************************************/
/*********************************************************************************************************************************************************/

static uint32_t GPIO_EDIT_REG_MASK    (uint32_t GPIO_REG_EDIT,uint32_t GPIO_MASK, GPIO_REG_OPER OPERA);
static uint32_t GPIO_EDIT_Bit_Reg     (uint32_t GPIO_REG_EDIT,uint32_t BIT_NUM,GPIO_REG_OPER OPERA);
static GPIO_ErrorStatus GPIOx_INIT    (GPIO_pin_Confguration * GPIO_Arg_PinConfg,GPIO_typedef GPIOx);
static GPIO_ErrorStatus GPIOx_SET_REST(GPIO_typedef GPIOx,GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_SET_opts GPIO_Arg_SET_VAL);

/*********************************************************************************************************************************************************/
/***************************************************************** Functions Implementation **************************************************************/
/*********************************************************************************************************************************************************/


GPIO_ErrorStatus GPIO_InitPin(GPIO_pin_Confguration * GPIO_ARG_PinConfg)
{
    
    GPIO_ErrorStatus GPIO_Loc_Error =GPIO_Init_NOK;



    if(GPIO_ARG_PinConfg == NULL)
    {
        GPIO_Loc_Error = GPIO_NULL_PTR;

    }
    else if (!(GPIO_ARG_PinConfg ->GPIO_PORT >= GPIO_PORTA && GPIO_ARG_PinConfg ->GPIO_PORT <=GPIO_PORTH))
    {
        GPIO_Loc_Error = GPIO_Init_ERROR;
    }
      else if (!(GPIO_ARG_PinConfg ->GPIO_PIN >= GPIO_PIN0 && GPIO_ARG_PinConfg ->GPIO_PIN <=GPIO_PIN15))
    {
        GPIO_Loc_Error = GPIO_Init_ERROR;
    }
    else
    {
        GPIO_Loc_Error = GPIO_Init_ERROR;
        
        switch (GPIO_ARG_PinConfg->GPIO_PORT)
        {
            
            case GPIO_PORTA :
            {
                GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOA);
                GPIO_Loc_Error = GPIO_Init_OK ;

            }break;
            case GPIO_PORTB :
            {
                GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOB);
                GPIO_Loc_Error = GPIO_Init_OK ;

            }break;
            case GPIO_PORTC :
            {
                GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOC);
                GPIO_Loc_Error = GPIO_Init_OK ;

            }break;
            case GPIO_PORTD :
            {
               GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOD);
               GPIO_Loc_Error = GPIO_Init_OK ;

            }break;
            case GPIO_PORTE :
            {
                GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOE);
                GPIO_Loc_Error = GPIO_Init_OK ;

            }break;
            case GPIO_PORTH :
            {

                GPIOx_INIT(GPIO_ARG_PinConfg ,GPIOH);
                GPIO_Loc_Error = GPIO_Init_OK ;

            }break;  
             default :
             {
                 GPIO_Loc_Error = GPIO_Init_NOK ;

             }break;      

        } 
        

    }
    return GPIO_Loc_Error;    
    
}
GPIO_ErrorStatus GPIO_InitPin_v2(GPIO_pin_Confguration_V2* GPIO_Arg_PinConfg)
{
    GPIO_ErrorStatus GPIO_Loc_Error =GPIO_Init_OK;
     uint32_t GPIO_Loc_Mask = 0x00000000;

    if(!GPIO_Arg_PinConfg)
    {
       GPIO_Loc_Error =GPIO_NULL_PTR; 
    }
    else if(!GPIO_CHECK_PORT(GPIO_Arg_PinConfg->GPIO_PORT) && !(GPIO_CHECK_PIN(GPIO_Arg_PinConfg->GPIO_PIN)) )
    {
        GPIO_Loc_Error = GPIO_INVALID_PORT_PIN;
    }
    else if (!GPIO_CHECK_MODE_V2(GPIO_Arg_PinConfg->GPIO_MODE))
    {
         GPIO_Loc_Error = GPIO_INVALID_MODE;
    }
    else
    {
        /*Typedef*/
        GPIOx = (GPIOx_REGs*)(GPIO_Arg_PinConfg->GPIO_PORT);
        /*MODE SET (INPUT-OUTPUT-ANALOG-AF)*/
        GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_CFG(GPIO_Arg_PinConfg->GPIO_MODE),GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_MODER   = GPIO_EDIT_REG_MASK(GPIOx->GPIO_MODER ,GPIO_Loc_Mask,GPIO_SET);
        /*PULLUP-PULLDOWN-FLOATING*/
        GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_PU_PD(GPIO_Arg_PinConfg->GPIO_MODE),GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_PUPDR   = GPIO_EDIT_REG_MASK(GPIOx->GPIO_PUPDR,GPIO_Loc_Mask,GPIO_SET);
        /*PUSHPULL-OPENDRAIN*/
        GPIO_Loc_Mask       = GPIO_MASK_1bitMODE(GPIO_PP_OD(GPIO_Arg_PinConfg->GPIO_MODE),GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_OTYPE   = GPIO_EDIT_REG_MASK(GPIOx->GPIO_PUPDR,GPIO_Loc_Mask,GPIO_SET);
        /*OUTPUT -> SPEED*/
        GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_Arg_PinConfg->GPIO_Speed,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR,GPIO_Loc_Mask,GPIO_SET);
        /*Peripheral set */
        if((GPIO_Arg_PinConfg->GPIO_PIN >= 7 )&&(GPIO_Arg_PinConfg->GPIO_PIN <= 0 ))
        {
            GPIO_Loc_Mask       = GPIO_MASK_4bitMODE(GPIO_AF_SET(GPIO_Arg_PinConfg->GPIO_AF_PER),GPIO_Arg_PinConfg->GPIO_PIN);
            GPIOx->GPIO_AFRL    = GPIO_EDIT_REG_MASK(GPIOx->GPIO_AFRL ,GPIO_Loc_Mask,GPIO_SET);
        }
        else
        {
            GPIO_Loc_Mask       = GPIO_MASK_4bitMODE(GPIO_AF_SET(GPIO_Arg_PinConfg->GPIO_AF_PER),((GPIO_Arg_PinConfg->GPIO_PIN)-8));
            GPIOx->GPIO_AFRH    = GPIO_EDIT_REG_MASK(GPIOx->GPIO_AFRH ,GPIO_Loc_Mask,GPIO_SET);
        }
    }
    
    return GPIO_Loc_Error;    

}

GPIO_ErrorStatus GPIO_SetPin_Value(GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t GPIO_Arg_SET_VAL)
{
    GPIO_ErrorStatus Gpio_Loc_error = GPIO_Init_NOK ;
    switch (GPIO_Arg_Port)
    {
     case GPIO_PORTA :
            {
              
                Gpio_Loc_error = GPIOx_SET_REST(GPIOA,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);
                
            }break;
            case GPIO_PORTB :
            {
                Gpio_Loc_error = GPIOx_SET_REST(GPIOB,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);
            }break;
            case GPIO_PORTC :
            {
                Gpio_Loc_error = GPIOx_SET_REST(GPIOC,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);

            }break;
            case GPIO_PORTD :
            {
              Gpio_Loc_error = GPIOx_SET_REST(GPIOD,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);

            }break;
            case GPIO_PORTE :
            {
                Gpio_Loc_error = GPIOx_SET_REST(GPIOE,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);

            }break;
            case GPIO_PORTH :
            {
                Gpio_Loc_error = GPIOx_SET_REST(GPIOH,GPIO_Arg_Port,GPIO_Arg_Pin,GPIO_Arg_SET_VAL);
               
            }break;            

    }
    return Gpio_Loc_error;


}


GPIO_ErrorStatus GPIO_SetPin_Value_V2(void* GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t GPIO_Arg_SET_VAL)
{
    GPIO_ErrorStatus GPIO_Loc_error = GPIO_SETRESET_OK ;

    if( !GPIO_CHECK_PORT(GPIO_Arg_Port) && !(GPIO_CHECK_PIN(GPIO_Arg_Pin)) )
    {
        GPIO_Loc_error = GPIO_INVALID_PORT_PIN;
    }
    if(!GPIO_CHECK_STATE(GPIO_Arg_SET_VAL))
    {
        GPIO_Loc_error = GPIO_INVALID_STATE;
    }

    GPIOx = (GPIOx_REGs*)(GPIO_Arg_Port);
   
   if (GPIO_Arg_SET_VAL == GPIO_PIN_HIGH )
   {
     GPIOx->GPIO_BSRR = GPIO_EDIT_Bit_Reg( GPIOx->GPIO_BSRR ,GPIO_SET_BITNUM(GPIO_Arg_Pin) ,GPIO_SET);
   }
   else if(GPIO_Arg_SET_VAL == GPIO_PIN_LOW )
   {
         GPIOx->GPIO_BSRR = GPIO_EDIT_Bit_Reg( GPIOx->GPIO_BSRR ,GPIO_RESET_BITNUM(GPIO_Arg_Pin) ,GPIO_SET);
   }
   else
   {
     GPIO_Loc_error = GPIO_SETRESET_NOK ;

   }

    return GPIO_Loc_error;
}


GPIO_ErrorStatus GPIO_GetPin_Value_V2(void* GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_PIN_STATE_t *GPIO_Arg_Value)
{
    GPIO_ErrorStatus GPIO_Loc_error = GPIO_SETRESET_OK;
  
    if( !GPIO_CHECK_PORT(GPIO_Arg_Port) && !(GPIO_CHECK_PIN(GPIO_Arg_Pin)) )
    {
        GPIO_Loc_error = GPIO_INVALID_PORT_PIN;
    }
    if(GPIO_Arg_Value == NULL)
    {
        GPIO_Loc_error = GPIO_NULL_PTR;
    }

   
    
    return GPIO_Loc_error;  
}
/**/
GPIO_ErrorStatus GPIO_GetPin_Value(GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_SET_opts *GPIO_Arg_Value)
{
    GPIO_ErrorStatus Gpio_Loc_error = GPIO_SETRESET_OK;
    if(GPIO_Arg_Value == NULL)
    {
        Gpio_Loc_error = GPIO_NULL_PTR;
    }
    else if(GPIO_Arg_Pin <= GPIO_PIN0  && GPIO_Arg_Pin >= GPIO_PIN15 )
    {
          switch (GPIO_Arg_Port)
        {
            case GPIO_PORTA :
                {
                
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;
                    
                }break;
                case GPIO_PORTB :
                {
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;
                }break;
                case GPIO_PORTC :
                {
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;
                }break;
                case GPIO_PORTD :
                {
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;

                }break;
                case GPIO_PORTE :
                {
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;

                }break;
                case GPIO_PORTH :
                {
                    *GPIO_Arg_Value = ((GPIOA->GPIO_IDR) & GPIO_PIN_MASK(GPIO_Arg_Pin));
                    Gpio_Loc_error = GPIO_READ_OK;
                
                }break;
                default :
                {
                    Gpio_Loc_error = GPIO_READ_NOK;
                }break;
        }
    }
    else
    {
        Gpio_Loc_error = GPIO_READ_NOK;
    }
    
    return Gpio_Loc_error;
   
}
static GPIO_ErrorStatus GPIOx_SET_REST(GPIO_typedef GPIOx,GPIO_PORTs GPIO_Arg_Port,GPIO_PINs GPIO_Arg_Pin,GPIO_SET_opts GPIO_Arg_SET_VAL)
{
    GPIO_ErrorStatus Gpio_Loc_error = GPIO_SETRESET_OK;

      if (GPIO_SET_PIN)
        {
            GPIOx->GPIO_BSRR = GPIO_EDIT_Bit_Reg(GPIOA->GPIO_BSRR,GPIO_SET_BITNUM(GPIO_Arg_Pin),GPIO_SET);
        }
        else if(GPIO_RESET_PIN)
        {
            GPIOx->GPIO_BSRR = GPIO_EDIT_Bit_Reg(GPIOA->GPIO_BSRR,GPIO_RESET_BITNUM(GPIO_Arg_Pin),GPIO_SET);  
        }
        else
        {
            GPIOx->GPIO_BSRR = GPIO_EDIT_Bit_Reg(GPIOA->GPIO_BSRR,GPIO_SET_BITNUM(GPIO_Arg_Pin),GPIO_CLEAR);  
            Gpio_Loc_error = GPIO_SETRESET_NOK;
        }
        return Gpio_Loc_error;
}

static GPIO_ErrorStatus GPIOx_INIT(GPIO_pin_Confguration * GPIO_Arg_PinConfg,GPIO_typedef GPIOx)
{
    uint32_t GPIO_Loc_Mask = 0x00000000;
    uint8_t loc_Flag = GPIO_FLAG_OFF;
    GPIO_ErrorStatus Gpio_Loc_error = GPIO_Init_NOK ;


    if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_INPUT_FLOATING) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_INPUT_PULLUP) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_INPUT_PULLDOWN))
    {
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_INPUT_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_MODER = GPIO_EDIT_REG_MASK(GPIOx->GPIO_MODER ,GPIO_Loc_Mask,GPIO_SET);
    }
    else if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLDOWN) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLUP) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_PUSHPULL_PULLDOWN) ||(GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_PUSHPULL_PULLUP) )
    {
                                  /*Flag ON indicates that this cofig needs OPEN_DRAIN PUSH_PULL setting*/
        loc_Flag = GPIO_FLAG_OUTPUT_ON;
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_OUTPUT_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_MODER = GPIO_EDIT_REG_MASK(GPIOx->GPIO_MODER ,GPIO_Loc_Mask,GPIO_SET);
    }
    else if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_OPENDRAIN_PULLDOWN) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_OPENDRAIN_PULLUP) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_PUSHPULL_PULLDOWN) ||(GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_PUSHPULL_PULLUP) )
   {
        loc_Flag = GPIO_FLAG_AF_ON;
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_AF_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_MODER = GPIO_EDIT_REG_MASK(GPIOx->GPIO_MODER ,GPIO_Loc_Mask,GPIO_SET);
    }
    else if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_ANALOG))
    {
        
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_ANALOG_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_MODER = GPIO_EDIT_REG_MASK(GPIOx->GPIO_MODER ,GPIO_Loc_Mask,GPIO_SET);
    }
                                             /**Setting opendrain and pushpull option*/
    if(loc_Flag)
    {
        if((GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_OUTPUT_PUSHPULL_PULLDOWN) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_OUTPUT_PUSHPULL_PULLUP) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_AF_PUSHPULL_PULLDOWN) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_AF_PUSHPULL_PULLUP))
        {
              GPIOx->GPIO_OTYPE = GPIO_EDIT_Bit_Reg(GPIOx->GPIO_OTYPE,GPIO_Arg_PinConfg->GPIO_PIN,GPIO_CLEAR);
        }
        else if((GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_OUTPUT_OPENDRAIN) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLDOWN) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLUP) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_AF_OPENDRAIN_PULLDOWN) || (GPIO_Arg_PinConfg -> GPIO_MODE == GPIO_AF_OPENDRAIN_PULLUP))
        {
              GPIOx->GPIO_OTYPE = GPIO_EDIT_Bit_Reg(GPIOx->GPIO_OTYPE,GPIO_Arg_PinConfg->GPIO_PIN,GPIO_SET);
        }
                                                     /**Setting output speed option*/
         switch (GPIO_Arg_PinConfg->GPIO_Speed)
         {
            case GPIO_LOW_SPEED:
                {
                    GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_LOW_SPEED,GPIO_Arg_PinConfg->GPIO_PIN);
                    GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR ,GPIO_Loc_Mask,GPIO_SET);
                }break;
             case GPIO_MEDIUM_SPEED:
                {
                    GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_MEDIUM_SPEED,GPIO_Arg_PinConfg->GPIO_PIN);
                    GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR ,GPIO_Loc_Mask,GPIO_SET);
                }break;

            case GPIO_HIGH_SPEED:
                {
                    GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_HIGH_SPEED,GPIO_Arg_PinConfg->GPIO_PIN);
                    GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR ,GPIO_Loc_Mask,GPIO_SET);
                }break;
            case GPIO_VERY_HIGH_SPEED:
                {
                    GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_VERY_HIGH_SPEED,GPIO_Arg_PinConfg->GPIO_PIN);
                    GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR ,GPIO_Loc_Mask,GPIO_SET);
                }break;
            default:
            {

                   GPIO_Loc_Mask       = GPIO_MASK_2bitMODE(GPIO_LOW_SPEED,GPIO_Arg_PinConfg->GPIO_PIN);
                   GPIOx->GPIO_OSPEEDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_OSPEEDR ,GPIO_Loc_Mask,GPIO_SET);
            } break;
         }
    }

                                                  /**********  PULLUP PULLDOWN  ***********/
    if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_INPUT_FLOATING) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN) )
    {
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_NOPUPD_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_PUPDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_PUPDR ,GPIO_Loc_Mask,GPIO_SET);
    }
    else if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLDOWN) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_PUSHPULL_PULLDOWN) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_OPENDRAIN_PULLDOWN) || ( GPIO_Arg_PinConfg->GPIO_MODE == GPIO_AF_PUSHPULL_PULLDOWN))
    {
        
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_PULLDOWN_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_PUPDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_PUPDR ,GPIO_Loc_Mask,GPIO_SET);
    }
    else if((GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_OUTPUT_OPENDRAIN_PULLUP) || (GPIO_Arg_PinConfg ->GPIO_MODE ==GPIO_OUTPUT_PUSHPULL_PULLUP) || (GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_OPENDRAIN_PULLUP) ||(GPIO_Arg_PinConfg ->GPIO_MODE == GPIO_AF_PUSHPULL_PULLUP) )
    {
        GPIO_Loc_Mask     = GPIO_MASK_2bitMODE(GPIO_PULLUP_MASK,GPIO_Arg_PinConfg->GPIO_PIN);
        GPIOx->GPIO_PUPDR = GPIO_EDIT_REG_MASK(GPIOx->GPIO_PUPDR ,GPIO_Loc_Mask,GPIO_SET);
    }
    
    return Gpio_Loc_error;
}


/************************************** GPIO_EDIT_REG_MASK **********************************/

/* 
   
   * Functionality    : Apply mask on input register
   * Input Parameters : 1- Register you want to EDIT 
   *                    2- MASK 
   *                    3- Select Operation you want to apply.
   *                       (options : CLEAR , SET , TOGGLE) 	
   
   * NOTE             :   
 
 */
static uint32_t GPIO_EDIT_REG_MASK(uint32_t GPIO_REG_EDIT,uint32_t GPIO_MASK, GPIO_REG_OPER OPERA)
{
	uint32_t GPIO_Local_Var =0;
	switch (OPERA)
	{
	
		case GPIO_CLEAR :
			{
				GPIO_Local_Var  = GPIO_REG_EDIT ;
				GPIO_Local_Var &= ~GPIO_MASK;
				
			}
			break;
		case GPIO_SET :
			{
				GPIO_Local_Var  = GPIO_REG_EDIT ;
				GPIO_Local_Var |= GPIO_MASK; 
			}break;

		default:
			break;
	}
	return GPIO_Local_Var;
}
/************************************** GPIO_EDIT_Bit_Reg **********************************/

/* 
   
   * Functionality    : EDIT bit in register
   * Input Parameters : 1- Register you want to EDIT 
   *                    2- Number of Bit you want to EDIT
   *                    3- Select Operation you want to apply.
   *                       (options : CLEAR , SET , TOGGLE) 	
   
   * NOTE             :   
 
 */
static uint32_t GPIO_EDIT_Bit_Reg(uint32_t GPIO_REG_EDIT,uint32_t BIT_NUM,GPIO_REG_OPER OPERA)
{
	uint32_t GPIO_Local_Var =0;
	switch (OPERA)
	{
	
	case GPIO_CLEAR :
		{
			GPIO_Local_Var  = GPIO_REG_EDIT ;
			GPIO_Local_Var &= ~(1<<BIT_NUM);
			
		}
		break;
	case GPIO_SET :
		{
			GPIO_Local_Var  = GPIO_REG_EDIT ;
			GPIO_Local_Var |= (1<<BIT_NUM); 
		}break;

	default:
		break;
	}
	return GPIO_Local_Var;
}