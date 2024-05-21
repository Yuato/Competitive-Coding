#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std; 

int main() {
    int T, N, M, G;
    cin>>T>>N>>M>>G;
    vector<int>store;
    for (int i = 0; i<G; i++){
        int n;
        cin>>n;
        store.push_back(n);
    }
    vector<pii>arr[N+1];
    bool visited[N+1];
    int path[N+1];
    for (int i = 0; i<N+1; i++){
        visited[i] = false;
    }
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i<M; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back(pair(b,c));
        if (a == 0){
            pq.push(pair(c,b));
        }
    } 
    while(!pq.empty()){
        int length = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visited[node]==false){
            path[node] = length;
            visited[node] = true;
            for (int i = 0; i<arr[node].size(); i++){
                int nnode = arr[node][i].first;
                int nlength = length+arr[node][i].second;
                if (visited[nnode]==false){
                    pq.push(pair(nlength,nnode));
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i<store.size(); i++){
        if (path[store[i]]<T&&visited[store[i]]==true){
            count++;
        }
    }
    cout<<count;
}