/*
 * PWMTest.c
 *
 * Created: 20.05.2017 01:12:54
 * Author : s-del
 */

#define F_CPU 14745600
#define DDR_OC0 PORTB3

#include <avr/io.h>
//#include <iom16.h>
#include <util/delay.h>

int main(void)
{
	//Timer/Counter 0 on PB3
	/*
    OCR0;	//set pwm ratio
	TCCR0;	//controls mode of timer/counter 0 (for pwm set bits CS02:0 to 1)
		WGM00;	//simplest mode = 1 (fast pwm)
		WGM01;	//simplest mode = 1
		
		COM01;	//set to 1	(non inverting pwm mode)
		COM00;	//set to 0	(set on 0, clear on match)
		
		//Clock mode:
		CS02;	// 0 0 0 no clock source (not running)
		CS01;	// in binary 1-5 coresponds to
		CS00;	// system clock in 1, 1/8, 1/64, 1/256, 1/1024 prescaling
				// 1 1 0/1 1 1 clock on T0 rising/falling edge
	DDRB;	// output (DDR_OC0 to 1)
	*/

	//TCCR0 = 0;
	TCCR0 |= (1<<WGM01)|(1<<WGM00);
	
	TCCR0 |= (1<<COM01);
	TCCR0 &= ~(1<<COM00);
	
	TCCR0 &= ~(1<<CS02);
	TCCR0 &= ~(1<<CS01);
	TCCR0 |= (1<<CS00);
	

	DDRB |= (1<< DDB3);

	OCR0 = 0xFF;
	
	unsigned char val = 0;
	signed char step = 1;
    while (1) 
    {
		OCR0 = val;
		val = (unsigned char)((signed char)val + step);
		if(val == 255)
			step = -1;
		else if(val == 0)
			step = 1;
		_delay_ms(3);
    }
}

