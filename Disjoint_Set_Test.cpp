#include <bits/stdc++.h>

using namespace std;

int parent [1000010];
int sz [1000010];
int mx = 0;
vector<int>idk;

int fd(int a){
    if (parent[a]==a){
        
        return a;
    }
    return parent[a] = fd(parent[a]);
}

bool same(int a, int b){
    return fd(a)==fd(b);
}

void unite(int a, int b, int c){
    a = fd(a);
    b = fd(b);
    if (sz[b]>sz[a]) swap(a,b);
    if (!same(a,b)){
        idk.push_back(c);
        sz[a]+=sz[b];
        parent[b] = a;
        if (sz[a]>mx) {
            mx = sz[a];
        }
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);
    int n, q; cin>>n>>q;
    for (int i = 1; i<=n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i<q; i++){
        int a,b; cin>>a>>b;
        unite(a,b,i+1);
    }
    if (mx==n){
        for (int i = 0; i<idk.size(); i++){
            cout<<idk[i]<<'\n';
        }
    }
    else{
        cout<<"Disconnected Graph";
    }
}