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
//! \file adc_sense.h
//! \brief ADC driver header.
//! \version version 0.1
//! \date Jan, 2013
//! \author ernie@whistle.com
////////////////////////////////////////////////////////////////////////////////

#ifndef ADC_SENSE_H_
#define ADC_SENSE_H_

////////////////////////////////////////////////////////////////////////////////
// Includes
////////////////////////////////////////////////////////////////////////////////
#include "PE_Types.h"
#include "corona_errors.h"

////////////////////////////////////////////////////////////////////////////////
// Structures
////////////////////////////////////////////////////////////////////////////////
/*
 *   Cable type corresponds to UID pin being sampled by ADC.
 */
typedef enum cable_type
{
    CABLE_BURNIN      = 27990,  // 2.2kohm
    CABLE_FACTORY_DBG = 35950,  // 3.6kohm
    CABLE_CUSTOMER    = 65500   // open, infinite, 16-bit saturation
    
}cable_t;

////////////////////////////////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////////////////////////////////
corona_err_t adc_sense_test(void);
corona_err_t adc_sense(uint32_t channelIdx, uint16_t *pRaw, uint16_t *pNatural);
uint16_t adc_ok(void);
cable_t adc_get_cable(const uint32_t uid_counts);

#endif /* ADC_SENSE_H_ */
////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}
