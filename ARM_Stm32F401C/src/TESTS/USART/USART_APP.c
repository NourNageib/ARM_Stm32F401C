
#include "USART.h"
#include "GPIO.h"
#include "RCC.h"
#include "NVIC.h"
#include "SWITCH.h"


GPIO_pin_Confguration_V2 MYLED;
extern GPIO_pin_Confguration_V2 MYLED2;
 extern  USART_Request_t USART_TxRequest;
   uint8_t  FLAG =1;
extern SWITCH_STATE_t     SWITCH_STATE[_SWITCH_NUM];
void APP_LED_INIT(void)
{
    
    MYLED.GPIO_PORT = GPIO_PORTA_v2;
    MYLED.GPIO_PIN = GPIO_PIN3;
    MYLED.GPIO_MODE = GPIO_OUTPUT_PUSHPULL_PULLDOWN_V2;
    MYLED.GPIO_Speed = GPIO_HIGH_SPEED;
    GPIO_InitPin_v2(&MYLED);


}
void APP_LED_ON(void)
{

    if (FLAG)
    {
       GPIO_SetPin_Value_V2(MYLED.GPIO_PORT,MYLED.GPIO_PIN,GPIO_SET_PIN);
       FLAG =0;
       
    }
    else if (!FLAG)
    {
         GPIO_SetPin_Value_V2(MYLED.GPIO_PORT,MYLED.GPIO_PIN,GPIO_PIN_LOW);
         FLAG =1;
    }


}
 
void APP_SWITCH(void)
{
     uint8_t SwitchState[6]={SWITCH_RELEASED,SWITCH_RELEASED,SWITCH_RELEASED,SWITCH_RELEASED,SWITCH_RELEASED,SWITCH_RELEASED};
    
      SWITCH_GetSWITCH_STATE(SWITCH_START,&SwitchState[SWITCH_START]);
    if(SWITCH_STATE[SWITCH_START]==SWITCH_PRESSED)
    {
       GPIO_SetPin_Value_V2(MYLED2.GPIO_PORT,MYLED2.GPIO_PIN,GPIO_SET_PIN);
    }

}
void APP_USART_INIT(void)
{
  
    // RCC_EN_DIS_Peripheral(RCC_USART1_APB2,RCC_Enable_Peripheral);
    // RCC_EN_DIS_Peripheral(RCC_GPIOA_AHB1,RCC_Enable_Peripheral);
    // NVIC_EnableIRQ(NVIC_USART1);
    

    // /*Tx pin configuration*/
    // GPIO_pin_Confguration_V2 USART_TX_PIN;
    // USART_TX_PIN.GPIO_PORT = GPIO_PORTA_v2;
    // USART_TX_PIN.GPIO_PIN = GPIO_PIN9;
    // USART_TX_PIN.GPIO_AF_PER = GPIO_AF7_USART1_2;
    // USART_TX_PIN.GPIO_MODE  = GPIO_AF_PUSHPULL_NOPUPD_V2;
    // USART_TX_PIN.GPIO_Speed = GPIO_HIGH_SPEED;

    // /*Configuring USART TX */

    // USART_TX_CONFIG.USART_Number = USART1;
    // USART_TX_CONFIG.USART_Sampling_rate = USART_OVERSAPMLING_16;
    // USART_TX_CONFIG.USART_Break_Detection_Length = USART_NO_BD;
    // USART_TX_CONFIG.USART_Device_mode = USART_FullDuplex_mode_;
    // USART_TX_CONFIG.USART_mode_cfg    = USART_Asynchronous_mode;
    // USART_TX_CONFIG.USART_BaudRate = 9600;
    // USART_TX_CONFIG.USART_wordlength = USART_WORD_LENGTH_8;
    // USART_TX_CONFIG.USART_StopBitsNum = USART_StopBits_1;

    // /*Init PIN*/
    // GPIO_InitPin_v2(&USART_TX_PIN);
    // /*Init USART*/
    // USART_Init(&USART_TX_CONFIG);

    // /*PREPARE TX REQUEST*/
  
    // //uint8_t NAME[5] = {'N','O','U','R','\n'};
    // uint8_t NAME[4] = {'N','O','U','R'};;
    // USART_TxRequest.USART_Data = NAME;
    // USART_TxRequest.USART_DataArraySize = 4;
    // USART_TxRequest.USART_ID = USART1_ID;
    // USART_TxRequest.USART_Number = USART1;
    // USART_TxRequest.USART_CBFunc = APP_LED_ON;



}
void APP_USART(void)
{
  USART_TxByte_Async(USART_TxRequest);



}