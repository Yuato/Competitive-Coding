//working (checked with DMOJ)
#include <bits/stdc++.h>

using namespace std;

void line(int len, int print){
    for (int i = 0; i<len; i++){
        cout<<print;
        if (i+1!=len){
            cout<<' ';
        }
    }
}

int main() {
    int n;
    cin>>n;
    if (n%5 == 1){
        for (int i= 0; i<n; i++){
            if (i%5==2){
                line(n,1);
            }
            else if (n-3==i){
                for (int j = 0; j<n; j++){
                    if (j%4 == 0||j%4==1){
                        cout<<1;
                    }
                    else if (j+2==n||j+1==n){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
                    if(j+1!=n){
                        cout<<" ";
                    }
                }
            }
            else{
                line(n, 0);
            }
            if (i+1!=n){
                cout<<'\n';
            }
        }
    }
    else{
        for (int i= 0; i<n; i++){
            if (i%5==2){
                line(n,1);
            }
            else if (n%5==2&&i+1==n){
                line(n,1);
            }
            else{
                line (n,0);
            }
            if (i+1!=n){
                cout<<'\n';
            }
        }
    }
}
