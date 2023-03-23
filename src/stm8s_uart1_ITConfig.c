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
  * @brief  Deinitializes the UART peripheral.
  * @param  None
  * @retval None
	*/

/**
  * @brief  Enables or disables the specified USART interrupts.
  * @param  UART1_IT specifies the USART interrupt sources to be enabled or disabled.
  *         This parameter can be one of the following values:
  *         - UART1_IT_TXE:  Transmit Data Register empty interrupt
  *         - UART1_IT_TC:   Transmission complete interrupt
  *         - UART1_IT_RXNE_OR: Receive Data register not empty and Overrun interrupt
  *         - UART1_IT_IDLE: Idle line detection interrupt
  *         - USRT1_IT_ERR:  Error interrupt
  * @param  NewState new state of the specified USART interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_ITConfig(UART1_IT_TypeDef UART1_IT, FunctionalState NewState)
{
  uint8_t uartreg = 0, itpos = 0x00;

  /* Check the parameters */
  assert_param(IS_UART1_CONFIG_IT_OK(UART1_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  /* Get the UART1 register index */
  uartreg = (uint8_t)((uint16_t)UART1_IT >> 0x08);
  /* Get the UART1 IT index */
  itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));

  if (NewState != DISABLE)
  {
    /**< Enable the Interrupt bits according to UART1_IT mask */
    if (uartreg == 0x01)
    {
      UART1->CR1 |= itpos;
    }
    else if (uartreg == 0x02)
    {
      UART1->CR2 |= itpos;
    }
    else
    {
      UART1->CR4 |= itpos;
    }
  }
  else
  {
    /**< Disable the interrupt bits according to UART1_IT mask */
    if (uartreg == 0x01)
    {
      UART1->CR1 &= (uint8_t)(~itpos);
    }
    else if (uartreg == 0x02)
    {
      UART1->CR2 &= (uint8_t)(~itpos);
    }
    else
    {
      UART1->CR4 &= (uint8_t)(~itpos);
    }
  }

}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
