/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : UART5_DBG.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : Serial_LDD
**     Version     : Component 01.166, Driver 01.10, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-04-19, 18:31, # CodeGen: 94
**     Abstract    :
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
**     Settings    :
**          Component name                                 : UART5_DBG
**          Device                                         : UART5
**          Interrupt service/event                        : Enabled
**            Interrupt RxD                                : INT_UART5_RX_TX
**            Interrupt RxD priority                       : medium priority
**            Interrupt TxD                                : INT_UART5_RX_TX
**            Interrupt TxD priority                       : medium priority
**            Interrupt Error                              : INT_UART5_ERR
**            Interrupt Error priority                     : medium priority
**          Settings                                       : 
**            Data width                                   : 8 bits
**            Parity                                       : None
**            Stop bits                                    : 1
**            Loop mode                                    : Normal
**            Baud rate                                    : 115200 baud
**            Wakeup condition                             : Idle line wakeup
**            Stop in wait mode                            : no
**            Idle line mode                               : Starts after start bit
**            Transmitter output                           : Not inverted
**            Receiver input                               : Not inverted
**            Break generation length                      : 10/11 bits
**            Receiver                                     : Enabled
**              RxD                                        : PTD8/I2C0_SCL/UART5_RX/FB_A16
**              RxD pin signal                             : MCU_DBG_RXD
**            Transmitter                                  : Enabled
**              TxD                                        : PTD9/I2C0_SDA/UART5_TX/FB_A17
**              TxD pin signal                             : MCU_DBG_TXD
**            Flow control                                 : Hardware (RTS/CTS)
**              CTS                                        : Enabled
**                CTS Pin                                  : PTD11/SPI2_PCS0/UART5_CTS_b/SDHC0_CLKIN/FB_AD8/FB_A19
**                CTS pin signal                           : MCU_DBG_CTS
**                Interrupt CTS                            : INT_PORTD
**                Interrupt CTS priority                   : medium priority
**              RTS                                        : Enabled
**                RTS Pin                                  : PTD10/UART5_RTS_b/FB_AD9/FB_A18
**                RTS pin signal                           : MCU_DBG_RTS
**                RTS enabled                              : 1
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnTxComplete                               : Enabled
**              OnError                                    : Disabled
**              OnBreak                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                - LDD_TDeviceData* UART5_DBG_Init(LDD_TUserData *UserDataPtr);
**         Deinit              - void UART5_DBG_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable              - LDD_TError UART5_DBG_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable             - LDD_TError UART5_DBG_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock           - LDD_TError UART5_DBG_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock        - LDD_TError UART5_DBG_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum      - uint16_t UART5_DBG_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum  - uint16_t UART5_DBG_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetTxCompleteStatus - bool UART5_DBG_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file UART5_DBG.h
** @version 01.10
** @date 2013-04-19, 18:31, # CodeGen: 94
** @brief
**         This component "Serial_LDD" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial communication channel.
*/         
/*!
**  @addtogroup UART5_DBG_module UART5_DBG module documentation
**  @{
*/         

#ifndef __UART5_DBG_H
#define __UART5_DBG_H

/* MODULE UART5_DBG. */


#include "Cpu.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define UART5_DBG_PRPH_BASE_ADDRESS  0x400EB000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define UART5_DBG_Init_METHOD_ENABLED  /*!< Init method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_Deinit_METHOD_ENABLED /*!< Deinit method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_Enable_METHOD_ENABLED /*!< Enable method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_Disable_METHOD_ENABLED /*!< Disable method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_SendBlock_METHOD_ENABLED /*!< SendBlock method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_GetSentDataNum_METHOD_ENABLED /*!< GetSentDataNum method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_GetReceivedDataNum_METHOD_ENABLED /*!< GetReceivedDataNum method of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_GetTxCompleteStatus_METHOD_ENABLED /*!< GetTxCompleteStatus method of the component UART5_DBG is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define UART5_DBG_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_OnBlockSent_EVENT_ENABLED /*!< OnBlockSent event of the component UART5_DBG is enabled (generated) */
#define UART5_DBG_OnTxComplete_EVENT_ENABLED /*!< OnTxComplete event of the component UART5_DBG is enabled (generated) */

