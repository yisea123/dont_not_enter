/*HEADER**********************************************************************
*
* Copyright 2008 Freescale Semiconductor, Inc.
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
*   This file contains the task template list for this processor.
*
*
*END************************************************************************/

#include <mqx.h>
#include <bsp.h>
#include <lwmsgq.h>
#include "server.h"

uint32_t server_queue[sizeof(LWMSGQ_STRUCT)/sizeof(uint32_t) +
   NUM_MESSAGES * MSG_SIZE];
uint32_t client_queue[sizeof(LWMSGQ_STRUCT)/sizeof(uint32_t) +
   NUM_MESSAGES * MSG_SIZE];


const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{
   /* Task Index,   Function,    Stack,  Priority,  Name,       Attributes,          Param, Time Slice */
    { SERVER_TASK,  server_task, 2000,   8,         "server",   MQX_AUTO_START_TASK, 0,     0 },
    { CLIENT_TASK,  client_task, 1000,   8,         "client",   0,                   0,     0 },    
    { 0 }
};

/* EOF */
