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
void UART1_DeInit(void)
{
  /* Clear the Idle Line Detected bit in the status register by a read
  to the UART1_SR register followed by a Read to the UART1_DR register */
  (void)UART1->SR;
  (void)UART1->DR;

  UART1->BRR2 = UART1_BRR2_RESET_VALUE;  /* Set UART1_BRR2 to reset value 0x00 */
  UART1->BRR1 = UART1_BRR1_RESET_VALUE;  /* Set UART1_BRR1 to reset value 0x00 */

  UART1->CR1 = UART1_CR1_RESET_VALUE;  /* Set UART1_CR1 to reset value 0x00 */
  UART1->CR2 = UART1_CR2_RESET_VALUE;  /* Set UART1_CR2 to reset value 0x00 */
  UART1->CR3 = UART1_CR3_RESET_VALUE;  /* Set UART1_CR3 to reset value 0x00 */
  UART1->CR4 = UART1_CR4_RESET_VALUE;  /* Set UART1_CR4 to reset value 0x00 */
  UART1->CR5 = UART1_CR5_RESET_VALUE;  /* Set UART1_CR5 to reset value 0x00 */

  UART1->GTR = UART1_GTR_RESET_VALUE;
  UART1->PSCR = UART1_PSCR_RESET_VALUE;
}

/**
  * @brief  Enables or disables the UART’s Half Duplex communication.
  * @param  NewState new state of the UART Communication.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_HalfDuplexCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    UART1->CR5 |= UART1_CR5_HDSEL;  /**< UART1 Half Duplex Enable  */
  }
  else
  {
    UART1->CR5 &= (uint8_t)~UART1_CR5_HDSEL; /**< UART1 Half Duplex Disable */
  }
}

/**
  * @brief  Configures the UART’s IrDA interface.
  * @param  UART1_IrDAMode specifies the IrDA mode.
  *         This parameter can be any of the @ref UART1_IrDAMode_TypeDef values.
  * @retval None
  */
void UART1_IrDAConfig(UART1_IrDAMode_TypeDef UART1_IrDAMode)
{
  assert_param(IS_UART1_IRDAMODE_OK(UART1_IrDAMode));

  if (UART1_IrDAMode != UART1_IRDAMODE_NORMAL)
  {
    UART1->CR5 |= UART1_CR5_IRLP;
  }
  else
  {
    UART1->CR5 &= ((uint8_t)~UART1_CR5_IRLP);
  }
}

/**
  * @brief  Enables or disables the UART’s IrDA interface.
  * @param  NewState new state of the IrDA mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_IrDACmd(FunctionalState NewState)
{
  /* Check parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the IrDA mode by setting the IREN bit in the CR3 register */
    UART1->CR5 |= UART1_CR5_IREN;
  }
  else
  {
    /* Disable the IrDA mode by clearing the IREN bit in the CR3 register */
    UART1->CR5 &= ((uint8_t)~UART1_CR5_IREN);
  }
}

/**
  * @brief  Sets the UART1 LIN Break detection length.
  * @param  UART1_LINBreakDetectionLength specifies the LIN break detection length.
  *         This parameter can be any of the
  *         @ref UART1_LINBreakDetectionLength_TypeDef values.
  * @retval None
  */
void UART1_LINBreakDetectionConfig(UART1_LINBreakDetectionLength_TypeDef UART1_LINBreakDetectionLength)
{
  assert_param(IS_UART1_LINBREAKDETECTIONLENGTH_OK(UART1_LINBreakDetectionLength));

  if (UART1_LINBreakDetectionLength != UART1_LINBREAKDETECTIONLENGTH_10BITS)
  {
    UART1->CR4 |= UART1_CR4_LBDL;
  }
  else
  {
    UART1->CR4 &= ((uint8_t)~UART1_CR4_LBDL);
  }
}

/**
  * @brief  Enables or disables the UART1’s LIN mode.
  * @param  NewState is new state of the UART1 LIN mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_LINCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the LIN mode by setting the LINE bit in the CR2 register */
    UART1->CR3 |= UART1_CR3_LINEN;
  }
  else
  {
    /* Disable the LIN mode by clearing the LINE bit in the CR2 register */
    UART1->CR3 &= ((uint8_t)~UART1_CR3_LINEN);
  }
}

