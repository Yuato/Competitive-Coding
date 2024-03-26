//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, k;
    cin>>n>>k;
    int arr [n];
    int dp[n];
    for (int i = 0; i<n; i++){
        cin>>a;
        arr[i] = a;
    }
    dp[0] = 0;
    for (int i = 1; i<n; i++){
        int min = INT16_MAX;
        min = dp[i-1] + abs(arr[i]-arr[i-1]);
        for (int e = 1; e<k+1; e++){ 
            if ((i-e>=0)&&(min>dp[i-e]+abs(arr[i-e]-arr[i]))){
                min = dp[i-e]+abs(arr[i-e]-arr[i]);
            }
        }
        dp[i] = min;
    }
    cout<<dp[n-1];
}