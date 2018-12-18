#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min_diff_array(vector<int> A){

    int N = A.size();
    
    
    if(N==2)
        return 1;

    int pmax = 1;

    long int leftSum  = A[0];
    long int rightSum = 0;    
    for(int p=1;p<N;++p){
        rightSum += A[p];
    }

    cout<<endl;
    cout<<"leftSum "<<leftSum<<endl;
    cout<<"rightSum "<<rightSum<<endl;
    cout<<endl;

    
    
    long int diff = abs(leftSum-rightSum);
    cout<<abs(leftSum-rightSum)<<endl;

    long int currentDiff = diff;
    for(int p=2;p<N;++p){

        leftSum   += A[p-1];
        rightSum  -= A[p-1];
        
        if(abs(leftSum-rightSum) < diff)
        {
            diff = abs(leftSum-rightSum);
        }
        cout<<abs(leftSum-rightSum)<<endl;

    }
    cout<<endl;
    return diff;
}




int main(){

    vector<int> test1= {4,3,6,-3,10,20};
    vector<int> test2= {999,-999,0,123,100,500};
    vector<int> test3= {3,1,2,4,3};
    vector<int> test4= {3,1,2,4,3,-100};
    vector<int> test5= {1,2,3,2,100};
    vector<int> test6= {-1,-2,-3,2,100,50};
    

    
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test1)<<endl;
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test2)<<endl;
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test3)<<endl;
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test4)<<endl;
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test5)<<endl;
    cout<<"Test :"<<" -> pmax "<<min_diff_array(test6)<<endl;
    


    return 0;
}
