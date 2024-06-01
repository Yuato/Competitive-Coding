#include <bits/stdc++.h>

using namespace std;

int tree[400010];
int arr[100010];

void pushup(int v) {
    tree[v] = min(tree[2*v], tree[2*v+1]);
}

void build(int l, int r, int v){
    if (l==r){
        tree[v] = arr[l];
        return;
    }
    
    int m = (l+r)/2;
    build (l,m,v*2);
    build(m+1,r, v*2+1);
    pushup(v);
}

void update(int v, int l, int r, int pos, int val){
    if (l==r){
        tree[v] = val;
        return;
    }
    
    int m = (l+r)/2;
    pos<=m?update(v*2,l,m,pos,val):update(v*2+1,m+1,r,pos,val);
    pushup(v);
}

int query(int v, int l, int r, int sl, int sr){
    if(r < sl || sr < l) {
        return INT32_MAX;
    }
    if (sl <= l && r <= sr){
        return tree[v];
    }

    int m = (l+r)/2;
    return min(query(v*2,l,m, sl, sr), query(v*2+1,m+1,r,sl,sr));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    for (int i = 1; i<N+1;i++){
        int a; cin>>a;
        arr[i] = a;
    }
    int l = 1, r = N;
    build(l,r,1);
    while (M>0){
        char A;
        int i,j;
        cin>>A>>i>>j;
        if (A == 'M'){
            update(1,l,r,i+1,j);
        }
        else if (A == 'Q'){         
            cout<<query(1,l,r,i+1,j+1)<<'\n';
        }
        M--;
    }
}