#include "irq.h"

#define MAKE_DEFAULT_HANDLER(myIRQ) \
        void __attribute__((weak)) myIRQ(void) { \
            asm volatile("cpsid i"); \
            while(1){} \
        }


void default_handler(void) {
  asm volatile("cpsid i");
  while(1){}
}


MAKE_DEFAULT_HANDLER(Reset_Handler)
MAKE_DEFAULT_HANDLER(NMI_Handler)
MAKE_DEFAULT_HANDLER(HardFault_Handler)
MAKE_DEFAULT_HANDLER(MemManage_Handler)
MAKE_DEFAULT_HANDLER(BusFault_Handler)
MAKE_DEFAULT_HANDLER(UsageFault_Handler)
MAKE_DEFAULT_HANDLER(SVCall_Handler)
MAKE_DEFAULT_HANDLER(Debug_Handler)
MAKE_DEFAULT_HANDLER(PendSV_Handler)
MAKE_DEFAULT_HANDLER(SysTick_Handler)
MAKE_DEFAULT_HANDLER(WWDG_IRQHandler)
MAKE_DEFAULT_HANDLER(PVD_PVM_IRQHandler)
MAKE_DEFAULT_HANDLER(RTC_TAMP_STAMP_IRQHandler)
MAKE_DEFAULT_HANDLER(RTC_WKUP_IRQHandler)
MAKE_DEFAULT_HANDLER(FLASH_IRQHandler)
MAKE_DEFAULT_HANDLER(RCC_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI0_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI1_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI2_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI3_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH1_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH2_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH3_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH5_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH6_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA1_CH7_IRQHandler)
MAKE_DEFAULT_HANDLER(ADC1_2_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_TX_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_RX0_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_RX1_IRQHandler)
MAKE_DEFAULT_HANDLER(CAN1_SCE_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM15_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM16_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM17_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM1_CC_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM2_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM3_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM4_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C1_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C1_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C2_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C2_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI1_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI2_IRQHandler)
MAKE_DEFAULT_HANDLER(USART1_IRQHandler)
MAKE_DEFAULT_HANDLER(USART2_IRQHandler)
MAKE_DEFAULT_HANDLER(USART3_IRQHandler)
MAKE_DEFAULT_HANDLER(EXTI15_10_IRQHandler)
MAKE_DEFAULT_HANDLER(RTC_ALARM_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT3_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_BRK_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_UP_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_TRG_COM_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM8_CC_IRQHandler)
MAKE_DEFAULT_HANDLER(ADC3_IRQHandler)
MAKE_DEFAULT_HANDLER(FMC_IRQHandler)
MAKE_DEFAULT_HANDLER(SDMMC1_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM5_IRQHandler)
MAKE_DEFAULT_HANDLER(SPI3_IRQHandler)
MAKE_DEFAULT_HANDLER(UART4_IRQHandler)
MAKE_DEFAULT_HANDLER(UAR5_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM6_DACUNDER_IRQHandler)
MAKE_DEFAULT_HANDLER(TIM7_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH1_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH2_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH3_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH4_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH5_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT0_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT1_IRQHandler)
MAKE_DEFAULT_HANDLER(DFSDM1_FLT2_IRQHandler)
MAKE_DEFAULT_HANDLER(COMP_IRQHandler)
MAKE_DEFAULT_HANDLER(LPTIM1_IRQHandler)
MAKE_DEFAULT_HANDLER(LPTIM2_IRQHandler)
MAKE_DEFAULT_HANDLER(OTG_FS_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH6_IRQHandler)
MAKE_DEFAULT_HANDLER(DMA2_CH7_IRQHandler)
MAKE_DEFAULT_HANDLER(LPUART1_IRQHandler)
MAKE_DEFAULT_HANDLER(QUADSPI_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C3_EV_IRQHandler)
MAKE_DEFAULT_HANDLER(I2C3_ER_IRQHandler)
MAKE_DEFAULT_HANDLER(SAI1_IRQHandler)
MAKE_DEFAULT_HANDLER(SAI2_IRQHandler)
MAKE_DEFAULT_HANDLER(SWPMI1_IRQHandler)
MAKE_DEFAULT_HANDLER(TSC_IRQHandler)
MAKE_DEFAULT_HANDLER(LCD_IRQHandler)
MAKE_DEFAULT_HANDLER(AES_IRQHandler)
MAKE_DEFAULT_HANDLER(RNG_IRQHandler)
MAKE_DEFAULT_HANDLER(FPU_IRQHandler)

extern uint32_t _stackptr;
extern uint32_t _start;


void * __attribute((section(".vectors"))) vector_table[] = {
    // Stack and Reset Handler
    &_stackptr, /* Top of stack */
    &_start,  /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,       /* NMI handler */
    HardFault_Handler, /* Hard Fault handler */
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,               /* Reserved */
    0,               /* Reserved */
    0,               /* Reserved */
    0,               /* Reserved */
    SVCall_Handler,     /* SVC handler */
    0,               /* Reserved */
    0,               /* Reserved */
    PendSV_Handler,  /* Pending SVC handler */
    SysTick_Handler, /* SysTick hanlder */

    // STM32L475 External interrupts
    WWDG_IRQHandler,    /* Watchdog IRQ */
    PVD_PVM_IRQHandler, /* ... */
    RTC_TAMP_STAMP_IRQHandler,
    RTC_WKUP_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_CH1_IRQHandler,
    DMA1_CH2_IRQHandler,
    DMA1_CH3_IRQHandler,
    DMA1_CH4_IRQHandler,
    DMA1_CH5_IRQHandler,
    DMA1_CH6_IRQHandler,
    DMA1_CH7_IRQHandler,
    ADC1_2_IRQHandler,
    CAN1_TX_IRQHandler,
    CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    TIM15_IRQHandler,
    TIM16_IRQHandler,
    TIM17_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTC_ALARM_IRQHandler,
    DFSDM1_FLT3_IRQHandler,
    TIM8_BRK_IRQHandler,
    TIM8_UP_IRQHandler,
    TIM8_TRG_COM_IRQHandler,
    TIM8_CC_IRQHandler,
    ADC3_IRQHandler,
    FMC_IRQHandler,
    SDMMC1_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UAR5_IRQHandler,
    TIM6_DACUNDER_IRQHandler,
    TIM7_IRQHandler,
    DMA2_CH1_IRQHandler,
    DMA2_CH2_IRQHandler,
    DMA2_CH3_IRQHandler,
    DMA2_CH4_IRQHandler,
    DMA2_CH5_IRQHandler,
    DFSDM1_FLT0_IRQHandler,
    DFSDM1_FLT1_IRQHandler,
    DFSDM1_FLT2_IRQHandler,
    COMP_IRQHandler,
    LPTIM1_IRQHandler,
    LPTIM2_IRQHandler,
    OTG_FS_IRQHandler,
    DMA2_CH6_IRQHandler,
    DMA2_CH7_IRQHandler,
    LPUART1_IRQHandler,section(".vectors")))
    QUADSPI_IRQHandler,section(".vectors")))
    I2C3_EV_IRQHandler,section(".vectors")))
    I2C3_ER_IRQHandler,section(".vectors")))
    SAI1_IRQHandler,
    SAI2_IRQHandler,
    SWPMI1_IRQHandler,
    TSC_IRQHandler,
    LCD_IRQHandler,
    AES_IRQHandler,
    RNG_IRQHandler,
    FPU_IRQHandler
};

void irq_init(void) {
    SCB->VTOR = (uint32_t) &vector_table;
}
