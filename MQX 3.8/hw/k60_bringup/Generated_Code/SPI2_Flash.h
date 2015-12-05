/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SPI2_Flash.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : SPIMaster_LDD
**     Version     : Component 01.084, Driver 01.07, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-11-11, 14:04, # CodeGen: 106
**     Abstract    :
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
**     Settings    :
**          Component name                                 : SPI2_Flash
**          Device                                         : SPI2
**          Interrupt service/event                        : Enabled
**            Input interrupt                              : INT_SPI2
**            Input interrupt priority                     : medium priority
**            Output interrupt                             : INT_SPI2
**            Output interrupt priority                    : medium priority
**          Settings                                       : 
**            Input pin                                    : Enabled
**              Pin                                        : PTB23/SPI2_SIN/FB_AD28
**              Pin signal                                 : DATA_SPI_MISO
**            Output pin                                   : Enabled
**              Pin                                        : PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT
**              Pin signal                                 : DATA_SPI_MOSI
**            Clock pin                                    : 
**              Pin                                        : PTB21/SPI2_SCK/FB_AD30/CMP1_OUT
**              Pin signal                                 : DATA_SPI_CK
**            Chip select list                             : 1
**              Chip select 0                              : 
**                Pin                                      : PTB20/SPI2_PCS0/FB_AD31/CMP0_OUT
**                Pin signal                               : DATA_SPI_CS_B
**                Active level                             : Low
**            CS external demultiplexer                    : Disabled
**            Attribute set list                           : 1
**              Attribute set 0                            : 
**                Width                                    : 8 bits
**                MSB first                                : yes
**                Clock polarity                           : High
**                Clock phase                              : Change on leading edge
**                Parity                                   : None
**                Chip select toggling                     : no
**                Clock rate index                         : 0
**                Delay between chars index                : 0
**                CS to CLK delay index                    : 0
**                CLK to CS delay index                    : 0
**            Clock rate                                   : 1.001358 �s
**            Delay between chars                          : 0.25 �s
**            CS to CLK delay                              : 0.083381 �s
**            CLK to CS delay                              : 0.083381 �s
**            HW input buffer size                         : 1
**            HW input watermark                           : 1
**            HW output buffer size                        : 1
**            HW output watermark                          : 1
**          Initialization                                 : 
**            Initial chip select                          : 0
**            Initial attribute set                        : 0
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBlockSent                                : Enabled
**              OnBlockReceived                            : Enabled
**              OnError                                    : Enabled
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
**         Init                   - LDD_TDeviceData* SPI2_Flash_Init(LDD_TUserData *UserDataPtr);
**         Deinit                 - void SPI2_Flash_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SendBlock              - LDD_TError SPI2_Flash_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ReceiveBlock           - LDD_TError SPI2_Flash_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         GetSentDataNum         - uint16_t SPI2_Flash_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetReceivedDataNum     - uint16_t SPI2_Flash_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
**         GetBlockSentStatus     - bool SPI2_Flash_GetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
**         GetBlockReceivedStatus - bool SPI2_Flash_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
**         GetError               - LDD_TError SPI2_Flash_GetError(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SPI2_Flash.h
** @version 01.07
** @date 2013-11-11, 14:04, # CodeGen: 106
** @brief
**         This component "SPIMaster_LDD" implements MASTER part of synchronous
**         serial master-slave communication.
*/         
/*!
**  @addtogroup SPI2_Flash_module SPI2_Flash module documentation
**  @{
*/         

#ifndef __SPI2_Flash_H
#define __SPI2_Flash_H

/* MODULE SPI2_Flash. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"
#include "SPI_PDD.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SPI2_Flash_PRPH_BASE_ADDRESS  0x400AC000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define SPI2_Flash_Init_METHOD_ENABLED /*!< Init method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_Deinit_METHOD_ENABLED /*!< Deinit method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_SendBlock_METHOD_ENABLED /*!< SendBlock method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_ReceiveBlock_METHOD_ENABLED /*!< ReceiveBlock method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_GetSentDataNum_METHOD_ENABLED /*!< GetSentDataNum method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_GetReceivedDataNum_METHOD_ENABLED /*!< GetReceivedDataNum method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_GetBlockSentStatus_METHOD_ENABLED /*!< GetBlockSentStatus method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_GetBlockReceivedStatus_METHOD_ENABLED /*!< GetBlockReceivedStatus method of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_GetError_METHOD_ENABLED /*!< GetError method of the component SPI2_Flash is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define SPI2_Flash_OnBlockSent_EVENT_ENABLED /*!< OnBlockSent event of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_OnBlockReceived_EVENT_ENABLED /*!< OnBlockReceived event of the component SPI2_Flash is enabled (generated) */
#define SPI2_Flash_OnError_EVENT_ENABLED /*!< OnError event of the component SPI2_Flash is enabled (generated) */

#define SPI2_Flash_CHIP_SELECT_COUNT 1U /*!< Number of chip selects */
#define SPI2_Flash_CONFIGURATION_COUNT 1U /*!< Number of predefined configurations */

/* Communication error data type */


LDD_TDeviceData* SPI2_Flash_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_Init (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Device data structure pointer.
*/
/* ===================================================================*/

void SPI2_Flash_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_Deinit (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method deinitializes the device. It switches off the
**         device, frees the device data structure memory, interrupts
**         vectors, etc.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
*/
/* ===================================================================*/

LDD_TError SPI2_Flash_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);
/*
** ===================================================================
**     Method      :  SPI2_Flash_ReceiveBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method specifies the number of data to receive. The
**         method returns ERR_BUSY until the specified number of
**         characters is received. The method <CancelBlockReception>
**         can be used to cancel a running receive operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to A buffer where
**                           received characters will be stored.
**     @param
**         Size            - Size of the block
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous receive request is
**                           pending
*/
/* ===================================================================*/

LDD_TError SPI2_Flash_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size);
/*
** ===================================================================
**     Method      :  SPI2_Flash_SendBlock (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method sends a block of characters. The method returns
**         ERR_BUSY when the previous block transmission is not
**         completed. The method <CancelBlockTransmission> can be used
**         to cancel a transmit operation.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Number of characters in the buffer.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - The previous transmit request is
**                           pending
*/
/* ===================================================================*/

uint16_t SPI2_Flash_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_GetReceivedDataNum (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Returns the number of received characters in the receive
**         buffer. This method is available only if the ReceiveBlock
**         method is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the input
**                           buffer.
*/
/* ===================================================================*/

uint16_t SPI2_Flash_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_GetSentDataNum (component SPIMaster_LDD)
*/
/*!
**     @brief
**         Returns the number of sent characters. This method is
**         available only if method SendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the output
**                           buffer.
*/
/* ===================================================================*/

bool SPI2_Flash_GetBlockSentStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_GetBlockSentStatus (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method returns whether the transmitter is finished
**         transmitting all data block. This method is available only
**         if method SendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           true - Data block is completely transmitted
**                           false - Data block isn't completely
**                           transmitted.
*/
/* ===================================================================*/

bool SPI2_Flash_GetBlockReceivedStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_GetBlockReceivedStatus (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method returns whether the receiver is finished
**         reception of all data block. This method is available only
**         if method ReceiveBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Return value:
**                           true - Data block is completely received
**                           false - Data block isn't completely received
*/
/* ===================================================================*/

LDD_TError SPI2_Flash_GetError(LDD_TDeviceData *DeviceDataPtr, LDD_SPIMASTER_TError *ErrorPtr);
/*
** ===================================================================
**     Method      :  SPI2_Flash_GetError (component SPIMaster_LDD)
*/
/*!
**     @brief
**         This method returns a set of asserted flags. The flags are
**         accumulated in the set. After calling this method the set is
**         returned and cleared. This method is enabled when SPI device
**         support error detect.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ErrorPtr        - A pointer to the returned set of
**                           error flags:
**                           LDD_SPIMASTER_RX_OVERFLOW - Receiver
**                           overflow
**                           LDD_SPIMASTER_PARITY_ERROR - Parity error
**                           (only if HW supports parity feature)
**     @return
**                         - Error code (if GetError did not succeed),
**                           possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_DISABLED - Component is disabled
*/
/* ===================================================================*/

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(SPI2_Flash_Interrupt);
/*
** ===================================================================
**     Method      :  SPI2_Flash_Interrupt (component SPIMaster_LDD)
**
**     Description :
**         The ISR function handling the device receive/transmit 
**         interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END SPI2_Flash. */

#endif
/* ifndef __SPI2_Flash_H */
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
