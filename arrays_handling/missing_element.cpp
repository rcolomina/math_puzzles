
#include <vector>
#include <iostream>

using namespace std;

int get_missing_element(vector<int> A){

    unsigned long long int n=A.size();
    unsigned long long int arraySum=0;

    for(int i=0;i<n;++i){
        arraySum+= (unsigned long long int)A[i];

    }
    cout<<arraySum<<endl;
    
    unsigned long long int properSum = (n+1) * (n+2) / 2;
    cout<<properSum<<endl;    
    return (int)(properSum - arraySum);
    
}

int main(){

    int missing=1000; // missing is 1001 (latter sum one in creation)
    vector<int> A;
    for(int i=1;i<=150000;i++){
        if(i!=missing)
            A.push_back(i+1);
    }
    cout<<"A size "<<A.size()<<endl;
    
    int result = get_missing_element(A);
    cout<<"test case big number: "<<result<<endl;
}
