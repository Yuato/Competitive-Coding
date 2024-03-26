//An Animal Contest 1 P1 - Alpaca Shapes
//Simple mathmatics involving  the area of a square and circle, directly compare for answer
#include <iostream>
#include <math.h>
#define pi 3.14

using namespace std;
int main(){
    int S, R;
    cin>> S>> R;
    if (pow(S,2)>pi*pow(R,2)){
        cout<<"SQUARE";
    }
    else cout<<"CIRCLE";
}