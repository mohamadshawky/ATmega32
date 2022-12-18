//BIT_MATH.h

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

	#define SET_BIT(r,b) ((r) |= (1<<(b)))
	#define CLR_BIT(r,b) (r) &= ~(1<<(b))
	#define TOG_BIT(r,b) (r) ^= (1<<(b))
	#define GET_BIT(r,b) (((r)>>(b)) & (0x01))

#endif
