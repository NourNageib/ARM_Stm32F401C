/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED     	           */
/*	Layer	  : HAL                  */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024      */
/*	Last Edit : N/A                */
/***********************************/


/************************************************************************************/
/**************************       LED  DRIVER         *******************************/
/************************************************************************************/
#include "LED_CFG.h"
#include "LED.h"
#include "GPIO.h"

/*        Configuration Set for my LEDs    */
/*                 in system               */

const LED_Cfg_t  TrafficLight_LEDs[_LED_NUM] =
{
  [LED_RED] = 
                { .LED_PORT       = GPIO_PORTA_v2,
                  .LED_PIN        = GPIO_PIN0,
                  .LED_STATE      = LED_STATE_OFF,
                  .LED_CONNECTION = LED_Connection_FORWARD

                },
  [LED_YELLOW]  = 
                { .LED_PORT       = GPIO_PORTA_v2,
                  .LED_PIN        = GPIO_PIN1,
                  .LED_STATE      = LED_STATE_OFF,
                  .LED_CONNECTION = LED_Connection_REVERSED

                },
   [LED_GREEN]  = 
                { .LED_PORT       = GPIO_PORTA_v2,
                  .LED_PIN        = GPIO_PIN2,
                  .LED_STATE      = LED_STATE_OFF,
                  .LED_CONNECTION = LED_Connection_REVERSED

                }

};
/*
LED_Cfg_t  LED_myLEDs [_LED_NUM] =
{
  [LED_START] = 
                { .LED_PORT =,
                  .LED_PIN  =,
                  .LED_STATE=

                },
  [LED_STOP]  = 
                { .LED_PORT =,
                  .LED_PIN  =,
                  .LED_STATE=

                }
                

};
*/