/**
  * @brief  Enables or disables the UART1 Smart Card mode.
  * @param  NewState: new state of the Smart Card mode.
  * This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_SmartCardCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the SC mode by setting the SCEN bit in the CR5 register */
    UART1->CR5 |= UART1_CR5_SCEN;
  }
  else
  {
    /* Disable the SC mode by clearing the SCEN bit in the CR5 register */
    UART1->CR5 &= ((uint8_t)(~UART1_CR5_SCEN));
  }
}

/**
  * @brief  Enables or disables NACK transmission.
  * @note   This function is valid only for UART1 because is related to SmartCard mode.
  * @param  NewState: new state of the Smart Card mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_SmartCardNACKCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the NACK transmission by setting the NACK bit in the CR5 register */
    UART1->CR5 |= UART1_CR5_NACK;
  }
  else
  {
    /* Disable the NACK transmission by clearing the NACK bit in the CR5 register */
    UART1->CR5 &= ((uint8_t)~(UART1_CR5_NACK));
  }
}

/**
  * @brief  Selects the UART1 WakeUp method.
  * @param  UART1_WakeUp: specifies the UART1 wakeup method.
  *         This parameter can be any of the @ref UART1_WakeUp_TypeDef values.
  * @retval None
  */
void UART1_WakeUpConfig(UART1_WakeUp_TypeDef UART1_WakeUp)
{
  assert_param(IS_UART1_WAKEUP_OK(UART1_WakeUp));

  UART1->CR1 &= ((uint8_t)~UART1_CR1_WAKE);
  UART1->CR1 |= (uint8_t)UART1_WakeUp;
}

/**
  * @brief  Determines if the UART1 is in mute mode or not.
  * @param  NewState: new state of the UART1 mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void UART1_ReceiverWakeUpCmd(FunctionalState NewState)
{
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the mute mode UART1 by setting the RWU bit in the CR2 register */
    UART1->CR2 |= UART1_CR2_RWU;
  }
  else
  {
    /* Disable the mute mode UART1 by clearing the RWU bit in the CR1 register */
    UART1->CR2 &= ((uint8_t)~UART1_CR2_RWU);
  }
}

/**
  * @brief  Returns the most recent received data by the UART1 peripheral.
  * @param  None
  * @retval The received data.
  */
uint16_t UART1_ReceiveData9(void)
{
  uint16_t temp = 0;

  temp = (uint16_t)(((uint16_t)( (uint16_t)UART1->CR1 & (uint16_t)UART1_CR1_R8)) << 1);
  return (uint16_t)( (((uint16_t) UART1->DR) | temp ) & ((uint16_t)0x01FF));
}

/**
  * @brief  Transmits 8 bit data through the UART1 peripheral.
  * @param  Data: The data to transmit.
  * @retval None
  */
void UART1_SendData8(uint8_t Data)
{
  /* Transmit Data */
  UART1->DR = Data;
}

/**
  * @brief  Transmits 9 bit data through the UART peripheral.
  * @param  Data : The data to transmit.
  *         This parameter should be lower than 0x1FF.
  * @retval None
  */
void UART1_SendData9(uint16_t Data)
{
  /**< Clear the transmit data bit 8 [8]  */
  UART1->CR1 &= ((uint8_t)~UART1_CR1_T8);
  /**< Write the transmit data bit [8]  */
  UART1->CR1 |= (uint8_t)(((uint8_t)(Data >> 2)) & UART1_CR1_T8);
  /**< Write the transmit data bit [0:7] */
  UART1->DR   = (uint8_t)(Data);
}

/**
  * @brief  Transmits break characters.
  * @param  None
  * @retval None
  */
void UART1_SendBreak(void)
{
  UART1->CR2 |= UART1_CR2_SBK;
}

/**
  * @brief  Sets the address of the UART1 node.
  * @param  UART1_Address: Indicates the address of the UART1 node.
  * @retval None
  */
void UART1_SetAddress(uint8_t UART1_Address)
{
  /*assert_param for UART1_Address*/
  assert_param(IS_UART1_ADDRESS_OK(UART1_Address));

  /* Clear the UART1 address */
  UART1->CR4 &= ((uint8_t)~UART1_CR4_ADD);
  /* Set the UART1 address node */
  UART1->CR4 |= UART1_Address;
}

/**
  * @brief  Sets the specified UART guard time.
  * @note   SmartCard Mode should be Enabled
  * @param  UART1_GuardTime: specifies the guard time.
  * @retval None
  */
