#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"

void irq_init(void);
void default_handler(void);

void __attribute__((weak)) Reset_Handler(void);
void __attribute__((weak)) NMI_Handler(void);
void __attribute__((weak)) HardFault_Handler(void);
void __attribute__((weak)) MemManage_Handler(void);
void __attribute__((weak)) BusFault_Handler(void);
void __attribute__((weak)) UsageFault_Handler(void);
void __attribute__((weak)) SVCall_Handler(void);
void __attribute__((weak)) Debug_Handler(void);
void __attribute__((weak)) PendSV_Handler(void);
void __attribute__((weak)) SysTick_Handler(void);
void __attribute__((weak)) WWDG_IRQHandler(void);
void __attribute__((weak)) PVD_PVM_IRQHandler(void);
void __attribute__((weak)) RTC_TAMP_STAMP_IRQHandler(void);
void __attribute__((weak)) RTC_WKUP_IRQHandler(void);
void __attribute__((weak)) FLASH_IRQHandler(void);
void __attribute__((weak)) RCC_IRQHandler(void);
void __attribute__((weak)) EXTI0_IRQHandler(void);
void __attribute__((weak)) EXTI1_IRQHandler(void);
void __attribute__((weak)) EXTI2_IRQHandler(void);
void __attribute__((weak)) EXTI3_IRQHandler(void);
void __attribute__((weak)) EXTI4_IRQHandler(void);
void __attribute__((weak)) DMA1_CH1_IRQHandler(void);
void __attribute__((weak)) DMA1_CH2_IRQHandler(void);
void __attribute__((weak)) DMA1_CH3_IRQHandler(void);
void __attribute__((weak)) DMA1_CH4_IRQHandler(void);
void __attribute__((weak)) DMA1_CH5_IRQHandler(void);
void __attribute__((weak)) DMA1_CH6_IRQHandler(void);
void __attribute__((weak)) DMA1_CH7_IRQHandler(void);
void __attribute__((weak)) ADC1_2_IRQHandler(void);
void __attribute__((weak)) CAN1_TX_IRQHandler(void);
void __attribute__((weak)) CAN1_RX0_IRQHandler(void);
void __attribute__((weak)) CAN1_RX1_IRQHandler(void);
void __attribute__((weak)) CAN1_SCE_IRQHandler(void);
void __attribute__((weak)) TIM15_IRQHandler(void);
void __attribute__((weak)) TIM16_IRQHandler(void);
void __attribute__((weak)) TIM17_IRQHandler(void);
void __attribute__((weak)) TIM1_CC_IRQHandler(void);
void __attribute__((weak)) TIM2_IRQHandler(void);
void __attribute__((weak)) TIM3_IRQHandler(void);
void __attribute__((weak)) TIM4_IRQHandler(void);
void __attribute__((weak)) I2C1_EV_IRQHandler(void);
void __attribute__((weak)) I2C1_ER_IRQHandler(void);
void __attribute__((weak)) I2C2_EV_IRQHandler(void);
void __attribute__((weak)) I2C2_ER_IRQHandler(void);
void __attribute__((weak)) SPI1_IRQHandler(void);
void __attribute__((weak)) SPI2_IRQHandler(void);
void __attribute__((weak)) USART1_IRQHandler(void);
void __attribute__((weak)) USART2_IRQHandler(void);
void __attribute__((weak)) USART3_IRQHandler(void);
void __attribute__((weak)) EXTI15_10_IRQHandler(void);
void __attribute__((weak)) RTC_ALARM_IRQHandler(void);
void __attribute__((weak)) DFSDM1_FLT3_IRQHandler(void);
void __attribute__((weak)) TIM8_BRK_IRQHandler(void);
void __attribute__((weak)) TIM8_UP_IRQHandler(void);
void __attribute__((weak)) TIM8_TRG_COM_IRQHandler(void);
void __attribute__((weak)) TIM8_CC_IRQHandler(void);
void __attribute__((weak)) ADC3_IRQHandler(void);
void __attribute__((weak)) FMC_IRQHandler(void);
void __attribute__((weak)) SDMMC1_IRQHandler(void);
void __attribute__((weak)) TIM5_IRQHandler(void);
void __attribute__((weak)) SPI3_IRQHandler(void);
void __attribute__((weak)) UART4_IRQHandler(void);
void __attribute__((weak)) UAR5_IRQHandler(void);
void __attribute__((weak)) TIM6_DACUNDER_IRQHandler(void);
void __attribute__((weak)) TIM7_IRQHandler(void);
void __attribute__((weak)) DMA2_CH1_IRQHandler(void);
void __attribute__((weak)) DMA2_CH2_IRQHandler(void);
void __attribute__((weak)) DMA2_CH3_IRQHandler(void);
void __attribute__((weak)) DMA2_CH4_IRQHandler(void);
void __attribute__((weak)) DMA2_CH5_IRQHandler(void);
void __attribute__((weak)) DFSDM1_FLT0_IRQHandler(void);
void __attribute__((weak)) DFSDM1_FLT1_IRQHandler(void);
void __attribute__((weak)) DFSDM1_FLT2_IRQHandler(void);
void __attribute__((weak)) COMP_IRQHandler(void);
void __attribute__((weak)) LPTIM1_IRQHandler(void);
void __attribute__((weak)) LPTIM2_IRQHandler(void);
void __attribute__((weak)) OTG_FS_IRQHandler(void);
void __attribute__((weak)) DMA2_CH6_IRQHandler(void);
void __attribute__((weak)) DMA2_CH7_IRQHandler(void);
void __attribute__((weak)) LPUART1_IRQHandler(void);
void __attribute__((weak)) QUADSPI_IRQHandler(void);
void __attribute__((weak)) I2C3_EV_IRQHandler(void);
void __attribute__((weak)) I2C3_ER_IRQHandler(void);
void __attribute__((weak)) SAI1_IRQHandler(void);
void __attribute__((weak)) SAI2_IRQHandler(void);
void __attribute__((weak)) SWPMI1_IRQHandler(void);
void __attribute__((weak)) TSC_IRQHandler(void);
void __attribute__((weak)) LCD_IRQHandler(void);
void __attribute__((weak)) AES_IRQHandler(void);
void __attribute__((weak)) RNG_IRQHandler(void);
void __attribute__((weak)) FPU_IRQHandler(void);


#endif  //IRQ_H