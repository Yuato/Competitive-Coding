#include <iostream>
#include <stack>
#include <vector>
#define pii pair<int, int>

//COI '06 #1 Patrick
using namespace std;

// 5
// 7 4 5 4 4
int main(){
    int number, tower;
    vector<pii>height;
    vector<int>points;
    points.push_back(0);
    cin>>number;
    cin>>tower;
    height.push_back(pair(tower,0));
    for (int i = 1; i <number; i++){
        int count = 1;
        cin>>tower;
        while ((height.size()!=0)&&((height.back()).first<=tower)){
            count+=(height.back()).second;
            height.pop_back();
        }
        height.push_back(pair(tower,count));
        points.push_back(count);
    }
    for (int i =0; i<number; i++){
        cout<<points[i]<<" ";
    }
}