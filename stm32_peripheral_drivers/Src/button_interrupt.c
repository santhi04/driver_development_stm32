/*
 * main.c
 *
 *  Created on: 15 May 2026
 *      Author: nikhi
 */


#include "stm32f401xx.h"
#include "gpio_driver.h"

void delay(void)
{
	for(int i = 0; i < 250000; i++);
}

int main(void)
{
	gpiox_handle_t gpio_led, gpio_button;

	    gpio_led.gpiox_base_addr = GPIOA;
	    gpio_led.gpio_pin_config.gpiox_pin_number = GPIO_PIN_NO_5;
	    gpio_led.gpio_pin_config.gpiox_pin_mode = GPIO_MODE_OUTPUT;
	    gpio_led.gpio_pin_config.gpiox_pin_optype = GPIO_OP_TYPE_PP;
	    gpio_led.gpio_pin_config.gpiox_pin_pupd_ctrl = GPIO_NO_PU_PD;
	    gpio_led.gpio_pin_config.gpiox_pin_speed = GPIO_SPEED_FAST;

	    gpio_pclk_ctrl(GPIOA, ENABLE);

	    gpio_init(&gpio_led);

	    gpio_button.gpiox_base_addr = GPIOC;
	    gpio_button.gpio_pin_config.gpiox_pin_number = GPIO_PIN_NO_13;
	    gpio_button.gpio_pin_config.gpiox_pin_mode = GPIO_MODE_IT_FT;
	    gpio_button.gpio_pin_config.gpiox_pin_pupd_ctrl = GPIO_PULL_UP;
	    gpio_button.gpio_pin_config.gpiox_pin_speed = GPIO_SPEED_FAST;

	    gpio_pclk_ctrl(GPIOC, ENABLE);

	    gpio_init(&gpio_button);

	    //config the interrupt
	     gpio_irq_priority_config(IRQ_NO_EXTI15_10, NVIC_IRQ_PRI15);
         gpio_irq_config(IRQ_NO_EXTI15_10, ENABLE);

         while(1);

    return 0;
}


void EXTI15_10_IRQHandler(void)
{
  delay();
  gpio_irq_handle(GPIO_PIN_NO_13);
  gpio_toggle_pin(GPIOA, GPIO_PIN_NO_5);
}
