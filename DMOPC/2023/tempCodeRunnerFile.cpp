#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    int count = 0;
    int arr [n][n]; 
    int lim = (n*n+3*n)/5;
    for (int y = 0; y<n; y++){
        for (int x = 0; x<n; x++){
            if ((y%4==3||y%4==2)&&(x%4==3||x%4==2)){
                arr[y][x]=1;
                count++;
            }
            else{
                arr[y][x]=0;
            }
        }
    }
    arr[0][0] = 1;
    arr [ 0][n-1] = 1;
    arr [n-1][0] = 1;
    arr [n-1][n-1]=1;
    count += 4;
    if (count>lim){
        cout<<-1;
    }
    else{
        for (int y = 0; y<n; y++){
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
}
