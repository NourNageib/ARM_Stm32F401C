#include "GPIO.h"
#include "RUNNABLE_CFG.h"



  GPIO_pin_Confguration_V2  myled;
  GPIO_pin_Confguration_V2  myled2;

void blinkled_init(void)
{

  
    myled.GPIO_PORT=GPIO_PORTA_v2;
    myled2.GPIO_PORT=GPIO_PORTA_v2;
    myled.GPIO_PIN = GPIO_PIN0;
    myled2.GPIO_PIN = GPIO_PIN2;
    myled.GPIO_MODE = GPIO_OUTPUT_PUSHPULL_PULLDOWN_V2;
    myled2.GPIO_MODE = GPIO_OUTPUT_PUSHPULL_PULLDOWN_V2;
    GPIO_InitPin_v2(&myled);
    GPIO_InitPin_v2(&myled2);

}
void app_blinkled_on(void)
{

    GPIO_SetPin_Value_V2(myled.GPIO_PORT,myled.GPIO_PIN,GPIO_SET_PIN);
    GPIO_SetPin_Value_V2(myled2.GPIO_PORT,myled2.GPIO_PIN,GPIO_RESET_PIN);
    

}
void app_blinkled_off(void)
{

    GPIO_SetPin_Value_V2(myled.GPIO_PORT,myled.GPIO_PIN,GPIO_RESET_PIN);
    GPIO_SetPin_Value_V2(myled2.GPIO_PORT,myled2.GPIO_PIN,GPIO_SET_PIN);
    

}