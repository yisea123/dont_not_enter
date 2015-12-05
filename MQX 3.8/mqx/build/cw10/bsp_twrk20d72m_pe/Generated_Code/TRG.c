/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TRG.c
**     Project     : ProcessorExpert
**     Processor   : MK20DX256VLL7
**     Component   : TimerUnit_LDD
**     Version     : Component 01.123, Driver 01.06, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2012-03-09, 20:24, # CodeGen: 0
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TRG
**          Module name                                    : FTM1
**          Counter                                        : FTM1_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : 36 MHz
**          Counter restart                                : On-match
**            Period device                                : FTM1_MOD
**            Period                                       : 64000 Hz
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_FTM1
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**     Contents    :
**         Init                  - LDD_TDeviceData* TRG_Init(LDD_TUserData *UserDataPtr);
**         Deinit                - void TRG_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable                - LDD_TError TRG_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable               - LDD_TError TRG_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask          - LDD_TError TRG_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask...
**         GetEventMask          - LDD_TEventMask TRG_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         GetEventStatus        - LDD_TEventMask TRG_GetEventStatus(LDD_TDeviceData *DeviceDataPtr);
**         GetInputFrequencyReal - LDD_TimerUnit_Tfloat TRG_GetInputFrequencyReal(LDD_TDeviceData *DeviceDataPtr);
**         GetInputFrequency     - uint32_t TRG_GetInputFrequency(LDD_TDeviceData *DeviceDataPtr);
**         SetPeriodTicks        - LDD_TError TRG_SetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TRG_TValueType...
**         GetPeriodTicks        - LDD_TError TRG_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TRG_TValueType...
**         ResetCounter          - LDD_TError TRG_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**         GetCounterValue       - TRG_TValueType TRG_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
**         GetDriverState        - LDD_TDriverState TRG_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE TRG. */

#include "Events.h"
#include "TRG.h"
#include "mqx.h"
#include "ioctl.h"
#include "IO_Map.h"


typedef struct {
  LDD_RTOS_TISRVectorSettings SavedISRSettings_TUInterrupt; /* {MQX RTOS Adapter} Saved settings of allocated interrupt vector */
  bool EnUser;                         /* Enable/Disable device */
  bool EnMode;                         /* Enable/Disable device in clock configuration */
  LDD_TEventMask EnEvents;             /* Enable/Disable events mask */
  uint32_t Source;                     /* Current source clock */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} TRG_TDeviceData;

typedef TRG_TDeviceData *TRG_TDeviceDataPtr; /* Pointer to the device data structure. */


#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_COUNTER_RESTART)

/* Internal method prototypes */
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  TRG_Init (component TimerUnit_LDD)
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
LDD_TDeviceData* TRG_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  TRG_TDeviceData *DeviceDataPrv;
  /* {MQX RTOS Adapter} Driver memory allocation: RTOS function call is defined by MQX RTOS Adapter property */
  DeviceDataPrv = (TRG_TDeviceData *)_mem_alloc_system((_mem_size)sizeof(TRG_TDeviceData));
  #if MQX_CHECK_MEMORY_ALLOCATION_ERRORS
  if (DeviceDataPrv == NULL) {
    return (NULL);
  }
  #endif
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {MQX RTOS Adapter} Save old and set new interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not saved, because it is not modified */
  DeviceDataPrv->SavedISRSettings_TUInterrupt.isrData = _int_get_isr_data(LDD_ivIndex_INT_FTM1);
  DeviceDataPrv->SavedISRSettings_TUInterrupt.isrFunction = _int_install_isr(LDD_ivIndex_INT_FTM1, TRG_Interrupt, DeviceDataPrv);
  /* SIM_SCGC6: FTM1=1 */
  SIM_SCGC6 |= (uint32_t)0x02000000UL;                       
  /* FTM1_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,CAPTEST=0,PWMSYNC=0,WPDIS=1,INIT=0,FTMEN=0 */
  FTM1_MODE = (uint32_t)0x04UL;        /* Set up mode register */
  /* FTM1_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
  FTM1_SC = (uint32_t)0x00UL;          /* Clear status and control register */
  /* FTM1_CNTIN: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,INIT=0 */
  FTM1_CNTIN = (uint32_t)0x00UL;       /* Clear counter initial register */
  /* FTM1_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
  FTM1_CNT = (uint32_t)0x00UL;         /* Reset counter register */
  /* FTM1_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM1_C0SC = (uint32_t)0x00UL;        /* Clear channel status and control register */
  /* FTM1_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM1_C1SC = (uint32_t)0x00UL;        /* Clear channel status and control register */
  /* FTM1_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0x0231 */
  FTM1_MOD = (uint32_t)0x0231UL;       /* Set up modulo register */
  DeviceDataPrv->EnEvents = 0x0100u;   /* Enable selected events */
  DeviceDataPrv->Source = FTM_PDD_SYSTEM; /* Store clock source */
  /* NVICIP63: PRI63=0x80 */
  NVICIP63 = (uint8_t)0x80U;                             
  /* NVICISER1: SETENA|=0x80000000 */
  NVICISER1 |= (uint32_t)0x80000000UL;                       
  /* FTM1_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=1,CPWMS=0,CLKS=0,PS=0 */
  FTM1_SC = (uint32_t)0x40UL;          /* Set up status and control register */
  DeviceDataPrv->EnUser = FALSE;       /* Set the flag "device disabled" */
  TRG_SetClockConfiguration(DeviceDataPrv, Cpu_GetClockConfiguration()); /* Set Initial according clock configuration */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_TRG_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  TRG_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/
