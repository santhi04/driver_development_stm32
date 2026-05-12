/*
 * led_button.c
 *
 *  Created on: 12 May 2026
 *      Author: nikhi
 */


#include <stdint.h>
#include "stm32f401xx.h"
#include "gpio_driver.h"

void delay()
{
   for(int i = 0; i < 500000; i++);
}


int main(void)
{
    gpiox_handle_t gpio_led, gpio_button;

    gpio_led.gpiox_base_addr = GPIOA;
    gpio_led.gpio_pin_config.gpiox_pin_number = GPIO_PIN_NO_5;
    gpio_led.gpio_pin_config.gpiox_pin_mode = GPIO_MODE_OUTPUT;
    gpio_led.gpio_pin_config.gpiox_pin_optype = GPIO_OP_TYPE_PP; //open drain configuration
    gpio_led.gpio_pin_config.gpiox_pin_pupd_ctrl = GPIO_NO_PU_PD;
    gpio_led.gpio_pin_config.gpiox_pin_speed = GPIO_SPEED_FAST;

    gpio_pclk_ctrl(GPIOA, ENABLE);

    gpio_init(&gpio_led);

    gpio_button.gpiox_base_addr = GPIOC;
    gpio_button.gpio_pin_config.gpiox_pin_number = GPIO_PIN_NO_13;
    gpio_button.gpio_pin_config.gpiox_pin_mode = GPIO_MODE_INPUT;
    gpio_button.gpio_pin_config.gpiox_pin_pupd_ctrl = GPIO_NO_PU_PD;
    gpio_button.gpio_pin_config.gpiox_pin_speed = GPIO_SPEED_FAST;

    gpio_pclk_ctrl(GPIOC, ENABLE);

    gpio_init(&gpio_button);

    while(1)
    {
       if(!gpio_read_pin(GPIOC, GPIO_PIN_NO_13))
       {
           gpio_toggle_pin(GPIOA, GPIO_PIN_NO_5);
           delay();
       }
       
    }
    
    return 0;
}
