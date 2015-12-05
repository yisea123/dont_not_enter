/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : UART5_DBG.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : Serial_LDD
**     Version     : Component 01.166, Driver 01.10, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-11-11, 14:04, # CodeGen: 106
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
** @file UART5_DBG.c
** @version 01.10
** @date 2013-11-11, 14:04, # CodeGen: 106
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

/* MODULE UART5_DBG. */
/*lint -save  -e926 -e927 -e928 -e929 -e572 Disable MISRA rule (11.4,12.8) checking. */

/* {Default RTOS Adapter} No RTOS includes */
#include "UART5_DBG.h"
#include "Events.h"
#include "UART_PDD.h"

/*! The mask of available events used to enable/disable events during runtime. */
#define AVAILABLE_EVENTS_MASK (LDD_SERIAL_ON_BLOCK_RECEIVED | LDD_SERIAL_ON_BLOCK_SENT | LDD_SERIAL_ON_TXCOMPLETE)

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static UART5_DBG_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static UART5_DBG_TDeviceDataPtr INT_UART5_RX_TX__DEFAULT_RTOS_ISRPARAM;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static UART5_DBG_TDeviceDataPtr INT_UART5_ERR__DEFAULT_RTOS_ISRPARAM;

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
LDD_TDeviceData* UART5_DBG_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  UART5_DBG_TDeviceDataPtr DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;

  /* Clear the receive counters and pointer */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Clear the counter of received characters */
  DeviceDataPrv->InpDataNumReq = 0x00U; /* Clear the counter of characters to receive by ReceiveBlock() */
  DeviceDataPrv->InpDataPtr = NULL;    /* Clear the buffer pointer for received characters */
  /* Clear the transmit counters and pointer */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters */
  DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
  DeviceDataPrv->OutDataPtr = NULL;    /* Clear the buffer pointer for data to be transmitted */
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Allocate interrupt vectors */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_UART5_RX_TX__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_UART5_ERR__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC1: UART5=1 */
  SIM_SCGC1 |= SIM_SCGC1_UART5_MASK;                                   
  /* PORTD_PCR8: ISF=0,MUX=3 */
  PORTD_PCR8 = (uint32_t)((PORTD_PCR8 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x04)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x03)
               ));                                  
  /* PORTD_PCR9: ISF=0,MUX=3 */
  PORTD_PCR9 = (uint32_t)((PORTD_PCR9 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x04)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x03)
               ));                                  
  /* PORTD_PCR11: ISF=0,MUX=3 */
  PORTD_PCR11 = (uint32_t)((PORTD_PCR11 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));                                  
  /* PORTD_PCR10: ISF=0,MUX=3 */
  PORTD_PCR10 = (uint32_t)((PORTD_PCR10 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK |
                 PORT_PCR_MUX(0x04)
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x03)
                ));                                  
  /* NVICIP55: PRI55=0x80 */
  NVICIP55 = NVIC_IP_PRI55(0x80);                                   
  /* NVICISER1: SETENA|=0x00800000 */
  NVICISER1 |= NVIC_ISER_SETENA(0x00800000);                                   
  /* NVICIP56: PRI56=0x80 */
  NVICIP56 = NVIC_IP_PRI56(0x80);                                   
  /* NVICISER1: SETENA|=0x01000000 */
  NVICISER1 |= NVIC_ISER_SETENA(0x01000000);                                   
  UART_PDD_EnableTransmitter(UART5_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART5_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  DeviceDataPrv->SerFlag = 0x00U;      /* Reset flags */
  DeviceDataPrv->EnUser = TRUE;        /* Enable device */
  /* UART5_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART5_C1 = 0x00U;                    /*  Set the C1 register */
  /* UART5_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART5_C3 = 0x00U;                    /*  Set the C3 register */
  /* UART5_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART5_S2 = 0x00U;                    /*  Set the S2 register */
  /* UART5_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=1,TXRTSPOL=0,TXRTSE=0,TXCTSE=1 */
  UART5_MODEM = (UART_MODEM_RXRTSE_MASK | UART_MODEM_TXCTSE_MASK); /*  Set the MODEM register */
  UART_PDD_SetBaudRateFineAdjust(UART5_BASE_PTR, 1u); /* Set baud rate fine adjust */
  UART_PDD_SetBaudRate(UART5_BASE_PTR, 13U); /* Set the baud rate register. */
  UART_PDD_EnableFifo(UART5_BASE_PTR, (UART_PDD_TX_FIFO_ENABLE | UART_PDD_RX_FIFO_ENABLE)); /* Enable RX and TX FIFO */
  UART_PDD_FlushFifo(UART5_BASE_PTR, (UART_PDD_TX_FIFO_FLUSH | UART_PDD_RX_FIFO_FLUSH)); /* Flush RX and TX FIFO */
  UART_PDD_EnableTransmitter(UART5_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
  UART_PDD_EnableReceiver(UART5_BASE_PTR, PDD_ENABLE); /* Enable receiver */
  UART_PDD_EnableInterrupt(UART5_BASE_PTR, ( UART_PDD_INTERRUPT_RECEIVER )); /* Enable interrupts */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_UART5_DBG_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

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
void UART5_DBG_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  (void)DeviceDataPrv;
  UART_PDD_DisableInterrupt(UART5_BASE_PTR, ( UART_PDD_INTERRUPT_TRANSMITTER_COMPLETE | UART_PDD_INTERRUPT_RECEIVER | UART_PDD_INTERRUPT_TRANSMITTER )); /* Disable interrupts */
  UART_PDD_EnableTransmitter(UART5_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
  UART_PDD_EnableReceiver(UART5_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* Disable clock gate */
  /* SIM_SCGC1: UART5=0 */
  SIM_SCGC1 &= (uint32_t)~(uint32_t)(SIM_SCGC1_UART5_MASK);                                   
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

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
LDD_TError UART5_DBG_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnUser) {        /* Is the device disabled by user? */
    DeviceDataPrv->EnUser = TRUE;      /* If yes then set the flag "device enabled" */
    UART_PDD_EnableFifo(UART5_BASE_PTR, (UART_PDD_TX_FIFO_ENABLE | UART_PDD_RX_FIFO_ENABLE)); /* Enable RX and TX FIFO */
    UART_PDD_FlushFifo(UART5_BASE_PTR, (UART_PDD_TX_FIFO_FLUSH | UART_PDD_RX_FIFO_FLUSH)); /* Flush RX and TX FIFO */
    UART_PDD_EnableTransmitter(UART5_BASE_PTR, PDD_ENABLE); /* Enable transmitter */
    UART_PDD_EnableReceiver(UART5_BASE_PTR, PDD_ENABLE); /* Enable receiver */
    UART_PDD_EnableInterrupt(UART5_BASE_PTR, ( UART_PDD_INTERRUPT_RECEIVER )); /* Enable interrupts */
  }
  return ERR_OK;                       /* OK */
}

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
LDD_TError UART5_DBG_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  if (DeviceDataPrv->EnUser) {         /* Is the device enabled by user? */
    DeviceDataPrv->EnUser = FALSE;     /* If yes then set the flag "device disabled" */
    UART_PDD_DisableInterrupt(UART5_BASE_PTR, ( UART_PDD_INTERRUPT_TRANSMITTER_COMPLETE | UART_PDD_INTERRUPT_RECEIVER | UART_PDD_INTERRUPT_TRANSMITTER )); /* Disable interrupts */
    UART_PDD_EnableTransmitter(UART5_BASE_PTR, PDD_DISABLE); /* Disable transmitter. */
    UART_PDD_EnableReceiver(UART5_BASE_PTR, PDD_DISABLE); /* Disable receiver. */
  }
  return ERR_OK;                       /* OK */
}

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
LDD_TError UART5_DBG_ReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnUser) {        /* Is the device disabled by user? */
    return ERR_DISABLED;               /* If yes then error */
  }
  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the previous receive operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->InpDataPtr = BufferPtr; /* Store a pointer to the input data. */
  DeviceDataPrv->InpDataNumReq = Size; /* Store a number of characters to be received. */
  DeviceDataPrv->InpRecvDataNum = 0x00U; /* Set number of received characters to zero. */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

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
LDD_TError UART5_DBG_SendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, uint16_t Size)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  if (!DeviceDataPrv->EnUser) {        /* Is the device disabled by user? */
    return ERR_DISABLED;               /* If yes then error */
  }
  if (Size == 0U) {                    /* Is the parameter Size within an expected range? */
    return ERR_PARAM_SIZE;             /* If no then error */
  }
  if (DeviceDataPrv->OutDataNumReq != 0x00U) { /* Is the previous transmit operation pending? */
    return ERR_BUSY;                   /* If yes then error */
  }
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  DeviceDataPrv->OutDataPtr = BufferPtr; /* Set a pointer to the output data. */
  DeviceDataPrv->OutDataNumReq = Size; /* Set the counter of characters to be sent. */
  DeviceDataPrv->OutSentDataNum = 0x00U; /* Clear the counter of sent characters. */
  DeviceDataPrv->SerFlag |= ENABLED_TX_INT; /* Set the flag ENABLED_TX_INT */
  DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)TX_COMPLETED); /* Clear the TX_COMPLETED flag */
  UART_PDD_EnableInterrupt(UART5_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER); /* Enable TX interrupt */
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

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
uint16_t UART5_DBG_GetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->InpRecvDataNum); /* Return the number of received characters. */
}

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
uint16_t UART5_DBG_GetSentDataNum(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  return (DeviceDataPrv->OutSentDataNum); /* Return the number of sent characters. */
}

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
bool UART5_DBG_GetTxCompleteStatus(LDD_TDeviceData *DeviceDataPtr)
{
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = (UART5_DBG_TDeviceDataPtr)DeviceDataPtr;

  if ((DeviceDataPrv->SerFlag & TX_COMPLETED) != 0U) { /* Is a transmission completed? */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)TX_COMPLETED); /* If yes then clear the flag and return the result */
    return TRUE;
  }
  return FALSE;
}

