/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc	      : SWITCH             */
/*	Layer     : HAL                */
/*	Version   : 1.0                */
/*	Date      : Feb 9 , 2024       */
/*	Last Edit : N/A                */
/***********************************/


                        /**********************************************************************************/
                        /********************        SWITCH   DRIVER        *******************************/
                        /**********************************************************************************/

/**************************************************************************/
/********************          Includes        ****************************/
/**************************************************************************/

 #include "SWITCH.h"
 #include "GPIO.h"
 

/************************************************************************/
/********************          Defines       ****************************/
/************************************************************************/

#define SWITCH_ID_CHECK(SWITCH)          ((SWITCH) < _SWITCH_NUM)
#define NULL                             (void*)0
#define SWITCH_CONNECTION(CONNECTION)    ((CONNECTION == SWITCH_CONNECTION_FLOATING) ||\
                                          (CONNECTION == SWITCH_CONNECTION_PULLUP)   ||\
                                          (CONNECTION == SWITCH_CONNECTION_PULLDOWN))
#define SWITCH_CFG_OFFSET                2UL

/************************************************************************/
/********************        Typedefs        ****************************/
/************************************************************************/

extern const SWITCH_cfg_t My_Switches[_SWITCH_NUM];
SWITCH_STATE_t     SWITCH_STATE[_SWITCH_NUM];

/************************************************************************************/
/*************************   SWITCH APIs Implementation  ****************************/
/************************************************************************************/

 SWITCH_ErrorStatus_t SWITCH_INIT(void)
 {

   SWITCH_ErrorStatus_t     SW_local_status = SW_ERROR;
   GPIO_ErrorStatus         SW_PinCfg_status = GPIO_Init_ERROR;
   GPIO_pin_Confguration_V2 Local_SWITCH_CFG;
   uint8_t SW_local_SW_idx = 0;
   uint8_t SW_Local_Flag   = 1;

   Local_SWITCH_CFG.GPIO_AF_PER = GPIO_AF0_System;
   Local_SWITCH_CFG.GPIO_Speed  = GPIO_HIGH_SPEED;

    for (SW_local_SW_idx = 0;SW_Local_Flag && (SW_local_SW_idx < _SWITCH_NUM); SW_local_SW_idx++)
    {
      if(SWITCH_CONNECTION(My_Switches[SW_local_SW_idx].SW_Connection))
      {
        Local_SWITCH_CFG.GPIO_PORT = My_Switches[SW_local_SW_idx].SW_Port;
        Local_SWITCH_CFG.GPIO_PIN  = My_Switches[SW_local_SW_idx].SW_Pin;
        Local_SWITCH_CFG.GPIO_MODE = (uint32_t)(My_Switches[SW_local_SW_idx].SW_Connection<<SWITCH_CFG_OFFSET) ;
        SW_PinCfg_status           = GPIO_InitPin_v2(&Local_SWITCH_CFG);
        if (SW_PinCfg_status != GPIO_Init_OK)
        { 
          SW_Local_Flag = 0;
        }
      }
      else
      {
        SW_local_status = SW_INIT_ERROR;
        break;
      }
   }
   return SW_local_status;

 }
/*     |-------------|-------------------|-------------|     */
/*     |   SWITCH    | SWITCH CONNECTION | FINAL STATE |
       |-------------|-------------------|-------------|
       |  PRESSED    |     PULL-UP       |   PIN-LOW   | 
       | NOT PRESSED |    PULL-DOWN      |   PIN-HIGH  |
       |-------------|-------------------|-------------|
                        01 <- 0100 ->UP
                        10 <- 1000 -> DOWN
          ---------------------------------------------------
          | NOTPRESSED --> 0 | XOR | PULLDOWN 0  | ----> 0  | 
          | NOTPRESSED --> 0 | XOR | PULLUP   1  | ----> 1  |
          | PRESSED    --> 1 | XOR | PULLUP   1  | ----> 0  | 
          | PRESSED    --> 1 | XOR | PULLDOWN 0  | ----> 1  | 
          ---------------------------------------------------

 */
 SWITCH_ErrorStatus_t SWITCH_GetSWITCH_STATE(uint8_t Arg_SWITCH_ID, SWITCH_STATE_t * SWITCH_STATE)
 {
   SWITCH_ErrorStatus_t SW_local_status = SW_GETSET_STATE_ERROR;
   if(!SWITCH_ID_CHECK(Arg_SWITCH_ID)  && !SWITCH_STATE)
   {
      SW_local_status = SW_NOT_VALID;
   }
   else
   {
      SW_local_status = SW_GETSET_STATE_OK;
      *SWITCH_STATE = (SWITCH_STATE[Arg_SWITCH_ID]) ^ (My_Switches[Arg_SWITCH_ID].SW_Connection>>SWITCH_CFG_OFFSET);
   }                         
   return SW_local_status;
 }


 void APP_UPDATE_SWITCH(void)
 {

    static uint32_t SWITCH_PREVIOUS_STATE[_SWITCH_NUM] = {0};
    static uint32_t SWITCH_COUNTS[_SWITCH_NUM]         = {0};
    static GPIO_PIN_STATE_t  SWITCH_CURRENT_STATE      =  0 ;
           uint8_t  SW_local_SW_idx                    =  0 ;

    for(SW_local_SW_idx = 0; SW_local_SW_idx < _SWITCH_NUM; SW_local_SW_idx++)
    {
      GPIO_GetPin_Value_V2(My_Switches[SW_local_SW_idx].SW_Port, My_Switches[SW_local_SW_idx].SW_Pin, &SWITCH_CURRENT_STATE);
      if(SWITCH_CURRENT_STATE == SWITCH_PREVIOUS_STATE[SW_local_SW_idx])
      {
        SWITCH_COUNTS[SW_local_SW_idx]++;
      }
      else
      {
        SWITCH_COUNTS[SW_local_SW_idx] = 0;
      }
      /*must have 5 consecutive readings to be the same to ensure the sw state every 5ms*/
      if((SWITCH_COUNTS[SW_local_SW_idx] % 5 ) == 0)
      {
        SWITCH_STATE[SW_local_SW_idx] = SWITCH_CURRENT_STATE;
      }
      /*updte array for the next time checking on sw state*/
      SWITCH_PREVIOUS_STATE[SW_local_SW_idx] = SWITCH_CURRENT_STATE;
    }

 }
