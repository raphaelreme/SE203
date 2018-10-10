#include "led.h"

void led_init(){
  CLOCK_ENA = CLOCK_ENA | (3<<1); //enable port B and C
  GPIOB_MODER = (GPIOB_MODER & ~(0x3<<28)) | (1<<28);
  GPIOC_MODER = (GPIOC_MODER & ~(0x3<<18));
}

void led_g_on(){
  GPIOB_BSRR = 1<<14;
}

void led_g_off(){
  GPIOB_BSRR = 1<<30;
}

void led(enum state s){
  if (s==LED_OFF){
    GPIOC_MODER = GPIOC_MODER & ~(0x3<<18);
    return;
  }
  GPIOC_MODER = (GPIOC_MODER & ~(0x3<<18)) | (1<<18);
  if (s==LED_YELLOW){
    GPIOC_BSRR = 1<<9;
    return;
  }
  GPIOC_BSRR = 1<<25;
}
