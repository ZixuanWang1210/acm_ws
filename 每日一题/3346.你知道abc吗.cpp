#include<bits/stdc++.h>
using namespace std;

void sol(){
    vector<int> v(10);
    for(int i=1;i<=7;i++){
        cin>>v[i];
        // cout<<i<<' '<<v[i]<<endl;
    }
    sort(v.begin()+1,v.begin()+1+7);
    cout<<v[1]<<' '<<v[2]<<' '<<v[7]-v[1]-v[2]<<endl;
}

int main(){
    sol();


    return 0;
}