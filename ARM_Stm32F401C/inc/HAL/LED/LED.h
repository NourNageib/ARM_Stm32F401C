/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED     	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/


#ifndef LED_H_
#define LED_H_

/************************************************************************************/
/**************************       LED  DRIVER         *******************************/
/************************************************************************************/

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;


typedef enum 
{
    LED_OK,
    LED_ERROR,
    LED_INIT_OK,
    LED_INIT_ERROR,
    LED_STATE_OK,
    LED_SET_STATE_OK,
    LED_SET_STATE_NOK,
    LED_STATE_NOK,
    LED_ID_NOK,
    LED_ID_OK,
    LED_TOGGLE_OK,
    LED_TOGGLE_NOK

}LED_ErrorStatus_t;

typedef enum
{
    LED_Connection_REVERSED,
    LED_Connection_FORWARD

}LED_Connction_t;

typedef enum
{
    LED_STATE_OFF,
    LED_STATE_ON

}LED_State_t;

typedef struct 
{
   void * LED_PORT;
   uint32_t LED_PIN;
   LED_Connction_t LED_CONNECTION;
   LED_State_t LED_STATE;

}LED_Cfg_t;


/*************************** LED_Init **************************/
/*
/* Functionality    : Loop on all leds configuration in myLEDs
                      array in LED_CFG.c file to check its state
                      and connection configured correctly.
                      Then using sruct of GPIO type used to copy 
                      required data from led array to be used in 
                      GPIO driver for the pin configuration,
                      finally send this object to GPIO INIT Fun 
                      now the pin configured when return GPIO 
                      status is OK, This loop finished based on 
                      NUM_of LEDs in array thus you must place 
                      LED name in LED list in LED_CFG.h then 
                      start congiguring it in LED_CFG.c.

                                  1 - PORT.
                                  2 - PIN.
                                  3 - STATE.
                                  4 - CONNECTION.
                        
   Input Parameters : 1- VOID

   Return           : Init status :
                                    1- LED_INIT_OK.
                                    2- LED_INIT_ERROR.
	                                                           */
/***************************************************************/
LED_ErrorStatus_t LED_Init(void);

/************************** LED_Set_State **********************/
/*
/* Functionality    :  After init state of LED when it is 
                       required to change its state by sending 
                       its ID and Required state.
                        
   Input Parameters : 1- LED ID set based on LIST of LEDs in 
                         the LED_CFG.h 
                      2- Required State : 
                                          1 - LED_STATE_OFF.
                                          2 - LED_STATE_ON.
   Return           : Set State status :
                                          1 - LED_SET_STATE_OK.
                                          2 - LED_SET_STATE_NOK.

	                                                           */
/***************************************************************/
LED_ErrorStatus_t LED_Set_State(LED_LEDList_t LED_ArgID,LED_State_t LED_ArgState);

/************************** LED_Set_State **********************/
/*
/* Functionality    :  Toggle switch state based on prev state
                       of LED.
                        
   Input Parameters : 1- LED ID set based on LIST of LEDs in 
                         the LED_CFG.h.

   Return           : Toggle State status :
                                         1 - LED_TOGGLE_OK.
                                         2 - LED_TOGGLE_NOK.
             
	                                                           */
/***************************************************************/
LED_ErrorStatus_t LED_Toggle_State(LED_LEDList_t LED_ArgID );

#endif