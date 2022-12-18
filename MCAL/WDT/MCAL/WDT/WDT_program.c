/*
 * WDT_program.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Mohamed
 */
#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "WDT_private.h"
#include "WDT_CFG.h"
#include "WDT_interface.h"


void WDT_vEnable(u8 A_u8Timeout){
	WDTCR = (WDTCR & ~(0b111)) | A_u8Timeout;
	SET_BIT(WDTCR, 3);
}

void WDT_vDisable(void){
	WDTCR = 0b00011000;
	WDTCR = 0;
}
