#include "stm32f4xx.h"

extern "C" int main()
{
  // Switch on blue LED on STM32F407Discovery

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_InitTypeDef gpio_out = {
    .GPIO_Pin = GPIO_Pin_15,
    .GPIO_Mode = GPIO_Mode_OUT,
    .GPIO_Speed = GPIO_High_Speed,
    .GPIO_OType = GPIO_OType_PP,
    .GPIO_PuPd = GPIO_PuPd_NOPULL
  };

  GPIO_Init(GPIOD, &gpio_out);
  GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_SET);

  for (;;);

  return 0;
}
