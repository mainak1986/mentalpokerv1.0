/*
 * MentalPoker_Alice.c
 *
 *  Created on: Nov 17, 2014
 *      Author: mainak
 */

#include "headers.h"


int main()
{
	mpz_t p[NO_CARDS],q[NO_CARDS],n[NO_CARDS];
//	mpz_t *p,*q;

	struct Cards card[NO_CARDS];


	int i;

	for(i = 0;i<NO_CARDS;i++)
	{
		mpz_init(*(p+i));
		mpz_init(*(q+i));
		mpz_init(*(n+i));

		card[i].cardNumber = i;
		mpz_init(card[i].N);
	}

	for(i = 0;i<NO_CARDS;i++)
		fprintf(stdout,"\n\t%d",card[i].cardNumber);

	// generated prime number for each cards
	generatePrime(p,q,n,NO_CARDS);

	// shuffle the cards using Fisher-Yates algorithm
	cardShuffle(card,n,NO_CARDS);

/*	for(i = 0; i < NO_CARDS ; i++)
	{
		gmp_fprintf(stdout,"\np = %Zd",*(p+i));
		gmp_fprintf(stdout,"  q = %Zd",*(q+i));
		gmp_fprintf(stdout,"  n = %Zd",*(n+i));
	}*/

	for(i = 0;i<NO_CARDS;i++)
	{
		fprintf(stdout,"\nCard No::%d",card[i].cardNumber);
		gmp_fprintf(stdout,"  n = %Zd",card[i].N);
	}



	return TRUE;
}

