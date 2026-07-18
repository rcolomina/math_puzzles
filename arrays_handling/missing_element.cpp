
#include <vector>
#include <iostream>

#include "../common/log.h"

using namespace std;

int get_missing_element(vector<int> A){

    unsigned long long int n=A.size();
    unsigned long long int arraySum=0;

    for(int i=0;i<n;++i){
        arraySum+= (unsigned long long int)A[i];

    }
    LOG_DEBUG("array sum  = " << arraySum);

    unsigned long long int properSum = (n+1) * (n+2) / 2;
    LOG_DEBUG("proper sum = " << properSum);
    return (int)(properSum - arraySum);
    
}

int main(){

    int missing=1000; // missing is 1001 (latter sum one in creation)
    vector<int> A;
    for(int i=1;i<=150000;i++){
        if(i!=missing)
            A.push_back(i+1);
    }
    LOG_DEBUG("A size " << A.size());

    int result = get_missing_element(A);
    LOG_INFO("test case big number: missing element = " << result);
}
