/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Traffic Lights     */
/*	Layer	  : APP                */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/


/**************************************************/
/**          APP_TRAFFIC_LIGHT driver            **/
/**************************************************/
#include "LED.h"
#include "RCC.h"

/**************************************************/
/**          APP_TRAFFIC_LIGHT defines           **/
/**************************************************/
#define TRAFFIC_LIGHT_PERIODICITY          1
#define TRAFFIC_LIGHT_RED_DELAY            5
#define TRAFFIC_LIGHT_YELLOW_DELAY         10
#define TRAFFIC_LIGHT_GREEN_DELAY          15

/**************************************************/
/**          APP_TRAFFIC_LIGHT typedefs          **/
/**************************************************/
static uint8_t TRAFFIC_LIGHT_TIMMING = 0;

typedef enum
{
    TAFFIC_LIGHT_RED,
    TAFFIC_LIGHT_YELLOW,
    TAFFIC_LIGHT_GREEN

}APP_TRAFFIC_LIGHTs_t;

static APP_TRAFFIC_LIGHTs_t TRAFFIC_LIGHT_NOW = TAFFIC_LIGHT_RED;

/*****************************************************************/
/**          APP_TRAFFIC_LIGHT APIs  Implementation             **/
/*****************************************************************/

void APP_TRAFFIC_LIGHT(void)
{

    TRAFFIC_LIGHT_TIMMING+=TRAFFIC_LIGHT_PERIODICITY;

    switch (TRAFFIC_LIGHT_NOW)
    {
       case TAFFIC_LIGHT_RED :
            {
                LED_Set_State(LED_RED,LED_STATE_ON);
                LED_Set_State(LED_YELLOW,LED_STATE_OFF);
                LED_Set_State(LED_GREEN,LED_STATE_OFF);
                /*Update next state*/
                if (TRAFFIC_LIGHT_TIMMING == TRAFFIC_LIGHT_YELLOW_DELAY)
                {
                     TRAFFIC_LIGHT_NOW = TAFFIC_LIGHT_YELLOW;
                }
            } break;

       case TAFFIC_LIGHT_YELLOW :
            {
                LED_Set_State(LED_RED,LED_STATE_OFF);
                LED_Set_State(LED_YELLOW,LED_STATE_ON);
                LED_Set_State(LED_GREEN,LED_STATE_OFF);
                /*Update next state*/
                 if (TRAFFIC_LIGHT_TIMMING == TRAFFIC_LIGHT_YELLOW_DELAY)
                {  
                    TRAFFIC_LIGHT_NOW = TAFFIC_LIGHT_GREEN;
                }

            } break;

       case TAFFIC_LIGHT_GREEN :
            {
                LED_Set_State(LED_RED,LED_STATE_OFF);
                LED_Set_State(LED_YELLOW,LED_STATE_OFF);
                LED_Set_State(LED_GREEN,LED_STATE_ON);
                /*Update next state*/
                   if (TRAFFIC_LIGHT_TIMMING == TRAFFIC_LIGHT_YELLOW_DELAY)
                {  
                    TRAFFIC_LIGHT_NOW = TAFFIC_LIGHT_GREEN;
                    TRAFFIC_LIGHT_TIMMING = 0;
                }
                

            } break;
        
    
      default:
         break;
    }

}

void APP_TRAFFIC_LIGHT_INIT(void)
{
     RCC_EN_DIS_Peripheral(RCC_GPIOA_AHB1,RCC_Enable_Peripheral);
     LED_Init();
}