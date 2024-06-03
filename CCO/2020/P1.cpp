#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, L, R, Y;
    vector<long long>start;
    vector<long long>end;
    cin>>n>>L>>R>>Y;
    long long arr[n+1];
    for (int i = 0; i<n; i++){
        arr[i+1] = 0;
        double p, y, x;
        cin>>p>>y>>x;
        double b1 = -(y/x)*p;
        double b2 = (y/x)*p;
        double endx = x*(Y+b2)/y;
        double startx = -x*(Y+b1)/y;
        if (startx<(long long)startx){
            start.push_back((long long)startx-1);
        }
        else{
            start.push_back((long long)startx);
        }
        if (endx>(long long)endx){
            end.push_back((long long)endx+1);//non inclusive point
        }
        else{
            end.push_back((long long)(endx));//non inclusive point
        }
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    long long point = L;
    long long gaze = 0;
    long long inx1 = 0;
    long long inx2 = 0;
    while (inx1<start.size()&&start[inx1]<L){
        gaze++;
        inx1++;
    }
    while(inx2<start.size()&&end[inx2]<L){
        gaze--;
        inx2++;
    }
    while ((inx1<start.size()||inx2<end.size())){
        if (inx1<start.size()&&inx2<end.size()){
            if (start[inx1]<end[inx2]){
                if (start[inx1]<=R){
                    arr[gaze]+=start[inx1]-point+1;
                }
                else{
                    arr[gaze]+=R-point+1;
                }
                point = start[inx1]+1;
                inx1++;
                gaze++;
            }
            else if (start[inx1]==end[inx2]){
                inx1++;
                inx2++;    
            }
            else{
                if (end[inx2]<=R){
                    arr[gaze]+=end[inx2]-point;
                }
                else{
                    arr[gaze]+=R-point+1;
                }
                point = end[inx2];
                inx2++;
                gaze--;
            }
        }
        else if (inx1<start.size()){
            if (start[inx1]<=R){
                arr[gaze]+=start[inx1]-point+1;
            }
            else{
                arr[gaze]+=R-point+1;
            }
            point = start[inx1]+1;
            inx1++;
            gaze++;
        }
        else{
            if (end[inx2]<=R){
                    arr[gaze]+=end[inx2]-point;
                }
                else{
                    arr[gaze]+=R-point+1;
                }
                point = end[inx2];
                inx2++;
                gaze--;
        }
        if (point>R){
            break;
        }
    }
    long long solution[n+1];
    long long points = R-L+1;
    solution[n]= points;
    for (int i = n; i>=1; i--){
        points-=arr[i];
        solution[i-1] = points;
    }
    for (int i = 0; i<n+1; i++){
        cout<<solution[i]<<'\n';
    }
}