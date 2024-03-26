#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

void recursive(int n, int x, int y, bool line){
    int counter = 0;
    if (line){
        cout<<'\n';
    }
    int quad = 0; 
    int div = n/2;
    int upy = y-(y%n)+n/2-1;
    int leftx = x-(x%n)+n/2-1;
    int downy = y-(y%n)+n/2;
    int rightx = x-(x%n)+n/2;
    if ((x%n)<div&&(y%n)<div){
        quad = 0;
    } 
    else if((x%n)>=div&&(y%n)<div){
        quad = 1;
    } 
    else if ((x%n)<div&&(y%n)>=div){
        quad = 2;
    } 
    else{
        quad = 3;
    }
    if (quad != 0){
        counter++;
        cout<<leftx<<" "<<upy<<" ";
    }
    if (quad!=1){
        counter++;
        cout<<rightx<<" "<<upy<<" ";
    }
    if(quad!=2){
        counter++;
        cout<<leftx<<" "<<downy;
        if (counter < 3) cout<<" ";
    }
    if (quad!=3){
        counter++;
        cout<<rightx<<" "<<downy;
        if (counter < 3) cout<<" ";
    }
    if (div > 1){
        if (quad != 0){
            recursive(div,leftx,upy, true);
        }
        if (quad!=1){
            recursive(div,rightx,upy, true);
        }
        if(quad!=2){
            recursive(div,leftx,downy, true);
        }
        if (quad!=3){
            recursive(div,rightx,downy, true);
        }
        recursive(div,x,y, true);
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, x1, y1;
    cin>>N>>x1>>y1;
    int side = pow(2,N); 
    recursive(side,x1,y1, false);
}