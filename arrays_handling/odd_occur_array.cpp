#include <vector>
#include <map>
#include <iostream>

#include "../common/log.h"

using namespace std;

// O(n) version using key-value
int find_odd_occur_array(vector<int> &A){

    map<int,int> numberElements;

    int size = (int)A.size();
    for(int i=0;i<size;++i){
        numberElements[A[i]]++;
    }

    for(auto &item: numberElements){
        if(item.second == 1)
            return item.first;
    }
    
    return -1;

}

int find_odd_occur_array_xor(vector<int> &A){

    int myret = A[0];
    int size  = A.size();

    for(int i=1;i<size;++i){
        int element=A[i];
        myret = myret ^ element;
        LOG_DEBUG("xor after index " << i << " = " << myret);
    }
    return myret;    
}


int main(){

    vector<int> A = {9,3,9,3,9,7,9};

    LOG_INFO("find_odd_occur_array -> " << find_odd_occur_array(A));
    LOG_INFO("find_odd_occur_array_xor -> " << find_odd_occur_array_xor(A));
     
    
}
