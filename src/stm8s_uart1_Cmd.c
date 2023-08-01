/**
  ********************************************************************************
  * @file    stm8s_uart1.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the UART1 peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s_uart1.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/** @}
  * @addtogroup UART1_Public_Functions
  * @{
  */

/**
  * @brief  Enable the UART1 peripheral.
  * @param  NewState : The new state of the UART Communication.
  *         This parameter can be any of the @ref FunctionalState enumeration.
  * @retval None
  */
void UART1_Cmd(FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    /* UART1 Enable */
    UART1->CR1 &= (uint8_t)(~UART1_CR1_UARTD);
  }
  else
  {
    /* UART Disable */
    UART1->CR1 |= UART1_CR1_UARTD;
  }
}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
