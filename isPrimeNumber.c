
#include "./headers.h"

/* Checks whether a number is prime or not...if prime returns TRUE else return FALSE */
int isPrimeNumber(mpz_t randomNumber)
{
  int status;

  //This function does some trial divisions, then some Miller-Rabin probabilistic primality tests.
  //Return 2 if n is definitely prime, return 1 if n is probably prime (without being certain), or return 0 if n is definitely composite.
  status = mpz_probab_prime_p (randomNumber,500);

  if(status == 2 || status == 1)
   return TRUE;
  else
   return FALSE;
}
