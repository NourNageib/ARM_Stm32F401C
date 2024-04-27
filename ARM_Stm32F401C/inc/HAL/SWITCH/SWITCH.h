/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc	      : SWITCH             */
/*	Layer     : HAL                */
/*	Version   : 1.0                */
/*	Date      : Feb 9 , 2024       */
/*	Last Edit : N/A                */
/***********************************/


#ifndef _SWITCH_H_
#define _SWITCH_H_

                        /**********************************************************************************/
                        /********************        SWITCH   DRIVER        *******************************/
                        /**********************************************************************************/
#include "SWITCH_Cfg.h"
/************************************************************************/
/********************        Typedefs        ****************************/
/************************************************************************/
typedef  unsigned char  uint8_t;

typedef enum 
{
    SW_OK,
    SW_ERROR,
    SW_INIT_OK,
    SW_INIT_ERROR,
    SW_STATE_OK,
    SW_GETSET_STATE_ERROR,
    SW_GETSET_STATE_OK,
    SW_NOT_VALID

}SWITCH_ErrorStatus_t;

typedef enum
{
    SWITCH_CONNECTION_FLOATING,
    SWITCH_CONNECTION_PULLUP,
    SWITCH_CONNECTION_PULLDOWN

}SWITCH_Connection_state;

typedef enum  
{
    SWITCH_RELEASED,
    SWITCH_PRESSED

}SWITCH_STATE_t;

typedef struct  
{
    void *                  SW_Port;
    uint8_t                 SW_Pin;
    SWITCH_Connection_state SW_Connection;

}SWITCH_cfg_t;

/****************************************************************/
/*************************   SWITCH APIs  ***********************/
/****************************************************************/

/*************************** SWITCH_INIT **************************/
/*
   Functionality    : Loop on all switches configuration in 
                      My_Switches array in LED_CFG.c file to 
                      check its state and connection configured 
                      correctly.
                      Then using sruct of GPIO type used to copy 
                      required data from sw array to be used in 
                      GPIO driver for the pin configuration,
                      finally send this object to GPIO INIT Fun 
                      now the pin configured when return GPIO 
                      status is OK, This loop finished based on 
                      NUM_of SWs in the array thus you must place 
                      sw name in sw list in SWITCH_CFG.h then 
                      start congiguring it in SWITCH_CFG.c.

                                  1 - PORT.
                                  2 - PIN.
                                  4 - CONNECTION.
                        
   Input Parameters : 1- VOID

   Return           : SWITCH_ErrorStatus_t :
                                    1- SW_INIT_ERROR.
                                    2- SW_INIT_OK.
    
	                                                           */
/***************************************************************/
SWITCH_ErrorStatus_t SWITCH_INIT(void);

/*************************** SWITCH_GetSWITCH_STATE **************************/
/*
   * Functionality    : This function gets the current status of the switch
                      wether its pressed or not pressed based on the provided 
                      switch ID to the function.
                        
   * Input Parameters : 1 - SWs_List_t -> use switch name from switch list
        

   Return           : SWITCH_ErrorStatus_t :
                                    1- SW_GETSET_STATE_OK.
                                    2- SW_GETSET_STATE_ERROR.
                     SWITCH_STATE_t :
                                    1- SWITCH_PRESSED.
                                    2-  SWITCH_RELEASED,
	                                                           */
/***************************************************************/
SWITCH_ErrorStatus_t SWITCH_GetSWITCH_STATE(uint8_t Arg_SWITCH_ID , SWITCH_STATE_t * Add_enuHSwitchState);

/*************************** APP_UPDATE_SWITCH **************************/
/*
   Functionality    : Runnable with specified periodicity to check the 
                      Switch state by sampling consecutive state to protect 
                      hardware from 


                      you define for this runnable its
                      1 - periodicity.
                      2 - priority.   
                      3 - assign this function to the runnable CALLBACK 
                          func thus to be executed based on its configyred
                          periodicity.
                      4 - delay time (ms).

   Input Parameters : void

   Return           : void
	                                                           */
/***************************************************************/
void APP_UPDATE_SWITCH(void);


#endif