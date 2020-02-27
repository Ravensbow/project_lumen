/*
 * funkcje.h
 *
 *  Created on: Feb 27, 2020
 *      Author: Vermik
 */
#include "arm_math.h"
#include "main.h"
#ifndef INC_FUNKCJE_H_
#define INC_FUNKCJE_H_

void SetLCDValues(int zad, int wyj);
void ReadIntegerLight(int* val);
void SetPWM(int wej, int wyj, arm_pid_instance_f32 * PID,TIM_HandleTypeDef *htim3);
#endif /* INC_FUNKCJE_H_ */
