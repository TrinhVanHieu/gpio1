#include<project.h>
/************************************************************************/
void system_init(void)
{
    unsigned int temp_reg;

    /* Reset the RCC clock configuration to the default reset state ------------*/
    /* Set HSION bit */
    temp_reg = read_reg(RCC_CR, ~0x00000001u);
    temp_reg |= 0x00000001U;
    write_reg(RCC_CR, temp_reg);

    /* Reset SW[1:0], HPRE[3:0], PPRE[2:0], ADCPRE and MCOSEL[2:0] bits */
    temp_reg = read_reg(RCC_CFGR, ~0xF8FFB80Cu);
    write_reg(RCC_CFGR, temp_reg);
    
    /* Reset HSEON, CSSON and PLLON bits */
    temp_reg = read_reg(RCC_CR, ~0xFEF6FFFFU);
    write_reg(RCC_CR, temp_reg);
    
    /* Reset HSEBYP bit */
    temp_reg = read_reg(RCC_CR, ~0xFFFBFFFFU);
    write_reg(RCC_CR, temp_reg);
    
    /* Reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
    temp_reg = read_reg(RCC_CFGR, ~0xFFC0FFFFU);
    write_reg(RCC_CFGR, temp_reg);
    
    /* Reset PREDIV[3:0] bits */
    temp_reg = read_reg(RCC_CFGR2, ~0xFFFFFFF0U);
    write_reg(RCC_CFGR2, temp_reg);
    
    /* Reset USART1SW[1:0], I2C1SW, CECSW and ADCSW bits */
    temp_reg = read_reg(RCC_CFGR3, ~0xFFFFFEACU);
    write_reg(RCC_CFGR3, temp_reg);
    
    /* Reset HSI14 bit */
    temp_reg = read_reg(RCC_CR2, ~0xFFFFFFFEU);
    write_reg(RCC_CR2, temp_reg);
    
    /* Disable all interrupts */
    write_reg(RCC_CIR, 0x00000000U);
}

void enable_clk(void)
{
	unsigned int tmprep;
	/*clock port C*/
	tmprep = read_reg(RCC_AHBENR, ~(0x01u << 19));
	tmprep = tmprep | (0x01u <<19);
	write_reg(RCC_AHBENR, tmprep);
}