# driver_development_stm32
# Low level drivers for the peripherals GPIO, SPI, I2C and USART of an STM32F401xx Microcontroller

stm32f401xx.h: The device header files contains the addresses of the memory, peripherals, peripheral registers addresses
and the clock enable and disable macros of the peripherals.

gpio_driver.h : Contains the macros required for the configuration of the GPIO port and the APIs.

gpio_driver.c : Implementation of the APIs for a GPIO port which covers initialization, deinitialization, read from a pin and port, write to a pin
and port and toggle the specified pin number.

led_toggle.c : Logic to toggle a specified pin using the developed APIs.