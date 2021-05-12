/**
  ******************************************************************************
  * @file    dma.c
  * @brief   This file provides code for the configuration
  *          of all the requested memory to memory DMA transfers.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "dma.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure DMA                                                              */
/*----------------------------------------------------------------------------*/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Enable DMA controller clock
  */
void MX_DMA_Init(void)
{

  /* Init with LL driver */
  /* DMA controller clock enable */
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  LL_DMA_DisableChannel(DMA1, UART_DMA_TX);
	LL_DMA_DisableChannel(DMA1, UART_DMA_RX);
	LL_DMA_ClearFlag_TC4(DMA1);
	LL_DMA_ClearFlag_TE4(DMA1);
	LL_DMA_ClearFlag_TC5(DMA1);
	LL_DMA_ClearFlag_TE5(DMA1);
	LL_USART_EnableDMAReq_RX(USART1);
	LL_USART_EnableDMAReq_TX(USART1);
	LL_DMA_EnableIT_TC(DMA1, UART_DMA_TX);
	LL_DMA_EnableIT_TE(DMA1, UART_DMA_TX);
	LL_DMA_EnableIT_TC(DMA1, UART_DMA_RX);
	LL_DMA_EnableIT_TE(DMA1, UART_DMA_RX);
	LL_DMA_ClearFlag_GI5(DMA1);
	LL_DMA_ClearFlag_GI4(DMA1);
	LL_DMA_ClearFlag_TC4(DMA1);
	LL_DMA_ClearFlag_TE4(DMA1);
	LL_DMA_ClearFlag_TC5(DMA1);
	LL_DMA_ClearFlag_TE5(DMA1);



  /* DMA interrupt init */
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0);
  NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

}

/* USER CODE BEGIN 2 */



/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
