/*
 * SPI_private.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#define ENABLE				1
#define DISABLE				0

/* SPI Control Register – SPCR */
#define SPCR 		*((volatile u8*)(0x2D))
#define	SPIE				7				/*	SPI Interrupt Enable */
#define	SPE					6				/* SPI Enable */
#define	DORD				5				/* Data Order */
#define	MSTR				4				/* Master/Slave Select */
#define	CPOL				3				/* Clock Polarity */
#define	CPHA				2				/* Clock Phase */
#define	SPR1				1				/* SPI Clock Rate Select 1 */
#define	SPR0				0				/* SPI Clock Rate Select 0 */

/* SPI Status Register – SPSR */
#define SPSR		*((volatile u8*)(0x2E))
#define	SPIF				7				/* SPI Interrupt Flag */
#define WCOL				6				/* Write COLlision Flag */
#define SPI2X				0				/* Double SPI Speed Bit */

/* SPI Data Register – SPDR */
#define SPDR		*((volatile u8*)(0x2F))
#define MSB 				7
#define	LSB					0

/* Data order values */
#define SPI_DATA_ORDER_MSB		0
#define SPI_DATA_ORDER_LSB		1

/* Master selection values */
#define	SPI_SLAVE			0
#define SPI_MASTER			1

/* SPI Mode values */
#define SPI_SAMPLE_RISING_SETUP_FALLING		0
#define SPI_SETUP_RISING_SAMPLE_FALLING		1
#define SPI_SAMPLE_FALLING_SETUP_RISING		2
#define SPI_SETUP_FALLING_SAMPLE_RISING		3

/* Pre-scaler values */
#define SPI_PSC_DIV_4		0
#define SPI_PSC_DIV_16		1
#define SPI_PSC_DIV_64		2
#define SPI_PSC_DIV_128		3
#define SPI_PSC_DIV_2		4
#define SPI_PSC_DIV_8		5
#define SPI_PSC_DIV_32		6

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
