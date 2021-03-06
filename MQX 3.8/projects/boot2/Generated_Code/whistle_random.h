/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : whistle_random.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : RNG_LDD
**     Version     : Component 01.069, Driver 01.02, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-08-16, 16:46, # CodeGen: 84
**     Abstract    :
**         This component implements the Random Number Generator/Accelerator (RNGB/RNGA) driver.
**     Settings    :
**          Component name                                 : whistle_random
**          Device                                         : RNG
**          Interrupt service                              : Disabled
**          Settings                                       : 
**            High assurance                               : Enabled
**          Initialization                                 : 
**            Sleep                                        : no
**            Start RNGA                                   : yes
**            Entropy register init                        : Enabled
**              Entropy value                              : 12345
**            Event mask                                   : 
**              OnError                                    : Enabled
**            Auto initialization                          : yes
**     Contents    :
**         Init            - LDD_TDeviceData* whistle_random_Init(LDD_TUserData *UserDataPtr);
**         SetEventMask    - LDD_TError whistle_random_SetEventMask(LDD_TDeviceData *DeviceDataPtr,...
**         GetEventMask    - LDD_TEventMask whistle_random_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         InsertEntropy   - void whistle_random_InsertEntropy(LDD_TDeviceData *DeviceDataPtr, uint32_t...
**         Start           - void whistle_random_Start(LDD_TDeviceData *DeviceDataPtr);
**         Main            - void whistle_random_Main(LDD_TDeviceData *DeviceDataPtr);
**         GetRandomNumber - LDD_TError whistle_random_GetRandomNumber(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file whistle_random.h
** @version 01.02
** @date 2013-08-16, 16:46, # CodeGen: 84
** @brief
**         This component implements the Random Number Generator/Accelerator (RNGB/RNGA) driver.
*/         
/*!
**  @addtogroup whistle_random_module whistle_random module documentation
**  @{
*/         


#ifndef __whistle_random_H
#define __whistle_random_H

/* MODULE whistle_random. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "RNGA_PDD.h"

#include "Cpu.h"

typedef struct {
  LDD_TUserData *UserData;             /* Pointer to user data */
  LDD_TEventMask EventMask;            /* Enable/Disable events mask */
} whistle_random_TDeviceData;

typedef whistle_random_TDeviceData *whistle_random_TDeviceDataPtr; /* Pointer to the device data structure. */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define whistle_random_PRPH_BASE_ADDRESS  0x400A0000U
  
/*! Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define whistle_random_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_whistle_random_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define whistle_random_Init_METHOD_ENABLED /*!< Init method of the component whistle_random is enabled (generated) */
#define whistle_random_SetEventMask_METHOD_ENABLED /*!< SetEventMask method of the component whistle_random is enabled (generated) */
#define whistle_random_GetEventMask_METHOD_ENABLED /*!< GetEventMask method of the component whistle_random is enabled (generated) */
#define whistle_random_InsertEntropy_METHOD_ENABLED /*!< InsertEntropy method of the component whistle_random is enabled (generated) */
#define whistle_random_Start_METHOD_ENABLED /*!< Start method of the component whistle_random is enabled (generated) */
#define whistle_random_Main_METHOD_ENABLED /*!< Main method of the component whistle_random is enabled (generated) */
#define whistle_random_GetRandomNumber_METHOD_ENABLED /*!< GetRandomNumber method of the component whistle_random is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define whistle_random_OnError_EVENT_ENABLED /*!< OnError event of the component whistle_random is enabled (generated) */

/*
** ===================================================================
**     Method      :  whistle_random_Init (component RNG_LDD)
*/
/*!
**     @brief
**         Initializes the device according to design-time
**         configuration properties. Allocates memory for the device
**         data structure. 
**         This method can be called only once. Before the second call
**         of Init the Deinit method must be called first.
**     @param
**         UserDataPtr     - Pointer to device data
**                           structure pointer. This pointer will be
**                           passed to all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* whistle_random_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  whistle_random_GetRandomNumber (component RNG_LDD)
*/
/*!
**     @brief
**         This method gets the next random number generated by the RNG.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @param
**         Value           - Pointer to variable where random
**                           number will be stored.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_FAULT - only for RNG B-type: RNG failed.
**                           Use GetError() method to get error type. 
**                           ERR_NOTAVAIL - Seed was not generated since
**                           last reset. Call GenerateSeed() method -
**                           RNGB, or RNGA is stopped/sleeping.
*/
/* ===================================================================*/
LDD_TError whistle_random_GetRandomNumber(LDD_TDeviceData *DeviceDataPtr, uint32_t *Value);

/*
** ===================================================================
**     Method      :  whistle_random_SetEventMask (component RNG_LDD)
*/
/*!
**     @brief
**         This method masks the events of the interrupts generated by
**         errors or interrupts generated upon completion of seed and
**         self test modes in the RNGB.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @param
**         EventMask       - Value of the event mask. 
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Event mask not valid
*/
/* ===================================================================*/
LDD_TError whistle_random_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask);

/*
** ===================================================================
**     Method      :  whistle_random_GetEventMask (component RNG_LDD)
*/
/*!
**     @brief
**         This Methods returns the status of the interrupt error masks
**         and interrupt completion masks.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @return
**                         - Returns the masks currently set.
*/
/* ===================================================================*/
LDD_TEventMask whistle_random_GetEventMask(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  whistle_random_Start (component RNG_LDD)
*/
/*!
**     @brief
**         If RNGA is not started during initialization, use this
**         method to start random number generator.
**     @param
**         DeviceDataPtr   - Pointer to device data
**                           structure pointer returned by Init method. 
*/
/* ===================================================================*/
void whistle_random_Start(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  whistle_random_InsertEntropy (component RNG_LDD)
*/
/*!
**     @brief
**         Use this method to insert additional entropy to RNGA
**         (current time using highest precision possible, mouse and
**         keyboard motions...). 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
**     @param
**         Value           - New entropy value for RNGA.
*/
/* ===================================================================*/
void whistle_random_InsertEntropy(LDD_TDeviceData *DeviceDataPtr, uint32_t Value);

/*
** ===================================================================
**     Method      :  whistle_random_Main (component RNG_LDD)
*/
/*!
**     @brief
**         This method is available only in polling mode. If interrupt
**         service is disabled this method replaces the RNG interrupt
**         handler. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by Init method. 
*/
/* ===================================================================*/
void whistle_random_Main(LDD_TDeviceData *DeviceDataPtr);

/* END whistle_random. */

#endif
/* ifndef __whistle_random_H */
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
