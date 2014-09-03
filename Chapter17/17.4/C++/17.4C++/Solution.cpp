#include "Solution.h"
#include <iostream>

//Returns 1 is n >= 0 and returns 0 if n < 0
int sign(int n)
{
	return (n >> 31) & 0x1; //Without &01, -1 will be 11111111, and after flipping, flip_sign will be 11111110 (-2)
}

int flipSign(int sign)
{
	return sign ^ 0x1; // 0^0 = 1 and a^1 = ~a
}

/*
if ( ab < 0)
	k = sign(a)
else
	k = sign(a - b)
*/
int getMax(int a, int b)
{
	int diff = a - b;
	int sign_a = sign(a);
	int sign_b = sign(b);
	int sign_diff = sign(diff);

	int use_sign_a = sign_a ^ sign_b; //use sign_a only when a,b has different signs
	int use_sign_diff = flipSign(use_sign_a); // otherwise, use sign of diff

	//Use k to wrap up the selection above: k is sign_a when a, b has different signs; k is sign_diff, when a, b has same sign.
	int k = use_sign_a*sign_a + use_sign_diff*sign_diff; 
	int flip_k = flipSign(k);

	return flip_k * a + k * b;
}


int getMaxNaive(int a, int b)
{
	int sign_bit = sign(a - b); // a - b will cause overflow/underflow when ab < 0;
	int flip_sign = flipSign(sign_bit); 

	return a*flip_sign + b*sign_bit;
}


