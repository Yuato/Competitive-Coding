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
    if (!same(a,b)){
        sz[a]+=sz[b];
        parent[b] = fd(a);
    }
}

int main() {
    int n, q; cin>>n>>q;
    for (int i = 1; i<n+1; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i<q; i++){
        char ch; cin>>ch;
        if (ch == 'A'){
            int a, b; cin>>a>>b;
            a = fd(a);
            b= fd(b);
            sz[a]>sz[b]?unite(a,b):unite(b,a);
        }
        else {
            int a, b; cin>>a>>b;
            if (same(a,b)){
                cout<<"Y";
            }
            else{
                cout<<"N";
            }
            cout<<'\n';
        }
    }
}