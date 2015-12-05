/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : WDog1.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMD10
**     Component   : WatchDog_LDD
**     Version     : Component 01.023, Driver 01.04, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-03-06, 17:23, # CodeGen: 0
**     Abstract    :
**          The WatchDog component provides a high level API for unified hardware access
**          across various watchdog timer devices.
**     Settings    :
**          Component name                                 : WDog1
**          Device                                         : EWM
**          Action                                         : Output to pin
**            Input pin                                    : Disabled
**            Output pin                                   : Enabled
**              Pin                                        : ADC0_SE17/PTE24/CAN1_TX/UART4_TX/EWM_OUT_b
**              Output pin signal                          : 
**          Period                                         : 255 ms
**          Windowed mode                                  : Enabled
**            Window                                       : 150
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Protected                                    : no
**            Auto initialization                          : no
**          CPU clock/configuration selection              : Ignored
**     Contents    :
**         Init    - LDD_TDeviceData* WDog1_Init(LDD_TUserData *UserDataPtr);
**         Deinit  - void WDog1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable  - LDD_TError WDog1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable - LDD_TError WDog1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         Clear   - LDD_TError WDog1_Clear(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE WDog1. */

#include "WDog1.h"
#include "mqx.h"
#include "ioctl.h"
#include "IO_Map.h"

typedef struct {
  bool CtrlRegWritten;                 /* Initialization status of control register */
  uint8_t CtrlRegValue;                /* Content of write-once control register */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} WDog1_TDeviceData;

typedef WDog1_TDeviceData *WDog1_TDeviceDataPtr; /* Pointer to the device data structure. */



/* Internal method prototypes */
/*
** ===================================================================
**     Method      :  WDog1_Init (component WatchDog_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/
LDD_TDeviceData* WDog1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  WDog1_TDeviceData *DeviceDataPrv;

  /* {MQX RTOS Adapter} Driver memory allocation: RTOS function call is defined by MQX RTOS Adapter property */
  DeviceDataPrv = (WDog1_TDeviceData *)_mem_alloc_system((_mem_size)sizeof(WDog1_TDeviceData));
  #if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
  if (DeviceDataPrv == NULL) {
    return (NULL);
  }
  #endif
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* SIM_SCGC4: EWM=1 */
  SIM_SCGC4 |= (uint32_t)0x02UL;                       

  /* PORTE_PCR24: ISF=0,MUX=6 */
  PORTE_PCR24 = (uint32_t)((PORTE_PCR24 & (uint32_t)~0x01000100UL) | (uint32_t)0x0600UL);
  DeviceDataPrv->CtrlRegWritten = FALSE; /* Control register is not initialized yet. */
  DeviceDataPrv->CtrlRegValue = 0x01u; /* Content of control register */
  /* EWM_CMPL: COMPAREL=0x96 */
  EWM_CMPL = (uint8_t)0x96U;           /* Set window register */
  /* EWM_CMPH: COMPAREH=0xF8 */
  EWM_CMPH = (uint8_t)0xF8U;           /* Set period register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_WDog1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  WDog1_Deinit (component WatchDog_LDD)
**
**     Description :
**         De-initializes the device and frees the device data
**         structure memory.
**         Note: De-initialization on some devices is impossible.
**         Method Deinit does nothing in this case.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/
void WDog1_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  WDog1_TDeviceData *DeviceDataPrv = (WDog1_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_WDog1_ID);
  /* Deallocation of the device structure */
  /* {MQX RTOS Adapter} Driver memory deallocation: RTOS function call is defined by MQX RTOS Adapter property */
  _mem_free(DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  WDog1_Enable (component WatchDog_LDD)
**
**     Description :
**         Enables the watchdog.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_PROTECT - Device is write protected and
**                           cannot be unlocked.
** ===================================================================
*/
LDD_TError WDog1_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  WDog1_TDeviceData *DeviceDataPrv = (WDog1_TDeviceData *)DeviceDataPtr;

  if (!DeviceDataPrv->CtrlRegWritten) {
    /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_disable();
    EWM_PDD_WriteControlReg(EWM_BASE_PTR, DeviceDataPrv->CtrlRegValue);
    DeviceDataPrv->CtrlRegWritten = TRUE; /* Control register is now initialized. */
    /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_enable();
  }
  else {
    return ERR_PROTECT;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  WDog1_Disable (component WatchDog_LDD)
**
**     Description :
**         Disables the watchdog.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_PROTECT - Device is write protected and
**                           cannot be unlocked.
** ===================================================================
*/
LDD_TError WDog1_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  WDog1_TDeviceData *DeviceDataPrv = (WDog1_TDeviceData *)DeviceDataPtr;

  if (!DeviceDataPrv->CtrlRegWritten) { /* Are registers un-protected? */
    /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_disable();
    EWM_PDD_WriteControlReg(EWM_BASE_PTR, 0U); /* Disable watchdog */
    DeviceDataPrv->CtrlRegWritten = TRUE; /* Control register is now initialized. */
    /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_enable();
  }
  else {
    return ERR_PROTECT;
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  WDog1_Clear (component WatchDog_LDD)
**
**     Description :
**         Clears the watchdog timer (it makes the timer restart from
**         zero).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_DISABLED - The component is disabled
** ===================================================================
*/
LDD_TError WDog1_Clear(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Enable test - this test can be disabled by setting the "Ignore enable test"
     property to the "yes" value in the "Configuration inspector" */
  if ((EWM_PDD_GetEnableDeviceStatus(EWM_BASE_PTR)) != 0U) {
    /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_disable();
    EWM_PDD_WriteServiceReg(EWM_BASE_PTR, EWM_PDD_KEY_1);
    EWM_PDD_WriteServiceReg(EWM_BASE_PTR, EWM_PDD_KEY_2);
    /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
    _int_enable();
  }
  else {
    return ERR_DISABLED;
  }
  return ERR_OK;
}

/* END WDog1. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
