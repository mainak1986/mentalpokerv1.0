/*
 * randomSeedCardShuffle.c
 *
 *  Created on: Nov 17, 2014
 *      Author: mainak
 */


#include "./headers.h"


/* Function to generate 1 byte random seed less than 52. The return value is generated using /dev/urandom */
int randomSeedCardShuffle()
{
  unsigned char random;
  FILE *fp;
  int i;

  if((fp=fopen("/dev/urandom","r"))==NULL) // opens /dev/urandom to read random numbers
   exit(1);

  random = 0x0;

  do{
	  random = fgetc(fp);

  }while(random >= 52 || random < 0);

  fclose(fp);

  return random;
}

