//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n=0, W, w, v;
    cin>>n>>W;
    int weight[n+1];
    int value[n+1];
    long long dp[n+1][W+1];
    for (int i = 1; i<n+1; i++){
        cin>>w>>v;
        weight[i] = w;
        value[i] = v;
    }
    for (int i = 0; i<n+1; i++){
        for (int x = 0; x<W+1; x++){
            if ((i == 0)||(x==0)){
                dp[i][x] = 0;
            }
            else{
                if (weight[i]<=x){
                    if (value[i]+dp[i-1][x-weight[i]]>=dp[i-1][x]){
                        dp[i][x] = value[i]+dp[i-1][x-weight[i]];
                    }
                    else{
                        dp[i][x] = dp[i-1][x];
                    }
                }
                else{
                    dp[i][x] = dp[i-1][x];
                }
            }
        }
    }
    cout<<dp[n][W];
}