void TRG_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;
  FTM_PDD_SelectPrescalerSource(FTM1_BASE_PTR, FTM_PDD_DISABLED);
  /* Interrupt vector(s) deallocation */
  /* {MQX RTOS Adapter} Restore interrupt vector (function handler and ISR parameter) */
  /* Note: Exception handler for interrupt is not restored, because it was not modified */
  (void)_int_install_isr(LDD_ivIndex_INT_FTM1, ((TRG_TDeviceDataPtr)DeviceDataPrv)->SavedISRSettings_TUInterrupt.isrFunction, ((TRG_TDeviceDataPtr)DeviceDataPrv)->SavedISRSettings_TUInterrupt.isrData);
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_TRG_ID);
  /* Deallocation of the device structure */
  /* {MQX RTOS Adapter} Driver memory deallocation: RTOS function call is defined by MQX RTOS Adapter property */
  _mem_free(DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  TRG_Enable (component TimerUnit_LDD)
**
**     Description :
**         Enables the component - it starts the signal generation.
**         Events may be generated (see SetEventMask). The method is
**         not available if the counter can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError TRG_Enable(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  if (!DeviceDataPrv->EnUser) {        /* Is the device disabled by user? */
    DeviceDataPrv->EnUser = TRUE;      /* If yes then set the flag "device enabled" */
    HWEnDi(DeviceDataPtr);             /* Enable/disable device according to status flags */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TRG_Disable (component TimerUnit_LDD)
**
**     Description :
**         Disables the component - it stops signal generation and
**         events calling. The method is not available if the counter
**         can't be disabled/enabled by HW.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError TRG_Disable(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  if (DeviceDataPrv->EnUser) {         /* Is the device enabled by user? */
    DeviceDataPrv->EnUser = FALSE;     /* If yes then set the flag "device disabled" */
    HWEnDi(DeviceDataPtr);             /* Enable/disable device according to status flags */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TRG_SetEventMask (component TimerUnit_LDD)
**
**     Description :
**         Enables/disables event(s). The events contained within the
**         mask are enabled. Events not contained within the mask are
**         disabled. The component event masks are defined in the
**         PE_LDD.h file. Note: Event that are not generated (See the
**         "Events" tab in the Component inspector) are not handled by
**         this method. In this case the method returns ERR_PARAM_MASK
**         error code. See also method <GetEventMask>.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         EventMask       - Event mask
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
**                           ERR_PARAM_MASK - Event mask is not valid
** ===================================================================
*/
LDD_TError TRG_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  /* Event mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((EventMask & ((LDD_TEventMask)~AVAILABLE_EVENTS_MASK)) != 0U) {
    return ERR_PARAM_MASK;
  }
  /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_disable();
  if ((EventMask & LDD_TIMERUNIT_ON_COUNTER_RESTART) != 0U) { /* Is the event enabled? */
    FTM_PDD_ClearOverflowInterruptFlag(FTM1_BASE_PTR); /* If yes then clear flag */
    FTM_PDD_EnableOverflowInterrupt(FTM1_BASE_PTR); /* and enable interrupt */
  }
  else {
    FTM_PDD_DisableOverflowInterrupt(FTM1_BASE_PTR); /* Disable overflow interrupt */
  }
  DeviceDataPrv->EnEvents = EventMask;
  /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_enable();
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  TRG_GetEventMask (component TimerUnit_LDD)
**
**     Description :
**         Returns current events mask. Note: Event that are not
**         generated (See the "Events" tab in the Component inspector)
**         are not handled by this method. See also method
**         <SetEventMask>.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method.
**     Returns     :
**         ---             - Current EventMask.
**                           The component event masks are defined in
**                           the PE_LDD.h file.
** ===================================================================
*/
LDD_TEventMask TRG_GetEventMask(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  return DeviceDataPrv->EnEvents;
}

/*
** ===================================================================
**     Method      :  TRG_GetEventStatus (component TimerUnit_LDD)
**
**     Description :
**         Returns current pending flags and clears them.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method.
**     Returns     :
**         ---             - Current status flags
** ===================================================================
*/
LDD_TEventMask TRG_GetEventStatus(LDD_TDeviceData *DeviceDataPtr)
{
  LDD_TEventMask Mask = 0U;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_disable();
  if ((FTM_PDD_GetOverflowInterruptFlag(FTM1_BASE_PTR)) != 0U) { /* Is the overflow interrupt flag pending? */
    FTM_PDD_ClearOverflowInterruptFlag(FTM1_BASE_PTR); /* If yes then clear them */
    Mask |= LDD_TIMERUNIT_ON_COUNTER_RESTART; /* and set mask */
  }
  /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_enable();
  return Mask;                         /* Return the mask. */
}

/*
** ===================================================================
**     Method      :  TRG_GetInputFrequencyReal (component TimerUnit_LDD)
**
**     Description :
**         Returns current input frequency of the counter in Hz as
**         float number. This method can be used only if <"Input clock
**         source"> property is set to "internal".
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method.
**     Returns     :
**         ---             - Input frequency
** ===================================================================
*/
LDD_TimerUnit_Tfloat TRG_GetInputFrequencyReal(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Cpu_GetClockConfiguration()) {
    case CPU_CLOCK_CONFIG_0:
      return TRG_CNT_INP_FREQ_R_0_CFG_0;
    default:
      ;
  }
  return TRG_CNT_INP_FREQ_R_0;
}

/*
** ===================================================================
**     Method      :  TRG_GetInputFrequency (component TimerUnit_LDD)
**
**     Description :
**         Returns current input frequency of the counter in Hz as
**         32-bit unsigned integer number. This method can be used only
**         if <"Input clock source"> property is set to "internal".
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method.
**     Returns     :
**         ---             - Input frequency
** ===================================================================
*/
uint32_t TRG_GetInputFrequency(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Cpu_GetClockConfiguration()) {
    case CPU_CLOCK_CONFIG_0:
      return TRG_CNT_INP_FREQ_U_0_CFG_0;
    default:
      ;
  }
  return TRG_CNT_INP_FREQ_U_0;
}

