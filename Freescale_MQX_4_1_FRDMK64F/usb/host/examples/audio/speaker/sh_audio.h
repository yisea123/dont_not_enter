/*HEADER**********************************************************************
*
* Copyright 2010 Freescale Semiconductor, Inc.
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
*   This file contains the definitions of constants and structures
*   required for playing and recording audio.
*
*
*END************************************************************************/
#ifndef __sh_audio_h_
#define __sh_audio_h_
#include <mqx.h>
#include <wav.h>
#include <fio.h>

extern int32_t Shell_play(int32_t argc, char *argv[]);
extern int32_t Shell_pause_audio(int32_t argc, char *argv[]);
extern int32_t Shell_mute(int32_t argc, char *argv[]);
extern int32_t Shell_increase_volume(int32_t argc, char *argv[]);
extern int32_t Shell_decrease_volume(int32_t argc,char *argv[]);
#endif
/* EOF */
