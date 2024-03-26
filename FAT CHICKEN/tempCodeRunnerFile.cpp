#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int>::iterator itr; 
    for (int i = 0; i<5; i++){
        long long R, C, Ro;
        cin>>R>>C>>Ro;
        vector<int>row;
        vector<int>col;
        long long total = R*C;
        for (int i = 0; i<Ro; i++){
            int r, c;
            cin>>r>>c;
            if (find(row.begin(), row.end(), r)==row.end()){
                row.push_back(r);
            }
            if (find(col.begin(), col.end(), c)==col.end()){
                col.push_back(c);
            }
        }
        for (int n = 0; n<row.size(); n++){
            total -= R;
            total += col.size();
        }
        for (int n = 0; n<col.size(); n++){
            total -= C;
            total += row.size();
        }
        total -= row.size()*col.size();
        row.clear();
        col.clear();
        cout<<total;
        if (i+1!=5){
            cout<<'\n';
        }
    }
}