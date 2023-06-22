/******************************************************************************
 *
 * Module: ACD
 *
 * File Name:adc.c
 *
 * Description: ADC Driver
 *
 *Author: Ahmed Gamal
 *
 *******************************************************************************/

#include <avr/io.h>/* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description: Function to initialize the ICU driver
 * 	1.Set reference voltage
 * 	2.Enable ADC
 * 	3.Disable/Enable ADC Interrupt
 * 	4.Set the required clock.
 */
void ADC_init(const ADC_SetConfig * config_ptr)
{
	/*Set the reference voltage */
	ADMUX = (ADMUX & 0x3F) | ((config_ptr->reference)<<6);
	/* Enable ADC driver */
	SET_BIT(ADCSRA,ADEN);
	/* Disable/Enable Interrupt*/
	ADCSRA = (ADCSRA & 0xF7) | ((config_ptr->interrupt)<<4);
	/* Select the ADC driver prescale*/
	ADCSRA = (ADCSRA & 0xF8) | (config_ptr->clock);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX = (ADMUX & 0xE0)| channel_num ;
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
