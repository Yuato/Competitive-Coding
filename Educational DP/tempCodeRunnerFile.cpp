//work in progress
#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin>>a>>b;
    string arr[a.size()+1][b.size()+1];
    for (int i = 0; i<a.size()+1; i++){
        for (int j = 0; j<b.size()+1; j++){
            if (i == 0||j==0){
                arr[i][j] = "";
            }
            else if (a[i-1]==b[j-1]){
                arr[i][j] = arr[i-1][j-1]+a[i-1];
            }
            else if (arr[i][j-1]>arr[i-1][j]){
                arr[i][j] = arr[i][j-1];
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    cout<<arr[a.size()][b.size()];
}