/***********************************/
/*	Author 	  : Nour Abd-elaziz    */
/*	Swc		  : Scheduler 	       */
/*	Layer	  : MCAL               */
/*	Version   : 1.0                */
/*	Date	  : March 14 , 2024    */
/*	Last Edit : N/A                */
/***********************************/




/*************************************************************************************/
/********************   Scheduler  Runnables configuration  **************************/
/*************************************************************************************/

#include "RUNNABLE_CFG.h"
#include "SCHED.h"


/*************************************************************************************/
/******************    eterns for runnables callback functions  **********************/
/*************************************************************************************/

extern void APP_RECEIVE_SW_ID(void);
extern void APP_READSWITCH(void);
extern void Clock_Runnable(void);
extern void Display_Runnable(void);
extern void StopWatch_Runnable(void);
extern void LCD_Runnable(void);
extern void HSwitch_Runnable(void);
extern void APP_USART(void);
extern void APP_UPDATE_SWITCH(void);
extern void APP_SWITCH(void);


/**************************************************************************************/

/*************************************************************************************/
/****************         Setting Runnable Configurations        *********************/
/*************************************************************************************/

const SCHED_runnable_t SCHED_myrunnbles[__SCHED_MAX_Runnables] =
{
    //     [LCD] = {
    //               .runnable_name = "lcd",
    //               .SCHED_periodicity_ms = 2,
    //               .SCHED_delayTime_ms = 0, 
                  
    //             },
    // [LCD_APP] = {
    //               .runnable_name = "lcd APP",
    //               .SCHED_periodicity_ms = 1000, 
    //               .SCHED_delayTime_ms = 0, 
                
    //             },
    // [LCD_CLEAR] = {
                
    //                .runnable_name = "lcd APP",
    //                .SCHED_periodicity_ms = 1100, 
    //                .SCHED_delayTime_ms = 0,
    //              }

    
    [APP_USART_]    ={
                                .runnable_name        = "send USART",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 100,
                                .SCHED_Runnable_CBF   = &APP_USART
                            },
    [APP_SWITCH_]  ={
                                .runnable_name        = "APP_UPDATE_SWITCH",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 15,
                                .SCHED_Runnable_CBF   = &APP_SWITCH
                            },
   
    [APP_UPDATE_SWITCH_]       ={
                                .runnable_name        = "APP_UPDATE_SWITCH",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 5,
                                .SCHED_Runnable_CBF   = &APP_UPDATE_SWITCH
                            }
    /*
    [HSwitch_Runnable_]     ={
                                .runnable_name        = "HSwitch Runnable",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 5,
                                .SCHED_Runnable_CBF   = &HSwitch_Runnable
                            },
    [StopWatch_Runnable_]  ={
                                .runnable_name        = "StopWatch_Runnable_",
                                .SCHED_delayTime_ms   = 35,
                                .SCHED_periodicity_ms = 100,
                                .SCHED_Runnable_CBF   = &StopWatch_Runnable
                            },
    [APP_RECEIVE_SW_ID_]       ={
                                .runnable_name        = "APP_SEND_SW_ID",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 200,
                                .SCHED_Runnable_CBF   = &APP_RECEIVE_SW_ID
                    
                           },
    [READSWITCH]           = {
                                .runnable_name        = "APP READSWITCH",
                                .SCHED_delayTime_ms   = 0,
                                .SCHED_periodicity_ms = 100,
                                .SCHED_Runnable_CBF   = &APP_READSWITCH
             
                          }*/

};