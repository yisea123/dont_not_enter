/*
 * fwu_mgr_priv.h
 *
 *  Created on: May 8th, 2013
 *      Author: Rob Philip
 */

#ifndef FWU_MGR_PRIV_H_
#define FWU_MGR_PRIV_H_

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "psptypes.h"
#include "app_errors.h"
#include <mqx.h>

////////////////////////////////////////////////////////////////////////////////
// Defines
////////////////////////////////////////////////////////////////////////////////

enum 
{
    FWU_BOOT2A_OFFSET = 0,
    FWU_BOOT2B_OFFSET = 1,
    FWU_APP_OFFSET    = 2,
    FWU_BOOT1_OFFSET  = 3,
    FWU_MAX_OFFSETS
};

////////////////////////////////////////////////////////////////////////////////
// Structs
////////////////////////////////////////////////////////////////////////////////

typedef struct 
{
    uint8_t boot_flags[FWU_MAX_OFFSETS];
} FWU_PERSISTENT_SPI_T;



////////////////////////////////////////////////////////////////////////////////
// Externs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Structures
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// FWUMGR's Private Declarations
////////////////////////////////////////////////////////////////////////////////

#endif /* FWU_MGR_PRIV_H_ */
