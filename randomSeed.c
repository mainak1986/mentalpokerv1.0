
#include "./headers.h"


/* Function to generate 4 byte random seed. The return value is generated using /dev/urandom */
unsigned long int randomSeed()
{
  unsigned long int random;
  FILE *fp;
  int i;

  if((fp=fopen("/dev/urandom","r"))==NULL) // opens /dev/urandom to read random numbers
   exit(1);

  random = 0x0;

  for(i = 0;i<4;i++)
  {
    random =  random|fgetc(fp); //reads random number
  
    if(i!=3)
     random = random << 8; //except the last byte left shift the data by 8 bits
  }

  fclose(fp);

  return random; 
}

