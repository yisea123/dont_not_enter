/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTC_GPIO.c
**     Project     : ProcessorExpert
**     Processor   : MK20DN512VMC10
**     Component   : Init_GPIO
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-01-24, 16:42, # CodeGen: 1
**     Abstract    :
**          This file implements the GPIO (PTC) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PTC_GPIO
**          Device                                         : PTC
**          Pins                                           : 
**            Pin 0                                        : Disabled
**            Pin 1                                        : Disabled
**            Pin 2                                        : Disabled
**            Pin 3                                        : Disabled
**            Pin 4                                        : Disabled
**            Pin 5                                        : Disabled
**            Pin 6                                        : Disabled
**            Pin 7                                        : Disabled
**            Pin 8                                        : Disabled
**            Pin 9                                        : Disabled
**            Pin 10                                       : Disabled
**            Pin 11                                       : Disabled
**            Pin 12                                       : Disabled
**            Pin 13                                       : Disabled
**            Pin 14                                       : Disabled
**            Pin 15                                       : Disabled
**            Pin 16                                       : Enabled
**              Pin                                        : PTC16/CAN1_RX/UART3_RX/FB_CS5_b/FB_TSIZ1/FB_BE23_16_b
**              Pin signal                                 : EN_26MHz
**              Pin output                                 : Enabled
**              Output value                               : 1
**              Open drain enable                          : No initialization
**              Pull enable                                : No initialization
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 17                                       : Disabled
**            Pin 18                                       : Disabled
**            Pin 19                                       : Disabled
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTC
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PTC_GPIO_Init(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PTC_GPIO. */

#include "PTC_GPIO.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  PTC_GPIO_Init (component Init_GPIO)
**
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
void PTC_GPIO_Init(void)
{
  /* GPIOC_PSOR: PTSO|=0x00010000 */
  GPIOC_PSOR |= GPIO_PSOR_PTSO(0x00010000);                                                   
  /* GPIOC_PCOR: PTCO&=~0x00010000 */
  GPIOC_PCOR &= (uint32_t)~(uint32_t)(GPIO_PCOR_PTCO(0x00010000));                                                   
  /* GPIOC_PDDR: PDD|=0x00010000 */
  GPIOC_PDDR |= GPIO_PDDR_PDD(0x00010000);                                                   
}


/* END PTC_GPIO. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
