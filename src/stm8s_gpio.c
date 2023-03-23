/**
  ******************************************************************************
  * @file    stm8s_gpio.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the GPIO peripheral.
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
#include "stm8s_gpio.h"

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

/**
  * @addtogroup GPIO_Public_Functions
  * @{
  */

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx: Select the GPIO peripheral number (x = A to I).
  * @retval None
  */
void GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
  GPIOx->ODR = GPIO_ODR_RESET_VALUE; /* Reset Output Data Register */
  GPIOx->DDR = GPIO_DDR_RESET_VALUE; /* Reset Data Direction Register */
  GPIOx->CR1 = GPIO_CR1_RESET_VALUE; /* Reset Control Register 1 */
  GPIOx->CR2 = GPIO_CR2_RESET_VALUE; /* Reset Control Register 2 */
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @note   The port must be configured in output mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_PortVal : Specifies the value to be written to the port output
  *         data register.
  * @retval None
  */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint8_t PortVal)
{
  GPIOx->ODR = PortVal;
}

/**
  * @brief  Writes reverse level to the specified GPIO pins.
  * @note   The port must be configured in output mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  PortPins : Specifies the pins to be reversed to the port output.
  *         data register.
  * @retval None
  */
void GPIO_WriteReverse(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef PortPins)
{
  GPIOx->ODR ^= (uint8_t)PortPins;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @note   The port must be configured in input mode.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @retval GPIO output data port value.
  */
uint8_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
  return ((uint8_t)GPIOx->ODR);
}

/**
  * @brief  Reads the specified GPIO input data pin.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number.
  * @retval BitStatus : GPIO input pin status.
  */
BitStatus GPIO_ReadInputPin(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  return ((BitStatus)(GPIOx->IDR & (uint8_t)GPIO_Pin));
}

/**
  * @brief  Configures the external pull-up on GPIOx pins.
  * @param  GPIOx : Select the GPIO peripheral number (x = A to I).
  * @param  GPIO_Pin : Specifies the pin number
  * @param  NewState : The new state of the pull up pin.
  * @retval None
  */
void GPIO_ExternalPullUpConfig(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_GPIO_PIN_OK(GPIO_Pin));
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE) /* External Pull-Up Set*/
  {
    GPIOx->CR1 |= (uint8_t)GPIO_Pin;
  } else /* External Pull-Up Reset*/
  {
    GPIOx->CR1 &= (uint8_t)(~(GPIO_Pin));
  }
}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
