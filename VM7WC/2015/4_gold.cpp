//work in progress
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

int main() {
    int N, M;
    cin>>N>>M;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    vector<vector<pii>>routes;
    vector<pii>empty;
    bool fwd[N];
    bool back[N];
    int forward[N];
    int backward[N];
    for (int i = 0; i<N; i++){
        routes.push_back(empty);
        forward[i] = 0;
        fwd[i] = true;
        backward[i] = 0;
        back[i] = true;
    }
    for (int i = 0; i<M; i++){
        int a,b,t;
        cin>>a>>b>>t;
        routes[a].push_back(pair(b,t));
        routes[b].push_back(pair(a,t));
    }
    pq.push(pair(0,0));

    while (!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (fwd[node]){
            for (int i = 0; i<routes[node].size();i++){
                pq.push(pair(time+routes[node][i].second,routes[node][i].first));
            }
            forward[node] = time;
            fwd[node] = false;
        }
    }

    pq.push(pair(0,N-1));
    while (!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (back[node]){
            for (int i = 0; i<routes[node].size();i++){
                pq.push(pair(time+routes[node][i].second,routes[node][i].first));
            }
            backward[node] = time;
            back[node] = false;
        }
    }
    int max = 0;
    for (int i = 0 ; i<N; i++){
        if (forward[i]+backward[i]>max){
            max = forward[i]+backward[i];
        }
    }
    cout<<max;
}