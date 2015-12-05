/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
* Copyright 2004-2008 Embedded Access Inc.
* Copyright 1989-2008 ARC International
*
* This software is owned or controlled by Freescale Semiconductor.
* Use of this software is governed by the Freescale MQX RTOS License
* distributed with this Material.
* See the MQX_RTOS_LICENSE file distributed for more details.
*
* Brief License Summary:
* This software is provided in source form for you to use free of charge,
* but it is not open source software. You are allowed to use this software
* but you cannot redistribute it or derivative works of it in source form.
* The software may be used only in connection with a product containing
* a Freescale microprocessor, microcontroller, or digital signal processor.
* See license agreement file for full license terms including other
* restrictions.
*****************************************************************************
*
* Comments:
*
*   This file contains the RTCS shell.
*
*
*END************************************************************************/

#include <ctype.h>
#include <string.h>
#include <mqx.h>
#include "shell.h"
#if SHELLCFG_USES_RTCS

#include <rtcs.h>
#include "sh_rtcs.h"

#define SHELL_TFTPD_PRIO        7
#define SHELL_TFTPD_STACK       2500

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name :  Shell_TFTPd
*  Returned Value:  none
*  Comments  :  SHELL utility to TFTP to or from a host
*  Usage:  tftp host get source [destination] [mode]
*
*END*-----------------------------------------------------------------*/

int32_t  Shell_TFTPd(int32_t argc, char *argv[] )
{
   uint32_t  result;
   bool  print_usage, shorthelp = FALSE;
   int32_t   return_code = SHELL_EXIT_SUCCESS;

   print_usage = Shell_check_help_request(argc, argv, &shorthelp );

   if (!print_usage)  {
      if (argc == 2)  {
         if (strcmp(argv[1], "start") == 0)  {

            result = TFTPSRV_init("TFTP_server", SHELL_TFTPD_PRIO, SHELL_TFTPD_STACK );
            if (result ==  0)  {
               printf("TFTP Server Started.\n");
            } else  {
               printf("Unable to start TFTP Server, error = 0x%x\n",result);
               return_code = SHELL_EXIT_ERROR;
            }
         } else if (strcmp(argv[1], "stop") == 0)  {
            result = TFTPSRV_stop();
            if (result ==  0)  {
               printf("TFTP Server Stopped.\n");
            } else  {
               printf("Unable to stop TFTP Server, error = 0x%x\n",result);
               return_code = SHELL_EXIT_ERROR;
            }
         } else  {
         printf("Error, %s invoked with incorrect option\n", argv[0]);
            print_usage = TRUE;
         }
      } else  {
         printf("Error, %s invoked with incorrect number of arguments\n", argv[0]);
         print_usage = TRUE;
      }
   }

   if (print_usage)  {
      if (shorthelp)  {
         printf("%s [start|stop]\n", argv[0]);
      } else  {
         printf("Usage: %s [start|stop]\n",argv[0]);
      }
   }
   return return_code;
} /* Endbody */

#endif /* SHELLCFG_USES_RTCS */

/* EOF */
