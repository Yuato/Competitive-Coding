#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int>houses;
    set<int>power;
    set<int>::iterator it;
    int T, N, x, p, erase;
    cin>>T;
    while (T>0){
        int cord = 0;
        int min = INT32_MAX;
        cin>>N;
        while (N>0){
            cin>>x>>p;
            if (p==0){
                houses.push_back(x);
            }
            else power.insert(x);
            N--;
        }
        while(houses.size()>0){
            for (int i = 0; i<houses.size(); i++){
                it = power.lower_bound(houses[i]);
                int x = abs(houses[i]-*it);
                it--;
                if (x>abs(houses[i]-*it)){
                    x = abs(houses[i]-*it);
                }
                if (x<min){
                    min = x;
                    erase = i;
                }
            }
            power.insert(houses[erase]);
            houses.erase(houses.begin()+erase);
            cord+=min;
            min = INT32_MAX;
        }
        cout<<cord;
        T--;
        if(T!=0){
            cout<<'\n';
        }
    }

    return 0;
}