/*
** ===================================================================
**     Method      :  TRG_SetPeriodTicks (component TimerUnit_LDD)
**
**     Description :
**         The method sets timer re-initialization period (in timer
**         ticks). This method is available only if the property
**         <"Counter restart"> is switched to 'on-match' value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Ticks           - Number of counter ticks before counter
**                           re-initialization. Value 0 means maximal
**                           period value the same as "free-running
**                           mode", e.g. counter overflow or underflow
**                           without any explicit re-initialization.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError TRG_SetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TRG_TValueType Ticks)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  FTM_PDD_WriteModuloReg(FTM1_BASE_PTR, (uint16_t)(--Ticks));
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TRG_GetPeriodTicks (component TimerUnit_LDD)
**
**     Description :
**         Returns the number of counter ticks before re-initialization.
**         See also method <SetPeriodTicks>. This function is available
**         only if the property <"Counter restart"> is switched to
**         'on-match' value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * TicksPtr        - Pointer to return value of the
**                           number of counter ticks before
**                           re-initialization
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError TRG_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TRG_TValueType *TicksPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;
  uint16_t tmp;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  tmp = (uint16_t)(FTM_PDD_ReadModuloReg(FTM1_BASE_PTR));
  *TicksPtr = (TRG_TValueType)++tmp;
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TRG_ResetCounter (component TimerUnit_LDD)
**
**     Description :
**         Resets counter. If counter is counting up then it is set to
**         zero. If counter is counting down then counter is updated to
**         the reload value.
**         The method is not available if HW doesn't allow resetting of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError TRG_ResetCounter(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  /* Clock configuration test - this test can be disabled by setting the "Ignore clock configuration test"
     property to the "yes" value in the "Configuration inspector" */
  if (!DeviceDataPrv->EnMode) {        /* Is the device disabled in the actual clock configuration? */
    return ERR_SPEED;                  /* If yes then error */
  }
  FTM_PDD_InitializeCounter(FTM1_BASE_PTR);
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TRG_GetCounterValue (component TimerUnit_LDD)
**
**     Description :
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method.
**     Returns     :
**         ---             - Counter value (number of counted ticks).
** ===================================================================
*/
TRG_TValueType TRG_GetCounterValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (TRG_TValueType)FTM_PDD_ReadCounterReg(FTM1_BASE_PTR);
}

