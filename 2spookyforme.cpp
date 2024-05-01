#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;


int main() {
    int N;
    long long L, S;
    cin>>N>>L>>S;
    int a,b,s;
    vector<pii> spooks;
    for (int i = 0; i<N; i++){
        cin>>a>>b>>s;
        spooks.push_back(pair(a,s));
        spooks.push_back(pair(b+1,-s));
    }
    sort(spooks.begin(),spooks.end());
    int ch = 1;
    int tot = 0;
    int sum = 0;
    for (int i = 0; i<spooks.size(); i++){
        int house, chg;
        house = spooks[i].first;
        chg = spooks[i].second;
        if (sum<S){
            tot+=(house-ch);
        }
        ch=house;
        sum+=chg;
    }
    tot+=(L-ch+1);
    cout<<tot;
}