#define ENABLED_TX_INT        0x01U    /*!< TX interrupt enabled      */
#define BREAK_DETECTED        0x02U    /*!< Break detected            */
#define TX_COMPLETED          0x04U    /*!< Transmission completed    */
#define ENABLE_TX_COMPLETE    0x10U    /*!< Enable/Disable of TX complete detection. Used in the polling mode only */

/*! Device data structure type */
typedef struct {
  uint16_t SerFlag;                    /*!< Flags for serial communication */
  bool EnUser;                         /*!< Enable/Disable device */
  uint16_t InpRecvDataNum;             /*!< The counter of received characters */
  uint8_t *InpDataPtr;                 /*!< The buffer pointer for received characters */
  uint16_t InpDataNumReq;              /*!< The counter of characters to receive by ReceiveBlock() */
  uint16_t OutSentDataNum;             /*!< The counter of sent characters */
  uint8_t *OutDataPtr;                 /*!< The buffer pointer for data to be transmitted */
  uint16_t OutDataNumReq;              /*!< The counter of characters to be send by SendBlock() */
  LDD_TUserData *UserDataPtr;          /*!< Pointer to user data */
} UART5_DBG_TDeviceData;

typedef UART5_DBG_TDeviceData *UART5_DBG_TDeviceDataPtr ; /*!< Pointer to the device data structure. */

/*
** ===================================================================
**     Method      :  UART5_DBG_Init (component Serial_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/
LDD_TDeviceData* UART5_DBG_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_Deinit (component Serial_LDD)
*/
/*!
**     @brief
**          Deinitializes the device. Switches off the device, frees
**         the device data structure memory, interrupts vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/
void UART5_DBG_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_Enable (component Serial_LDD)
*/
/*!
**     @brief
**         Enables the device, starts the transmitting and receiving.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
*/
/* ===================================================================*/
LDD_TError UART5_DBG_Enable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_Disable (component Serial_LDD)
*/
/*!
**     @brief
**         Disables the device, stops the transmitting and receiving.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
*/
/* ===================================================================*/
LDD_TError UART5_DBG_Disable(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_ReceiveBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Specifies the number of data to receive. The method returns
**         ERR_BUSY until the specified number of characters is
**         received. Method <CancelBlockReception> can be used to
**         cancel a running receive operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**     @param
**         Size            - Number of characters to receive
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous receive request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError UART5_DBG_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  UART5_DBG_SendBlock (component Serial_LDD)
*/
/*!
**     @brief
**         Sends a block of characters. The method returns ERR_BUSY
**         when the previous block transmission is not completed.
**         Method <CancelBlockTransmission> can be used to cancel a
**         transmit operation. This method is available only if the
**         transmitter property is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer from where
**                           data will be sent.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - The component or device is
**                           disabled.
**                           ERR_BUSY - The previous transmit request is
**                           pending.
*/
/* ===================================================================*/
LDD_TError UART5_DBG_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);

/*
** ===================================================================
**     Method      :  UART5_DBG_GetReceivedDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Number of received characters in the receive
**                           buffer.
*/
/* ===================================================================*/
uint16_t UART5_DBG_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_GetSentDataNum (component Serial_LDD)
*/
/*!
**     @brief
**         Returns the number of sent characters.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of sent characters.
*/
/* ===================================================================*/
uint16_t UART5_DBG_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  UART5_DBG_GetTxCompleteStatus (component Serial_LDD)
*/
/*!
**     @brief
**         Returns whether the transmitter has transmitted all
**         characters and there are no other characters in the
**         transmitter's HW FIFO or the shift register. This method is
**         available only if a peripheral supports this feature.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Possible values:
**                           <true> - Data block is completely
**                           transmitted.
**                           <false> - Data block isn't completely
**                           transmitted.
*/
/* ===================================================================*/
bool UART5_DBG_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(UART5_DBG_Interrupt);
/*
** ===================================================================
**     Method      :  UART5_DBG_Interrupt (component Serial_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt. Calls InterruptTX/InterruptRX methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END UART5_DBG. */

#endif
/* ifndef __UART5_DBG_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0.12 [05.05]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
