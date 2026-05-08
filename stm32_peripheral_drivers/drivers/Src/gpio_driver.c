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