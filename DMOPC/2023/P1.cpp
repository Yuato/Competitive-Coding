#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    if (k==0){
        cout<<-1;
    }
    else if (k>n){
        cout<<-1;
    }
    else{
        int arr[n][n];
        int i = 1;
        for (int y= 0; y<n; y++){
            for (int x = 0; x<n; x++){
                arr[y][x]= i;
                i++;
            }
        }
        for (int r = 1; r<k; r++){
            int x = arr[n-1][n-r-1];
            arr[n-1][n-r-1] = arr[n-r-1][n-r-1];
            arr[n-r-1][n-r-1] = x;
        }
        for (int y= 0; y<n; y++){
            for (int x = 0; x<n; x++){
                cout<<arr[y][x];
                if (x+1!=n){
                    cout<<" ";
                }
            }
            if (y+1!=n){
                cout<<'\n';
            }
        }
    }
    return 0;
}