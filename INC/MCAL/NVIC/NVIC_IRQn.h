typedef enum
{

/***************************************  STM32 IRQns *********************************************************/
  NVIC_WWDG      ,                      /* Window WatchDog Interrupt                                         */
  NVIC_PVD       ,                 /* PVD through EXTI Line detection Interrupt                         */
  NVIC_TAMP_STAMP,     /* Tamper and TimeStamp interrupts through the EXTI line             */
  NVIC_RTC_WKUP,       /* RTC Wakeup interrupt through the EXTI line                        */
  NVIC_FLASH               ,       /* FLASH global Interrupt    */
  NVIC_RCC                   ,      /* RCC global Interrupt     */
  NVIC_EXTI0                 ,      /* EXTI Line0 Interrupt      */
  NVIC_EXTI1                  ,      /* EXTI Line1 Interrupt                                              */
  NVIC_EXTI2                  ,      /* EXTI Line2 Interrupt                                              */
  NVIC_EXTI3                 ,      /* EXTI Line3 Interrupt                                              */
  NVIC_EXTI4                 ,     /* EXTI Line4 Interrupt                                              */
  NVIC_DMA1_Stream0           ,     /* DMA1 Stream 0 global Interrupt                                    */
  NVIC_DMA1_Stream1          ,     /* DMA1 Stream 1 global Interrupt                                    */
  NVIC_DMA1_Stream2           ,     /* DMA1 Stream 2 global Interrupt                                    */
  NVIC_DMA1_Stream3          ,     /* DMA1 Stream 3 global Interrupt                                    */
  NVIC_DMA1_Stream4         ,     /* DMA1 Stream 4 global Interrupt                                    */
  NVIC_DMA1_Stream5          ,     /* DMA1 Stream 5 global Interrupt                                    */
  NVIC_DMA1_Stream6          ,     /* DMA1 Stream 6 global Interrupt                                    */
  NVIC_ADC                  ,     /* ADC1, ADC2 and ADC3 global Interrupts                             */
  NVIC_EXTI9_5               = 23,     /* External Line[9:5] Interrupts                                     */
  NVIC_TIM1_BRK_TIM9          = 24,     /* TIM1 Break interrupt and TIM9 global interrupt                    */
  NVIC_TIM1_UP_TIM10         = 25,     /* TIM1 Update Interrupt and TIM10 global interrupt                  */
  NVIC_TIM1_TRG_COM_TIM11     = 26,     /* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  NVIC_TIM1_CC               = 27,     /* TIM1 Capture Compare Interrupt                                    */
  NVIC_TIM2                   = 28,     /* TIM2 global Interrupt                                             */
  NVIC_TIM3                   = 29,     /* TIM3 global Interrupt                                             */
  NVIC_TIM4                  = 30,     /* TIM4 global Interrupt                                             */
  NVIC_I2C1_EV                = 31,     /* I2C1 Event Interrupt                                              */
  NVIC_I2C1_ER                = 32,     /* I2C1 Error Interrupt                                              */
  NVIC_I2C2_EV                = 33,     /* I2C2 Event Interrupt                                              */
  NVIC_I2C2_ER                = 34,     /* I2C2 Error Interrupt                                              */
  NVIC_SPI1                  = 35,     /* SPI1 global Interrupt                                             */
  NVIC_SPI2                  = 36,     /* SPI2 global Interrupt                                             */
  NVIC_USART1                 = 37,     /* USART1 global Interrupt                                           */
  NVIC_USART2                 = 38,     /* USART2 global Interrupt                                           */
  NVIC_EXTI15_10              = 40,     /* External Line[15:10] Interrupts                                   */
  NVIC_RTC_Alarm              = 41,     /* RTC Alarm (A and B) through EXTI Line Interrupt                   */
  NVIC_OTG_FS_WKUP            = 42,     /* USB OTG FS Wakeup through EXTI line interrupt                     */
  NVIC_DMA1_Stream7           = 47,     /* DMA1 Stream7 Interrupt                                            */
  NVIC_SDIO                   = 49,     /* SDIO global Interrupt                                             */
  NVIC_TIM5                   = 50,     /* TIM5 global Interrupt                                             */
  NVIC_SPI3                   = 51,     /* SPI3 global Interrupt                                             */
  NVIC_DMA2_Stream0          = 56,     /* DMA2 Stream 0 global Interrupt                                    */
  NVIC_DMA2_Stream1          = 57,     /* DMA2 Stream 1 global Interrupt                                    */
  NVIC_DMA2_Stream2           = 58,     /* DMA2 Stream 2 global Interrupt                                    */
  NVIC_DMA2_Stream3         = 59,     /* DMA2 Stream 3 global Interrupt                                    */
  NVIC_DMA2_Stream4         = 60,     /* DMA2 Stream 4 global Interrupt                                    */
  NVIC_OTG_FS               = 67,     /* USB OTG FS global Interrupt                                       */
  NVIC_DMA2_Stream5           = 68,     /* DMA2 Stream 5 global interrupt                                    */
  NVIC_DMA2_Stream6           = 69,     /* DMA2 Stream 6 global interrupt                                    */
  NVIC_DMA2_Stream7          = 70,     /* DMA2 Stream 7 global interrupt                                    */
  NVIC_USART6                 = 71,     /* USART6 global interrupt                                           */
  NVIC_I2C3_EV               = 72,     /* I2C3 event interrupt                                              */
  NVIC_I2C3_ER                = 73,     /* I2C3 error interrupt                                              */
  NVIC_FPU                   = 81,     /* FPU global interrupt                                              */
  NVIC_SPI4                   = 84,     /* SPI4 global Interrupt  											 */
  _NVIC_IRQn                            /*num of IRQs*/

} NVIC_IRQn_Type;