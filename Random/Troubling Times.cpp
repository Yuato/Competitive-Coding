#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, D, time, min;
    cin >> N>>D;
    D = abs(D);
    min = D+1;
    while (N>0){
        cin>>time;
        while (time==0){
            cin>>time;
            N--;
        }
        if ((D%time==0)&&(D/time<min)){
            min = D/time;
        }
        N--;
    }
    if (min == D+1){
        cout<<"This is not the best time for a trip.";
    }
    else {
        cout<<min;
    }
    return 0;
}