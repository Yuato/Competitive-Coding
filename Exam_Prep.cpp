//TLE (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

long long parent [1000010];
long long sum [1000010];
long long resource[1000010];

long long fd(long long a){
    while (parent[a]!=a){
        a = parent[a];
    }
    return a;
}

bool same(long long a, long long b){
    return fd(a)==fd(b);
}


void unite(int a, int b){
    if (!same(a,b)){
        sum[a]+=sum[b];
        resource[a]+= resource[b];
        parent[b] = fd(a);
    }
}


int main() {
    long long n, q; cin>>n>>q;
    for (int i = 0; i<n; i++){
        long long a; cin>>a;
        parent[i+1] = i+1;
        sum[i+1] = 1;
        resource[i+1] = a;
    }
    
    while (q>0){
        long long cmd; cin>>cmd;
        if (cmd==1){
            long long a, b; cin>>a>>b;
            a = fd(a);
            b = fd(b);
            sum[fd(a)]>sum[fd(b)]?unite(a,b):unite(b,a);
        }
        else if (cmd == 2){
            long long a; cin>>a;
            cout<<sum[fd(a)] << "\n";
        }
        else{
            long long a; cin>>a;
            cout<<resource[fd(a)] << "\n";
        }
        q--;
    }
}