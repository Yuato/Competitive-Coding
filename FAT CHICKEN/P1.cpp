#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 0;
    int arr[n];
    for (int i = 0; i<n; i++){
        int t;
        cin>>t;
        arr[i]= t;
    }
    for (int i = 0; i<n/2; i++){
        if (arr[i]!=arr[n-i-1]){
            count+=2;
        }
    }
    cout<<count;
}