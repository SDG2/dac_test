/*
 * dac_player.h
 *
 *  Created on: 17 feb. 2018
 *      Author: jcala
 */

#ifndef DAC_PLAYER_H_
#define DAC_PLAYER_H_

#include "stdint.h"
#include "stm32f4xx_hal.h"

/*
 * bit 0 -> buffer 1 disp
 * bit 1 -> buffer 2 disp
 * bit 2 -> buffer 1 vacio
 * bit 2 -> buffer 2 vacio
 * bit 3 -> final cancion
 * bit 4 -> transmision ch1 completada
 * bit 5 -> transmision ch2 completada
 * */
uint32_t dac_flags;

void HAL_DACEx_ConvCpltCallbackChX(DAC_HandleTypeDef* hdac);

#endif /* DAC_PLAYER_H_ */
