/*
 * gpio_driver.c
 *
 *  Created on: 8 May 2026
 *      Author: NikhilaPantham
 */


#include "gpio_driver.h"

/*****************************************************************
 * @fn              - gpio_pclk_ctrl
 * 
 * @brief           - This function enables or disable the the peripheral clock of the given GPIO port
 * 
 * @param[in]       - base address of the given GPIO port
 * @param[in]       - ENABLE or DISABLE macros
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_pclk_ctrl(gpio_reg_def_t *gpiox_base_addr, uint8_t enordi)
{
  if (enordi == ENABLE) {
    if (gpiox_base_addr == GPIOA) {
      GPIOA_PCLK_EN();
    } else if (gpiox_base_addr == GPIOB) {
      GPIOB_PCLK_EN();
    } else if (gpiox_base_addr == GPIOC) {
      GPIOC_PCLK_EN();
    } else if (gpiox_base_addr == GPIOD) {
      GPIOD_PCLK_EN();
    } else if (gpiox_base_addr == GPIOE) {
      GPIOE_PCLK_EN();
    } else if (gpiox_base_addr == GPIOH) {
      GPIOH_PCLK_EN();
    }
  }
  else{
    if (gpiox_base_addr == GPIOA) {
      GPIOA_PCLK_DI();
    } else if (gpiox_base_addr == GPIOB) {
      GPIOB_PCLK_DI();
    } else if (gpiox_base_addr == GPIOC) {
      GPIOC_PCLK_DI();
    } else if (gpiox_base_addr == GPIOD) {
      GPIOD_PCLK_DI();
    } else if (gpiox_base_addr == GPIOE) {
      GPIOE_PCLK_DI();
    } else if (gpiox_base_addr == GPIOH) {
      GPIOH_PCLK_DI();
    }
  }
}

/*****************************************************************
 * @fn              - gpio_init
 * 
 * @brief           - This function initializes the specified GPIO port.
 * 
 * @param[in]       - base address of the given GPIO port
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_init(gpiox_handle_t *gpiox_handle)
{
  uint32_t pin_config_position = 0;
    /* configure the mode of the pin*/
  if(gpiox_handle->gpio_pin_config.gpiox_pin_mode <= GPIO_MODE_ANALOG)
  {
    pin_config_position = gpiox_handle->gpio_pin_config.gpiox_pin_mode << (2 * gpiox_handle->gpio_pin_config.gpiox_pin_number);
    gpiox_handle->gpiox_base_addr->MODER &= ~(0x3 << gpiox_handle->gpio_pin_config.gpiox_pin_number);
    gpiox_handle->gpiox_base_addr->MODER |= pin_config_position;
  }
  else
  {
    // interrupt pin modes.
  }

  pin_config_position = 0;//clear the pin config position.

  /* configure the speed of the pin*/
  pin_config_position = gpiox_handle->gpio_pin_config.gpiox_pin_speed << (2 * gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->OSPEEDR &= ~(0x3 << gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->OSPEEDR |= pin_config_position;
  pin_config_position = 0; //clear the pin config position.

  /* configure the pupd config of the pin*/
  pin_config_position = gpiox_handle->gpio_pin_config.gpiox_pin_pupd_ctrl << (2 * gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->PUPDR &= ~(0x3 << gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->PUPDR |= pin_config_position;
  pin_config_position = 0; //clear the pin config position.

  /* configure the out type of the pin*/
  pin_config_position = gpiox_handle->gpio_pin_config.gpiox_pin_optype << ( gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->OTYPER &= ~(1 << gpiox_handle->gpio_pin_config.gpiox_pin_number);
  gpiox_handle->gpiox_base_addr->OTYPER |= pin_config_position;
  pin_config_position = 0; //clear the pin config position.

  /* configure the alternate functionality of the pin*/
  if(gpiox_handle->gpio_pin_config.gpiox_pin_mode <= GPIO_MODE_ALTFUN)
  {
    uint32_t afr_pos, afr_bit_pos = 0;
    afr_pos = gpiox_handle->gpio_pin_config.gpiox_pin_number / 8;
    afr_bit_pos = gpiox_handle->gpio_pin_config.gpiox_pin_number % 8;
    gpiox_handle->gpiox_base_addr->AFR[afr_pos] &= ~(0xF << (4 * afr_bit_pos));
    gpiox_handle->gpiox_base_addr->AFR[afr_pos] |= gpiox_handle->gpio_pin_config.gpiox_pin_altfun_mode << (4 * afr_bit_pos);
  }

}

/*****************************************************************
 * @fn              - gpio_deinit
 * 
 * @brief           - This function deinitializes the specified GPIO port.
 * 
 * @param[in]       - base address of the given GPIO port
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_deinit(gpio_reg_def_t *gpiox_base_addr)
{
  if (gpiox_base_addr == GPIOA) {
      GPIOA_REG_RESET();
    } else if (gpiox_base_addr == GPIOB) {
      GPIOB_REG_RESET();
    } else if (gpiox_base_addr == GPIOC) {
      GPIOC_REG_RESET();
    } else if (gpiox_base_addr == GPIOD) {
      GPIOD_REG_RESET();
    } else if (gpiox_base_addr == GPIOE) {
      GPIOE_REG_RESET();
    } else if (gpiox_base_addr == GPIOH) {
      GPIOH_REG_RESET();
    }

}

/*****************************************************************
 * @fn              - gpio_read_pin
 * 
 * @brief           - This function reads the value of the specified GPIO pin
 * 
 * @param[in]       - base address of the given GPIO port
 * @param[in]       - pin number
 * 
 * @return          - uint8_t
 * 
 * @note            - none
 * 
 * 
 */
uint8_t gpio_read_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin)
{
  uint8_t value = 0;
  value = (uint8_t)((gpiox_base_addr->IDR >> pin) & 0x00000001 );
  return value;
}

/*****************************************************************
 * @fn              - gpio_read_port
 * 
 * @brief           - This function reads data from the given GPIO port
 * 
 * @param[in]       - base address of the given GPIO port
 * 
 * @return          - uint16_t
 * 
 * @note            - none
 * 
 * 
 */
uint16_t gpio_read_port(gpio_reg_def_t *gpiox_base_addr)
{
  uint16_t value = 0;
  value = (uint16_t)(gpiox_base_addr->IDR);
  return value;
}

/*****************************************************************
 * @fn              - gpio_write_pin
 * 
 * @brief           - This function writes value to the specified GPIO pin.
 * 
 * @param[in]       - base address of the given GPIO port
 * @param[in]       - pin number
 * @param[in]       - data or value we are writing
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_write_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin, uint8_t value)
{
  if(value == GPIO_PIN_SET)
  {
    gpiox_base_addr->ODR |= (1 << pin);
  }
  else if(value == GPIO_PIN_RESET)
  {
    gpiox_base_addr->ODR &= ~(1 << pin);
  }

}

/*****************************************************************
 * @fn              - gpio_write_port
 * 
 * @brief           - This function writes data to the given GPIO port
 * 
 * @param[in]       - base address of the given GPIO port
 * @param[in]       - the value or data we are writing
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_write_port(gpio_reg_def_t *gpiox_base_addr, uint16_t value)
{
  gpiox_base_addr->ODR = value;
}

/*****************************************************************
 * @fn              - gpio_toggle_pin
 * 
 * @brief           - This function toggles the specified GPIO pin
 * 
 * @param[in]       - base address of the given GPIO port
 * @param[in]       - pin number
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_toggle_pin(gpio_reg_def_t *gpiox_base_addr, uint8_t pin)
{
  gpiox_base_addr->ODR ^= (1 << pin);
}

/*****************************************************************
 * @fn              - gpio_irq_config
 * 
 * @brief           - This function configures the interrupt 
 * 
 * @param[in]       - interrupt number
 * @param[in]       - interrupt priority
 * @param[in]       - ENABLE or DISABLE macros
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_irq_config(uint8_t irq_number, uint8_t irq_priority, uint8_t enordi)
{

}

/*****************************************************************
 * @fn              - gpio_irq_handle
 * 
 * @brief           - This function handles the interrupt requests of the pin
 * 
 * @param[in]       - pin number of the interrupt source
 * 
 * @return          - none
 * 
 * @note            - none
 * 
 * 
 */
void gpio_irq_handle(uint8_t pin_number)
{

}
