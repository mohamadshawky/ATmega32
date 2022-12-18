/*
 * GIE_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_GIE_GIE_PROGRAM_C_
#define MCAL_GIE_GIE_PROGRAM_C_


#include "../../Utils/STD_TYPES.h"
#include "../../Utils/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_CFG.h"

void MGIE_vEnable(){
	SET_BIT(GIE_SREG, I_BIT);
}

void MGIE_vDiable(){
	CLR_BIT(GIE_SREG , I_BIT);

}

#endif /* MCAL_GIE_GIE_PROGRAM_C_ */
