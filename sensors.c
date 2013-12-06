
#include "msp430.h"
#include "sensors.h"

void initSensors()
{
	 ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
	 ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
}

unsigned int midSensor()
{
	 ADC10CTL0 &= ~ENC;
	 ADC10CTL1 = INCH_3;
	 ADC10AE0 |= BIT3;
	 ADC10CTL0 |= ENC + ADC10SC;
	 __bis_SR_register(CPUOFF + GIE);
	 return ADC10MEM;
}
unsigned int leftSensor()
{
	 ADC10CTL0 &= ~ENC;
	 ADC10CTL1 = INCH_4;
	 ADC10AE0 |= BIT4;
	 ADC10CTL0 |= ENC + ADC10SC;
	 __bis_SR_register(CPUOFF + GIE);
	 return ADC10MEM;
}
unsigned int rightSensor()
{
	 ADC10CTL0 &= ~ENC;
	 ADC10CTL1 = INCH_7;
	 ADC10AE0 |= BIT7;
	 ADC10CTL0 |= ENC + ADC10SC;
	 __bis_SR_register(CPUOFF + GIE);
	 return ADC10MEM;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
