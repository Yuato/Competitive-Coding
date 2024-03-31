//work in progress
#include <bits/stdc++.h>
#define pii pair<long long,long long>

using namespace std;

int main() {
    int n, m; cin>>n>>m;
    long long arr [n];
    int track [2][1000010];
    for (int i = 0; i<1000010; i++){
        track[0][i] = track[0][i+1]= 1000010;
        track[1][i+1]= -1;
    }
    for (int i = 0; i<n; i++){
        long long a; cin>>a;
        arr[i] = a;
    }
    for (int i = 0; i<n; i++){
        if (track[0][arr[i]]!=1000010){
            track[0][arr[i]] = i;
        }
        track[1][arr[i]] = i;
    }
    int min = 0;
    vector<pii>scarf;
    for (int i = 0; i<m; i++){
        long long a,b; cin>>a>>b;
        scarf.push_back(pair(a,b));
    }
    for (int i = 0; i<m; i++){
        long long a = scarf[i].first;
        long long b = scarf[i].second;
        if (track[1][b]-track[0][a]+1>min){
            min = track[1][b]-track[0][a]+1;
        }
    }
    cout<<min;
}