/*
** ===================================================================
**     Method      :  InterruptRx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptRx(UART5_DBG_TDeviceDataPtr DeviceDataPrv)
{
  register uint16_t Data;              /* Temporary variable for data */

  Data = (uint16_t)UART_PDD_GetChar8(UART5_BASE_PTR); /* Read an 8-bit character from the receiver */
  if (DeviceDataPrv->InpDataNumReq != 0x00U) { /* Is the receive block operation pending? */
    *(DeviceDataPrv->InpDataPtr++) = (uint8_t)Data; /* Put an 8-bit character to the receive buffer */
    DeviceDataPrv->InpRecvDataNum++;   /* Increment received char. counter */
    if (DeviceDataPrv->InpRecvDataNum == DeviceDataPrv->InpDataNumReq) { /* Is the requested number of characters received? */
      DeviceDataPrv->InpDataNumReq = 0x00U; /* If yes then clear number of requested characters to be received. */
      UART5_DBG_OnBlockReceived(DeviceDataPrv->UserDataPtr);
    }
  }
}

/*
** ===================================================================
**     Method      :  InterruptTx (component Serial_LDD)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void InterruptTx(UART5_DBG_TDeviceDataPtr DeviceDataPrv)
{

  if (DeviceDataPrv->OutSentDataNum < DeviceDataPrv->OutDataNumReq) { /* Is number of sent characters less than the number of requested incoming characters? */
    UART_PDD_PutChar8(UART5_BASE_PTR, *(DeviceDataPrv->OutDataPtr++)); /* Put a 8-bit character to the transmit register */
    DeviceDataPrv->OutSentDataNum++;   /* Increment the counter of sent characters. */
    if (DeviceDataPrv->OutSentDataNum == DeviceDataPrv->OutDataNumReq) {
      DeviceDataPrv->OutDataNumReq = 0x00U; /* Clear the counter of characters to be send by SendBlock() */
      UART5_DBG_OnBlockSent(DeviceDataPrv->UserDataPtr);
    }
  } else {
    UART_PDD_DisableInterrupt(UART5_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER); /* Disable TX interrupt */
    UART_PDD_EnableInterrupt(UART5_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER_COMPLETE); /* Enable TX complete interrupt */
    DeviceDataPrv->SerFlag &= (uint16_t)(~(uint16_t)ENABLED_TX_INT); /* Clear the flag ENABLED_TX_INT */
  }
}

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
PE_ISR(UART5_DBG_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  UART5_DBG_TDeviceDataPtr DeviceDataPrv = INT_UART5_RX_TX__DEFAULT_RTOS_ISRPARAM;
  register uint16_t StatReg = UART_PDD_ReadInterruptStatusReg(UART5_BASE_PTR); /* Read status register */

  if (StatReg & (UART_S1_NF_MASK | UART_S1_OR_MASK | UART_S1_FE_MASK | UART_S1_PF_MASK)) { /* Is any error flag set? */
    (void)UART_PDD_GetChar8(UART5_BASE_PTR); /* Dummy read 8-bit character from receiver */
    StatReg &= (uint16_t)(~(uint16_t)UART_S1_RDRF_MASK); /* Clear the receive data flag to discard the errorneous data */
  }
  if (StatReg & UART_S1_RDRF_MASK) {   /* Is the receiver's interrupt flag set? */
    InterruptRx(DeviceDataPrv);        /* If yes, then invoke the internal service routine. This routine is inlined. */
  }
  if (DeviceDataPrv->SerFlag & ENABLED_TX_INT) { /* Is the transmitter interrupt enabled? */
    if (StatReg & UART_S1_TDRE_MASK) { /* Is the transmitter empty? */
      InterruptTx(DeviceDataPrv);      /* If yes, then invoke the internal service routine. This routine is inlined. */
    }
  }
  if ((UART_PDD_GetTxCompleteInterruptMask(UART5_BASE_PTR) != 0U)  && (StatReg & UART_S1_TC_MASK)) { /* Is a transmission completed? */
    UART_PDD_DisableInterrupt(UART5_BASE_PTR, UART_PDD_INTERRUPT_TRANSMITTER_COMPLETE); /* If yes then disable TX complete interrupt */
    DeviceDataPrv->SerFlag |= TX_COMPLETED; /* Set the flag */
    UART5_DBG_OnTxComplete(DeviceDataPrv->UserDataPtr); /* If yes then invoke user event */
  }
}

/*lint -restore Enable MISRA rule (11.4,12.8) checking. */
/* END UART5_DBG. */

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
