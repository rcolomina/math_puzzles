#include <iostream>
#include <omp.h>

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
	       std::cout << "Working with " << omp_get_num_threads() << " threads " << std::endl;
#pragma omp for
	  for(int n=0; n < MAXNUM; ++n)
	       bPrimes[n] = isPrime(n);
     }

     for(int n=MAXNUM-100; n<MAXNUM; ++n)
	  if(bPrimes[n])
	       std::cout << n << std::endl;
}






