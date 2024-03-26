#include <bits/stdc++.h>
#define pic pair<int,char>

using namespace std;

int main() {
    int t, n;
    cin>>t;
    deque<pic>storage;
    for (int i = 0; i<t; i++){
        string sub;
        cin>>n>>sub;
        int max = 0, count = 0;
        storage.clear();
        char temp;
        for (int j = 0; j<n; j++){
            char now = sub[j];
            if (j == 0){
                temp=now;
            }
            if (now == temp){
                count++;
            }
            else{
                storage.push_back(pair(count,temp));
                temp = now;
                count = 1;
            }
            if (j+1==n){
                storage.push_back(pair(count,temp));
            }
        }
        for (int j = 0; j<storage.size();j++){
            if (j+1!=storage.size()&&storage.at(j+1).first==1){
                if (j+2!=storage.size()&&storage.at(j).second==storage.at(j+2).second){
                    count = storage.at(j).first+storage.at(j+2).first+1;
                }
                else{
                    count = storage.at(j).first+1;
                }
            }
            else{
                count = storage.at(j).first+1;
            }
            if (count>max){
                max= count;
            }
        }
        cout<<max;
        if (i+1!=t){
            cout<<'\n';
        }
    }
}