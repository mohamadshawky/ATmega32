/*
 * SPI_CFG.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_

#define SPI_EN_DIS
/*
 * Options:
 * 			ENABLE
 * 			DIABLE
 * */
#define SPI_INTERRUPT ENABLE
#define SPI_EN_DIS ENABLE


/*
 * Options:
 * 			SPI_DATA_ORDER_MSB
 *			SPI_DATA_ORDER_LSB
 * */
#define SPI_DATA_ORDER SPI_DATA_ORDER_LSB

/*
 * Options:
 * 			SPI_SLAVE
 * 			SPI_MASTER
 * */
#define SPI_MASTER_SEL SPI_MASTER

/*
 * Options:
 * 			SPI_SAMPLE_RISING_SETUP_FALLING
 *			SPI_SETUP_RISING_SAMPLE_FALLING
 *			SPI_SAMPLE_FALLING_SETUP_RISING
 * 			SPI_SETUP_FALLING_SAMPLE_RISING
 * */
#define SPI_MODE SPI_SETUP_FALLING_SAMPLE_RISING

/*
 * Options:
 *			SPI_PSC_DIV_4
 *			SPI_PSC_DIV_16
 *			SPI_PSC_DIV_64
 *			SPI_PSC_DIV_128
 *			SPI_PSC_DIV_2
 *			SPI_PSC_DIV_8
 *			SPI_PSC_DIV_32
 * */
#define SPI_PS_SEL SPI_PSC_DIV_4

#endif /* MCAL_SPI_SPI_CFG_H_ */
