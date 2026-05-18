/*
 * gpio_driver.h
 *
 *  Created on: 8 May 2026
 *      Author: NikhilaPantham
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

#include "stm32f401xx.h"

/*configuration structure for a GPIO pin*/

typedef struct 
{
    uint8_t gpiox_pin_number;       /* specifies the GPIO pin number @GPIO_PIN_NUMBERS*/
    uint8_t gpiox_pin_mode;         /* specifies the mode of the GPIO pin @GPIO_PIN_MODES*/
    uint8_t gpiox_pin_speed;        /* specifies the operating speed of the pin* @GPIO_PIN_SPEED */
    uint8_t gpiox_pin_pupd_ctrl;    /* specifies if the pin is in push or pull config @GPIO_PIN_PUPD_CONFIG*/
    uint8_t gpiox_pin_optype;        /* specifies the out put type of the pin @GPIO_PIN_OPT*/
    uint8_t gpiox_pin_altfun_mode;   /* specifies the alternate function mode of the pin*/
} gpiox_pin_config_t;

typedef struct 
{
    gpio_reg_def_t *gpiox_base_addr;     /* pointer to the base address of the GPIo port the pin belongs to*/
    gpiox_pin_config_t gpio_pin_config;   /* GPIO pin configuration settings*/
} gpiox_handle_t;

/*
 *@GPIO_PIN_NUMBERS
 *GPIO pin numbers
 */

 #define GPIO_PIN_NO_0     0
 #define GPIO_PIN_NO_1     1
 #define GPIO_PIN_NO_2     2
 #define GPIO_PIN_NO_3     3
 #define GPIO_PIN_NO_4     4
 #define GPIO_PIN_NO_5     5
 #define GPIO_PIN_NO_6     6
 #define GPIO_PIN_NO_7     7
 #define GPIO_PIN_NO_8     8
 #define GPIO_PIN_NO_9     9
 #define GPIO_PIN_NO_10    10
 #define GPIO_PIN_NO_11    11
 #define GPIO_PIN_NO_12    12
 #define GPIO_PIN_NO_13    13
 #define GPIO_PIN_NO_14    14
 #define GPIO_PIN_NO_15    15

/*
 * @GPIO_PIN_MODES
 * GPIO modes
 */
#define GPIO_MODE_INPUT    0
#define GPIO_MODE_OUTPUT   1
#define GPIO_MODE_ALTFUN   2
#define GPIO_MODE_ANALOG   3
/* Interrupt modes*/
#define GPIO_MODE_IT_FT    4
#define GPIO_MODE_IT_RT    5
#define GPIO_MODE_IT_RFT   6

/*
 * @GPIO_PIN_OPT
 * GPIO out put type
 */
#define GPIO_OP_TYPE_PP    0
#define GPIO_OP_TYPE_OD    1

/*
 * @GPIO_PIN_SPEED
 * GPIO pin speed
 */
#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3

/*
 * @GPIO_PIN_PUPD_CONFIG
 * GPIO pull up pull down config macros
 */
#define GPIO_NO_PU_PD      0
#define GPIO_PULL_UP       1
#define GPIO_PULL_DOWN     2

/* API prototypes for the GPIO driver*/

/* peripheral clock setup*/
void gpio_pclk_ctrl(gpio_reg_def_t *gpiox_base_addr, uint8_t enordi);

/* Init and DeInit of the peripheral*/
void gpio_init(gpiox_handle_t *gpiox_handle);
void gpio_deinit(gpio_reg_def_t *gpiox_base_addr);

/* Read and Write data from and to the port*/
uint8_t gpio_read_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin);
uint16_t gpio_read_port(gpio_reg_def_t *gpiox_base_addr);
void gpio_write_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin, uint8_t value);
void gpio_write_port(gpio_reg_def_t *gpiox_base_addr, uint16_t value);
void gpio_toggle_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin);

/* IRQ config and IRQ handle*/
void gpio_irq_config(uint8_t irq_number, uint8_t enordi);
void gpio_irq_priority_config(uint8_t irq_number, uint32_t irq_priority);
void gpio_irq_handle(uint8_t pin_number);


#endif /* INC_GPIO_DRIVER_H_ */
