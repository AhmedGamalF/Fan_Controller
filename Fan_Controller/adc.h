
/******************************************************************************
 *
 * Module: ACD
 *
 * File Name:adc.h
 *
 * Description: ADC Driver
 *
 * Author : Ahmed Gamal
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

# include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/**********************************************For ADC_init function****************************************/

/* Select the Reference */
typedef enum{
	AREf , AVCC, INTERNAL=3
} ADC_ReferenceSelection;

/*Enable/Disable Interrupt*/
typedef enum
{
	DISABLE ,ENABLE
}ADC_InterruptConfig;

/* Select the ADC driver Prescale*/
typedef enum
{
	F_CPU0,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_ClockType;

/* to set the ADC driver configuration*/
typedef struct
{
	ADC_ReferenceSelection reference ;
	ADC_InterruptConfig interrupt ;
	ADC_ClockType clock ;

}ADC_SetConfig;

/**********************************************For ADC_readChannel function****************************************/

/*Set the ADC driver channel */
typedef enum
{
	ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7
}ADC_ChannelConfig;

void ADC_init(const ADC_SetConfig * config_ptr);
uint16 ADC_readChannel(ADC_ChannelConfig ch_num);

#endif /* ADC_H_ */
