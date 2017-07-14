/*
 * ATmega16Test.c
 *
 * Created: 19.05.2017 11:20:28
 * Author : s-del
 */ 


#define F_CPU 14745600


#include <util/delay.h>
#include <avr/io.h>
//#include <avr/iom16.h>
//#include <avr/interrupt.h>
//#include <avr/include/stdio.h>

int main (void)
{
	
	DDRA |= (1 << 0);
	
	#pragma region
	while (1)
	{
		PORTA |= (1 << PORTA0);
		//_delay_ms(500);
		PORTA &= ~(1 << PORTA0);
		//_delay_ms(500);
	}
	#pragma endregion

	#pragma region
	/*
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;

	PORTA = 0xFF;
	PORTB = 0xFF;
	PORTC = 0xFF;
	PORTD = 0xFF;
	*/
	#pragma endregion		

	return 0;
}