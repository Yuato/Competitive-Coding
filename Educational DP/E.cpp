//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

int main() { 
    long long n=0, w, v;
    long long W;
    cin>>n>>W;
    long long weight[n+1];
    long long value[n+1];
    long long dp[n*1000+1];
    for (int i = 1; i<n+1; i++){
        cin>>w>>v;
        weight[i] = w;
        value[i] = v;
    }
    for (int i = 0; i<n+1; i++){
        for (int j = n*1000; j>=0; j--){
            if (i == 0){
                dp[j] = 1000000001;
            }
            else if (j == 0){
                if (weight[i]<dp[j+value[i]]){
                    dp[j+value[i]] = weight[i];
                }
            }
            else if (dp[j]<=W){
                if (dp[j]+weight[i]<=W && dp[j+value[i]]>dp[j]+weight[i]){
                    dp[j+value[i]] = dp[j]+weight[i];
                }
            }
        }
    }
    for (int j = n*1000; j>=0; j--){
        if (dp[j]<=W){
            cout<<j;
            break;
        }
    }
}