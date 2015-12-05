/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CRC1.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : CRC_LDD
**     Version     : Component 01.012, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-04-06, 17:46, # CodeGen: 82
**     Abstract    :
**         This component implements the Cyclic Redundancy Check (CRC) code calculation.
**     Settings    :
**          Component name                                 : CRC1
**          Device                                         : CRC
**          Settings                                       : 
**            CRC standard                                 : CRC32
**          Initialization                                 : 
**            Auto initialization                          : no
**     Contents    :
**         Init         - LDD_TDeviceData* CRC1_Init(LDD_TUserData *UserDataPtr);
**         GetCRCResult - uint32_t CRC1_GetCRCResult(LDD_TDeviceData *DeviceDataPtr);
**         GetCRC8      - uint32_t CRC1_GetCRC8(LDD_TDeviceData *DeviceDataPtr, uint8_t Data);
**         ResetCRC     - void CRC1_ResetCRC(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file CRC1.c
** @version 01.06
** @date 2013-04-06, 17:46, # CodeGen: 82
** @brief
**         This component implements the Cyclic Redundancy Check (CRC) code calculation.
*/         
/*!
**  @addtogroup CRC1_module CRC1 module documentation
**  @{
*/         

/* MODULE CRC1. */

/* {Default RTOS Adapter} No RTOS includes */
#include "CRC1.h"

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static CRC1_TDeviceData DeviceDataPtr__DEFAULT_RTOS_ALLOC;

/*
** ===================================================================
**     Method      :  CRC1_Init (component CRC_LDD)
*/
/*!
**     @brief
**         Initializes the device and allocates memory for the private
**         device data structure.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* CRC1_Init(LDD_TUserData *UserDataPtr)
{
  CRC1_TDeviceDataPtr DeviceDataPtr;

  /* Allocate LDD device structure */
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPtr = &DeviceDataPtr__DEFAULT_RTOS_ALLOC;
  DeviceDataPtr->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* SIM_SCGC6: CRC=1 */
  SIM_SCGC6 |= SIM_SCGC6_CRC_MASK;                                   
  DeviceDataPtr->CRCStandard = LDD_CRC_32;
  DeviceDataPtr->CRC32bit = TRUE;
  DeviceDataPtr->SeedHigh = 0xFFFFU;
  DeviceDataPtr->SeedLow = 0xFFFFU;
  CRC_PDD_SetCRC_32(CRC_BASE_PTR);
  /* CRC_CRC: HU=0xFF,HL=0xFF,LU=0xFF,LL=0xFF */
  CRC_CRC = CRC_CRC_HU(0xFF) |
            CRC_CRC_HL(0xFF) |
            CRC_CRC_LU(0xFF) |
            CRC_CRC_LL(0xFF);          /* Setup seed */
  /* CRC_GPOLY: HIGH=0x04C1,LOW=0x1DB7 */
  CRC_GPOLY = (CRC_GPOLY_HIGH(0x04C1) | CRC_GPOLY_LOW(0x1DB7)); /* Setup polynomial */
  /* CRC_CTRL: WAS=0 */
  CRC_CTRL &= (uint32_t)~(uint32_t)(CRC_CTRL_WAS_MASK); /* Clear seed bit */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_CRC1_ID,DeviceDataPtr);
  return ((LDD_TDeviceData *)DeviceDataPtr);
}

/*
** ===================================================================
**     Method      :  CRC1_ResetCRC (component CRC_LDD)
*/
/*!
**     @brief
**         Reset CRC module for new CRC computation. This method keeps
**         previous settings (CRC standard, seed value...).
**     @param
**         DeviceDataPtr   - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
*/
/* ===================================================================*/
void CRC1_ResetCRC(LDD_TDeviceData *DeviceDataPtr)
{
  CRC1_TDeviceData *DeviceDataPrv = (CRC1_TDeviceData*)DeviceDataPtr;

  CRC_PDD_SetSeedBit(CRC_BASE_PTR); /* set seed mode */
  if (DeviceDataPrv->CRC32bit == TRUE) { /* 32bit CRC? */
    CRC_PDD_SetSeedHigh(CRC_BASE_PTR, DeviceDataPrv->SeedHigh); /* setup seed high */
  }
  CRC_PDD_SetSeedLow(CRC_BASE_PTR, DeviceDataPrv->SeedLow); /* setup seed low */
  CRC_PDD_ClearSeedBit(CRC_BASE_PTR); /* clear seed mode */
}

/*
** ===================================================================
**     Method      :  CRC1_GetCRC8 (component CRC_LDD)
*/
/*!
**     @brief
**         This method appends 1 data byte to current CRC calculation
**         and returns new result. It automatically enables code
**         generation of GetCRCResult method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @param
**         Data            - New data value for actual CRC
**                           computation.
**     @return
**                         - Returns current CRC result. 
*/
/* ===================================================================*/
uint32_t CRC1_GetCRC8(LDD_TDeviceData *DeviceDataPtr, uint8_t Data)
{
  uint32_t result;
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */

  CRC_PDD_SetCRCDataLLRegister(CRC_BASE_PTR, Data); /* 8bit access */
  result = CRC1_GetCRCResult(DeviceDataPtr);
  return result;
}

/*
** ===================================================================
**     Method      :  CRC1_GetCRCResult (component CRC_LDD)
*/
/*!
**     @brief
**         Returns actual CRC result. This method cannot be disabled if
**         at least one of the following methods is enabled: GetCRC8,
**         GetCRC16, GetCRC32, GetBlockCRC.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @return
**                         - Returns current CRC result. 
*/
/* ===================================================================*/
uint32_t CRC1_GetCRCResult(LDD_TDeviceData *DeviceDataPtr)
{
  CRC1_TDeviceData *DeviceDataPrv = (CRC1_TDeviceData*)DeviceDataPtr;
  uint8_t transpose;
  uint32_t result;

  transpose = (uint8_t)CRC_PDD_GetOutputTranspose(CRC_BASE_PTR);
  if (DeviceDataPrv->CRC32bit == FALSE) {
    if ((transpose == (uint8_t)CRC_PDD_BITS_AND_BYTES) || (transpose == (uint8_t)CRC_PDD_BYTES)) {
      result = CRC_PDD_GetCRCDataHRegister(CRC_BASE_PTR); /* Return upper 16bits of CRC because of transposition in 16bit mode */
    } else {
      result = CRC_PDD_GetCRCDataLRegister(CRC_BASE_PTR); /* Return lower 16bits of CRC */
    }
    return result;
  }
  result = CRC_PDD_GetCRCDataRegister(CRC_BASE_PTR); /* Return 32bit CRC */
  return result;
}

/* END CRC1. */

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
