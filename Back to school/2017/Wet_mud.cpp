//work in progress
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, j;
    bool poss = true;
    int arr[n+2];
    vector<int>possible;
    cin>>n>>m>>j;
    for (int i= 0; i<n; i++){
        arr[i] = -1;
    }
    for (int i= 1; i<=m; i++){
        int p,t;
        cin>>p>>t;
        arr[p] = t;
    }
    
}