/*
 * stm32f401xx.h
 *
 *  Created on: 7 May 2026
 *      Author: NikhilaPantham
 */

#include <stdint.h>

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_


/* base addresses of Flash, SRAM and ROM memories */

#define FLASH_BASEADDR  0x08000000U
#define SRAM1_BASEADDR  0x20000000U
#define ROM_BASEADDR    0x1FFF0000U
#define SRAM            SRAM1_BASEADDR

/* AHBx and APBx Bus peripheral addresses*/

#define PERIPHERAL_BASEADDR         0x40000000U
#define APB1_PERIPHERAL_BASEADDR    PERIPHERAL_BASEADDR
#define APB2_PERIPHERAL_BASEADDR    0x40010000U
#define AHB1_PERIPHERAL_BASEADDR    0x40020000U
#define AHB2_PERIPHERAL_BASEADDR    0x50000000U

/* Base addresses of peripherals on AHB1 bus */

#define GPIOA_BASEADDR   0x40020000U
#define GPIOB_BASEADDR   0x40020400U
#define GPIOC_BASEADDR   0x40020800U
#define GPIOD_BASEADDR   0x40020C00U
#define GPIOE_BASEADDR   0x40021000U
#define GPIOH_BASEADDR   0x40021C00U
#define CRC_BASEADDR     0x40023000U
#define RCC_BASEADDR     0x40023800U
#define FIR_BASEADDR     0x40023C00U
#define DMA1_BASEADDR    0x40026000U
#define DMA2_BASEADDR    0x40026400U
#define RCC_BASEADDR     (AHB1_PERIPHERAL_BASEADDR + 0x3800)

/* Base addresses of peripherals on APB1  bus*/

#define SPI2_BASEADDR    (APB1_PERIPHERAL_BASEADDR + 0x3800)
#define SPI3_BASEADDR    (APB1_PERIPHERAL_BASEADDR + 0x3C00)
#define USART2_BASEADDR  (APB1_PERIPHERAL_BASEADDR + 0x4400)
#define I2C1_BASEADDR    (APB1_PERIPHERAL_BASEADDR + 0x5400)
#define I2C2_BASEADDR    (APB1_PERIPHERAL_BASEADDR + 0x5800)
#define I2C3_BASEADDR    (APB1_PERIPHERAL_BASEADDR + 0x5C00)

/* Base addresses of peripherals on APB1  bus*/
#define USART1_BASEADDR  (APB2_PERIPHERAL_BASEADDR + 0x1000)
#define USART6_BASEADDR  (APB2_PERIPHERAL_BASEADDR + 0x1400)
#define SPI1_BASEADDR    (APB2_PERIPHERAL_BASEADDR + 0x3000)
#define SPI4_BASEADDR    (APB2_PERIPHERAL_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR  (APB2_PERIPHERAL_BASEADDR + 0x3800)
#define EXTI_BASEADDR    (APB2_PERIPHERAL_BASEADDR + 0x3C00)


/* peripheral registers addresses*/

typedef struct
{
   volatile uint32_t MODER;       /* Address offset 0x00*/
   volatile uint32_t OTYPER;      /* Address offset 0x04*/
   volatile uint32_t OSPEEDR;     /* Address offset 0x08*/
   volatile uint32_t PUPDR;       /* Address offset 0x0C*/
   volatile uint32_t IDR;         /* Address offset 0x10*/
   volatile uint32_t ODR;         /* Address offset 0x14*/
   volatile uint32_t BSRR;        /* Address offset 0x18*/
   volatile uint32_t LCKR;        /* Address offset 0x1C*/
   volatile uint32_t AFR[2];      /* Address offset 0x20*/
}GPIO_reg_def_t;

typedef struct 
{
   volatile uint32_t RCC_CR;         /* Address offset 0x00*/
   volatile uint32_t RCC_PLLCFGR;    /* Address offset 0x04*/
   volatile uint32_t RCC_CFGR;       /* Address offset 0x08*/
   volatile uint32_t RCC_CIR;        /* Address offset 0x0C*/
   volatile uint32_t RCC_AHB1RSTR;   /* Address offset 0x10*/
   volatile uint32_t RCC_AHB2RSTR;   /* Address offset 0x14*/
   uint32_t RESERVED0[2];            /* Address offset 0x18*/
   volatile uint32_t RCC_APB1RSTR;   /* Address offset 0x20*/ 
   volatile uint32_t RCC_APB2RSTR;   /* Address offset 0x24*/
   uint32_t RESERVED1[2];             /* Address offset 0x28*/
   volatile uint32_t RCC_AHB1ENR;    /* Address offset 0x30*/
   volatile uint32_t RCC_AHB2ENR;    /* Address offset 0x34*/
   uint32_t RESERVED2[2];             /* Address offset 0x38*/
   volatile uint32_t RCC_APB1ENR;    /* Address offset 0x40*/
   volatile uint32_t RCC_APB2ENR;    /* Address offset 0x44*/
   uint32_t RESERVED3[2];             /* Address offset 0x48*/
   volatile uint32_t RCC_AHB1LPENR;  /* Address offset 0x50*/
   volatile uint32_t RCC_AHB2LPENR;  /* Address offset 0x54*/
   uint32_t RESERVED4[2];             /* Address offset 0x58*/
   volatile uint32_t RCC_APB1LPENR;  /* Address offset 0x60*/
   volatile uint32_t RCC_APB2LPENR;  /* Address offset 0x64*/
   uint32_t RESERVED5[2];             /* Address offset 0x68*/
   volatile uint32_t RCC_BDCR;       /* Address offset 0x70*/
   volatile uint32_t RCC_CSR;        /* Address offset 0x74*/
   uint32_t RESERVED6[2];             /* Address offset 0x78*/
   volatile uint32_t RCC_SSCGR;      /* Address offset 0x80*/
   volatile uint32_t RCC_PLLI2SCFGR; /* Address offset 0x84*/
   uint32_t RESERVED7;                /* Address offset 0x88*/
   volatile uint32_t RCC_DCKCFGR;    /* Address offset 0x8C*/
} RCC_reg_def_t;

/* peripheral definitions of the base addresses*/

#define GPIOA  ((GPIO_reg_def_t*)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_reg_def_t*)GPIOB_BASEADDR)
#define GPIOC  ((GPIO_reg_def_t*)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_reg_def_t*)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_reg_def_t*)GPIOE_BASEADDR)
#define GPIOH  ((GPIO_reg_def_t*)GPIOH_BASEADDR)

#define RCC    ((RCC_reg_def_t*)RCC_BASEADDR)

#endif /* INC_STM32F401XX_H_ */
