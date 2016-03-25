#include <msp430.h>
#include <stdint.h>

int main(void){
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= 0x01;

	while(1){
		P1OUT ^= 0x01;
		for(volatile uint32_t i=0; i<40000; i++);

	}
	return 0;

}