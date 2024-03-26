#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    unsigned long long m;
    cin>>n>>m;
    unsigned long long arr[n];
    for (int i = 0; i<n; i++){
        unsigned long long c;
        cin>>c;
        arr[i] = c;
    }
    int max = 0;
    int left = 0;
    unsigned long long total = 0;
    for (int i = 0; i<n; i++){
        if (arr[i]+total<m){
            total = total +arr[i];
        }
        else if (arr[i]>=m){
            left = i;
            total = 0;
        }
        else{
            while (arr[i]+total>=m){
                total = total - arr[left];
                left++;
            }
            total = arr[i]+total;
        }
        if (i-left+1>max){
            max = i-left+1;
            if (i-left+1==1&&arr[i]>=m){
                max = 0;
            }
        }
    }
    cout<<max;
}