#include "GPIO.h"
#include "RCC.h"
#include "NVIC.h"
#include "SCHED.h"
#include "USART_APP.h"
#include "USART.h"
#include "SWITCH.h"


 USART_Request_t USART_TxRequest;
 USART_Request_t USART_RxRequest;

  int main(void)
 {    
        RCC_EN_DIS_Peripheral(RCC_USART1_APB2,RCC_Enable_Peripheral);
        RCC_EN_DIS_Peripheral(RCC_GPIOA_AHB1,RCC_Enable_Peripheral);
        RCC_EN_DIS_Peripheral(RCC_GPIOC_AHB1,RCC_Enable_Peripheral);

        APP_LED_INIT();
        // SWITCH_INIT();
        // uint8_t SWITCH_CURRENT_STATE =50;
        //   uint8_t SWITCH_CURRENT =50;
        // while ((SWITCH_CURRENT_STATE == 50 ))
        // {
        //   GPIO_GetPin_Value_V2(GPIO_PORTC_v2, GPIO_PIN15, &SWITCH_CURRENT_STATE);
        //    SWITCH_GetSWITCH_STATE(SWITCH_START,&SWITCH_CURRENT);

        //    if((SWITCH_CURRENT == 0) || (SWITCH_CURRENT_STATE==0))
        //    {
        //     GPIO_SetPin_Value_V2(GPIO_PORTA_v2,GPIO_PIN3,GPIO_SET_PIN);
        //    }
        // }
    NVIC_EnableIRQ(NVIC_USART1);
   
    // GPIO_pin_Confguration_V2 USART_TX_PIN;
    // USART_TX_PIN.GPIO_PORT = GPIO_PORTA_v2;
    // USART_TX_PIN.GPIO_PIN = GPIO_PIN9;
    // USART_TX_PIN.GPIO_AF_PER = GPIO_AF7_USART1_2;
    // USART_TX_PIN.GPIO_MODE  = GPIO_AF_PUSHPULL_NOPUPD_V2;
    // USART_TX_PIN.GPIO_Speed = GPIO_HIGH_SPEED;
   

      
   /*       Recive           */
    GPIO_pin_Confguration_V2 USART_RX_PIN;
    USART_RX_PIN.GPIO_PORT   = GPIO_PORTA_v2;
    USART_RX_PIN.GPIO_PIN    = GPIO_PIN10;
    USART_RX_PIN.GPIO_AF_PER = GPIO_AF7_USART1_2;
    USART_RX_PIN.GPIO_MODE   = GPIO_AF_PUSHPULL_NOPUPD_V2;
    USART_RX_PIN.GPIO_Speed  = GPIO_HIGH_SPEED;
    USART_CFG_t USART_TX_CONFIG;
    USART_TX_CONFIG.USART_Number = USART1;
    USART_TX_CONFIG.USART_Sampling_rate = USART_OVERSAPMLING_16;
    USART_TX_CONFIG.USART_Break_Detection_Length = USART_NO_BD;
    USART_TX_CONFIG.USART_Device_mode = USART_FullDuplex_mode_;
    USART_TX_CONFIG.USART_mode_cfg    = USART_Asynchronous_mode;
    USART_TX_CONFIG.USART_BaudRate = 9600;
    USART_TX_CONFIG.USART_wordlength = USART_WORD_LENGTH_8;
    USART_TX_CONFIG.USART_StopBitsNum = USART_StopBits_1;
    // GPIO_InitPin_v2(&USART_TX_PIN);
    GPIO_InitPin_v2(&USART_RX_PIN);
    USART_Init(&USART_TX_CONFIG);
   
    uint8_t LED_OK[4] = {17};
    //uint8_t NAME2 = 'D';
    USART_TxRequest.USART_Data = LED_OK;
    USART_TxRequest.USART_DataArraySize = 4;
    USART_TxRequest.USART_ID = USART1_ID;
    USART_TxRequest.USART_Number = USART1;
    USART_TxRequest.USART_CBFunc = APP_LED_ON;
  

    uint8_t Function_ID[4]={0} ;
    //uint8_t NAME2 = 'D';
    USART_RxRequest.USART_Data = Function_ID;
    USART_RxRequest.USART_DataArraySize = 1;
    USART_RxRequest.USART_ID = USART1_ID;
    USART_RxRequest.USART_Number = USART1;
    USART_RxRequest.USART_CBFunc = APP_LED_OFF;

      // SCHED_Init();
      // SCHED_Start();
    while (1)
    {
    
       USART_RxByte_Async(USART_RxRequest); 
       //USART_RxByte_Sync(USART1,&Function_ID[0]); 
       switch (Function_ID[0])
       {
            case 0X03:
               APP_LED_ON();
                USART_TxByte_Sync(USART1,0x11); 
                break;
            case 0X04:
              APP_LED_ON2();
              USART_TxByte_Sync(USART1,0x22); 
                break;
       
       default:
        break;
       }
      }
   
   
     return 0;
  }
