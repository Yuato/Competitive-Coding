#include <bits/stdc++.h>

using namespace std;

int main(){
    int L, W;
    char b;
    cin>>W>>L;
    int arr [W][L];
    for (int y = 0; y<W; y++){
        for (int x = 0; x<L; x++){
            cin>>b;
            arr[y][x]=0;
            if (b=='#'){
                arr[y][x]=0;
            }
            else if (y==0&&x==0){
                arr[y][x]=1;
            }
            else if (y>0&&x>0){
                arr[y][x]=(arr[y-1][x]+arr[y][x-1])%1000000007;
            }
            else if (y>0){
                arr[y][x]=(arr[y-1][x])%1000000007;
            }
            else if (x>0){
                arr[y][x]=(arr[y][x-1])%1000000007;
            }
            else{
                arr[y][x]=0;
            }
        }
    }
    cout<<arr[W-1][L-1];
}

