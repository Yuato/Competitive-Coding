#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N, P, one = 0, three, four;
    cin>>N;
    vector<int>permutation;
    for (int i = 0; i<N; i++){
        cin>>P;
        permutation.push_back(P);
        if (P==1){
            one = i; 
        }
        else if (P==3){
            three = i; 
        }
        else if (P==4){
            four = i; 
        }
    }
    if (N==3){
        cout<<three+1<<" "<< three+1;
    }
    else if ((N==4)&&(abs(four-three)==1)){
        if (three<four){
            cout<<three+1<<" "<< four+1;
        }
        else if (three>four){
            cout<<four+1<<" "<< three+1;
        }
    }
    else if (one == 0){
        cout<<"2 "<< N;
    }
    else if (one == N-1){
        cout<<"1 "<<N-1;
    }
    else {
        cout<<"1 "<<N;
    }
}