/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Sleep_Timer_LDD.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : TimerInt_LDD
**     Version     : Component 01.013, Driver 01.01, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-03-28, 10:13, # CodeGen: 73
**     Abstract    :
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
**     Settings    :
**          Component name                                 : Sleep_Timer_LDD
**          Periodic interrupt source                      : FTM1_MOD
**          Counter                                        : FTM1_CNT
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_FTM1
**            Interrupt priority                           : high priority
**          Interrupt period                               : 1 ms
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**          Referenced components                          : 
**            Linked TimerUnit                             : TU2
**     Contents    :
**         Init   - LDD_TDeviceData* Sleep_Timer_LDD_Init(LDD_TUserData *UserDataPtr);
**         Deinit - void Sleep_Timer_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Sleep_Timer_LDD.h
** @version 01.01
** @date 2013-03-28, 10:13, # CodeGen: 73
** @brief
**          This TimerInt component implements a periodic interrupt.
**          When the component and its events are enabled, the "OnInterrupt"
**          event is called periodically with the period that you specify.
**          TimerInt supports also changing the period in runtime.
**          This TimerInt component provides a high level API for unified
**          hardware access to various timer devices using the TimerUnit
**          component.
*/         
/*!
**  @addtogroup Sleep_Timer_LDD_module Sleep_Timer_LDD module documentation
**  @{
*/         

#ifndef __Sleep_Timer_LDD_H
#define __Sleep_Timer_LDD_H

/* MODULE Sleep_Timer_LDD. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "TU2.h"

#include "Cpu.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define Sleep_Timer_LDD_PRPH_BASE_ADDRESS  0x40039000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define Sleep_Timer_LDD_Init_METHOD_ENABLED /*!< Init method of the component Sleep_Timer_LDD is enabled (generated) */
#define Sleep_Timer_LDD_Deinit_METHOD_ENABLED /*!< Deinit method of the component Sleep_Timer_LDD is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define Sleep_Timer_LDD_OnInterrupt_EVENT_ENABLED /*!< OnInterrupt event of the component Sleep_Timer_LDD is enabled (generated) */



/*
** ===================================================================
**     Method      :  Sleep_Timer_LDD_Init (component TimerInt_LDD)
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
LDD_TDeviceData* Sleep_Timer_LDD_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  Sleep_Timer_LDD_Deinit (component TimerInt_LDD)
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
void Sleep_Timer_LDD_Deinit(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU2_OnCounterRestart (component TimerInt_LDD)
**
**     Description :
**         The method services the event of the linked component TU2 and 
**         eventually invokes event Sleep_Timer_LDD_OnInterrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void TU2_OnCounterRestart(LDD_TUserData *UserDataPtr);

/* END Sleep_Timer_LDD. */

#endif
/* ifndef __Sleep_Timer_LDD_H */
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
