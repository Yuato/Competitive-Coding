#include <bits/stdc++.h>

using namespace std;
// 7  
// 1 2 3
// 1 5 7 8
int main() {
    long int N, a;
    cin>>N;
    set<long int>sequence;
    set<long int>::iterator it;
    if (N>0){
        cin>>a;
        sequence.insert(a);
        N--;
    }
    while (N>0){
        cin>>a;
        it = sequence.upper_bound(a);
        if ((it == sequence.end())){
            sequence.insert(a);
        }
        else if (*sequence.lower_bound(a)!=a){
            sequence.insert(it,a); 
            sequence.erase(it++);

        }
        // for (it = sequence.begin();it!=sequence.end();it++){
        //     cout<<*it<<" ";
        // }
        // cout<<'\n';
        N--;
    }
    cout<<sequence.size();
    
    return 0;
}