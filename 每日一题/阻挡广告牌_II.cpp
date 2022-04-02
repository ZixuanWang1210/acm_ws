#include <bits/stdc++.h>
using namespace std;

int main(){
    int x[5], y[5];
    for(int i=1; i<=4; i++)
        cin>>x[i]>>y[i];
    if(x[4]>=x[2] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1])
        cout<<0;//完全覆盖
    else if(x[3]<=x[1] && y[3]<=y[1] && y[4]>y[1] && x[4]>=x[2])
        cout<<(x[2]-x[1])*(y[2]-y[4]);//上方未覆盖
    else if(y[3]<y[2] && x[3]<=x[1] && y[4]>=y[2] && x[4]>=x[2])
        cout<<(x[2]-x[1])*(y[3]-y[1]);//下方未覆盖
    else if(x[4]>x[1] && x[3]<=x[1] && y[4]>=y[2] && y[3]<=y[1])
        cout<<(x[2]-x[4])*(y[2]-y[1]);//右侧未覆盖
    else if(x[3]<x[2] && x[4]>=x[2] && y[4]>=y[2] && y[3]<=x[1])
        cout<<(x[3]-x[1])*(y[2]-y[1]);//左侧未覆盖
    else cout<<(x[2]-x[1])*(y[2]-y[1]);//完全未覆盖 以及只覆盖边角
    return 0;
}
