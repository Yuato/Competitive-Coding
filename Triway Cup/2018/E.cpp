#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main() {
    int N, C;
    cin>>N>>C;
    long long x,y,d;
    vector<pii>points;
    for (int i = 0; i<N; i++){
        cin>>d>>y>>x;
        int dis = (x*x+y*y);
        points.push_back(pair(dis,d));
    }
    sort(points.begin(),points.end());
    int max = 0;
    long long dmg = 0;
    for (int i = 0; i<points.size();i++){
        dmg += points[i].second;
        int rad = points[i].first;
        int eff = dmg-C*rad;
        if(eff>max){
            max = eff; 
        }
    }
    cout<<(int)max;
}