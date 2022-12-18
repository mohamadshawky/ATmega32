/*
 * WDT_interface.h
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */


#ifndef MCAL_WDT_INTERFACE_H_
#define MCAL_WDT_INTERFACE_H_

#include "WDT_private.h"
#include "WDT_interface.h"
#include "WDT_CFG.h"

void WDT_vEnable(u8 A_u8Timeout);
void WDT_vDisable(void);

#endif /* MCAL_WDT_INTERFACE_H_ */
