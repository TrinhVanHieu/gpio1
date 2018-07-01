#include<project.h>
/****************************************************/
void Init_gpio(void)
{
	unsigned int tmprep;
	/*PC9*/
	tmprep = read_reg(GPIO_MODER, ~(0x03u << 18));
	tmprep = tmprep | (0x01 << 18);
	write_reg(GPIO_MODER, tmprep);
	
	/*PC8*/
	tmprep = read_reg(GPIO_MODER, ~(0x03u << 16));
	tmprep = tmprep | (0x01 << 16);
	write_reg(GPIO_MODER, tmprep);
}

void turn_on(unsigned char pin)
{
	write_reg(GPIO_BSRR, (1 << pin));
}
void turn_off(unsigned char pin)
{
	write_reg(GPIO_BSRR, (1 << (pin + 16)));
}