void UART1_SetGuardTime(uint8_t UART1_GuardTime)
{
  /* Set the UART1 guard time */
  UART1->GTR = UART1_GuardTime;
}

/**
  * @brief  Sets the system clock prescaler.
  * @note   IrDA Low Power mode or smartcard mode should be enabled
  * @note   This function is related to SmartCard and IrDa mode.
  * @param  UART1_Prescaler: specifies the prescaler clock.
  *         This parameter can be one of the following values:
  *         @par IrDA Low Power Mode
  *         The clock source is divided by the value given in the register (8 bits)
  *         - 0000 0000 Reserved
  *         - 0000 0001 divides the clock source by 1
  *         - 0000 0010 divides the clock source by 2
  *         - ...
  *        @par Smart Card Mode
  *        The clock source is divided by the value given in the register
  *        (5 significant bits) multiplied by 2
  *         - 0 0000 Reserved
  *         - 0 0001 divides the clock source by 2
  *         - 0 0010 divides the clock source by 4
  *         - 0 0011 divides the clock source by 6
  *         - ...
  * @retval None
  */
void UART1_SetPrescaler(uint8_t UART1_Prescaler)
{
  /* Load the UART1 prescaler value*/
  UART1->PSCR = UART1_Prescaler;
}

/**
  * @brief  Checks whether the specified UART1 flag is set or not.
  * @param  UART1_FLAG specifies the flag to check.
  *         This parameter can be any of the @ref UART1_Flag_TypeDef enumeration.
  * @retval FlagStatus (SET or RESET)
  */
