/*
 * SPI_program.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Mohamed
 */

#include "../../Utils/BIT_MATH.h"
#include "../../Utils/STD_TYPES.h"

#include "../DIO/DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_CFG.h"

void (*GP_SPI_STC_Callback)(void);

void SPI_vInit(void){

	u8 A_u8SPCR = 0;

	#if SPI_EN_DIS	== ENABLE
		SET_BIT(A_u8SPCR, SPIE);

	#if SPI_INTERRUPT == ENABLE
		SET_BIT(A_u8SPCR, SPIE);
	#elif SPI_INTERRUPT == DISABLE
		CLR_BIT(A_u8SPCR, SPIE);
	#endif

	#if SPI_MASTER_SEL == SPI_MASTER
		SET_BIT(A_u8SPCR, MSTR);
	#elif SPI_MASTER_SEL == SPI_SLAVE
		CLR_BIT(A_u8SPCR, MSTR);
	#endif

	#if SPI_DATA_ORDER == SPI_DATA_ORDER_MSB
		CLR_BIT(A_u8SPCR, DORD);
	#elif SPI_DATA_ORDER == SPI_DATA_ORDER_LSB
		SET_BIT(A_u8SPCR, DORD);
	#endif

	#if SPI_MODE == SPI_SAMPLE_RISING_SETUP_FALLING
		CLR_BIT(A_u8SPCR, CPHA);
		CLR_BIT(A_u8SPCR, CPOL);

	#elif SPI_MODE == SPI_SETUP_RISING_SAMPLE_FALLING
		SET_BIT(A_u8SPCR, CPHA);
		CLR_BIT(A_u8SPCR, CPOL);

	#elif SPI_MODE == SPI_SAMPLE_FALLING_SETUP_RISING
		CLR_BIT(A_u8SPCR);
		SET_BIT(A_u8SPCR, CPOL);

	#elif SPI_MODE == SPI_SETUP_FALLING_SAMPLE_RISING
		SET_BIT(A_u8SPCR, CPHA);
		SET_BIT(A_u8SPCR, CPOL);
	#endif

	#else
		CLR_BIT(A_u8SPCR, SPIE);
#endif
		SPCR = A_u8SPCR;
}


//void SPI_vInit(void){
//
//	/* 1. SPI Enable
//	 * SET_BIT(SPCR, SPE);
//	 *
//	 * 2. SPI Interrupt enable
//	 * polling
//	 *
//	 * 3. Data order
//	 * default
//	 *
//	 * 4. SPI master/slave
//	 * 	SET_BIT(SPCR, MSTR);
//	 * 	CLR_BIT(SPCR, MSTR);
//	 *
//	 * 5. SPI Mode
//	 * 5.1. CPOL
//	 * 5.2. CPHZ
//	 * loop back test.
//	 *
//	 * 6. Baud Rate
//	 * for master only but concern that slave will follow Fosc/16.. generic
//	 * SET_BIT(SPCR, SPR0);
//	 * CLR_BIT(SPCR, SPR1);
//	 * CLR_BIT(SPCR, SPI2X);
//	 * */
//	SPCR = 0b01011100;
//	/* Enable SPI
//	 * Initiate master
//	 * setting com. mode setup @ falling, sampling @ rising */
//	SPCR = (SPCR<<SPE)|(SPCR<<MSTR)|(SPCR<<CPOL)|(SPCR<<CPHA);
//
//	/* setting loop back mechanism */
//	DIO_SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);	/* MOSI */
//	DIO_SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_INPUT);	/* MISO */
//	DIO_SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);	/* SCK */
//}

u8	SPI_u8Transceive(u8 A_u8Byte){

	SPDR = A_u8Byte;

	/* Wait for reception complete ( Data update in MOSI) */
	while(GET_BIT(SPSR, SPIF) == 0);

	/* Return data register */
	return SPDR;
}

void SPI_vSetCallback(void(*fptr)(void)){
	GP_SPI_STC_Callback = fptr;
}

void __vector_12(void) __attribute__ ((signal));
void __vector_12(void){
	if (GP_SPI_STC_Callback != NULL)
		GP_SPI_STC_Callback();
}

