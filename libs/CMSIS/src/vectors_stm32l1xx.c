//
// This file is part of the GNU ARM Eclipse Plug-in
// Copyright (c) 2013 Liviu Ionescu
//

#if defined (__cplusplus)
extern "C"
{
#endif

//*****************************************************************************
//
// Forward declaration of the default handlers. These are aliased.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//
//*****************************************************************************
void __attribute__((weak))
Reset_Handler(void);
void __attribute__((weak))
NMI_Handler(void);
void __attribute__((weak))
HardFault_Handler(void);
void __attribute__((weak))
MemManage_Handler(void);
void __attribute__((weak))
BusFault_Handler(void);
void __attribute__((weak))
UsageFault_Handler(void);
void __attribute__((weak))
SVC_Handler(void);
void __attribute__((weak))
DebugMon_Handler(void);
void __attribute__((weak))
PendSV_Handler(void);
void __attribute__((weak))
SysTick_Handler(void);

void __attribute__((weak))
Default_Handler(void);

//*****************************************************************************
//
// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
//*****************************************************************************
void __attribute__ ((weak, alias ("Default_Handler")))
WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
PVD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TAMPER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RCC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Channel7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ADC1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_HP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_LP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DAC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
COMP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI9_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
LCD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM9_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM10_IRQHandler(void);

void __attribute__ ((weak, alias ("Default_Handler")))
TIM11_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI15_10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USB_FS_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM7_IRQHandler(void);

#if defined(STM32L1XX_HD)

void __attribute__ ((weak, alias ("Default_Handler")))
SDIO_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
AES_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
COMP_ACQ_IRQHandler(void);

#elif defined(STM32L1XX_MDP)

void __attribute__ ((weak, alias ("Default_Handler")))
TIM5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Channel5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
AES_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
COMP_ACQ_IRQHandler(void);

#endif

//*****************************************************************************

extern unsigned int _estack;

typedef void
		(* const pfn)(void);
//extern pfn g_pfnVectors[];

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif

//*****************************************************************************
//
// The vector table.
// This relies on the linker script to place at correct location in memory.
//
//*****************************************************************************

__attribute__ ((section(".isr_vector")))
pfn g_pfnVectors[] =
{
		// Core Level - CM3
		(pfn) &_estack, // The initial stack pointer
		Reset_Handler, // The reset handler

		NMI_Handler, // The NMI handler
		HardFault_Handler, // The hard fault handler
		MemManage_Handler, // The MPU fault handler
		BusFault_Handler, // The bus fault handler
		UsageFault_Handler, // The usage fault handler
		0, // Reserved
		0, // Reserved
		0, // Reserved
		0, // Reserved
		SVC_Handler, // SVCall handler
		DebugMon_Handler, // Debug monitor handler
		0, // Reserved
		PendSV_Handler, // The PendSV handler
		SysTick_Handler, // The SysTick handler

		// Chip Level - STM32F10x
		WWDG_IRQHandler, // Window WatchDog
		PVD_IRQHandler, // PVD through EXTI Line detection
		TAMPER_IRQHandler, // Tamper through the EXTI line
		RTC_IRQHandler, // RTC Wakeup through the EXTI line
		FLASH_IRQHandler, // FLASH
		RCC_IRQHandler, // RCC
		EXTI0_IRQHandler, // EXTI Line0
		EXTI1_IRQHandler, // EXTI Line1
		EXTI2_IRQHandler, // EXTI Line2
		EXTI3_IRQHandler, // EXTI Line3
		EXTI4_IRQHandler, // EXTI Line4
		DMA1_Channel1_IRQHandler, // DMA1 Channel 1
		DMA1_Channel2_IRQHandler, // DMA1 Channel 2
		DMA1_Channel3_IRQHandler, // DMA1 Channel 3
		DMA1_Channel4_IRQHandler, // DMA1 Channel 4
		DMA1_Channel5_IRQHandler, // DMA1 Channel 5
		DMA1_Channel6_IRQHandler, // DMA1 Channel 6
		DMA1_Channel7_IRQHandler, // DMA1 Channel 7
		ADC1_IRQHandler,
		USB_HP_IRQHandler,
		USB_LP_IRQHandler,
		DAC_IRQHandler,
		COMP_IRQHandler,
		EXTI9_5_IRQHandler,
		LCD_IRQHandler,
		TIM9_IRQHandler,
		TIM10_IRQHandler,
		TIM11_IRQHandler,
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
		RTC_Alarm_IRQHandler,
		USB_FS_WKUP_IRQHandler,
		TIM6_IRQHandler,
		TIM7_IRQHandler,

#if defined(STM32L1XX_HD)

		SDIO_IRQHandler,
		TIM5_IRQHandler,
		SPI3_IRQHandler,
		UART4_IRQHandler,
		UART5_IRQHandler,
		DMA2_Channel1_IRQHandler,
		DMA2_Channel2_IRQHandler,
		DMA2_Channel3_IRQHandler,
		DMA2_Channel4_IRQHandler,
		DMA2_Channel5_IRQHandler,
		AES_IRQHandler,
		COMP_ACQ_IRQHandler,
		0,
		0,
		0,
		0,
		0,

#elif defined(STM32L1XX_MDP)

		0,
		TIM5_IRQHandler,
		SPI3_IRQHandler,
		0,
		0,
		DMA2_Channel1_IRQHandler,
		DMA2_Channel2_IRQHandler,
		DMA2_Channel3_IRQHandler,
		DMA2_Channel4_IRQHandler,
		DMA2_Channel5_IRQHandler,
		AES_IRQHandler,
		COMP_ACQ_IRQHandler,
		0,
		0,
		0,
		0,
		0,

#elif defined(STM32L1XX_MD)

		0,
		0,
		0,
		0,
		0,

#else
#error "missing vectors"
#endif
		/* @0x108. This is for boot in RAM mode for
			STM32L15x ULtra Low Power Medium-density devices. */
		(pfn)0xF108F85F,
};

//*****************************************************************************
//
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//
//*****************************************************************************

void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
	while (1)
	{
	}
}

//*****************************************************************************
// Default exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
void __attribute__ ((section(".after_vectors")))
NMI_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
HardFault_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
MemManage_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
BusFault_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
UsageFault_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
SVC_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
DebugMon_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
PendSV_Handler(void)
{
	while (1)
	{
	}
}

void __attribute__ ((section(".after_vectors")))
SysTick_Handler(void)
{
	while (1)
	{
	}
}

