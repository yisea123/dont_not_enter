////////////////////////////////////////////////////////////////////////////////
//! \addtogroup drivers
//! \ingroup corona
//! @{
//
// Copyright (c) 2013 Whistle Labs
//
// Whistle Labs
// Proprietary and Confidential
//
// This source code and the algorithms implemented therein constitute
// confidential information and may comprise trade secrets of Whistle Labs
// or its associates.
//
//! \file a4100_wifi.h
//! \brief A4100 WIFI driver header.
//! \version version 0.1
//! \date Jan, 2013
//! \author chris@whistle.com
////////////////////////////////////////////////////////////////////////////////

#ifndef A4100_WIFI_H_
#define A4100_WIFI_H_

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "PE_Types.h"
#include "corona_errors.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

// SPI Command Types for the AR4100
#define A4100_REG_READ_MASK			0xC000
#define A4100_REG_WRITE_MASK		0x4000
#define A4100_MAILBOX_READ_MASK		0x8000
#define A4100_MAILBOX_WRITE_MASK	0x0000

// SPI Register Offsets
#define A4100_SPI_CFG				0x0400

////////////////////////////////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////////////////////////////////
corona_err_t a4100_wifi_test(void);
corona_err_t a4100_wifi_comm_ok(void);

#endif /* A4100_WIFI_H_ */
////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
