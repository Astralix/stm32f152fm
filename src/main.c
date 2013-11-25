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

#define I2C_GPIO_PORT			GPIOB
#define I2C_SDA_GPIO_PIN		GPIO_Pin_9
#define I2C_SCL_GPIO_PIN		GPIO_Pin_8
#define I2C_GPIO_PORT_CLK		RCC_AHBPeriph_GPIOB

#define BLINK_TICKS     SYSTICK_FREQUENCY_HZ/2

/* ------------------------------------------------------------------------- */

int i2c_transact( uint8_t ic, uint16_t addr,
		uint8_t *txb, uint8_t txl,
		uint8_t *rxb, uint8_t rxl )
{
	if( txb && txl) {
		I2C_GenerateSTART( I2C1, ENABLE);
		I2C_Send7bitAddress( I2C1, ic, I2C_Direction_Transmitter);
	}
	else if( rxb && rxl) {
		I2C_GenerateSTART( I2C1, ENABLE);
		I2C_Send7bitAddress( I2C1, ic, I2C_Direction_Receiver);
	}
	else {
		goto error_out;
	}

	while ( txl) {
		I2C_SendData( I2C1, *txb++);
		--txl;
	}
	if(rxb && rxl) {
		I2C_GenerateSTART( I2C1, ENABLE);
		while( rxl) {
			*rxb++ = I2C_ReceiveData( I2C1);
			--rxl;
		}
	}
	I2C_GenerateSTOP( I2C1, ENABLE);

	return 0;
error_out:
	return -1;
}

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

	/* GPIO Periph clock enable for I2C */
	RCC_AHBPeriphClockCmd(I2C_GPIO_PORT_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = I2C_SDA_GPIO_PIN | I2C_SCL_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(I2C_GPIO_PORT, &GPIO_InitStructure);

	/* I2C Periph clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

	/* Switch GPIO alternate functions */
	GPIO_PinAFConfig(I2C_GPIO_PORT, GPIO_PinSource8, GPIO_AF_I2C1);
	GPIO_PinAFConfig(I2C_GPIO_PORT, GPIO_PinSource9, GPIO_AF_I2C1);

	/* Initialize I2C subsystem */
	I2C_InitTypeDef I2C_InitStructure;
	I2C_StructInit( &I2C_InitStructure);
	// I2C_InitStructure.I2C_ClockSpeed = 400;
	I2C_Init( I2C1, &I2C_InitStructure);

	RCC_I2CConfig();

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

