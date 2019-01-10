
// Find the smalles possitive missing integer in the input array
// Ex:  [1,3,6,4,1,2] -> 5
//      [-1,-3] -> 1
//      [1,2,3] -> 4

// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
// write your code in C++14 (g++ 6.2.0)
// Build a set with input vector A
    set<int> s(A.begin(), A.end());

    auto it=s.upper_bound(0);
    cout<<"Upper bound to 0:  "<<*it<<endl;
    cout<<"size s:"<<s.size()<<endl;

    
    if(it == s.end())
    {    
        cout<<"lower bound is the end"<<endl;
        return 1;
    }
        

        
    set<int> s_pos(it,s.end());
    int N=s_pos.size();
    int mydiffs[N];

    cout<<"only positives"<<endl;
    cout<<"size s_pos:"<<s_pos.size()<<endl;
    for(auto it=s_pos.begin();it!=s_pos.end();++it)
        cout<<*it<<endl;
    cout<<"end listing"<<endl;
       
    adjacent_difference(s_pos.begin(),s_pos.end(),mydiffs);


    for(int i=0;i<N;++i)
        cout<<mydiffs[i]<<" ";
    cout<<endl;
    
    
    for(int i=0;i<N;++i){
        int current_diff = mydiffs[i];
        cout<<current_diff<<endl;
        if(current_diff > 1)
            return i+1;
    }
    return *(s_pos.end())+1;

}


int main(){

    vector<int> test1={-10,-5,1,3,6,4,1,2};

    int n=solution(test1);    
    cout<<"solution:"<<n<<endl;

    test1={1,2,3};
    n=solution(test1);    
    cout<<"solution:"<<n<<endl;

    test1={-1,-2,-3};
    n=solution(test1);    
    cout<<"solution:"<<n<<endl;

    
    
}
