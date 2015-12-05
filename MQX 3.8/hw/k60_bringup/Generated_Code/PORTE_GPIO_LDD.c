/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTE_GPIO_LDD.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-04-19, 18:31, # CodeGen: 94
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PORTE_GPIO_LDD
**          Port                                           : PTE
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 50
**          Interrupt service/event                        : Disabled
**          Bit fields                                     : 2
**            Bit field                                    : 
**              Field name                                 : WIFI_PD_B
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTE4/LLWU_P2/SPI1_PCS0/UART3_TX/SDHC0_D3/FB_CS3_b/FB_BE7_0_b/FB_TA_b
**                  Pin signal                             : WIFI_PWDN_B
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**            Bit field                                    : 
**              Field name                                 : BT_32KHz_EN
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTE6/SPI1_PCS3/UART3_CTS_b/I2S0_MCLK/FB_ALE/FB_CS1_b/FB_TS_b/USB_SOF_OUT
**                  Pin signal                             : BT_32KHz_EN
**                  Initial pin direction                  : Output
**                    Initial output state                 : 1
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Disabled
**     Contents    :
**         Init                    - LDD_TDeviceData* PORTE_GPIO_LDD_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void PORTE_GPIO_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void PORTE_GPIO_LDD_SetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         GetFieldValue           - PORTE_GPIO_LDD_TFieldValue PORTE_GPIO_LDD_GetFieldValue(LDD_TDeviceData...
**         ClearFieldBits          - void PORTE_GPIO_LDD_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldBits            - void PORTE_GPIO_LDD_SetFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         ToggleFieldBits         - void PORTE_GPIO_LDD_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldInputDirection  - void PORTE_GPIO_LDD_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void PORTE_GPIO_LDD_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError PORTE_GPIO_LDD_ConnectPin(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PORTE_GPIO_LDD.c
** @version 01.06
** @date 2013-04-19, 18:31, # CodeGen: 94
** @brief
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
*/         
/*!
**  @addtogroup PORTE_GPIO_LDD_module PORTE_GPIO_LDD module documentation
**  @{
*/         

/* MODULE PORTE_GPIO_LDD. */

#include "PORTE_GPIO_LDD.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} PORTE_GPIO_LDD_TDeviceData, *PORTE_GPIO_LDD_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static PORTE_GPIO_LDD_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_Init (component GPIO_LDD)
*/
/*!
**     @brief
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     @param
**         UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* PORTE_GPIO_LDD_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  PORTE_GPIO_LDD_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* GPIOE_PDOR: PDO&=~0x10,PDO|=0x40 */
  GPIOE_PDOR = (uint32_t)((GPIOE_PDOR & (uint32_t)~(uint32_t)(
                GPIO_PDOR_PDO(0x10)
               )) | (uint32_t)(
                GPIO_PDOR_PDO(0x40)
               ));                                  
  /* GPIOE_PDDR: PDD|=0x50 */
  GPIOE_PDDR |= GPIO_PDDR_PDD(0x50);                                   
  /* Initialization of Port Control registers */
  /* PORTE_PCR4: ISF=0,LK=0,MUX=1 */
  PORTE_PCR4 = (uint32_t)((PORTE_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_LK_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                  
  /* PORTE_PCR6: ISF=0,LK=0,MUX=1 */
  PORTE_PCR6 = (uint32_t)((PORTE_PCR6 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_LK_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                  
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_PORTE_GPIO_LDD_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_Deinit (component GPIO_LDD)
*/
/*!
**     @brief
**         This method disables the device and frees the device data
**         structure memory.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTE_PCR4: IRQC=0 */
  PORTE_PCR4 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                   
  /* PORTE_PCR6: IRQC=0 */
  PORTE_PCR6 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                   
  /* GPIOE_PDDR: PDD&=~0x50 */
  GPIOE_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x50));                                   
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_PORTE_GPIO_LDD_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_SetFieldValue (component GPIO_LDD)
*/
/*!
**     @brief
**         This method sets the output data value of the specified bit
**         field.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTE_GPIO_LDD_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
          & ((PORTE_GPIO_LDD_TPortValue)(~((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)))
        )
        | (
          ((PORTE_GPIO_LDD_TPortValue)(Value << PORTE_GPIO_LDD_WIFI_PD_B_START_BIT))
          & ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
        )
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_SetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
          & ((PORTE_GPIO_LDD_TPortValue)(~((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)))
        )
        | (
          ((PORTE_GPIO_LDD_TPortValue)(Value << PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT))
          & ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
        )
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_GetFieldValue (component GPIO_LDD)
*/
/*!
**     @brief
**         This method returns the current input data of the specified
**         field.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @return
**                         - Aligned current port input value masked for
**                           allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
*/
/* ===================================================================*/
PORTE_GPIO_LDD_TFieldValue PORTE_GPIO_LDD_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      return
        (PORTE_GPIO_LDD_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
            & (PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK
          )
          >> PORTE_GPIO_LDD_WIFI_PD_B_START_BIT
        );
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      return
        (PORTE_GPIO_LDD_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
            & (PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK
          )
          >> PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (PORTE_GPIO_LDD_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_ClearFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTE_GPIO_LDD_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_WIFI_PD_B_START_BIT))
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_ClearPortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_SetFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTE_GPIO_LDD_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_WIFI_PD_B_START_BIT))
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_SetPortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_ToggleFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTE_GPIO_LDD_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_WIFI_PD_B_START_BIT))
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_TogglePortDataOutputMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
        & ((PORTE_GPIO_LDD_TPortValue)(Mask << PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_SetFieldInputDirection (component GPIO_LDD)
*/
/*!
**     @brief
**         This method sets all pins of the field to the input
**         direction.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        PORTE_GPIO_LDD_WIFI_PD_B_MASK
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_SetPortInputDirectionMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        PORTE_GPIO_LDD_BT_32KHz_EN_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_SetFieldOutputDirection (component GPIO_LDD)
*/
/*!
**     @brief
**         This method sets all pins of the field to the output
**         direction.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to set to the output
**                           direction. Bit fields are defined during
**                           design time and for each bit field there is
**                           a generated constant.
**     @param
**         Value           - Aligned data value to appear on the
**                           bit field pins after they have been
**                           switched to the output direction.
*/
/* ===================================================================*/
void PORTE_GPIO_LDD_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTE_GPIO_LDD_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case WIFI_PD_B: {                  /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)(
          GPIO_PDD_GetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
          & ((PORTE_GPIO_LDD_TPortValue)(
            ~((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
          ))
        ))
        | (
          ((PORTE_GPIO_LDD_TPortValue)(Value << PORTE_GPIO_LDD_WIFI_PD_B_START_BIT))
          & ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_WIFI_PD_B_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        PORTE_GPIO_LDD_WIFI_PD_B_MASK
      );
      break;
    }
    case BT_32KHz_EN: {                /* bit field #1 */
      GPIO_PDD_SetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        ((PORTE_GPIO_LDD_TPortValue)(
          GPIO_PDD_GetPortDataOutput(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS)
          & ((PORTE_GPIO_LDD_TPortValue)(
            ~((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
          ))
        ))
        | (
          ((PORTE_GPIO_LDD_TPortValue)(Value << PORTE_GPIO_LDD_BT_32KHz_EN_START_BIT))
          & ((PORTE_GPIO_LDD_TPortValue)PORTE_GPIO_LDD_BT_32KHz_EN_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(PORTE_GPIO_LDD_MODULE_BASE_ADDRESS,
        PORTE_GPIO_LDD_BT_32KHz_EN_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  PORTE_GPIO_LDD_ConnectPin (component GPIO_LDD)
*/
/*!
**     @brief
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is only
**         available for CPU derivatives and peripherals that support
**         the runtime pin sharing with other internal on-chip
**         peripherals.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         PinMask         - Mask for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this mask.
**     @return
**                         - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
*/
/* ===================================================================*/
LDD_TError PORTE_GPIO_LDD_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Pin mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((PinMask & ((LDD_TPinMask)~((LDD_TPinMask)PORTE_GPIO_LDD_ALLOCATED_PINS_MASK))) != 0U) {
    return ERR_PARAM_MASK;
  }
  if ((PinMask & LDD_GPIO_PIN_4) != 0U) {
      clrSetReg32Bits(PORTE_PCR4, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  if ((PinMask & LDD_GPIO_PIN_6) != 0U) {
      clrSetReg32Bits(PORTE_PCR6, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  return ERR_OK;
}

/* END PORTE_GPIO_LDD. */

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
