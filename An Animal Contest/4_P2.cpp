#include <iostream>
#include <vector>
//4 2
// 2 4 6 8
// 4
// 24

int main(){
    int N, Q, a, t, left;
    std::cin>>N>>Q;
    std::vector<int>lights;
    for (int i = 0; i<N; i++){
        std::cin>>a;
        lights.push_back(a);
    }
    while (Q!=0){
        bool on = true;
        std::cin>>t;
        for (int i = 0; i<N; i++){
            if (t%lights[i]!=0){
                left = i+1;
                on = false;
                break;
            }
        }
        if (on){
            std::cout<<"-1";
        }
        if (on == false){
            std::cout<<left;
        }
        Q--;
    }
}