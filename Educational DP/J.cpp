#include <bits/stdc++.h>

using namespace std;

int main() {
    int plates, s, full;
    float total = 0;
    cin>>plates;
    full = plates;
    float chance[plates];
    vector<int>plate;
    vector<int>arr;
    for (int i = 0; i<plates; i++){
        cin>>s;
        plate.push_back(s);
        arr.push_back(s);
    }
    for (int i = 0; i<plates; i++){
        for (int n = i; n<arr.size(); n++){
            arr[n]=arr[n]-1;
            total+=(float)plates/full;
            if (arr[n]==0){
                full--;
                arr.erase(arr.begin()+n);
            }
        }
        
        while (arr.size()>0){
            for (int n = 0; n<arr.size(); n++){
                arr[n]=arr[n]-1;
                total+=(float)plates/full;
                if (arr[n]==0){
                    full--;
                    arr.erase(arr.begin()+n);
                }
            }
        }
        chance[i]=total;
        total = 0;
        full=plates;
        arr.clear();
        arr.insert(arr.begin(),plate.begin(),plate.end());
    }
    for (int i = 0; i<plates; i++){
        total += chance[i];
    }
    cout<<(total/plates);
}