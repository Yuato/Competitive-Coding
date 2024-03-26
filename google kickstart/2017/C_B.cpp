#include <iostream>
#include <vector>
//2
// 3
// ..X
// XX.
// XX.

using namespace std;
int main(){
    int grid,X, row=0, total;
    char repeat;
    bool possible = true;
    cin>>total;
    for (int c = 1; c<total+1; c++){
        cin>>grid;
        vector<int>arr(grid,0);
        int half = (grid - 1)/2;

        for (int y = 0; y<grid; y++){
            row = 0;
            cout<<y;

            for (int x = 0; x<grid; x++){
                cin>>repeat;
                if (repeat == 'X'){
                    row++;
                    arr[x] = arr[x]+1;
                }

            }

            if (row!=half+1-(y%half)){
                possible = false;
            }
        }
        for (int x = 0; x<grid; x++){
            if (arr[x]!=half+1-(x%half)){
                possible = false;
                break;
            }
        }
        cout<<"Case #"<<c<<": ";
        if (possible){
            cout<<"POSSIBLE";
        }
        else if (possible = false){
            cout<<"IMPOSSIBLE";
        }
        possible = true;
        
    }
}