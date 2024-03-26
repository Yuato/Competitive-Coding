#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    int arr[n];
    for (int i = 0; i<n; i++){
        int c;
        cin>>c;
        arr[i] = c;
    }
    int substr = 0;
    int max = 0;
    int total = 0;
    for (int i = 0; i<n; i++){
        if (arr[i]+total<m){
            total = total +arr[i];
            substr++;
        }
        else if (arr[i]>=m){
            substr = 0;
            total = 0;
        }
        else{
            while (arr[i]+total>=m){
                total -= arr[i-substr];
                substr--;
            }
        }
        if (substr>max){
            max = substr;
        }
    }
    cout<<max;
}