/*
** ===================================================================
**     Method      :  TRG_SetClockConfiguration (component TimerUnit_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TRG_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;

  switch (ClockConfiguration) {
    case CPU_CLOCK_CONFIG_0:
      DeviceDataPrv->EnMode = TRUE;    /* Set the flag "device enabled" in the actual clock configuration */
      DeviceDataPrv->Source = FTM_PDD_SYSTEM; /* Select clock source */
      FTM_PDD_SetPrescaler(FTM1_BASE_PTR, FTM_PDD_DIVIDE_1); /* Set prescaler register */
      break;
    default:
      DeviceDataPrv->EnMode = FALSE;   /* Set the flag "device disabled" in the actual clock configuration */
      break;
  }
  HWEnDi(DeviceDataPtr);               /* Enable/disable device according to status flags */
}

/*
** ===================================================================
**     Method      :  TRG_GetDriverState (component TimerUnit_LDD)
**
**     Description :
**         This method returns the current driver status.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - The current driver status mask.
**                           Following status masks defined in PE_LDD.h
**                           can be used to check the current driver
**                           status.
**                           PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATION - 1 -
**                           Driver is disabled in the current mode; 0 -
**                           Driver is enabled in the current mode.  
**                           PE_LDD_DRIVER_DISABLED_BY_USER - 1 - Driver
**                           is disabled by the user; 0 - Driver is
**                           enabled by the user.        
**                           PE_LDD_DRIVER_BUSY - 1 - Driver is the BUSY
**                           state; 0 - Driver is in the IDLE state.
** ===================================================================
*/
LDD_TDriverState TRG_GetDriverState(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceData *DeviceDataPrv = (TRG_TDeviceData *)DeviceDataPtr;
  LDD_TDriverState DriverState = 0x00U;

  DriverState |= (DeviceDataPrv->EnMode)? 0x00U : PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATION; /* Driver disabled in the current clock configuration? */
  DriverState |= (DeviceDataPrv->EnUser)? 0x00U : PE_LDD_DRIVER_DISABLED_BY_USER; /* Driver disabled byt the user? */
  return DriverState;
}

/*
** ===================================================================
**     Method      :  TRG_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TRG_Interrupt(LDD_RTOS_TISRParameter _isrParameter)
{
  /* {MQX RTOS Adapter} ISR parameter is passed as parameter from RTOS interrupt dispatcher */
  TRG_TDeviceDataPtr DeviceDataPrv = (TRG_TDeviceDataPtr)_isrParameter;
  LDD_TEventMask State = 0U;

  if ((FTM_PDD_GetOverflowInterruptFlag(FTM1_BASE_PTR)) != 0U) { /* Is the overflow interrupt flag pending? */
    State |= LDD_TIMERUNIT_ON_COUNTER_RESTART; /* and set mask */
  }
  State &= DeviceDataPrv->EnEvents;    /* Handle only enabled interrupts */
  if (State & LDD_TIMERUNIT_ON_COUNTER_RESTART) { /* Is the overflow interrupt flag pending? */
    FTM_PDD_ClearOverflowInterruptFlag(FTM1_BASE_PTR); /* Clear flag */
    TRG_OnCounterRestart(DeviceDataPrv->UserDataPtr); /* Invoke OnCounterRestart event */
  }
}

/*
** ===================================================================
**     Method      :  HWEnDi (component TimerUnit_LDD)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(LDD_TDeviceData *DeviceDataPtr)
{
  TRG_TDeviceDataPtr DeviceDataPrv = (TRG_TDeviceDataPtr)DeviceDataPtr;

  /* {MQX RTOS Adapter} Critical section begin (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_disable();
  if (DeviceDataPrv->EnMode && DeviceDataPrv->EnUser) { /* Enable device? */
    FTM_PDD_SelectPrescalerSource(FTM1_BASE_PTR, DeviceDataPrv->Source);
  }
  else {
    FTM_PDD_SelectPrescalerSource(FTM1_BASE_PTR, FTM_PDD_DISABLED);
  }
  /* {MQX RTOS Adapter} Critical section ends (RTOS function call is defined by MQX RTOS Adapter property) */
  _int_enable();
}
/* END TRG. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/