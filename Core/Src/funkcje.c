/*
 * funkcje.c
 *
 *  Created on: Feb 27, 2020
 *      Author: Vermik
 */

#include <funkcje.h>
#include "bh1750.h"

void SetLCDValues(int zad, int wyj)
{
	lcd_clear();
	char bufor[100];
	 lcd_put_cur(0,0);
	// lcd_send_string("Natezenie zadane:");
	 if(zad <=190&&zad >=0)
		 sprintf(&bufor, "Lx_zad= %d", zad);
	 else if(zad>190)
		 sprintf(&bufor, "I SEE FIRE");
	 else
		 sprintf(&bufor, "Dotarles na dno");
	 lcd_send_string(bufor);
	 lcd_put_cur(1,0);
	 sprintf(&bufor, "Lx_pom= %d", wyj);
	 lcd_send_string(bufor);
}
void ReadIntegerLight(int* val)
{
	float temp;
	BH1750_ReadLight(&temp);
	*val=(int)temp;
}
void SetPWM(int wej, int wyj, arm_pid_instance_f32 * PID,TIM_HandleTypeDef *htim3)
{
//
	int uchyb =wej-wyj;
	int pid_return= arm_pid_f32(PID, uchyb);

	if(pid_return<0)
		pid_return=0;
	else if(pid_return >1000)
		pid_return=1000;

	__HAL_TIM_SET_COMPARE(htim3,TIM_CHANNEL_3, pid_return);
}
