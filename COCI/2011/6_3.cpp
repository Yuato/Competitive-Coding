//COCI '11 Contest 6 #3 Zagrade
//bitmasking
//stacking

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int start;
    string expression;
    cin>>expression;
    vector<vector<int>>index;
    size_t brac = expression.rfind('(');

    while (brac!=string::npos){
        index[0].push_back(brac+start);
        cout<<"uifhau";
        string sub = expression.substr(brac+1, expression.size());
        int count = 1, sec=0;
        for (int i = 0; i<sub.size(); i++){
            if (sub[i]==')'){
                count--;
            }
            else if (sub[i]=='('){
                count++;
            }
            if (count == 0){
                index[1].push_back(i+start);
            }
        }
        start = start + brac;
        size_t brac = expression.rfind('(');
    }
    for (int i = 0; i<index[0].size();i++){
        cout<<index[0][i]<<" "<<index[1][i]<<'\n';
    }

}