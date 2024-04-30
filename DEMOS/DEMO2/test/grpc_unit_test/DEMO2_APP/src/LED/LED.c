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
#include "LED_CFG.h"
#include "LED.h"
#include "GPIO.h"

/************************************************************************************/
/*************************          LED MACROS        *******************************/
/************************************************************************************/

#define LED_CHECK_STATE_CONNECTION_OK(STATE,CONNECTION) ((STATE== LED_STATE_OFF) || (STATE== LED_STATE_ON)) && ((CONNECTION == LED_Connection_FORWARD)||(CONNECTION == LED_Connection_REVERSED))
#define LED_CHECK_INIT_OK(GPIO,LED)                     ((GPIO==GPIO_Init_OK) && (LED == LED_STATE_OK))
#define LED_CHECK_ID(ID)                                ((ID >= 0 ) && (ID <= _LED_NUM))
#define LED_CHECK_LED_SET(GPIO,LED)                     ((LED == LED_ID_OK ) && (GPIO == GPIO_SETRESET_OK))

/* Extern for Array of LEDs in CFG file */
extern LED_Cfg_t  TrafficLight_LEDs[_LED_NUM] ;


/************************************************************************************/
/*************************   LED APIs Implementation  *******************************/
/************************************************************************************/

LED_ErrorStatus_t LED_Init(void)
{
    LED_ErrorStatus_t        LED_local_status  = LED_INIT_OK;     
    GPIO_pin_Confguration_V2 Local_LED_cfg;
    uint32_t                 local_LED_idx;
    GPIO_ErrorStatus         GPIO_STATUS = GPIO_Init_ERROR;


    Local_LED_cfg.GPIO_MODE   = GPIO_OUTPUT_PUSHPULL_NOPUPD_V2;
    Local_LED_cfg.GPIO_Speed  = GPIO_HIGH_SPEED ;
/*
     for (local_LED_idx = 0; CHECK_OK &&(local_LED_idx < _LED_NUM); local_LED_idx++)
    {
        LED_local_status = LED_STATE_OK;
       if(!(LED_CHECK_STATE_CONNECTION_OK(TrafficLight_LEDs[local_LED_idx].LED_STATE,TrafficLight_LEDs[local_LED_idx].LED_CONNECTION)))
       {
          CHECK_OK = 0;
          LED_local_status = LED_STATE_NOK;
       }
   
    }
    */
    
    for (local_LED_idx = 0;(local_LED_idx < _LED_NUM); local_LED_idx++)
    {
        Local_LED_cfg.GPIO_PORT = TrafficLight_LEDs[local_LED_idx].LED_PORT;
        Local_LED_cfg.GPIO_PIN  = TrafficLight_LEDs[local_LED_idx].LED_PIN;

       GPIO_STATUS = GPIO_InitPin_v2(&Local_LED_cfg);
       GPIO_STATUS= GPIO_SetPin_Value_V2(TrafficLight_LEDs[local_LED_idx].LED_PORT,TrafficLight_LEDs[local_LED_idx].LED_PIN,TrafficLight_LEDs[local_LED_idx].LED_CONNECTION ^ TrafficLight_LEDs[local_LED_idx].LED_STATE);
    }
    if(GPIO_STATUS)
    {
        
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
         GPIO_STATUS = GPIO_SetPin_Value_V2(TrafficLight_LEDs[LED_ArgID].LED_PORT,TrafficLight_LEDs[LED_ArgID].LED_PIN,TrafficLight_LEDs[LED_ArgID].LED_CONNECTION ^ LED_ArgState);
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
        LED_Prev_state = TrafficLight_LEDs[LED_ArgID].LED_STATE;
        GPIO_STATUS = GPIO_SetPin_Value_V2(TrafficLight_LEDs[LED_ArgID].LED_PORT,TrafficLight_LEDs[LED_ArgID].LED_PIN,TrafficLight_LEDs[LED_ArgID].LED_CONNECTION ^ (1^LED_Prev_state));
        LED_local_status = LED_TOGGLE_OK;
    }
    else
    {
        if(GPIO_STATUS)
        {

        }
        else
        {

        }

    }
 
    return LED_local_status;


}