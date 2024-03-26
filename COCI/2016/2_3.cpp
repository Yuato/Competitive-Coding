//work in progress
#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin>>n;
    long long arr[n];
    for (int i = 0; i<n; i++){
        long long l; cin>>l;
        arr[i] = l;
    }
    int left = 0;
    int right = n-1;
    int count = 0;
    while (true){
        if (left>=right){
            cout<<count;
            break;
        }
        if (arr[left]>arr[right]){
            arr[right-1] = arr[right-1]+arr[right];
            right--;
            count++;
        }
        else if (arr[left]<arr[right]){
            arr[left+1] = arr[left+1]+arr[left];
            left++;
            count++;
        }
        else if (arr[left]==arr[right]){
            right--;
            left++;
        }
    }
}