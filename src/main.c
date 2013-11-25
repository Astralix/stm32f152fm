#include "stm32l1xx.h"
#include <stdio.h>
#include <stdint.h>

/*
 * STM32F1 led blink sample.
 *
 * In debug configurations, demonstrate how to print a greeting message
 * on the standard output. In release configurations the message is
 * simply discarded. By default the trace messages are forwarded to the SWO,
 * but can be rerouted to semi-hosting or completely suppressed by changing
 * the definitions in misc/include/trace_impl.h.
 *
 * Then enter a continuous loop and blink a led with 1Hz.
 *
 * The external clock frequency is specified as HSE_VALUE=8000000,
 * adjust it for your own board. Also adjust the PLL constants to
 * reach the maximum frequency, or special clock configurations.
 *
 * The build does not use startup files, and on Release it does not even use
 * any standard library function (on Debug the printf() brigs lots of
 * functions; removing it should also use no other standard lib functions).
 *
 * If the application requires to use a special initialisation code present
 * in some other libraries (for example librdimon.a, for semi-hosting),
 * define USE_STARTUP_FILES and uncheck the corresponding option in the
 * linker configuration.
 */

/* ------------------------------------------------------------------------- */

static __IO uint32_t uwTimingDelay;

static void
Delay(__IO uint32_t nTime);

static void
TimingDelay_Decrement(void);

void
SysTick_Handler(void);

/* ----- SysTick definitions ----------------------------------------------- */

#define SYSTICK_FREQUENCY_HZ       1000

/* ----- LED definitions --------------------------------------------------- */

/* Olimex STM32-H103 LED definitions */
/* Adjust them for your own board. */

#define LD_GPIO_PORT 			GPIOB
#define LD_GREEN_GPIO_PIN		GPIO_Pin_7
#define LD_BLUE_GPIO_PIN        GPIO_Pin_6
#define LD_GPIO_PORT_CLK        RCC_AHBPeriph_GPIOB

#define MCO_GPIO_PORT			GPIOA
#define MCO_GPIO_PIN			GPIO_Pin_8
#define MCO_GPIO_PORT_CLK		RCC_AHBPeriph_GPIOA


#define BLINK_TICKS     SYSTICK_FREQUENCY_HZ/2

/* ------------------------------------------------------------------------- */

int
main(void)
{
#if defined(DEBUG)
	/*
	 * Send a greeting to the standard output (the semi-hosting debug channel
	 * on Debug, ignored on Release).
	 */
	printf("Hello ARM World!\n");
#endif

	/*
	 * At this stage the microcontroller clock setting is already configured,
	 * this is done through SystemInit() function which is called from startup
	 * file (startup_cm.c) before to branch to application main.
	 * To reconfigure the default setting of SystemInit() function, refer to
	 * system_stm32f10x.c file
	 */

	/* Use SysTick as reference for the timer */
	SysTick_Config(SystemCoreClock / SYSTICK_FREQUENCY_HZ);

	/* GPIO Periph clock enable for LED */
	RCC_AHBPeriphClockCmd(LD_GPIO_PORT_CLK, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	/* Configure the GPIO_LED pins  LD3 & LD4*/
	GPIO_InitStructure.GPIO_Pin = LD_GREEN_GPIO_PIN | LD_BLUE_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(LD_GPIO_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(LD_GPIO_PORT, LD_GREEN_GPIO_PIN);
	GPIO_ResetBits(LD_GPIO_PORT, LD_BLUE_GPIO_PIN);

	/* GPIO Periph clock enable for MCO */
	RCC_AHBPeriphClockCmd(MCO_GPIO_PORT_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = MCO_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(MCO_GPIO_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_MCO);
	RCC_MCOConfig(RCC_MCOSource_SYSCLK , RCC_MCODiv_8);

	int seconds = 0;

	/* Infinite loop */
	while (1)
	{
		/* Assume the LED is active low */

		/* Turn on led by setting the pin low */
		GPIO_ResetBits(LD_GPIO_PORT, LD_GREEN_GPIO_PIN);

		Delay(BLINK_TICKS);

		/* Turn off led by setting the pin high */
		GPIO_SetBits(LD_GPIO_PORT, LD_GREEN_GPIO_PIN);

		Delay(BLINK_TICKS);

		++seconds;

#if defined(DEBUG)
		/*
		 * Count seconds on the debug channel.
		 */
		printf("Second %d\n", seconds);
#endif
	}
}

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length, in SysTick ticks.
 * @retval None
 */
void
Delay(__IO uint32_t nTime)
{
	uwTimingDelay = nTime;

	while (uwTimingDelay != 0)
		;
}

/**
 * @brief  Decrements the TimingDelay variable.
 * @param  None
 * @retval None
 */
void
TimingDelay_Decrement(void)
{
	if (uwTimingDelay != 0x00)
	{
		uwTimingDelay--;
	}
}

/**
 * @brief  This function is the SysTick Handler.
 * @param  None
 * @retval None
 */
void
SysTick_Handler(void)
{
	TimingDelay_Decrement();
}

