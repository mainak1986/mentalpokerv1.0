/*
 * GeneratePrime.c
 *
 *  Created on: Nov 17, 2014
 *      Author: mainak
 */

#include "./headers.h"

int generatePrime(mpz_t *p,mpz_t *q,mpz_t *n,int number)
{
	int i;

	gmp_randstate_t rstate_p[number],rstate_q[number];

	for(i = 0; i < number; i++)
	{
		gmp_randinit_mt(rstate_p[i]);
		gmp_randinit_mt(rstate_q[i]);
	}


	for(i = 0; i < number; i++)
	{

		//Seeds to generate random number
		gmp_randseed_ui(rstate_p[i],randomSeed());
		gmp_randseed_ui(rstate_q[i],randomSeed());

		do{
			do{
				mpz_urandomb(*(p+i),rstate_p[i],32); // generate random number p less than 2^32-1

			}while(mpz_sizeinbase(*(p+i),2)!=32); //checks whether p is 32 bit or not


		}while(!isPrimeNumber(*(p+i)) || (!mpz_congruent_ui_p(*(p+i),3,4))); //checks whether p is prime or not with 500 witnesses


		do{
			do{
				mpz_urandomb(*(q+i),rstate_q[i],32); // generate random number q less than 2^32-1

			}while(mpz_sizeinbase(*(q+i),2)!=32); //checks whether p is 32 bit or not


		}while(!isPrimeNumber(*(q+i)) || (!mpz_congruent_ui_p(*(q+i),3,4))); //checks whether q is prime or not with 500 witnesses


		mpz_mul (*(n+i),*(p+i),*(q+i));

	}

/*	for(i = 0; i < number; i++)
	{
		//Seeds to generate random number
		gmp_randseed_ui(rstate_q[i],randomSeed());

		do{
			do{
				mpz_urandomb(*(q+i),rstate_q[i],32); // generate random number q less than 2^32-1

			}while(mpz_sizeinbase(*(q+i),2)!=32); //checks whether p is 32 bit or not


		}while(!isPrimeNumber(*(q+i)) || (!mpz_congruent_ui_p(*(q+i),3,4))); //checks whether q is prime or not with 500 witnesses

	}*/


	return TRUE;
}

