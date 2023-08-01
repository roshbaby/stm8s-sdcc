/**
  ******************************************************************************
  * @file    stm8s_tim4_Cmd.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains Cmd function for the TIM4 peripheral.
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
#include "stm8s_tim4.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/**
  * @addtogroup TIM4_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the TIM4 peripheral.
  * @param   NewState new state of the TIM4 peripheral. This parameter can
  * be ENABLE or DISABLE.
  * @retval None
  */
void TIM4_Cmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  /* set or Reset the CEN Bit */
  if (NewState != DISABLE)
  {
    TIM4->CR1 |= TIM4_CR1_CEN;
  }
  else
  {
    TIM4->CR1 &= (uint8_t)(~TIM4_CR1_CEN);
  }
}

/**
  * @}
  */

  /**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
