//An Animal Contest 1 P2 - Alpaca Racing
//simple math, implementation problem
#include<iostream>
#include <vector>
// 4 200 1 1
// 1000
// 12
// 2134
// 22
// 1

using namespace std;
int main(){
    int N, D, K;
    bool win = true;
    float X;
    cin>>N>>D>>K>>X;
    vector<float>arr;
    float speed, horse;
    for (int i = 0; i<N; i++){
        cin>>speed;
        arr.push_back(speed);
    }
    cin>>horse;
    for (int i = 0; i<N; i++){
        while((arr[i]>=horse)&&(K!=0)){
            arr[i]=(float)arr[i]*((100.0-X)/100.0);
            cout<<arr[i]<<'\n';
            K--;
        }
        if ((arr[i]>=horse)){
            win = false;
        }
    }
    if (win==true) cout<<"YES";
    else cout<<"NO";
}