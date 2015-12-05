/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTB_GPIO.c
**     Project     : ProcessorExpert
**     Processor   : MK20DN512VMC10
**     Component   : Init_GPIO
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-02-07, 11:29, # CodeGen: 57
**     Abstract    :
**          This file implements the GPIO (PTB) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PORTB_GPIO
**          Device                                         : PTB
**          Pins                                           : 
**            Pin 0                                        : Disabled
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
**            Pin 18                                       : Enabled
**              Pin                                        : TSI0_CH11/PTB18/CAN0_TX/FTM2_CH0/I2S0_TX_BCLK/FB_AD15/FTM2_QD_PHA
**              Pin signal                                 : DATA_SPI2_WP_B
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
**            Pin 19                                       : Enabled
**              Pin                                        : TSI0_CH12/PTB19/CAN0_RX/FTM2_CH1/I2S0_TX_FS/FB_OE_b/FTM2_QD_PHB
**              Pin signal                                 : DATA_SPI_HOLD_B
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
  /* GPIOB_PSOR: PTSO|=0x000C0000 */
  GPIOB_PSOR |= GPIO_PSOR_PTSO(0x000C0000);                                                   
  /* GPIOB_PCOR: PTCO&=~0x000C0000 */
  GPIOB_PCOR &= (uint32_t)~(uint32_t)(GPIO_PCOR_PTCO(0x000C0000));                                                   
  /* GPIOB_PDDR: PDD|=0x000C0000 */
  GPIOB_PDDR |= GPIO_PDDR_PDD(0x000C0000);                                                   
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
