/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : LED     	       */
/*	Layer	  : HAL                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
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
                { .LED_PORT       = GPIO_PORTA,
                  .LED_PIN        = GPIO_PIN0,
                  .LED_STATE      = LED_OFF_STATE,
                  .LED_CONNECTION = LED_FORWARD_Connection

                },
  [LED_YELLOW]  = 
                { .LED_PORT       = GPIO_PORTA,
                  .LED_PIN        = GPIO_PIN1,
                  .LED_STATE      = LED_OFF_STATE,
                  .LED_CONNECTION = LED_FORWARD_Connection

                },
   [LED_GREEN]  = 
                { .LED_PORT       = GPIO_PORTA,
                  .LED_PIN        = GPIO_PIN2,
                  .LED_STATE      = LED_ON_STATE,
                  .LED_CONNECTION = LED_FORWARD_Connection

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