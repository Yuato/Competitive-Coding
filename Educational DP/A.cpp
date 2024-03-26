//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin>>n;
    int arr [n];
    int dp[n];
    for (int i = 0; i<n; i++){
        cin>>a;
        arr[i] = a;
    }
    dp[0] = 0;
    dp[1]= abs(arr[1]-arr[0]);
    for (int i = 2; i<n; i++){
        dp[i] = dp[i-1] + abs(arr[i]-arr[i-1]);
        if (dp[i]>dp[i-2]+abs(arr[i-2]-arr[i])){
            dp[i]= dp[i-2]+abs(arr[i-2]-arr[i]);
        }
    }
    cout<<dp[n-1];
}