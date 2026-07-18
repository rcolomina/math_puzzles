
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

#include "../common/log.h"

using namespace std;

int solution(vector<int> &A) {
// write your code in C++14 (g++ 6.2.0)
// Build a set with input vector A
    set<int> s(A.begin(), A.end());

    auto it=s.upper_bound(0);
    LOG_DEBUG("upper bound to 0: " << *it);
    LOG_DEBUG("size s: " << s.size());


    if(it == s.end())
    {
        LOG_DEBUG("lower bound is the end -> answer 1");
        return 1;
    }



    set<int> s_pos(it,s.end());
    int N=s_pos.size();
    int mydiffs[N];

    LOG_DEBUG("only positives, size s_pos: " << s_pos.size());
    for(auto it=s_pos.begin();it!=s_pos.end();++it)
        LOG_DEBUG("  positive: " << *it);

    adjacent_difference(s_pos.begin(),s_pos.end(),mydiffs);

    for(int i=0;i<N;++i)
        LOG_DEBUG("adjacent diff[" << i << "] = " << mydiffs[i]);

    for(int i=0;i<N;++i){
        int current_diff = mydiffs[i];
        if(current_diff > 1)
            return i+1;
    }
    return *(s_pos.end())+1;

}


int main(){

    vector<int> test1={-10,-5,1,3,6,4,1,2};

    int n=solution(test1);
    LOG_INFO("solution: " << n);

    test1={1,2,3};
    n=solution(test1);
    LOG_INFO("solution: " << n);

    test1={-1,-2,-3};
    n=solution(test1);
    LOG_INFO("solution: " << n);

    
    
}
