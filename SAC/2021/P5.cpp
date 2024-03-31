//solved (checked with DMOJ)

#include <bits/stdc++.h>

using namespace std;

int parent [1000010];
int sz [1000010];

int fd(int a){
    while (parent[a]!=a){
        a = parent[a];
    }
    return a;
}

bool same(int a, int b){
    return fd(a)==fd(b);
}

void unite(int a, int b){
    a = fd(a);
    b = fd(b);
    if (sz[b]>sz[a]) swap(a,b);
    if (!same(a,b)){
        sz[a]+=sz[b];
        parent[b] = a;
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for (int i = 1; i<=n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
    for (int i = 0; i<q; i++){
        int j; cin>>j;
        if (j==1){
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        else{
            int a; cin>>a;
            cout<<sz[fd(a)]<<'\n';
        }
    }
    return 0;
}