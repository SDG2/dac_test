/*
 * dac_player.c
 *
 *  Created on: 17 feb. 2018
 *      Author: jcala
 */


#include "dac_player.h"

#define SAMPLES 512
#define START_STATE 0x0000000000000003
#define CH1_COMPLETE 0x0000000000000010
#define CH2_COMPLETE 0x0000000000000020

uint32_t buffer1ch1[SAMPLES]; //n1
uint32_t buffer2ch1[SAMPLES]; //n2
uint32_t buffer1ch2[SAMPLES];//n3
uint32_t buffer2ch2[SAMPLES];//n4

void dac_init(DAC_HandleTypeDef hdac){
	HAL_DAC_Init(&hdac);
	dac_flags = dac_flags | START_STATE;
}

void dac_enable_timer(TIM_HandleTypeDef htim){
	HAL_TIM_Base_Start(&htim);
}

void transmit(){

}

void cpy_buffer(int numbuffer,uint32_t* buffer){
	unsigned int i;
	uint32_t* loc_buffer;

	switch(numbuffer){
	case 1:
		loc_buffer = buffer1ch1;
		break;
	case 2:
		loc_buffer = buffer2ch1;
		break;
	case 3:
		loc_buffer = buffer1ch2;
		break;
	case 4:
		loc_buffer = buffer2ch2;
		break;
	default:
		return;
	}
	for(i = 0; i < SAMPLES; i++)
		*(loc_buffer+i) = *(buffer+i);

}

void HAL_DACEx_ConvCpltCallbackCh1(DAC_HandleTypeDef* hdac){
	dac_flags = dac_flags | CH1_COMPLETE;
}
void HAL_DACEx_ConvCpltCallbackCh2(DAC_HandleTypeDef* hdac){
	dac_flags = dac_flags | CH2_COMPLETE;
}

void config_timer(TIM_HandleTypeDef htim,uint32_t sampling_rate){
	  TIM_MasterConfigTypeDef sMasterConfig;
	  htim.Instance = TIM6;
	  htim.Init.Prescaler = 0;
	  htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim.Init.Period = sampling_rate;
	  if (HAL_TIM_Base_Init(&htim) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }
	  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
	  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	  if (HAL_TIMEx_MasterConfigSynchronization(&htim, &sMasterConfig) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }
}



