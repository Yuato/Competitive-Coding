//Solved (Checked with DMOJ)
//Knapsack problem (DP approach)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[101];
    for (int i = 0; i<5; i++){
        int s, d, w, v;
        cin>>s>>d;
        for (int j = 0; j<101; j++){
            arr[j] = 0;
        }
        for (int j = 0; j<d; j++){
            cin>>w>>v;
            for (int k = s; k>=0; k--){
                if (k-w>=0&&arr[k-w]+v>arr[k]){
                    arr[k]=arr[k-w]+v;
                }
            } 
        }
        int max = 0;
        for (int j = 0; j<101; j++){
            if (arr[j]>max){
                max = arr[j];
            }
        }
        cout<<max<<'\n';
    }
}