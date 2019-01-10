// you can use includes, for example:
// #include <algorithm>
#include <stack>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <string>
#include <iostream>

using namespace std;

int iter_solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    if(S=="")
        return 1;

    stack<char> mystack;

    for(auto it=S.begin();it!=S.end();++it)
    {
        // check top of the stack
        char c=*it;
        //cout<<"Char "<<c<<endl;        
        if(c=='(' || c=='[' || c=='{')
        {
            mystack.push(c);
        }
        if(!mystack.empty())
        {
            //cout<<"top "<<mystack.top()<<endl;           
            if((mystack.top()=='(' && c==')') || (mystack.top()=='[' && c==']') || (mystack.top()=='{' && c=='}'))
                mystack.pop();

            
        }
    }
    if(mystack.empty())
        return 1;
    return 0;

}

int recur_solution(string &S){
    
    if(S.size() == 0)
        return 1;
    else
    {
        if(S.size() % 2 != 0)
            return 0;

        for(auto it=S.begin()+1;it!=S.end()-1;++it)
        {
            string s1 = S.substr(*(S.begin())+1,*it);
            string s2 = S.substr(*it,*(S.end()));
            if(recur_solution(s1) && recur_solution(s2))
                return 1;
        }
                
        char first = S[0];
        char last  = S[S.size()-1];
        auto it1=S.begin();
        auto it2=S.end();
        string middle;

        if(it1+1!=it2)
            middle=middle.substr(*it1+1,*it2-1);
        
        if(first==last && recur_solution(S))
            return 1;
        else
            return 0;
    }
}

int main(){

    string S="[[]]";
    bool nested=iter_solution(S);
    cout<<"(iter) properly nested:"<<nested<<endl;
    nested=iter_solution(S);    
    cout<<"(recut) properly nested:"<<nested<<endl;
    
    S="[([)]";
    nested=iter_solution(S);
    cout<<"(iter) properly nested:"<<nested<<endl;
    nested=iter_solution(S);    
    cout<<"(recut) properly nested:"<<nested<<endl;

    S="[{[]}][[()]]";
    nested=iter_solution(S);
    cout<<"(iter) properly nested:"<<nested<<endl;
    nested=iter_solution(S);    
    cout<<"(recut) properly nested:"<<nested<<endl;

    S="[][]";
    nested=iter_solution(S);
    cout<<"(iter) properly nested:"<<nested<<endl;
    nested=iter_solution(S);    
    cout<<"(recut) properly nested:"<<nested<<endl;
    
    
    
}
