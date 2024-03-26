//work in progress
#include <iostream>
#include <vector>
#define pii std::pair<int, int>

int main(){
    std::vector<int>cheers;
    int cheer, N, M, index = 0, max = 0, count = 0;
    pii start = std::pair(0,0);
    std::cin>>N>>M;
    std::string X;
    std::cin>>X;
    std::string change = X;
    for (int i = 0; i<M; i++){
        std::cin>>cheer;
        if (cheer>=max){
            max = cheer;
            start = std::pair(max,i+1);
        }
    }
    
    for (int i = 0; i<N; i++){
        if (X[i] == '0'){
            count++;
            change.erase(change.begin()+i-count+1);
        }
        if (i == start.second){
            index = i-count;
        }
    }
    std::cout<<change.substr(index+1,change.size()-index)<<change.substr(0,index+1);
}