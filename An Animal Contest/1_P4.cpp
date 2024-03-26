#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 5 3
// 1 5 5 2 3
// 1 3 25
// 1 4 6
// 1 5 10
int main(){
    int N, Q, l, r, x, num;
    bool yes = false;
    cin>>N>>Q;
    vector<int>arr;
    std::vector<int>::iterator itr;
    for (int i = 0; i <N; i++){
        cin>>num;
        arr.push_back(num);
    }
    for (int n = 0; n<Q; n++){
        cin>>l>>r>>x;
        for (int a = l; a<r-l+1; a++){
            if (x%arr[a]==0){
                itr = find(arr.begin()+(l-1),arr.begin()+(r-1), x/arr[a]);
                if ((itr != arr.begin()+(r-1))&&(x/arr[a]!=arr[a])){
                    yes = true;
                    break;
                }
            }
        }
        if (yes){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
        yes = false;
    }
}