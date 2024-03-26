//COCI '08 Contest 4 #4 Slikar

#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int N;
int arr[512][512];
int painting[512][512];

int countones(int x, int y, int p){
    int ret = 0;
    if (p == 0){
        return arr[y][x];
    }
    ret += countones(x,y,p-1);
    ret += countones((x+ pow(2,p-1)), y, p-1);
    ret += countones(x, (y+pow(2,p-1)), p-1);
    ret += countones((x+ pow(2,p-1)), (y+pow(2,p-1)), p-1);
    return ret;
}

void paint(int x, int y, int p, int num){
    for (int y1 = y; y1<y+pow(2,p); y1++){
        for (int x1 = x; x1<x+pow(2,p); x1++){
            painting[y1][x1]=num;
        }
    }
}

void solve(int x, int y, int p){
    int q1 = countones(x,y,p-1);
    int q2 = countones((x+ pow(2,p-1)), y, p-1);
    int q3 = countones(x, (y+pow(2,p-1)), p-1);
    int q4 = countones((x+ pow(2,p-1)), (y+pow(2,p-1)), p-1);
    vector<int>quadrants;
    quadrants.clear();
    int sol[4];
    for (int i = 0; i<4; i ++){
        sol[i]= 0;
    }
    quadrants.push_back(q1);
    quadrants.push_back(q2);
    quadrants.push_back(q3);
    quadrants.push_back(q4);
    sort(quadrants.begin(),quadrants.end());
    if (p == 1){
        bool one= false, zero= false;
        if ((q1==1)||(q2==1)||(q3==1)||(q4==1)){
            one = true;
        }
        if ((q1==0)||(q2==0)|| (q3==0)|| (q4==0)){
            zero = true;
        }
        for (int y1 = y; y1<y+2; y1++){
            for (int x1 = x; x1<x+2; x1++){
            painting[y1][x1]=arr[x1][y1];
            }
        }
        if (zero==false){
            painting[y][x]=0;
        }
        else if(one==false){
            painting[y][x]=1;
        }
    }
    //black(0)
    else{
    if (q1 == quadrants[0]){
        paint(x,y,p-1, 0);
        sol[0]=-1;
    }
    else if (q2 == quadrants[0]){
        paint((x+ pow(2,p-1)), y, p-1, 0);
        sol[1]=-1;
    }
    else if (q3 == quadrants[0]){
        paint(x, (y+pow(2,p-1)), p-1, 0);
        sol[2]= -1;
    }
    else if (q4 == quadrants[0]){
        paint((x+ pow(2,p-1)), (y+pow(2,p-1)), p-1, 0);
        sol[3]=-1;
    }
    //white (1)
    if (q4 == quadrants[3]){
        paint((x+ pow(2,p-1)), (y+pow(2,p-1)), p-1, 1);
        sol[3]=-1;
    }
    else if (q1 == quadrants[3]){
        paint(x,y,p-1, 1);
        sol[0]=-1;
    }
    else if (q2 == quadrants[3]){
        paint((x+ pow(2,p-1)), y, p-1, 1);
        sol[1]=-1;
    }
    else if (q3 == quadrants[3]){
        paint(x, (y+pow(2,p-1)), p-1, 1);
        sol[2]=-1;
    }
    if (sol[0]!=-1){
        solve(x,y,p-1);
    }
    if (sol[1]!=-1){
        solve((x+ pow(2,p-1)), y,p-1);
    }
    if (sol[2]!=-1){
        solve(x,(y+pow(2,p-1)),p-1);
    }
    if (sol[3]!=-1){
        solve((x+ pow(2,p-1)), (y+pow(2,p-1)),p-1);
    }
    }
}

int main (){
    int N;
    char color;
    cin>>N;
    int m = N;
    int p =0;
    int count = 0;
    while (m!=1){
        m=m/2;
        p++;
    }
    for (int y = 0; y<N; y++){
        for (int x = 0; x<N; x++){
            cin>>color;
            if (color == '0'){
                arr[y][x]=0;
            }
            else {
                arr[y][x]=1;
            }
        }
    }
    cout<<"solving";
    solve (0,0,p);

    for (int y = 0; y<N; y++){
        for (int x = 0; x<N; x++){
            if (arr[y][x]!=painting[y][x]){
                count++;
            }
        }
    }
    cout<<count;

    for (int y = 0; y<N; y++){
        cout<<'\n';
        for (int x = 0; x<N; x++){
            cout<<painting[y][x];
        }
    }
}