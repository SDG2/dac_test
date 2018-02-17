//#define DAC_CHANNEL_12D ((uint32_t)0x00000011)
//
//#include "stm32f4xx_hal.h"
//
//HAL_StatusTypeDef HAL_DAC_Start_DualDMA(DAC_HandleTypeDef* hdac,
//		uint32_t Channel, uint32_t* pData, uint32_t Length, uint32_t Alignment) {
//	uint32_t tmpreg = 0;
//
//	/* Check the parameters */
//	assert_param(IS_DAC_CHANNEL_INSTANCE(hdac->Instance, Channel));
//	assert_param(IS_DAC_ALIGN(Alignment));
//
//	/* Process locked */
//	__HAL_LOCK(hdac);
//
//	/* Change DAC state */
//	hdac->State = HAL_DAC_STATE_BUSY;
//
//	if (Channel == DAC_CHANNEL_1) {
//		/* Set the DMA transfer complete callback for channel1 */
//		hdac->DMA_Handle1->XferCpltCallback = DAC_DMAConvCpltCh1;
//
//		/* Set the DMA half transfer complete callback for channel1 */
//		hdac->DMA_Handle1->XferHalfCpltCallback = DAC_DMAHalfConvCpltCh1;
//
//		/* Set the DMA error callback for channel1 */
//		hdac->DMA_Handle1->XferErrorCallback = DAC_DMAErrorCh1;
//
//		/* Enable the selected DAC channel1 DMA request */
//		SET_BIT(hdac->Instance->CR, DAC_CR_DMAEN1);
//
//		/* Case of use of channel 1 */
//		switch (Alignment) {
//		case DAC_ALIGN_12B_R:
//			/* Get DHR12R1 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12R1;
//			break;
//		case DAC_ALIGN_12B_L:
//			/* Get DHR12L1 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12L1;
//			break;
//		case DAC_ALIGN_8B_R:
//			/* Get DHR8R1 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR8R1;
//			break;
//		default:
//			break;
//		}
//	} else if (Channel == DAC_CHANNEL_2) {
//		/* Set the DMA transfer complete callback for channel2 */
//		hdac->DMA_Handle2->XferCpltCallback = DAC_DMAConvCpltCh2;
//
//		/* Set the DMA half transfer complete callback for channel2 */
//		hdac->DMA_Handle2->XferHalfCpltCallback = DAC_DMAHalfConvCpltCh2;
//
//		/* Set the DMA error callback for channel2 */
//		hdac->DMA_Handle2->XferErrorCallback = DAC_DMAErrorCh2;
//
//		/* Enable the selected DAC channel2 DMA request */
//		SET_BIT(hdac->Instance->CR, DAC_CR_DMAEN2);
//
//		/* Case of use of channel 2 */
//		switch (Alignment) {
//		case DAC_ALIGN_12B_R:
//			/* Get DHR12R2 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12R2;
//			break;
//		case DAC_ALIGN_12B_L:
//			/* Get DHR12L2 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12L2;
//			break;
//		case DAC_ALIGN_8B_R:
//			/* Get DHR8R2 address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR8R2;
//			break;
//		default:
//			break;
//		}
//	} else { /* Dual-channel mode - added by JG @ Det3 */
//		/* Set the DMA transfer complete callback for channel1 */
//		hdac->DMA_Handle1->XferCpltCallback = DAC_DMAConvCpltCh1;
//
//		/* Set the DMA half transfer complete callback for channel1 */
//		hdac->DMA_Handle1->XferHalfCpltCallback = DAC_DMAHalfConvCpltCh1;
//
//		/* Set the DMA error callback for channel1 */
//		hdac->DMA_Handle1->XferErrorCallback = DAC_DMAErrorCh1;
//
//		/* Enable the selected DAC channel1 DMA request */
//		SET_BIT(hdac->Instance->CR, DAC_CR_DMAEN1);
//
//		/* Case of use of channel 1+2 - dual mode */
//		switch (Alignment) {
//		case DAC_ALIGN_12B_R:
//			/* Get DHR12RD address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12RD;
//			break;
//		case DAC_ALIGN_12B_L:
//			/* Get DHR12LD address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR12LD;
//			break;
//		case DAC_ALIGN_8B_R:
//			/* Get DHR8RD address */
//			tmpreg = (uint32_t) &hdac->Instance->DHR8RD;
//			break;
//		default:
//			break;
//		}
//
//	}
//
//	/* Enable the DMA Channel */
//	/* Reversed for dual-channel operation by JG @ Det3 */
//	if (Channel == DAC_CHANNEL_2) {
//		/* Enable the DAC DMA underrun interrupt */
//		__HAL_DAC_ENABLE_IT(hdac, DAC_IT_DMAUDR2);
//
//		/* Enable the DMA Channel */
//		HAL_DMA_Start_IT(hdac->DMA_Handle2, (uint32_t) pData, tmpreg, Length);
//	} else {
//		/* Enable the DAC DMA underrun interrupt */
//		__HAL_DAC_ENABLE_IT(hdac, DAC_IT_DMAUDR1);
//
//		/* Enable the DMA Channel */
//		HAL_DMA_Start_IT(hdac->DMA_Handle1, (uint32_t) pData, tmpreg, Length);
//	}
//
//	/* Process Unlocked */
//	__HAL_UNLOCK(hdac);
//
//	/* Enable the Peripheral */
//	if (Channel == DAC_CHANNEL_12D) {
//		__HAL_DAC_ENABLE(hdac, DAC_CHANNEL_1);
//		__HAL_DAC_ENABLE(hdac, DAC_CHANNEL_2);
//	} else {
//		__HAL_DAC_ENABLE(hdac, Channel);
//	}
//
//	/* Return function status */
//	return HAL_OK;
//}
