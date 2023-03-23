/**
  ******************************************************************************
  * @file    stm8s_spi.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the SPI peripheral.
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
#include "stm8s_spi.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @addtogroup SPI_Public_Functions
  * @{
  */

/**
  * @brief  Initializes the SPI according to the specified parameters.
  * @param  FirstBit : This parameter can be any of the
  *         @ref SPI_FirstBit_TypeDef enumeration.
  * @param  BaudRatePrescaler : This parameter can be any of the
  *         @ref SPI_BaudRatePrescaler_TypeDef enumeration.
  * @param  Mode : This parameter can be any of the
  *         @ref SPI_Mode_TypeDef enumeration.
  * @param  ClockPolarity : This parameter can be any of the
  *         @ref SPI_ClockPolarity_TypeDef enumeration.
  * @param  ClockPhase : This parameter can be any of the
  *         @ref SPI_ClockPhase_TypeDef enumeration.
  * @param  Data_Direction : This parameter can be any of the
  *         @ref SPI_DataDirection_TypeDef enumeration.
  * @param  Slave_Management : This parameter can be any of the
  *         @ref SPI_NSS_TypeDef enumeration.
  * @param  CRCPolynomial : Configures the CRC polynomial.
  * @retval None
  */
void SPI_Init(SPI_FirstBit_TypeDef FirstBit, SPI_BaudRatePrescaler_TypeDef BaudRatePrescaler, SPI_Mode_TypeDef Mode, SPI_ClockPolarity_TypeDef ClockPolarity, SPI_ClockPhase_TypeDef ClockPhase, SPI_DataDirection_TypeDef Data_Direction, SPI_NSS_TypeDef Slave_Management, uint8_t CRCPolynomial)
{
  /* Check structure elements */
  assert_param(IS_SPI_FIRSTBIT_OK(FirstBit));
  assert_param(IS_SPI_BAUDRATE_PRESCALER_OK(BaudRatePrescaler));
  assert_param(IS_SPI_MODE_OK(Mode));
  assert_param(IS_SPI_POLARITY_OK(ClockPolarity));
  assert_param(IS_SPI_PHASE_OK(ClockPhase));
  assert_param(IS_SPI_DATA_DIRECTION_OK(Data_Direction));
  assert_param(IS_SPI_SLAVEMANAGEMENT_OK(Slave_Management));
  assert_param(IS_SPI_CRC_POLYNOMIAL_OK(CRCPolynomial));

  /* Frame Format, BaudRate, Clock Polarity and Phase configuration */
  SPI->CR1 = (uint8_t)((uint8_t)((uint8_t)FirstBit | BaudRatePrescaler) |
                       (uint8_t)((uint8_t)ClockPolarity | ClockPhase));

  /* Data direction configuration: BDM, BDOE and RXONLY bits */
  SPI->CR2 = (uint8_t)((uint8_t)(Data_Direction) | (uint8_t)(Slave_Management));

  if (Mode == SPI_MODE_MASTER)
  {
    SPI->CR2 |= (uint8_t)SPI_CR2_SSI;
  }
  else
  {
    SPI->CR2 &= (uint8_t)~(SPI_CR2_SSI);
  }

  /* Master/Slave mode configuration */
  SPI->CR1 |= (uint8_t)(Mode);

  /* CRC configuration */
  SPI->CRCPR = (uint8_t)CRCPolynomial;
}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
