#include <bits/stdc++.h>

using namespace std;

int main() {
    char arr[1000];
    string str;
    int n; 
    cin>>str;
    cin>>n;
    for (int i = 0; i<26; i++){
        arr[i] = (char)(97+i);
    }
    for (int i = 0; i<n; i++){
        char a,b;
        cin>>a>>b;
        for (int i = 0; i<26; i++){
            if (arr[i] == a) arr[i] = b;
        }
    }
    for (int i = 0; i<str.size(); i++){
        cout<<arr[((int)str[i])-97];
    }
    return 0;
}