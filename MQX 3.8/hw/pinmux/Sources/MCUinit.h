/*
** ###################################################################
**     This code is generated by the Device Initialization Tool.
**     It is overwritten during code generation.
**     USER MODIFICATION ARE PRESERVED ONLY INSIDE EXPLICITLY MARKED SECTIONS.
**
**     Project     : DeviceInitialization
**     Processor   : MK20DX256ZVLQ10
**     Version     : Component 01.000, Driver 01.03, CPU db: 3.00.001
**     Datasheet   : K20P144M100SF2RM, Rev. 5, 8 May 2011
**     Compiler    : CodeWarrior ARM C Compiler
**     Date/Time   : 2013-01-07, 16:45, # CodeGen: 24
**     Abstract    :
**
**     Contents    :
**         Function "MCU_init" initializes selected peripherals
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################
*/

#ifndef __DeviceInitialization_H
#define __DeviceInitialization_H 1

/* Include shared modules, which are used for whole project */


/* User declarations and definitions */
/*   Code, declarations and definitions here will be preserved during code generation */
/* End of user declarations and definitions */


#if !defined(PE_ISR)
  #define PE_ISR(ISR_name) void ISR_name(void)
#endif

void __init_hardware(void);
/*
** ===================================================================
**     Method      :  __init_hardware (component MK20N512LQ100)
**
**     Description :
**         Initialization code for CPU core and a clock source.
** ===================================================================
*/


void MCU_init(void);
/*
** ===================================================================
**     Method      :  MCU_init (component MK20N512LQ100)
**
**     Description :
**         Device initialization code for selected peripherals.
** ===================================================================
*/


PE_ISR(isr_default);
/*
** ===================================================================
**     Interrupt handler : isr_default
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_NMI);
/*
** ===================================================================
**     Interrupt handler : isrINT_NMI
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_I2C1);
/*
** ===================================================================
**     Interrupt handler : isrINT_I2C1
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_SPI0);
/*
** ===================================================================
**     Interrupt handler : isrINT_SPI0
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_SPI1);
/*
** ===================================================================
**     Interrupt handler : isrINT_SPI1
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_UART2_RX_TX);
/*
** ===================================================================
**     Interrupt handler : isrINT_UART2_RX_TX
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_UART2_ERR);
/*
** ===================================================================
**     Interrupt handler : isrINT_UART2_ERR
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_UART5_RX_TX);
/*
** ===================================================================
**     Interrupt handler : isrINT_UART5_RX_TX
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_UART5_ERR);
/*
** ===================================================================
**     Interrupt handler : isrINT_UART5_ERR
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_PORTA);
/*
** ===================================================================
**     Interrupt handler : isrINT_PORTA
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_PORTC);
/*
** ===================================================================
**     Interrupt handler : isrINT_PORTC
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_PORTD);
/*
** ===================================================================
**     Interrupt handler : isrINT_PORTD
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/



PE_ISR(isrINT_PORTE__WIFI_INT);
/*
** ===================================================================
**     Interrupt handler : isrINT_PORTE__WIFI_INT
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/






/* END DeviceInitialization */

#endif
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.3 [05.01]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
