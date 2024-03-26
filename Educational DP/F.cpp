//work in progress
#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin>>a>>b;
    int arr[a.size()+1][b.size()+1];
    for (int i = 0; i<a.size()+1; i++){
        for (int j = 0; j<b.size()+1; j++){
            if (i == 0||j==0){
                arr[i][j] = 0;
            }
            else if (a[i-1]==b[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else if (arr[i][j-1]>arr[i-1][j]){
                arr[i][j] = arr[i][j-1];
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    string print = "";
    int x, y;
    x = a.size();
    y = b.size();
    while(true) {
        if (y==0||x==0){
            break;
        }
        if (a[x-1]==b[y-1]){
            print += b[y-1];
            x--;
            y--;
        }
        else if (arr[x][y-1]<arr[x-1][y]){
            x--;
        }
        else{
            y--;
        }
    }
    for (int i = print.size()-1; i>=0; i--){
        cout<<print[i];
    }
}