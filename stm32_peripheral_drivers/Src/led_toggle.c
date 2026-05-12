/*
 * led_toggle.c
 *
 *  Created on: 10 May 2026
 *      Author: nikhi
 */

#include <stdint.h>
#include "stm32f401xx.h"
#include "gpio_driver.h"

void delay()
{
   for(int i = 0; i < 250000; i++);
}


int main(void)
{
    gpiox_handle_t gpio_led;
    gpio_led.gpiox_base_addr = GPIOA;
    gpio_led.gpio_pin_config.gpiox_pin_number = GPIO_PIN_NO_5;
    gpio_led.gpio_pin_config.gpiox_pin_mode = GPIO_MODE_OUTPUT;
    gpio_led.gpio_pin_config.gpiox_pin_optype = GPIO_OP_TYPE_OD; //open drain configuration
    gpio_led.gpio_pin_config.gpiox_pin_pupd_ctrl = GPIO_PULL_UP;
    gpio_led.gpio_pin_config.gpiox_pin_speed = GPIO_SPEED_FAST;

    gpio_pclk_ctrl(GPIOA, ENABLE);
    gpio_init(&gpio_led);

    while(1)
    {
       gpio_toggle_pin(GPIOA, GPIO_PIN_NO_5);
       delay();
    }
    
    return 0;
}
