/**
 *SysTick
 *
 * @author Salma Mohammed Hamed
 * @date  16 Feb 2024
 * @version V01
 *
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SysTick_interface.h"
#include "SysTick_config.h"
#include "SysTick_private.h"

static void (*STK_Callback)(void) = NULL;
static u8 STK_ModeOfInterval;

void STK_Init(void)
{

    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;//Disable SysTick timer

    /* Configure SysTick timer to use the processor clock */
    #if STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_1
        STK -> CTRL |= STK_CTRL_CLKSOURCE_MASK;     // Set bit 2 to use the processor clock
    #elif STK_CTRL_CLKSOURCE == STK_CTRL_CLKSOURCE_8
        STK->CTRL &= ~STK_CTRL_CLKSOURCE_MASK;      // Clear bit 2 to use the processor clock/8
    #else
        #error "WRONG CHOICE FOR SYSTICK CLOCK SOURCE"
    #endif

    /**< Generate interrupt when it reaches zero */
    #if STK_CTRL_TICKINT == STK_CTRL_TICKINT_ENABLE
        STK->CTRL |= STK_CTRL_TICKINT_MASK;      /**< Set bit 1 to enable interrupt when the counter reaches zero */
    #elif STK_CTRL_TICKINT == STK_CTRL_TICKINT_DISABLE
        STK->CTRL &= ~STK_CTRL_TICKINT_MASK;      /**< Clear bit 1 to enable interrupt when the counter reaches zero */
    #else
        #error "WRONG OPTION"
    #endif
}

void STK_Start(void)
{
    /**< Start the SysTick timer */
    STK->CTRL |= STK_CTRL_ENABLE_MASK;
}

void STK_Stop(void)
{
    /**< Stop the SysTick timer */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;
}

void STK_Reset(void)
{
    /**< Disable SysTick timer */
    STK->CTRL = 0;
    /**< Clear the current value */
    STK->VAL = 0;
    /**< Set the reload value to 0 */
    STK->LOAD = 0;
    /**< Clear the count/interrupt flag */
    STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
}

u32 STK_GetRemainingCounts(void)
{
    /* Get the current value of the SysTick timer */
    return STK->VAL;
}

u32 STK_GetElapsedCounts(void)
{
    /* Calculate the number of elapsed ticks */
    u32 Local_u32ElapsedTicks = ((STK->LOAD + 1) - (STK->VAL));

    return Local_u32ElapsedTicks;
}

void STK_SetBusyWait(u32 Copy_Microseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of microseconds */
    u32 Local_u32Ticks = (Copy_Microseconds * STK_AHB_CLK) / 1000000;

    /**< Wait for the specified number of ticks using the SysTick timer */
    STK->LOAD = Local_u32Ticks;
    STK->CTRL |= STK_CTRL_ENABLE_MASK;              /**< Enable SysTick timer */
    while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK)); /**< Wait until the SysTick timer reach to zero */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;             /**< Disable SysTick timer */
}

void STK_SetDelay(f32 Copy_u32Milliseconds)
{
    /**< Calculate the number of ticks required to wait for the specified number of microseconds */
    u32 Local_u32Ticks = (Copy_u32Milliseconds * STK_AHB_CLK) / 1000.0;

    /**< Wait for the specified number of ticks using the SysTick timer */
    STK->LOAD = Local_u32Ticks;
    STK->CTRL |= STK_CTRL_ENABLE_MASK;              /**< Enable SysTick timer */
    while (!(STK->CTRL & STK_CTRL_COUNTFLAG_MASK)); /**< Wait until the SysTick timer reach to zero */
    STK->CTRL &= ~STK_CTRL_ENABLE_MASK;             /**< Disable SysTick timer */
}

void STK_SetIntervalSingle(u32 Copy_u32Microseconds, void (*Copy_pfCallback)(void))
{
    if(Copy_pfCallback != NULL)
    {
        /**< Save the callback function pointer */
        STK_Callback = Copy_pfCallback;

        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_u32Ticks = (Copy_u32Microseconds * STK_AHB_CLK) / 1000000;

        /* Set the reload value for the SysTick timer */
        STK->LOAD = Local_u32Ticks;

        /**< Set the Mode of interval to be single */
        STK_ModeOfInterval = STK_SINGLE_INTERVAL;

        /* Start the SysTick timer and enable the interrupt */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;
        STK->CTRL |= STK_CTRL_TICKINT_MASK;
    }
    else
    {
        /**< Set ErrorStatus */
    }

}

void STK_SetIntervalPeriodic(u32 Copy_Microseconds, void (*Copy_Callback)(void))
{
    if(Copy_Callback != NULL)
    {
        /**< Save the callback function pointer */
        STK_Callback = Copy_Callback;

        /* Calculate the number of ticks required to wait for the specified number of microseconds */
        u32 Local_u32Ticks = (Copy_Microseconds * STK_AHB_CLK) / 1000000;

        /**< Set the reload value for the SysTick timer */
        STK->LOAD = Local_u32Ticks;

        /**< Set the Mode of interval to be periodic */
        STK_ModeOfInterval = STK_PERIOD_INTERVAL;

        /**< Start the SysTick timer */
        STK->CTRL |= STK_CTRL_ENABLE_MASK;
        STK->CTRL |= STK_CTRL_TICKINT_MASK;
    }
    else
    {
        /**< Set ErrorStatus */
    }
}

void SysTick_Handler(void)
{
    /**< Call the callback function */
    if (STK_Callback != NULL)
    {
        if(STK_ModeOfInterval == STK_SINGLE_INTERVAL)
        {
            STK_Reset();
        }
        /**< Callback notification */
        STK_Callback();

        /**< Clear the count/interrupt flag */
        STK->CTRL &= ~STK_CTRL_COUNTFLAG_MASK;
    }
}






