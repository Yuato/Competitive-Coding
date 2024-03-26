//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b,c;
    cin>>n;
    int arr[n][3];
    int dp[n][3];
    for (int i = 0; i<n; i++){
        cin>>a>>b>>c;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = c;
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2]; 

    for (int i = 1; i<n; i++){
        if (dp[i-1][1]+arr[i][0]>=dp[i-1][2]+arr[i][0]){
            dp[i][0] = dp[i-1][1]+arr[i][0];
        }
        else{
            dp[i][0] = dp[i-1][2]+arr[i][0];
        }
        if (dp[i-1][0]+arr[i][1]>=dp[i-1][2]+arr[i][1]){
            dp[i][1] = dp[i-1][0]+arr[i][1];
        }
        else{
            dp[i][1] = dp[i-1][2]+arr[i][1];
        }
        if (dp[i-1][1]+arr[i][2]>=dp[i-1][0]+arr[i][2]){
            dp[i][2] = dp[i-1][1]+arr[i][2];
        }
        else{
            dp[i][2] = dp[i-1][0]+arr[i][2];
        }
    }
    int max = 0;
    for (int i = 0; i <3; i++){
        if (dp[n-1][i]>max){
            max = dp[n-1][i];
        }
    }
    cout<<max;
}