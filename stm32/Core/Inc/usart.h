/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

#define UART_DMA_TX LL_DMA_CHANNEL_2
#define UART_DMA_RX LL_DMA_CHANNEL_3

#define TX_BUFF_SIZE 5
#define RX_BUFF_SIZE 5

extern uint8_t tx_buff[TX_BUFF_SIZE];
extern uint8_t rx_buff[RX_BUFF_SIZE];

void MX_USART1_UART_Init(void);
void UART_TX (uint8_t* source, uint16_t len);
void UART_RX (uint8_t* dest, uint16_t len);
void DMA1_RecieveComplete(void);
void DMA1_TransmitComplete(void);

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
