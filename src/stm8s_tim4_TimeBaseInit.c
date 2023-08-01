/**
  ******************************************************************************
  * @file    stm8s_tim4_TimeBaseInit.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains TimeBaseInit function for the TIM4 peripheral.
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
  * @brief  Initializes the TIM4 Time Base Unit according to the specified parameters.
  * @param    TIM4_Prescaler specifies the Prescaler from TIM4_Prescaler_TypeDef.
  * @param    TIM4_Period specifies the Period value.
  * @retval None
  */
void TIM4_TimeBaseInit(TIM4_Prescaler_TypeDef TIM4_Prescaler, uint8_t TIM4_Period)
{
  /* Check TIM4 prescaler value */
  assert_param(IS_TIM4_PRESCALER_OK(TIM4_Prescaler));
  /* Set the Prescaler value */
  TIM4->PSCR = (uint8_t)(TIM4_Prescaler);
  /* Set the Autoreload value */
  TIM4->ARR = (uint8_t)(TIM4_Period);
}

/**
  * @}
  */

  /**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
