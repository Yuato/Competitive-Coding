#include <bits/stdc++.h>

using namespace std;

int Sumtree[400010];
int Lesstree[400010];
int sum[100010];
int lesslist[100010];

void Sumpushup(int v) {
    Sumtree[v] = Sumtree[2*v]+ Sumtree[2*v+1];
}

void Numpushup(int v){
    Lesstree[v]= Lesstree[2*v]+Lesstree[2*v+1];
}

void Sumbuild(int l, int r, int v){
    if (l==r){
        Sumtree[v] = sum[l];
        return;
    }
    
    int m = (l+r)/2;
    Sumbuild (l,m,v*2);
    Sumbuild(m+1,r, v*2+1);
    Sumpushup(v);
}
void Numbuild(int l, int r, int v){
    if (l==r){
        Lesstree[v] = lesslist[v];
        return;
    }
    int m = (l+r)/2;
    Numbuild(l,m,v*2);
    Numbuild(m+1,r,v*2+1);
    Numpushup(v);
}

void Sumupdate(int v, int l, int r, int pos, int val){
    if (l==r){
        Sumtree[v] = val;
        return;
    }
    
    int m = (l+r)/2;
    pos<=m?Sumupdate(v*2,l,m,pos,val):Sumupdate(v*2+1,m+1,r,pos,val);
    Sumpushup(v);
}

void Numupdate(int v, int l, int r, int pos, int val){
    if (l==r){
        Lesstree[v]-=val;
        return;
    }
    int m = (l+r)/2;
    pos<=m?Numupdate(v*2,l,m,pos,val):Numupdate(v*2+1,m+1,r,pos,val);
    Numpushup(v);
}

int Sumquery(int v, int l, int r, int sl, int sr){
    if(r < sl || sr < l) {
        return 0;
    }
    if (sl <= l && r <= sr){
        return Sumtree[v];
    }

    int m = (l+r)/2;
    return Sumquery(v*2,l,m, sl, sr)+Sumquery(v*2+1,m+1,r,sl,sr);
}

int Numquery(int v, int l, int r, int sl, int sr){
    if(r < sl || sr < l) {
        return 0;
    }
    if (sl <= l && r <= sr){
        return Lesstree[v];
    }

    int m = (l+r)/2;
    return Numquery(v*2,l,m, sl, sr)+Numquery(v*2+1,m+1,r,sl,sr);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    for (int i = 1; i<100100;i++){
        int a; cin>>a;
        lesslist[i] = 0;
        sum[i] = a;
    }
    for (int i = 0; i<N; i++){
        lesslist[sum[i]]++;
    }
    int l = 1;
    Numbuild(l,N,1);
    Sumbuild(l,100000,1);
    while (M>0){
        char A;
        int i,j;
        cin>>A;
        if (A == 'M'){
            Sumupdate(1,l,r,i+1,j);
        }
        else if (A == 'Q'){         
            cout<<query(1,l,100001,i+1,j+1)<<'\n';
        }
        M--;
    }
}