#include<bits/stdc++.h>
#define int long long
using namespace std;


void sol(){
    int n; cin>>n;
    vector<int> v(2*n),s1(2*n),s2(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.begin()+1+n);
    for(int i=1,j=n;i<=n;i++,j--){
        s1[i]=s1[i-1]+v[i];
        s2[j]=s2[j+1]+v[j];
    }
    for(int i=2,j=n;i<j;i++,j--){
        if(s1[i]<s2[j]){
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
    return;
}


signed main(){
    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}