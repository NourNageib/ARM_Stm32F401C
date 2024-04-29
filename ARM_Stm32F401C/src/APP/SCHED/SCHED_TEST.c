
#include "RCC.h"
#include "GPIO.h"
#include "SYSTICK.h"
#include "SCHED.h"
#include "APP_BLINKLED.h"


int main(void)
{
    RCC_EN_DIS_Peripheral(RCC_GPIOA_AHB1,RCC_Enable_Peripheral);
   
   blinkled_init();
    SCHED_Init();
    SCHED_Start();
    

    

    return 0;
}