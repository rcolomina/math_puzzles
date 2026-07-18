#include <iostream>
#include <omp.h>

#include "../common/log.h"

const int MAXNUM= 1000000;
bool isPrime(int);

bool isPrime(int num){
     int factor=2;

     while(factor*factor<=num)
     {
	  if(num%factor==0)
	       return false;
	  factor++;
     }
     
     return true;	
}


int main(){
     bool bPrimes[MAXNUM];

#pragma omp parallel
     {
	  if(omp_get_thread_num() == 0)
	       LOG_INFO("working with " << omp_get_num_threads() << " threads");
#pragma omp for
	  for(int n=0; n < MAXNUM; ++n)
	       bPrimes[n] = isPrime(n);
     }

     for(int n=MAXNUM-100; n<MAXNUM; ++n)
	  if(bPrimes[n])
	       LOG_INFO("prime near MAXNUM: " << n);
}






