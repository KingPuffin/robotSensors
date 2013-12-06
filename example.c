#include <msp430g2553.h>
#include "sensors.h"
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  initSensors();

  P1DIR |= 0x41;

  for(;;)
  {
	  rightSensor();
	  if( ADC10MEM > 0x2FF )
	  {
		  P1OUT |= BIT6;
	  }
	  else
	  {
		  P1OUT &= ~BIT6;
	  }
	  _delay_cycles(500000);

	  leftSensor();
	  if( ADC10MEM > 0x1FF )
	  {
		  P1OUT |= BIT0;
	  }
	  else
	  {
		  P1OUT &= ~BIT0;
	  }
	  _delay_cycles(500000);


  }
}


