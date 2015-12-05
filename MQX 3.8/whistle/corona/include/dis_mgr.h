/*
 * dis_mgr.h
 *
 *  Created on: Apr 11, 2013
 *      Author: Chris
 */

#ifndef DIS_MGR_H_
#define DIS_MGR_H_

#include "app_errors.h"

typedef enum DISMGR_pattern_e
{
	DISMGR_PATTERN_OFF,                             // 0
    DISMGR_PATTERN_BATT_LOW_REPEAT,
    DISMGR_PATTERN_BATT_LOW_STOP,
    DISMGR_PATTERN_BATT_LOW_ONESHOT,
    DISMGR_PATTERN_BATT_LEVEL_ONESHOT,
    DISMGR_PATTERN_BATT_CHARGE_CHARGING_REPEAT,     // 5
    DISMGR_PATTERN_BATT_CHARGE_CHARGED_REPEAT,
    DISMGR_PATTERN_BATT_CHARGE_STOP,
    DISMGR_PATTERN_SHIP_MODE_ONESHOT,
    DISMGR_PATTERN_POWER_ON_ONESHOT,
    DISMGR_PATTERN_BT_PAIRING_REPEAT,               // 10
    DISMGR_PATTERN_BT_PAIRING_SUCCEEDED_STOP,
    DISMGR_PATTERN_BT_PAIRING_FAILED_STOP,
    DISMGR_PATTERN_BT_CONNECTING_REPEAT,
    DISMGR_PATTERN_BT_CONNECTING_SUCCEEDED_STOP,
    DISMGR_PATTERN_BT_CONNECTING_FAILED_STOP,       // 15
    DISMGR_PATTERN_MAN_SYNC_REPEAT,
    DISMGR_PATTERN_MAN_SYNC_SUCCEEDED_STOP,
    DISMGR_PATTERN_MAN_SYNC_FAILED_STOP,
    DISMGR_PATTERN_MAN_SYNC_START_ONESHOT,
    DISMGR_PATTERN_MAN_SYNC_SUCCEEDED_ONESHOT,      // 20
    DISMGR_PATTERN_MAN_SYNC_FAILED_ONESHOT,
    DISMGR_PATTERN_RGB_DISPLAY
} DISMGR_pattern_t;

void DISMGR_init(void);
err_t DISMGR_run_pattern(DISMGR_pattern_t pattern);
err_t DISMGR_display_battery( uint_8 pct );
void DIS_tsk(uint_32 dummy);
void DISMGR_stop_timer(void);
void DISMGR_destroy(void);

#endif /* DIS_MGR_H_ */
