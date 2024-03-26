
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,t;
    cin>>n;
    int arr[100000];
    for (int i = 0; i<n; i++){
        cin>>t;
        arr[t] = arr[t]+1;
    }

    int cards = 0;
    int total = 0;
    int check = 1;
    while (total<n-1){
        while (arr[check] == 0){
            check++;
        }
        total = total + check;
        arr[check] = arr[check]-1;
        cout<<check<<" ";
        if (check<=total){
            check = total+1;
        }
        cards++;
    }
    cout<<cards;
}