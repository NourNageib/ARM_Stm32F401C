/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED     	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/



/************************************************************************************/
/**************************        LED DRIVER         *******************************/
/************************************************************************************/
#include "LED.h"
#include "LED_CFG.h"
#include "GPIO.h"

/************************************************************************************/
/*************************          LED MACROS        *******************************/
/************************************************************************************/

#define LED_CHECK_STATE_CONNECTION_OK(STATE,CONNECTION) ((STATE== LED_STATE_OFF) || (STATE== LED_STATE_ON)) && ((CONNECTION == LED_Connection_FORWARD)||(CONNECTION == LED_Connection_REVERSED))
#define LED_CHECK_INIT_OK(GPIO,LED)                     ((GPIO==GPIO_Init_OK) && (LED == LED_STATE_OK))
#define LED_CHECK_ID(ID)                                ((ID >= 0 ) && (ID <= _LED_NUM))
#define LED_CHECK_LED_SET(GPIO,LED)                     ((LED == LED_ID_OK ) && (GPIO == GPIO_SETRESET_OK))

/* Extern for Array of LEDs in CFG file */
extern LED_Cfg_t  LED_myLEDs [_LED_NUM] ;


/************************************************************************************/
/*************************   LED APIs Implementation  *******************************/
/************************************************************************************/

LED_ErrorStatus_t LED_Init(void)
{
    LED_ErrorStatus_t LED_local_status;GPIO_ErrorStatus GPIO_STATUS;
    GPIO_pin_Confguration Local_LED_cfg;
    uint32_t local_LED_idx;uint8_t CHECK_OK =1;

    Local_LED_cfg.GPIO_AF_PER = GPIO_AF0_System;
    for (local_LED_idx = 0; CHECK_OK &&(local_LED_idx < _LED_NUM); local_LED_idx)
    {
        LED_local_status = LED_STATE_OK;
       if(!(LED_CHECK_STATE_CONNECTION_OK(LED_myLEDs[local_LED_idx].LED_STATE,LED_myLEDs[local_LED_idx].LED_CONNECTION)))
       {
          CHECK_OK = 0;
          LED_local_status = LED_STATE_NOK;
       }

    }
    
    for (local_LED_idx = 0; CHECK_OK && (local_LED_idx < _LED_NUM); local_LED_idx)
    {
        Local_LED_cfg.GPIO_PORT = LED_myLEDs[local_LED_idx].LED_PORT;
        Local_LED_cfg.GPIO_PIN  = LED_myLEDs[local_LED_idx].LED_PIN;

        GPIO_STATUS = GPIO_InitPin(&Local_LED_cfg);
        GPIO_SetPin_Value(LED_myLEDs[local_LED_idx].LED_PORT,LED_myLEDs[local_LED_idx].LED_PIN,LED_myLEDs[local_LED_idx].LED_CONNECTION ^ LED_myLEDs[local_LED_idx].LED_STATE);
    }
    
    if(!LED_CHECK_INIT_OK(GPIO_STATUS,LED_local_status))
    {
        LED_local_status = LED_INIT_ERROR;
    }
    else
    {
        LED_local_status = LED_INIT_OK ;
    }

    return LED_local_status;
}


LED_ErrorStatus_t LED_Set_State(LED_LEDList_t LED_ArgID,LED_State_t LED_ArgState)
{
    LED_ErrorStatus_t LED_local_status = LED_SET_STATE_NOK ;
    GPIO_ErrorStatus  GPIO_STATUS      = GPIO_SETRESET_NOK;
    
    if(LED_CHECK_ID(LED_ArgID))
    {
         LED_local_status = LED_ID_OK ;
         GPIO_STATUS = GPIO_SetPin_Value(LED_myLEDs[LED_ArgID].LED_PORT,LED_myLEDs[LED_ArgID].LED_PIN,LED_myLEDs[LED_ArgID].LED_CONNECTION ^ LED_ArgState);
    }
    else
    {
        LED_local_status = LED_ID_NOK ;
    }
    if (LED_CHECK_LED_SET(GPIO_STATUS,LED_local_status))
    {
        LED_local_status = LED_SET_STATE_OK;
    }
    else
    {
        LED_local_status = LED_SET_STATE_NOK;
    }
    
    return LED_local_status;


}


LED_ErrorStatus_t LED_Toggle_State(LED_LEDList_t LED_ArgID )
{
    LED_ErrorStatus_t LED_local_status = LED_TOGGLE_NOK;
    GPIO_ErrorStatus  GPIO_STATUS      = GPIO_SETRESET_NOK;
    LED_State_t       LED_Prev_state;

    if(LED_CHECK_ID(LED_ArgID))
    {
        LED_Prev_state = LED_myLEDs[LED_ArgID].LED_STATE;
        GPIO_STATUS = GPIO_SetPin_Value(LED_myLEDs[LED_ArgID].LED_PORT,LED_myLEDs[LED_ArgID].LED_PIN,LED_myLEDs[LED_ArgID].LED_CONNECTION ^ (1^LED_Prev_state));
        LED_local_status = LED_TOGGLE_OK;
    }
    else
    {

    }
 
    return LED_local_status;


}