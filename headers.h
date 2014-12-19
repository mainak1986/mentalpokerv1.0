/*
 * headers.h
 *
 *  Created on: Nov 17, 2014
 *      Author: mainak
 */

#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define TRUE 0
#define FALSE 1

#define NO_CARDS 52

struct Cards
{
	int cardNumber;
	mpz_t N;
};


int generatePrime(mpz_t *,mpz_t *,mpz_t *,int );
int isPrimeNumber(mpz_t );
unsigned long int randomSeed();
int randomSeedCardShuffle();

int cardShuffle(struct Cards *,mpz_t *,int );




#endif /* HEADERS_H_ */
