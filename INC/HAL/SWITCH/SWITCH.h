/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : SWITCH     	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/


#ifndef SWITCH_H_
#define SWITCH_H_

/************************************************************************************/
/**************************      SWITCH  DRIVER         *****************************/
/************************************************************************************/

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;


typedef enum 
{
    SWITCH_OK,
    SWITCH_ERROR,
    SWITCH_INIT_OK,
    SWITCH_INIT_ERROR,
    SWITCH_STATE_OK,
    SWITCH_STATE_NOK

}SWITCH_ErrorStatus_t;
typedef enum
{


}SWITCH_State_t;

typedef struct 
{
   void *   SWITCH_PORT;
   uint32_t SWITCH_PIN;
   SWITCH_State_t SWITCH_STATE;

}SWITCH_Cfg_t;


SWITCH_ErrorStatus_t SWITCH_Init(void);
SWITCH_ErrorStatus_t SWITCH_GetState(uint8_t SWITCH_Arg_ID);

#endif