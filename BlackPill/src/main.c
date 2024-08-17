#include "definition.h"
#include "RCC_interface.h"
#include "Special_Functions.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "NVIC.private.h"
#include "EXTI_interface.h"
#include "SysTick_interface.h"
#include "SYSCFG_interface.h"
#include "UART_interface.h"
#include "OS_interface.h"
#include "Lcd_Interface.h"
void delay(u16 time)
{
	  for(u16 i=0;i<time;i++)
	  {
		  for (u16 j=0;j<time;j++)
		  {
			  asm("NOP");
		  }
	  }
}

void ahmed (void)
{
	while(1)
	{
		static u8 state =0;
			if(state==0)
			{
				GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , HIGH );
				NVIC_voidSetPendingFlag(7);
				delay(2000);
				state=1;
			}
			else
			{
				GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , Low );
				NVIC_voidSetPendingFlag(7);
				delay(2000);
				state=0;
			}

	}

}
void atia (void)
{
	static u8 state =0;
	if(state==0)
	{
		GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , HIGH );
		delay(2000);
		state=1;
	}
	else
	{
		GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , Low );
		delay(2000);
		state=0;
	}
}
int main(void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_AHB,0);
	RCC_voidEnableClock(RCC_APB2,4);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN9, PushPull,HighSpeed);
	GPIO_voidSetPinDirOutput(GPIO_PORTA,GPIO_PIN0, PushPull,HighSpeed);
	GPIO_voidSetPinDirInput(GPIO_PORTA,GPIO_PIN10,Floating);
	UART_voidInit();
	u8 x;
	u8 y='a';
  while (1)
  {
	  UART_voidTransmit(&y);
	  x = UART_u8Recieve();
	  if (x=='5')
	  {
		  GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , HIGH );
	  }
	  else if (x=='a')
	  {
		  GPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN0 , Low );

	  }
  }

}
