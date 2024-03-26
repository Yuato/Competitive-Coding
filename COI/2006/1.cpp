//COI '06 #1 Patrik
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#define pii pair<int, int>

using namespace std;

// 7
// 2
// 4
// 1
// 2
// 2
// 5
// 1
int main(){
    vector<pii>queue;
    int num, H;
    long int pairs = 0;
    cin>>num;
    if (num>0){
        cin>>H;
        queue.push_back(pair(H, 0));
        num--;
    }
    while (num>0){
        int count = 0;
        cin>>H;
        while ((queue.size()>0)&&(queue[queue.size()-1].first<=H)){
            int n = queue.size()-1;
            if (queue[n].first==H){
                count += queue[n].second;
                break;
            }
            else if (queue[n].first<H){
                pairs ++;
                queue.erase(queue.begin()+n);
            }
        }
        if (queue.size()>0){
            count++;
        }
        queue.push_back(pair(H,count));
        pairs += count;
        num--;
    }
    cout<<pairs;
}