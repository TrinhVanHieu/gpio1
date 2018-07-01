
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__


#define write_reg(addr, value) 				 	*((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      				*((unsigned long int *)(addr)) & (mask)

/*CLOCK*/
#define BASE_ADDR_RCC							0x40021000u		
#define RCC_AHBENR								(BASE_ADDR_RCC + 0x14u)

/*GPIOC*/
#define BASE_ADDR_GPIOC							0x48000800u		
#define GPIO_MODER								(BASE_ADDR_GPIOC + 0x00u)
#define GPIO_BSRR								(BASE_ADDR_GPIOC + 0x18u)

#define INPUT_MODER								0x00u
#define OUTPUT_MODER							0x01u	
#define ALT_MODER								0x10u	
#define ANALOG_MODER							0x11u

/*Led4_PC8 led3_PC9*/
#define LED3_PIN								9
#define LED4_PIN								8
/* end file */
#endif /* __HW_STM32F030_MINI_H__ */

