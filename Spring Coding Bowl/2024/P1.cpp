#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[3];
    int n; cin>>n;
    arr[0] = 0; arr[1] = 0; arr[2] = 0;
    for (int i = 0; i<n; i++){
        string inp;
        cin>>inp;
        if (inp=="rock"){
            arr[0]++;
        }
        else if (inp == "scissors"){
            arr[1]++;
        }
        else{
            arr[2]++;
        }
    }
    bool poss = true;
    int num = arr[0];
    for (int i = 0; i<3; i++){
        if (num!=arr[i]){
            poss = false;
            break;
        }
    }
    if (poss){
        cout<<"no";
    }
    else{
        cout<<"yes";
    }
}