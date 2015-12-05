/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTE_GPIO.h
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : Init_GPIO
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-03-28, 10:13, # CodeGen: 73
**     Abstract    :
**          This file implements the GPIO (PTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PORTE_GPIO
**          Device                                         : PTE
**          Pins                                           : 
**            Pin 0                                        : Disabled
**            Pin 1                                        : Enabled
**              Pin                                        : ADC1_SE5a/PTE1/LLWU_P0/SPI1_SOUT/UART1_RX/SDHC0_D0/FB_AD26/I2C1_SCL/SPI1_SIN
**              Pin signal                                 : BUTTON_NEW
**              Pin output                                 : Disabled
**              Output value                               : No initialization
**              Open drain enable                          : No initialization
**              Pull enable                                : Enabled
**              Pull select                                : Pull Up
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt configuration                    : Interrupt on falling
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 2                                        : Enabled
**              Pin                                        : ADC1_SE6a/PTE2/LLWU_P1/SPI1_SCK/UART1_CTS_b/SDHC0_DCLK/FB_AD25
**              Pin signal                                 : PGOOD_B
**              Pin output                                 : Disabled
**              Output value                               : No initialization
**              Open drain enable                          : No initialization
**              Pull enable                                : Enabled
**              Pull select                                : Pull Up
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt configuration                    : Interrupt on falling
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 3                                        : Disabled
**            Pin 4                                        : Disabled
**            Pin 5                                        : Disabled
**            Pin 6                                        : Disabled
**            Pin 24                                       : Disabled
**            Pin 25                                       : Disabled
**            Pin 26                                       : Disabled
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTE
**              Interrupt request                          : Enabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : isr_PORTE
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PORTE_GPIO_Init(void);
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PORTE_GPIO.h
** @version 01.03
** @date 2013-03-28, 10:13, # CodeGen: 73
** @brief
**          This file implements the GPIO (PTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup PORTE_GPIO_module PORTE_GPIO module documentation
**  @{
*/         

#ifndef PORTE_GPIO_H_
#define PORTE_GPIO_H_

/* MODULE PORTE_GPIO. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  PORTE_GPIO_Init (component Init_GPIO)
**     Description :
**         This method initializes registers of the GPIO module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTE_GPIO_Init(void);
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see PORTE_GPIO.c file for more information).
** ===================================================================
*/
PE_ISR(isr_PORTE);


/* END PORTE_GPIO. */
#endif /* #ifndef __PORTE_GPIO_H_ */
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
