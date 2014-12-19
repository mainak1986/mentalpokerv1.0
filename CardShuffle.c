/*
 * CardShuffle.c
 *
 *  Created on: Nov 17, 2014
 *      Author: mainak
 */

#include "headers.h"


//Implementing Fisher-Yates Shuffle
int cardShuffle(struct Cards *card,mpz_t *n,int number)
{
	int i,j,temp;


	for(i = 0; i < number; i++)
	{
		j = randomSeedCardShuffle();

		printf("\n\tJ = %d",j);

		temp = card[i].cardNumber;
		card[i].cardNumber = card[j].cardNumber;
		card[j].cardNumber = temp;
	}

	for(i = 0; i < number; i++)
	{
		mpz_set(card[i].N,*(n+i));

	}

	return TRUE;
}

