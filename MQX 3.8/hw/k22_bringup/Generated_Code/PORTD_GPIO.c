/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PORTD_GPIO.c
**     Project     : ProcessorExpert
**     Processor   : MK20DN512VMC10
**     Component   : Init_GPIO
**     Version     : Component 01.003, Driver 01.03, CPU db: 3.00.000
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-02-07, 11:29, # CodeGen: 57
**     Abstract    :
**          This file implements the GPIO (PTD) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PORTD_GPIO
**          Device                                         : PTD
**          Pins                                           : 
**            Pin 0                                        : Disabled
**            Pin 1                                        : Disabled
**            Pin 2                                        : Disabled
**            Pin 3                                        : Disabled
**            Pin 4                                        : Disabled
**            Pin 5                                        : Enabled
**              Pin                                        : ADC0_SE6b/PTD5/SPI0_PCS2/UART0_CTS_b/UART0_COL_b/FTM0_CH5/FB_AD1/EWM_OUT_b
**              Pin signal                                 : MFI_RST_B
**              Pin output                                 : Enabled
**              Output value                               : 1
**              Open drain enable                          : No initialization
**              Pull enable                                : No initialization
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : High
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 6                                        : Disabled
**            Pin 7                                        : Disabled
**            Pin 8                                        : Disabled
**            Pin 9                                        : Disabled
**            Pin 10                                       : Disabled
**            Pin 11                                       : Disabled
**            Pin 12                                       : Enabled
**              Pin                                        : PTD12/SPI2_SCK/SDHC0_D4/FB_AD7/FB_A20
**              Pin signal                                 : LED0
**              Pin output                                 : Enabled
**              Output value                               : 1
**              Open drain enable                          : No initialization
**              Pull enable                                : No initialization
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : High
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 13                                       : Enabled
**              Pin                                        : PTD13/SPI2_SOUT/SDHC0_D5/FB_AD6/FB_A21
**              Pin signal                                 : LED1
**              Pin output                                 : Enabled
**              Output value                               : 0
**              Open drain enable                          : No initialization
**              Pull enable                                : No initialization
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : High
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Pin 14                                       : Enabled
**              Pin                                        : PTD14/SPI2_SIN/SDHC0_D6/FB_AD5/FB_A22
**              Pin signal                                 : LED2
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
**            Pin 15                                       : Enabled
**              Pin                                        : PTD15/SPI2_PCS1/SDHC0_D7/FB_RW_b/FB_A23
**              Pin signal                                 : LED3
**              Pin output                                 : Enabled
**              Output value                               : 0
**              Open drain enable                          : No initialization
**              Pull enable                                : No initialization
**              Pull select                                : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : High
**              Interrupt configuration                    : No initialization
**              Digital filter enable                      : No initialization
**              Passive filter enable                      : No initialization
**              Lock                                       : No initialization
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTD
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PORTD_GPIO_Init(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE PORTD_GPIO. */

#include "PORTD_GPIO.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  PORTD_GPIO_Init (component Init_GPIO)
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
void PORTD_GPIO_Init(void)
{
  /* GPIOD_PSOR: PTSO&=~0xA000,PTSO|=0x5020 */
  GPIOD_PSOR = (uint32_t)((GPIOD_PSOR & (uint32_t)~(uint32_t)(
                GPIO_PSOR_PTSO(0xA000)
               )) | (uint32_t)(
                GPIO_PSOR_PTSO(0x5020)
               ));                                                  
  /* GPIOD_PCOR: PTCO&=~0x5020,PTCO|=0xA000 */
  GPIOD_PCOR = (uint32_t)((GPIOD_PCOR & (uint32_t)~(uint32_t)(
                GPIO_PCOR_PTCO(0x5020)
               )) | (uint32_t)(
                GPIO_PCOR_PTCO(0xA000)
               ));                                                  
  /* GPIOD_PDDR: PDD|=0xF020 */
  GPIOD_PDDR |= GPIO_PDDR_PDD(0xF020);                                                   
}


/* END PORTD_GPIO. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
