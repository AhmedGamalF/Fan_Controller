/******************************************************************************
 *
 * Module: APP
 *
 * File Name: App.c
 *
 * Description: Fan Controller system
 *
 * Author : Ahmed Gamal
 *
 *******************************************************************************/
# include "lcd.h"
# include "motor.h"
# include "adc.h"
# include "lm35_sensor.h"

int main()
{
	uint8 temp; /* to store the temprature  from the sensor*/
	ADC_SetConfig ADC_configration = {INTERNAL,DISABLE,F_CPU_8};

	LCD_init(); /* initialize LCD driver */
	ADC_init(& ADC_configration); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor driver */

	LCD_displayStringRowColumn(0, 4, "FAN is ");
	LCD_displayStringRowColumn(1, 4, "Temp =    C");

	while(1)
	{
		/* Read the temprature from  LM35 sensor*/
		temp = LM35_getTemperature();

		if (temp < 30)
		{
			LCD_displayStringRowColumn(0, 11, "OFF");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			/* Stop the motor */
			DcMotor_Rotate(STOP, 0);
		}

		else if((temp >= 30) && (temp < 60))
		{
			/* FAN rotates clockwise with speed 25%*/
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0, 11, "ON  ");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
		}
		else if ((temp >= 60) && (temp < 90))
		{
			/* FAN rotates clockwise with speed 50%*/
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0, 11, "ON  ");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
		}
		else if ((temp >= 90) && (temp < 120))
		{
			/* FAN rotates clockwise with speed 75%*/
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0,11, "ON  ");
			/* Display the temperature value every time at same position */
			LCD_moveCursor(1,10);
			if(temp >= 100)
			{
				LCD_intgerToString(temp);
			}
			else
			{
				LCD_intgerToString(temp);
				/* In case the digital value is two or one digits print space in the next digit place */
				LCD_displayCharacter(' ');
			}
		}
		else if(temp >= 120)
		{
			/* FAN rotates clockwise with speed 100%*/
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0, 11, "ON  ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temp);
		}
	}
}

