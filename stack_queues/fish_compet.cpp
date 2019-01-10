#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B){

    int N=A.size();
    
    stack<pair<int,int> > downstream; // 1
    stack<pair<int,int> > upstream;   // 0 
        
    for(int i=0;i<N;i++)
        if(B[i]==1)
            downstream.push(make_pair(i,A[i]));
    

    for(int i=N-1;i>=0;--i)
        if(B[i]==0)        
            upstream.push(make_pair(i,A[i]));

    
    int num_alive=0;
    
    while(!upstream.empty() && !downstream.empty()){
        pair<int,int> topDown = downstream.top();
        pair<int,int> topUp   = upstream.top();

        // case scape
        if(topDown.first > topUp.first){
            upstream.pop();
            num_alive++;
        }
        else
        {
            if(topUp.second > topDown.second)
                downstream.pop();
            else
                upstream.pop();
        }                            
    } 

    return num_alive+downstream.size()+upstream.size();

}


int solution_2(vector<int> &A, vector<int> &B){

    stack<int> s;
    int N=A.size();

/*    if(N==2){
        if(B[0] != B[1] && B[0] == 1)
            return 1;
        else
            return 2;
    }
*/  
    for(int i=0;i<N;i++)
    {
        cout<<"*** current fish *** "<<i<<endl;
        if(s.empty())
        {
            s.push(i);
            cout<<"push fish num. "<<i<<endl;
        }
        else
        {
            // Battle happens
            if(B[s.top()]==1 && B[i]==0)
            {
                cout<<"Battle happens"<<endl;
                while(A[i] > A[s.top()] && B[s.top()] == 1)
                    s.pop();

                if(A[i] > A[s.top()])
                    cout<<"Wins upstream "<<i<<endl;
                else
                    cout<<"Wins downstream "<<s.top()<<endl;
                
                if(!s.empty() && B[s.top()] == 0)
                    s.push(i);                
            }
            else
            {
                cout<<"Fish pushed into stack "<<i<<endl;
                s.push(i);
            }
        }
    }
    
    return s.size();
}


int main(){

    vector<int> A={4,3,2,1,5};
    vector<int> B={0,1,0,0,0};
    
    /*;    cout<<solution(A,B)<<endl;

    A={6,3,2,1,5};
    B={1,0,0,0,0};
    cout<<solution(A,B)<<endl;

    A={6,3,2,1,6};
    B={0,0,0,0,1};
    cout<<solution(A,B)<<endl;
    */    
    cout<<solution_2(A,B)<<endl;

    A={6,3,2,1,4};
    B={1,1,1,1,1};
    cout<<solution_2(A,B)<<endl;

    A={6,3,2,1,4};
    B={0,0,0,0,0};
    cout<<solution_2(A,B)<<endl;

    A={6,3};
    B={0,1};
    cout<<solution_2(A,B)<<endl;

    A={6,3};
    B={1,0};
    cout<<solution_2(A,B)<<endl;

    
    return 0;
}
