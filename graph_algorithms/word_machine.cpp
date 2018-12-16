
#include <iostream>
#include <stack>
#include <utility>
#include <list>
#include <vector>

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

int word_machine(string S){

    stack<int> mymachine;

    cout<<istream_iterator<string>();
    
    return -1;
    istringstream iss(S);
    vector<string> tokens;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(tokens));
    
    for(int i=0;i<tokens.size();++i)
    {
        string token = tokens[i];
        
        if(token=="POP"){
            if(mymachine.empty())return -1;
            mymachine.pop();
        }
        else if(token=="DUP"){
            if(mymachine.empty())return -1;
            mymachine.push(mymachine.top());
        }
        else if(token=="+"){
            if(mymachine.empty())return -1;
            int f=mymachine.top();mymachine.pop();
            if(mymachine.empty())return -1;
            int s=mymachine.top();mymachine.pop();
            mymachine.push(f+s);
        }
        else if(token=="-"){
            if(mymachine.empty())return -1;
            int f=mymachine.top();mymachine.pop();
            if(mymachine.empty())return -1;
            int s=mymachine.top();mymachine.pop();
            mymachine.push(f-s);
        }
        else{
            mymachine.push(stoi(token));
        }                
    }

    if(!mymachine.empty()) 
        return mymachine.top();
    else
        return -1;
}

int main(){

    string test = "13 DUP 4 POP 5 DUP + DUP + -";    
    cout<<"output word machine on: "<<test<<" = "<<word_machine(test)<<endl;

    test = "5 6 + -";
    cout<<"output word machine on: "<<test<<" = "<<word_machine(test)<<endl;


    test = "3 DUP 5 - -";
    cout<<"output word machine on: "<<test<<" = "<<word_machine(test)<<endl;
    
    return 0;
}
