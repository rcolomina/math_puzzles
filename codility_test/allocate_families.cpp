#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

/* Task to do

Allocate families in a place.

  A-B-C D-E-F-G H-J-K
1 
2
3
   ..    ..     ..
N

String comes in a string e.g. S="1A 2F 1C"

p


*/

using namespace std;

// allocate families 3 person in same row
int solution(int N, string &S){

    if(N==1 && S=="")
        return 3;
    

    istringstream iss(S);
    vector<string> seats(istream_iterator<string>{iss},
                         istream_iterator<string>());

    int fam1=N;
    int fam2=N;
    int fam3=N;

    int busy[10][N] = {0};
    //busy.fill(0);
    //memset(busy,-1,sizeof(busy) * 10 *N);

    
    for(int i=0;i<seats.size();i++){
        string seat = seats[i];
        char col = seat.back();
        int  row = stoi(seat.substr(0, seat.size()-1));
        cout<<col<<" "<<row<<" "<<endl;

        if(col=='A')
            busy[0][row-1]=1;
        if(col=='B')
            busy[1][row-1]=1;
        if(col=='C')
            busy[2][row-1]=1;
        if(col=='D')
            busy[3][row-1]=1;
        if(col=='E')
            busy[4][row-1]=1;
        if(col=='F')
            busy[5][row-1]=1;
        if(col=='G')
            busy[6][row-1]=1;
        if(col=='H')
            busy[7][row-1]=1;
        if(col=='J')
            busy[8][row-1]=1;
        if(col=='K')
            busy[9][row-1]=1;                
                
    }

    //for(int i=0;i<10;i++){
    //    for(int j=0;j<N;j++)
    //        cout<<busy[i][j]<<" ";
    // }

    for(int i=0;i<N;i++){
        // if row A, B or C busy substract afam1
        if(busy[0][i] == 1 || busy[1][i] == 1 || busy[2][i] == 1)
            fam1--;
        if(busy[7][i] == 1 || busy[8][i] == 1 || busy[9][i] == 1)
            fam3--;

        // DEF free
        bool defFree = busy[3][i] !=1 && busy[4][i] !=1  && busy[5][i] !=1;
        bool efgFree = busy[4][i] !=1 && busy[5][i] !=1  && busy[6][i] !=1;

        if(!defFree && !efgFree)
            fam2--;
        
    }

    return fam1+fam2+fam3;
}


int main(){

    //vector<int> A={4,3,2,1,5};
    //vector<int> B={0,1,0,0,0};

    int N=2;
    string S="1A 2F 1C"; // length N   ex: "1A 3C 2B 40G 5A"  reserverd seats
    int num_families = solution(N,S);    
    cout<<num_families<<endl;


    N=2;
    S="1A 2F 1C 1E"; // length N   ex: "1A 3C 2B 40G 5A"  reserverd seats
    num_families = solution(N,S);    
    cout<<num_families<<endl;
    
    
    return 0;
}
