/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : ADC0_Vsense.h
**     Project     : ProcessorExpert
**     Processor   : MK20DN512VMC10
**     Component   : ADC_LDD
**     Version     : Component 01.115, Driver 01.07, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-02-15, 14:02, # CodeGen: 62
**     Abstract    :
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : ADC0_Vsense
**          A/D converter                                  : ADC0
**          Discontinuous mode                             : no
**          Converter mode                                 : Sequential
**          Interrupt service/event                        : Disabled
**          A/D channel list                               : 2
**            Channel 0                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : ADC0_SE16/CMP1_IN2/ADC0_SE21
**                  A/D channel (pin) signal               : Corona_VBat
**            Channel 1                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : ADC1_SE16/CMP2_IN2/ADC0_SE22
**                  A/D channel (pin) signal               : Corona_UID
**          Static sample groups                           : Disabled
**          A/D resolution                                 : 16 bits
**          Low-power mode                                 : Enabled
**          High-speed conversion mode                     : Disabled
**          Asynchro clock output                          : Disabled
**          Sample time                                    : 4 clock periods
**          Number of conversions                          : 1
**          Conversion time                                : 10.416667 �s
**          ADC clock                                      : 2.399 MHz (416.667 ns)
**          Single conversion time - Single-ended          : 17.738 us
**          Single conversion time - Differential          : 21.488 us
**          Additional conversion time - Single-ended      : 10.416 us
**          Additional conversion time - Differential      : 14.166 us
**          Result type                                    : unsigned 16 bits, right justified
**          Trigger                                        : Disabled
**          Voltage reference                              : 
**            High voltage reference                       : 
**              Volt. ref. pin                             : VREFH
**              Volt. ref pin signal                       : 
**            Low voltage reference                        : 
**              Volt. ref. pin                             : VREFL
**              Volt. ref pin signal                       : 
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMeasurementComplete                      : Disabled
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
**         Init                         - LDD_TDeviceData* ADC0_Vsense_Init(LDD_TUserData *UserDataPtr);
**         Deinit                       - void ADC0_Vsense_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable                       - LDD_TError ADC0_Vsense_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable                      - LDD_TError ADC0_Vsense_Disable(LDD_TDeviceData *DeviceDataPtr);
**         StartSingleMeasurement       - LDD_TError ADC0_Vsense_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         StartLoopMeasurement         - LDD_TError ADC0_Vsense_StartLoopMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         CancelMeasurement            - LDD_TError ADC0_Vsense_CancelMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         CreateSampleGroup            - LDD_TError ADC0_Vsense_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr,...
**         GetMeasuredValues            - LDD_TError ADC0_Vsense_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr,...
**         GetMeasurementCompleteStatus - bool ADC0_Vsense_GetMeasurementCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
**         StartCalibration             - LDD_TError ADC0_Vsense_StartCalibration(LDD_TDeviceData *DeviceDataPtr);
**         GetCalibrationResultStatus   - LDD_TError ADC0_Vsense_GetCalibrationResultStatus(LDD_TDeviceData...
**         SetOperationMode             - LDD_TError ADC0_Vsense_SetOperationMode(LDD_TDeviceData *DeviceDataPtr,...
**         GetDriverState               - LDD_TDriverState ADC0_Vsense_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __ADC0_Vsense_H
#define __ADC0_Vsense_H

/* MODULE ADC0_Vsense. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "IO_Map.h"
#include "Cpu.h"
#include "ADC_PDD.h"
#include "PE_LDD.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define ADC0_Vsense_PRPH_BASE_ADDRESS  0x4003B000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define ADC0_Vsense_Init_METHOD_ENABLED
#define ADC0_Vsense_Deinit_METHOD_ENABLED
#define ADC0_Vsense_Enable_METHOD_ENABLED
#define ADC0_Vsense_Disable_METHOD_ENABLED
#define ADC0_Vsense_StartSingleMeasurement_METHOD_ENABLED
#define ADC0_Vsense_StartLoopMeasurement_METHOD_ENABLED
#define ADC0_Vsense_CancelMeasurement_METHOD_ENABLED
#define ADC0_Vsense_CreateSampleGroup_METHOD_ENABLED
#define ADC0_Vsense_GetMeasuredValues_METHOD_ENABLED
#define ADC0_Vsense_GetMeasurementCompleteStatus_METHOD_ENABLED
#define ADC0_Vsense_StartCalibration_METHOD_ENABLED
#define ADC0_Vsense_GetCalibrationResultStatus_METHOD_ENABLED
#define ADC0_Vsense_SetOperationMode_METHOD_ENABLED
#define ADC0_Vsense_GetDriverState_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */


/* Component specific public constants */

/* Driver mode */

/* A/D resolution of the component (the count of bits) */
#define ADC0_Vsense_ADC_RESOLUTION      16

/* Name of AD channel. If the "A/D channel (pin) signal" property in the channel
   pin group is not empty the constant "ComponentName_Signal" with the value of the channel
   index is generated, where the ComponentName = value of the "Component name" property
   and "Signal" is the value of the " A/D channel (pin) signal" property. This constant
   can be used in the method CreateSampleGroup() to specify required channel.
   (See ComponentName_TSample struct) */
#define ADC0_Vsense_Corona_VBat         0U
#define ADC0_Vsense_Corona_UID          1U

/* This constant contains the number of channels in the "A/D channel list"
   group */
#define ADC0_Vsense_CHANNEL_COUNT       2u

/* This constant can be used in the sample array to create a gap in sample group.
   It is intended to disable a measurement of a sample */
#define ADC0_Vsense_NO_CHANNEL          0x1FU



/* HW specific public constants */

/* Maximal number of samples in one sample group. This constant is HW specific.
   The CreateSampleGroup() method returns ERR_PARAM_SAMPLE_COUNT if the SampleCount parameter
   is greater then this constant. The value of this constant depends on the number
   of samples the HW is capable to measure in one measurement cycle. */
#define ADC0_Vsense_MAX_HW_SAMPLE_COUNT 1U

/* This constant informs about the actual width of results. */
#define ADC0_Vsense_RESULT_WIDTH        16U

/* This parameter informs about the type of results. */
#define ADC0_Vsense_RESULT_TYPE_UNSIGNED

/* Measurement result data type. Definition of the type depends
   on "Result type" property value. */
typedef uint16_t ADC0_Vsense_TResultData;


LDD_TDeviceData* ADC0_Vsense_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_Init (component ADC_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Device data structure pointer.
** ===================================================================
*/

void ADC0_Vsense_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_Deinit (component ADC_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError ADC0_Vsense_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_Enable (component ADC_LDD)
**
**     Description :
**         Enables ADC device. If possible, this method switches on A/D
**         converter device, voltage reference, etc. This method is
**         intended to be used together with <Disable()> method to
**         temporary switch On/Off the device after the device is
**         initialized. This method is required if the <Enabled in init.
**         code> property is set to "no" value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
** ===================================================================
*/

LDD_TError ADC0_Vsense_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_Disable (component ADC_LDD)
**
**     Description :
**         Disables the ADC device. If possible, this method switches
**         off A/D converter device, voltage reference, etc. (for
**         example to avoid power consumption and possible interference).
**         When the device is disabled, some component methods should
**         not be called. If so, error ERR_DISABLED is reported. This
**         method is intended to be used together with <Enable()>
**         method to temporary switch On/Off the device after the
**         device is initialized. This method is not required. The
**         <Deinit()> method can be used to switch off and uninstall
**         the device.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
** ===================================================================
*/

LDD_TError ADC0_Vsense_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_StartSingleMeasurement (component ADC_LDD)
**
**     Description :
**         This method starts one measurement of the selected group of
**         samples and exits immediately. The group of samples for
**         measurement is specified by preceding call to
**         <SelectSampleGroup()> or <SelectSampleGroup()> method. The
**         <OnMeasurementComplete() > event is invoked after the
**         measurement is done and the event is enabled. The state of
**         the measurement can be also polled by the
**         <GetMeasurementCompleteStatus()> method. Results of the
**         measurement can be read by the <GetMeasuredValues()> method.
**         The <Discontinuous mode> doesn't support this method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A measurement is in progress 
** ===================================================================
*/

LDD_TError ADC0_Vsense_StartLoopMeasurement(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_StartLoopMeasurement (component ADC_LDD)
**
**     Description :
**         This method starts periodic measurement of the selected
**         group of and exits immediately. The group of samples for
**         measurement is specified by preceding call to
**         <SelectSampleGroup()> or <SelectSampleGroup()> method. The
**         <OnMeasurementComplete()> event is invoked after the each
**         measurement is done and the event is enabled. The state of
**         the measurement can be also polled by the
**         <GetMeasurementCompleteStatus()> method. Results of the
**         measurement can be read by the <GetMeasuredValues()> method.
**         This method is available only if HW supports loop
**         measurement. The <Discontinuous mode> doesn't support this
**         method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - Measurement is in progress 
** ===================================================================
*/

LDD_TError ADC0_Vsense_CancelMeasurement(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_CancelMeasurement (component ADC_LDD)
**
**     Description :
**         This method cancels the measurement in progress. Typically
**         the OnMeasurementComplete() event is not invoked for
**         cancelled measurement.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
** ===================================================================
*/

LDD_TError ADC0_Vsense_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr, LDD_ADC_TSample *SampleGroupPtr, uint8_t SampleCount);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_CreateSampleGroup (component ADC_LDD)
**
**     Description :
**         This method prepares HW for next measurement according to
**         array of samples defined during run-time. The array of
**         samples should be prepared prior to calling this method.
**         Pointer to the array is passed into this method in parameter
**         SampleGroupPtr. The number of samples is defined by
**         parameter SampleCount. Once any group is prepared, the
**         measurement can be started multiple times. Note: This method
**         works only with the sample groups defined during run-time.
**         For design-time defined groups use <SelectSampleGroup()>
**         method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * SampleGroupPtr  - Pointer to the
**                           sample definition array. This array can be
**                           released as soon as the method ends.
**         SampleCount     - Number of items in the
**                           sample definition array. Must be less than
**                           or equal to
**                           ComponentName_MAX_HW_SAMPLE_COUNT.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_INDEX - Channel index in
**                           SampleGroup structure is out of range
**                           ERR_PARAM_SAMPLE_COUNT - SampleCount
**                           variable value is out of range
**                           ERR_BUSY - Measurement is in progress 
** ===================================================================
*/

LDD_TError ADC0_Vsense_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_GetMeasuredValues (component ADC_LDD)
**
**     Description :
**         This method copies results of the last measurement to the
**         user supplied buffer. Data size depends on the size of
**         measured sample group (see <SelectSampleGroup()> or
**         <CreateSampleGroup()> method). Data representation is
**         defined by the <Result type> property. Typically this method
**         is called from <OnMeasurementComplete> event to get results
**         of the last measurement.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to the start of the
**                           buffer for new results. Count of stored
**                           measured values equals to the count of the
**                           samples in the active sample group. It is
**                           in the user responsibility to provide
**                           buffer with appropriate size.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
** ===================================================================
*/

bool ADC0_Vsense_GetMeasurementCompleteStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_GetMeasurementCompleteStatus (component ADC_LDD)
**
**     Description :
**         Returns whether the measurement is done and the results can
**         be read by the user. It can be used to poll the state of
**         measurement if <Interrupt service/event> is disabled or if
**         <OnMeasurementComplete> event is disabled by the
**         <SetEventMask()> methods.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code
**                           true - Measurement is done
**                           false - Measurement is in progress
** ===================================================================
*/

LDD_TError ADC0_Vsense_StartCalibration(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_StartCalibration (component ADC_LDD)
**
**     Description :
**         This method starts self calibration process. Calibration is
**         typically used to remove the effects of the gain and offset
**         from a specific reading.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A conversion is already running 
** ===================================================================
*/

LDD_TError ADC0_Vsense_GetCalibrationResultStatus(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_GetCalibrationResultStatus (component ADC_LDD)
**
**     Description :
**         This method should be used for check the last calibration
**         result. If calibration completed normally the method finish
**         calibration process by writing gain calibration values.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code
**                           ERR_OK - OK 
**                           ERR_FAILED - Last calibration hasn't been
**                           finished correctly
** ===================================================================
*/

LDD_TError ADC0_Vsense_SetOperationMode(LDD_TDeviceData *DeviceDataPtr, LDD_TDriverOperationMode OperationMode, LDD_TCallback ModeChangeCallback, LDD_TCallbackParam *ModeChangeCallbackParamPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_SetOperationMode (component ADC_LDD)
**
**     Description :
**         This method requests to change the component's operation
**         mode. Upon a request to change the operation mode, the
**         component will finish a pending job first and then notify a
**         caller that an operation mode has been changed. When no job
**         is pending (ERR_OK), the component changes an operation mode
**         immediately and notifies a caller about this change. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         OperationMode   - Requested driver
**                           operation mode.
**         ModeChangeCallback - Callback to
**                           notify the upper layer once a mode has been
**                           changed.
**       * ModeChangeCallbackParamPtr 
**                           - Pointer to callback parameter to notify
**                           the upper layer once a mode has been
**                           changed.
**     Returns     :
**         ---             - Error code, possible codes: ERR_OK - The
**                           change operation mode request has been
**                           accepted, callback will notify an
**                           application as soon as the mode is changed.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration.
**                           ERR_DISABLED - This component is disabled
**                           by user. ERR_PARAM_MODE - Invalid operation
**                           mode. ERR_FAILED - Job is running and the
**                           driver can't cancel the job by itself (job
**                           has no implicit termination, explicit
**                           cancelation is needed). The driver has
**                           rejected the change operation mode request.
**                           This error is returned if continuous job is
**                           running. Such job can be started by
**                           <StartLoopMeasurement> or
**                           <StartLoopTriggeredMeasurement> method and
**                           it can be canceled by <CancelMeasurement>
**                           method. After the termination, this
**                           <SetOperationMode> method performs the
**                           operation mode change. ERR_BUSY - Job is
**                           running and the driver can't detect job end
**                           by itself. The end of the job can be
**                           detected by method <GetDriverState>. This
**                           error is returned if single job is running
**                           and <Interrupt service/event> is disabled.
**                           Such job can be started by
**                           <StartSingleMeasurement> method.
** ===================================================================
*/

LDD_TDriverState ADC0_Vsense_GetDriverState(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  ADC0_Vsense_GetDriverState (component ADC_LDD)
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
**                           PE_LDD_DRIVER_DISABLED_IN_CLOCK_CONFIGURATIO
**                           N - 1 - Driver is disabled in the current
**                           mode; 0 - Driver is enabled in the current
**                           mode.  
**                           PE_LDD_DRIVER_DISABLED_BY_USER - 1 - Driver
**                           is disabled by the user; 0 - Driver is
**                           enabled by the user.        
**                           PE_LDD_DRIVER_BUSY - 1 - Driver is the BUSY
**                           state; 0 - Driver is in the IDLE state.
** ===================================================================
*/

/* END ADC0_Vsense. */

#endif
/* ifndef __ADC0_Vsense_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
