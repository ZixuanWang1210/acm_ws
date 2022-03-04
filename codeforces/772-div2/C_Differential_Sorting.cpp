#include<bits/stdc++.h>
#define int long long 
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    if(v[n]<v[n-1]){
        cout<<"-1"<<endl;
        return;
    }
    vector<int> ans1,ans2,ans3;
    for(int i=n-2;i>=1;i--){
        if(v[i]>v[i+1]){
            v[i]=v[i+1]-v[n];
            ans1.push_back(i);
            ans2.push_back(i+1);
            ans3.push_back(n);
            if(v[i]>v[i+1]){
                cout<<-1<<endl;
                return;
            }
        }
    }

    cout<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<' '<<ans2[i]<<' '<<ans3[i]<<endl;
    }
}

signed main(){
    int T; cin>>T;
    while(T--){
        sol();
    }

    return 0;
}