FlagStatus UART1_GetFlagStatus(UART1_Flag_TypeDef UART1_FLAG)
{
  FlagStatus status = RESET;

  /* Check parameters */
  assert_param(IS_UART1_FLAG_OK(UART1_FLAG));


  /* Check the status of the specified UART1 flag*/
  if (UART1_FLAG == UART1_FLAG_LBDF)
  {
    if ((UART1->CR4 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
    {
      /* UART1_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART1_FLAG is reset*/
      status = RESET;
    }
  }
  else if (UART1_FLAG == UART1_FLAG_SBK)
  {
    if ((UART1->CR2 & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
    {
      /* UART1_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART1_FLAG is reset*/
      status = RESET;
    }
  }
  else
  {
    if ((UART1->SR & (uint8_t)UART1_FLAG) != (uint8_t)0x00)
    {
      /* UART1_FLAG is set*/
      status = SET;
    }
    else
    {
      /* UART1_FLAG is reset*/
      status = RESET;
    }
  }
  /* Return the UART1_FLAG status*/
  return status;
}

/**
  * @brief  Clears the UART1 flags.
  * @param  UART1_FLAG specifies the flag to clear
  *         This parameter can be any combination of the following values:
  *         - UART1_FLAG_LBDF: LIN Break detection flag.
  *         - UART1_FLAG_RXNE: Receive data register not empty flag.
  * @note
  *         - PE (Parity error), FE (Framing error), NE (Noise error),
  *         OR (OverRun error) and IDLE (Idle line detected) flags are
  *         cleared by software sequence: a read operation to UART1_SR register
  *         (UART1_GetFlagStatus())followed by a read operation to UART1_DR
  *         register(UART1_ReceiveData8() or UART1_ReceiveData9()).
  *
  *         - RXNE flag can be also cleared by a read to the UART1_DR register
  *         (UART1_ReceiveData8()or UART1_ReceiveData9()).
  *
  *         - TC flag can be also cleared by software sequence: a read operation
  *         to UART1_SR register (UART1_GetFlagStatus()) followed by a write
  *         operation to UART1_DR register (UART1_SendData8() or UART1_SendData9()).
  *
  *         - TXE flag is cleared only by a write to the UART1_DR register
  *         (UART1_SendData8() or UART1_SendData9()).
  *
  *         - SBK flag is cleared during the stop bit of break.
  * @retval None
  */
void UART1_ClearFlag(UART1_Flag_TypeDef UART1_FLAG)
{
  assert_param(IS_UART1_CLEAR_FLAG_OK(UART1_FLAG));

  /* Clear the Receive Register Not Empty flag */
  if (UART1_FLAG == UART1_FLAG_RXNE)
  {
    UART1->SR = (uint8_t)~(UART1_SR_RXNE);
  }
  /* Clear the LIN Break Detection flag */
  else
  {
    UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
  }
}

/**
  * @brief  Checks whether the specified UART1 interrupt has occurred or not.
  * @param  UART1_IT: Specifies the UART1 interrupt pending bit to check.
  *         This parameter can be one of the following values:
  *         - UART1_IT_LBDF:  LIN Break detection interrupt
  *         - UART1_IT_TXE:  Transmit Data Register empty interrupt
  *         - UART1_IT_TC:   Transmission complete interrupt
  *         - UART1_IT_RXNE: Receive Data register not empty interrupt
  *         - UART1_IT_IDLE: Idle line detection interrupt
  *         - UART1_IT_OR:  OverRun Error interrupt
  *         - UART1_IT_PE:   Parity Error interrupt
  * @retval The new state of UART1_IT (SET or RESET).
  */
ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT)
{
  ITStatus pendingbitstatus = RESET;
  uint8_t itpos = 0;
  uint8_t itmask1 = 0;
  uint8_t itmask2 = 0;
  uint8_t enablestatus = 0;

  /* Check parameters */
  assert_param(IS_UART1_GET_IT_OK(UART1_IT));

  /* Get the UART1 IT index */
  itpos = (uint8_t)((uint8_t)1 << (uint8_t)((uint8_t)UART1_IT & (uint8_t)0x0F));
  /* Get the UART1 IT index */
  itmask1 = (uint8_t)((uint8_t)UART1_IT >> (uint8_t)4);
  /* Set the IT mask*/
  itmask2 = (uint8_t)((uint8_t)1 << itmask1);


  /* Check the status of the specified UART1 pending bit*/
  if (UART1_IT == UART1_IT_PE)
  {
    /* Get the UART1_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART1->CR1 & itmask2);
    /* Check the status of the specified UART1 interrupt*/

    if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }

  else if (UART1_IT == UART1_IT_LBDF)
  {
    /* Get the UART1_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART1->CR4 & itmask2);
    /* Check the status of the specified UART1 interrupt*/
    if (((UART1->CR4 & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }
  else
  {
    /* Get the UART1_IT enable bit status*/
    enablestatus = (uint8_t)((uint8_t)UART1->CR2 & itmask2);
    /* Check the status of the specified UART1 interrupt*/
    if (((UART1->SR & itpos) != (uint8_t)0x00) && enablestatus)
    {
      /* Interrupt occurred*/
      pendingbitstatus = SET;
    }
    else
    {
      /* Interrupt not occurred*/
      pendingbitstatus = RESET;
    }
  }

  /* Return the UART1_IT status*/
  return  pendingbitstatus;
}

/**
  * @brief  Clears the UART1 pending flags.
  * @param  UART1_IT specifies the pending bit to clear
  *         This parameter can be one of the following values:
  *         - UART1_IT_LBDF:  LIN Break detection interrupt
  *         - UART1_IT_RXNE: Receive Data register not empty interrupt.
  * @note
  *         - PE (Parity error), FE (Framing error), NE (Noise error),
  *           OR (OverRun error) and IDLE (Idle line detected) pending bits are
  *           cleared by software sequence: a read operation to UART1_SR register
  *           (UART1_GetITStatus()) followed by a read operation to UART1_DR register
  *           (UART1_ReceiveData8() or UART1_ReceiveData9()).
  *
  *         - RXNE pending bit can be also cleared by a read to the UART1_DR register
  *           (UART1_ReceiveData8() or UART1_ReceiveData9()).
  *
  *         - TC (Transmit complete) pending bit can be cleared by software
  *           sequence: a read operation to UART1_SR register (UART1_GetITStatus())
  *           followed by a write operation to UART1_DR register (UART1_SendData8()
  *           or UART1_SendData9()).
  *
  *         - TXE pending bit is cleared only by a write to the UART1_DR register
  *           (UART1_SendData8() or UART1_SendData9()).
  * @retval None
  */
void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT)
{
  assert_param(IS_UART1_CLEAR_IT_OK(UART1_IT));

  /* Clear the Receive Register Not Empty pending bit */
  if (UART1_IT == UART1_IT_RXNE)
  {
    UART1->SR = (uint8_t)~(UART1_SR_RXNE);
  }
  /* Clear the LIN Break Detection pending bit */
  else
  {
    UART1->CR4 &= (uint8_t)~(UART1_CR4_LBDF);
  }
}

/**
  * @}
  */

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
