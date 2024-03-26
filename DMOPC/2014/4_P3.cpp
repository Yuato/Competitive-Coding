#include <bits/stdc++.h>

using namespace std;

int main() {
    int L, D, l, d;
    cin>>L>>D;
    int arr[D][L];
    int dp[D][L];
    int depth [D] = {0};
    for (int y = 0; y<D; y++){
        for (int x = 0; x<L; x++){
            int a;
            cin>>a;
            arr[y][x] = a;
            depth [y]+=a;
        }
    }
    cin>>l>>d;
    //dynamic programming
    for (int y = 0; y<D; y++){
        for (int x = 0; x<L; x++){
            if (y == 0 && x==0){
                dp[y][x] = arr[y][x];
            }
            else if (y == 0){
                dp[y][x] = dp[y][x-1]+arr[y][x];
            }
            else if (x == 0){
                dp[y][x] = dp[y-1][x]+arr[y][x];
            }
            else{
                if (dp[y-1][x]<dp[y][x-1]){
                    dp[y][x] = dp[y-1][x]+arr[y][x];
                }
                else{
                    dp[y][x]= dp[y][x-1]+arr[y][x];
                }
            }
        }
        for (int x = L-2; x>=0; x--){
            if (dp[y][x]>dp[y][x+1]+arr[y][x]){
                dp[y][x] = dp[y][x+1]+arr[y][x];
            }
        }
    }
    cout<<dp[d][l];
}