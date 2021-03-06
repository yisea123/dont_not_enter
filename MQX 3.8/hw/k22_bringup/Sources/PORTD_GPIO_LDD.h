/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTD_GPIO_LDD.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-02-08, 16:25, # CodeGen: 34
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : PORTD_GPIO_LDD
**          Port                                           : PTD
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : F000
**          Interrupt service/event                        : Disabled
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : LED_DBG
**              Pins                                       : 4
**                Pin                                      : 
**                  Pin                                    : PTD12/SPI2_SCK/SDHC0_D4/FB_AD7/FB_A20
**                  Pin signal                             : LED0
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**                Pin                                      : 
**                  Pin                                    : PTD13/SPI2_SOUT/SDHC0_D5/FB_AD6/FB_A21
**                  Pin signal                             : LED1
**                  Initial pin direction                  : Output
**                    Initial output state                 : 1
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**                Pin                                      : 
**                  Pin                                    : PTD14/SPI2_SIN/SDHC0_D6/FB_AD5/FB_A22
**                  Pin signal                             : LED2
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**                Pin                                      : 
**                  Pin                                    : PTD15/SPI2_PCS1/SDHC0_D7/FB_RW_b/FB_A23
**                  Pin signal                             : LED3
**                  Initial pin direction                  : Output
**                    Initial output state                 : 1
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Disabled
**     Contents    :
**         Init                    - LDD_TDeviceData* PORTD_GPIO_LDD_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void PORTD_GPIO_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void PORTD_GPIO_LDD_SetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         GetFieldValue           - PORTD_GPIO_LDD_TFieldValue PORTD_GPIO_LDD_GetFieldValue(LDD_TDeviceData...
**         ClearFieldBits          - void PORTD_GPIO_LDD_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldBits            - void PORTD_GPIO_LDD_SetFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         ToggleFieldBits         - void PORTD_GPIO_LDD_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldInputDirection  - void PORTD_GPIO_LDD_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void PORTD_GPIO_LDD_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError PORTD_GPIO_LDD_ConnectPin(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __PORTD_GPIO_LDD_H
#define __PORTD_GPIO_LDD_H

/* MODULE PORTD_GPIO_LDD. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"
#include "PORT_PDD.h"
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define PORTD_GPIO_LDD_PRPH_BASE_ADDRESS  0x400FF0C0U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define PORTD_GPIO_LDD_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_PORTD_GPIO_LDD_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define PORTD_GPIO_LDD_Init_METHOD_ENABLED
#define PORTD_GPIO_LDD_Deinit_METHOD_ENABLED
#define PORTD_GPIO_LDD_SetFieldValue_METHOD_ENABLED
#define PORTD_GPIO_LDD_GetFieldValue_METHOD_ENABLED
#define PORTD_GPIO_LDD_ClearFieldBits_METHOD_ENABLED
#define PORTD_GPIO_LDD_SetFieldBits_METHOD_ENABLED
#define PORTD_GPIO_LDD_ToggleFieldBits_METHOD_ENABLED
#define PORTD_GPIO_LDD_SetFieldInputDirection_METHOD_ENABLED
#define PORTD_GPIO_LDD_SetFieldOutputDirection_METHOD_ENABLED
#define PORTD_GPIO_LDD_ConnectPin_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */

/* Definition of bit field constants */
#define LED_DBG ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define PORTD_GPIO_LDD_ALLOCATED_PINS_MASK 0xF000U /* Mask of all allocated pins from the port */
#define PORTD_GPIO_LDD_MODULE_BASE_ADDRESS PTD_BASE_PTR /* Name of macro used as the base address */
#define PORTD_GPIO_LDD_PORTCONTROL_BASE_ADDRESS PORTD_BASE_PTR /* Name of macro used as the base address */
#define PORTD_GPIO_LDD_AVAILABLE_EVENTS_MASK 0x00U /* Mask of all available events */
#define PORTD_GPIO_LDD_FIELD_0_PIN_0 LDD_GPIO_PIN_12 /* Constant for the pin in the field used in the method ConnectPin */
#define PORTD_GPIO_LDD_FIELD_0_PIN_1 LDD_GPIO_PIN_13 /* Constant for the pin in the field used in the method ConnectPin */
#define PORTD_GPIO_LDD_FIELD_0_PIN_2 LDD_GPIO_PIN_14 /* Constant for the pin in the field used in the method ConnectPin */
#define PORTD_GPIO_LDD_FIELD_0_PIN_3 LDD_GPIO_PIN_15 /* Constant for the pin in the field used in the method ConnectPin */
#define PORTD_GPIO_LDD_LED_DBG_START_BIT 12u /* Index of the starting bit of the bit field (0 represents LSB) */
#define PORTD_GPIO_LDD_LED_DBG_MASK 0xF000u /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t PORTD_GPIO_LDD_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef PORTD_GPIO_LDD_TPortValue PORTD_GPIO_LDD_TFieldValue;



LDD_TDeviceData* PORTD_GPIO_LDD_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_Init (component GPIO_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/

void PORTD_GPIO_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_Deinit (component GPIO_LDD)
**
**     Description :
**         This method disables the device and frees the device data
**         structure memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**     Returns     : Nothing
** ===================================================================
*/

void PORTD_GPIO_LDD_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTD_GPIO_LDD_TFieldValue Value);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_SetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method sets the output data value of the specified bit
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
**     Returns     : Nothing
** ===================================================================
*/

PORTD_GPIO_LDD_TFieldValue PORTD_GPIO_LDD_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_GetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method returns the current input data of the specified
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     :
**         ---             - Aligned current port input value masked
**                           for allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
** ===================================================================
*/

void PORTD_GPIO_LDD_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTD_GPIO_LDD_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_ClearFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/

void PORTD_GPIO_LDD_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTD_GPIO_LDD_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_SetFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/

void PORTD_GPIO_LDD_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTD_GPIO_LDD_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_ToggleFieldBits (component GPIO_LDD)
**
**     Description :
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/

void PORTD_GPIO_LDD_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_SetFieldInputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the input
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     : Nothing
** ===================================================================
*/

void PORTD_GPIO_LDD_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, PORTD_GPIO_LDD_TFieldValue Value);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_SetFieldOutputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the output
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to set to the output
**                           direction. Bit fields are defined during
**                           design time and for each bit field there is
**                           a generated constant.
**         Value           - Aligned data value to appear on the
**                           bit field pins after they have been
**                           switched to the output direction.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError PORTD_GPIO_LDD_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);
/*
** ===================================================================
**     Method      :  PORTD_GPIO_LDD_ConnectPin (component GPIO_LDD)
**
**     Description :
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is only
**         available for CPU derivatives and peripherals that support
**         the runtime pin sharing with other internal on-chip
**         peripherals.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         PinMask         - Mask for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this mask.
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/

/* END PORTD_GPIO_LDD. */

#endif
/* ifndef __PORTD_GPIO_LDD_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
