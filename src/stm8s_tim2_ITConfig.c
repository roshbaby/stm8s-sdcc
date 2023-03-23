/**
  ******************************************************************************
  * @file    stm8s_tim2.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the TIM2 peripheral.
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
#include "stm8s_tim2.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @addtogroup TIM2_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified TIM2 interrupts.
  * @param   NewState new state of the TIM2 peripheral.
  * This parameter can be: ENABLE or DISABLE.
  * @param   TIM2_IT specifies the TIM2 interrupts sources to be enabled or disabled.
  * This parameter can be any combination of the following values:
  *                       - TIM2_IT_UPDATE: TIM2 update Interrupt source
  *                       - TIM2_IT_CC1: TIM2 Capture Compare 1 Interrupt source
  *                       - TIM2_IT_CC2: TIM2 Capture Compare 2 Interrupt source
  *                       - TIM2_IT_CC3: TIM2 Capture Compare 3 Interrupt source
  * @param   NewState new state of the TIM2 peripheral.
  * @retval None
  */
void TIM2_ITConfig(TIM2_IT_TypeDef TIM2_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM2_IT_OK(TIM2_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TIM2->IER |= (uint8_t)TIM2_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TIM2->IER &= (uint8_t)(~TIM2_IT);
  }
}

/**
  * @}
  */

  /**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
