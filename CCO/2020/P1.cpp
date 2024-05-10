#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, L, R, Y;
    vector<int>start;
    vector<int>end;
    int arr[n+1];
    cin>>n>>L>>R>>Y;
    for (int i = 0; i<n; i++){
        arr[i+1] = 0;
        double p, y, x;
        cin>>p>>y>>x;
        double b1 = -(y/x)*p;
        double b2 = (y/x)*p;
        double endx = x*(Y+b1)/y;
        double startx = x*(Y+b2)/y;
    }
    while (start.size()>0||end.size()>0){
        
    }
}