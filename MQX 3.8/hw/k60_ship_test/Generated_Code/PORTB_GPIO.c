/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTB_GPIO.c
**     Project     : ProcessorExpert
**     Processor   : MK60DN512VMC10
**     Component   : Init_GPIO
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-03-05, 15:42, # CodeGen: 30
**     Abstract    :
**          This file implements the GPIO (PTB) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PORTB_GPIO
**          Device                                         : PTB
**          Pins                                           : 
**            Pin 0                                        : Enabled
**              Pin                                        : ADC0_SE8/ADC1_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/RMII0_MDIO/MII0_MDIO/FTM1_QD_PHA
**              Pin signal                                 : BT_PWDN_B
**              Pin output                                 : Enabled
**              Output value                               : 0
**              Open drain enable                          : No initialization
**              Pull enable                                : Disabled
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 1                                        : Disabled
**            Pin 2                                        : Disabled
**            Pin 3                                        : Disabled
**            Pin 6                                        : Disabled
**            Pin 7                                        : Disabled
**            Pin 8                                        : Disabled
**            Pin 9                                        : Disabled
**            Pin 10                                       : Disabled
**            Pin 11                                       : Disabled
**            Pin 16                                       : Disabled
**            Pin 17                                       : Disabled
**            Pin 18                                       : Disabled
**            Pin 19                                       : Disabled
**            Pin 20                                       : Disabled
**            Pin 21                                       : Disabled
**            Pin 22                                       : Disabled
**            Pin 23                                       : Disabled
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTB
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PORTB_GPIO_Init(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PORTB_GPIO. */

#include "PORTB_GPIO.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  PORTB_GPIO_Init (component Init_GPIO)
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
void PORTB_GPIO_Init(void)
{
  /* GPIOB_PSOR: PTSO&=~1 */
  GPIOB_PSOR &= (uint32_t)~(uint32_t)(GPIO_PSOR_PTSO(0x01));                                                   
  /* GPIOB_PCOR: PTCO|=1 */
  GPIOB_PCOR |= GPIO_PCOR_PTCO(0x01);                                                   
  /* GPIOB_PDDR: PDD|=1 */
  GPIOB_PDDR |= GPIO_PDDR_PDD(0x01);                                                   
}


/* END PORTB_GPIO. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
