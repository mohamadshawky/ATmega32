/*
 * EXTI_private.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Mohamed
 */

/**************************************************************************************/
/*
 *      ________   _________ _____      _____  _____  _______      __  _______ ______
 *     |  ____\ \ / /__   __|_   _|    |  __ \|  __ \|_   _\ \    / /\|__   __|  ____|
 *     | |__   \ V /   | |    | |      | |__) | |__) | | |  \ \  / /  \  | |  | |__
 *     |  __|   > <    | |    | |      |  ___/|  _  /  | |   \ \/ / /\ \ | |  |  __|
 *     | |____ / . \   | |   _| |_     | |    | | \ \ _| |_   \  / ____ \| |  | |____
 *     |______/_/ \_\  |_|  |_____|    |_|    |_|  \_\_____|   \/_/    \_\_|  |______|
 *
 *
 */

/*===============================================================================================
*	 - Developer can't Edit in it
*	  - Register _ Definition
*	  - Design :
					- #define	:	Yes
					- Union		:	NO
					- Struct	:	NO

===================================================================================================*/

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define MCUCR 		*((volatile u8*)(0x55))
#define MCUCSR		*((volatile u8*)(0x54))
#define GICR 		*((volatile u8*)(0x5B))
#define GIFR		*((volatile u8*)(0x5A))





#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
