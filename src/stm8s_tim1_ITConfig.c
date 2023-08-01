/**
  ******************************************************************************
  * @file    stm8s_tim1.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the TIM1 peripheral.
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
#include "stm8s_tim1.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/**
  * @addtogroup TIM1_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the specified TIM1 interrupts.
  * @param  NewState new state of the TIM1 peripheral.
  *         This parameter can be: ENABLE or DISABLE.
  * @param  TIM1_IT specifies the TIM1 interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *           - TIM1_IT_UPDATE: TIM1 update Interrupt source
  *           - TIM1_IT_CC1: TIM1 Capture Compare 1 Interrupt source
  *           - TIM1_IT_CC2: TIM1 Capture Compare 2 Interrupt source
  *           - TIM1_IT_CC3: TIM1 Capture Compare 3 Interrupt source
  *           - TIM1_IT_CC4: TIM1 Capture Compare 4 Interrupt source
  *           - TIM1_IT_CCUpdate: TIM1 Capture Compare Update Interrupt source
  *           - TIM1_IT_TRIGGER: TIM1 Trigger Interrupt source
  *           - TIM1_IT_BREAK: TIM1 Break Interrupt source
  * @param  NewState new state of the TIM1 peripheral.
  * @retval None
  */
void TIM1_ITConfig(TIM1_IT_TypeDef  TIM1_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_TIM1_IT_OK(TIM1_IT));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the Interrupt sources */
    TIM1->IER |= (uint8_t)TIM1_IT;
  }
  else
  {
    /* Disable the Interrupt sources */
    TIM1->IER &= (uint8_t)(~(uint8_t)TIM1_IT);
  }
}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
