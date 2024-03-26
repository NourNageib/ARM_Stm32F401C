/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : SWITCH     	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/


#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

/************************************************************************************/
/**************************      SWITCH  DRIVER         *****************************/
/************************************************************************************/

/*        LIST of my SWITCHes         */

typedef enum
{
    SWITCH_START,
    SWITCH_STOP,
    SWITCH_EMERGENCY,
    _SWITCH_NUM

}SWITCH_SW_ID_t;


#endif